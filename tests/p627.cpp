#include "pch.h"

#include "../problems/p627.h"
#include <sqlite3.h>
namespace
{
    struct Employee
    {
        int Id = 0;
        std::string Name;
        std::string Sex;
        int Salary;
    };

    std::vector<Employee> extracted;

    int callback(void* data, int argc, char** argv, char** azColName)
    {
        extracted.push_back(Employee{atoi(argv[0]), std::string(argv[1]), std::string(argv[2]), atoi(argv[3])});
        return 0;
    }
}

TEST(p627, t0)
{
    sqlite3* DB = nullptr;
    auto ret = sqlite3_open(":memory:", &DB);
    ASSERT_TRUE(ret == SQLITE_OK);

    std::string sql = "CREATE TABLE Salary("
                      "id INT PRIMARY KEY NOT NULL, "
                      "name varchar NOT NULL, "
                      "sex ENUM, "
                      "salary INT);";

    char* err = nullptr;
    ret = sqlite3_exec(DB, sql.c_str(), nullptr, 0, &err);
    ASSERT_TRUE(ret == SQLITE_OK);

    sql = "INSERT INTO Salary VALUES(1, 'A', 'm', 2500);"
          "INSERT INTO Salary VALUES(2, 'B', 'f', 1500);"
          "INSERT INTO Salary VALUES(3, 'C', 'm', 5500);"
          "INSERT INTO Salary VALUES(4, 'D', 'f', 500);";

    ret = sqlite3_exec(DB, sql.c_str(), nullptr, 0, &err);
    ASSERT_TRUE(ret == SQLITE_OK);

    sql = p627::query();

    ret = sqlite3_exec(DB, sql.c_str(), nullptr, nullptr, nullptr);
    ASSERT_TRUE(ret == SQLITE_OK);

    sql = "SELECT * from Salary";
    ret = sqlite3_exec(DB, sql.c_str(), callback, nullptr, nullptr);
    ASSERT_TRUE(ret == SQLITE_OK);

    ASSERT_TRUE(extracted.size() == 4);
    EXPECT_TRUE(extracted[0].Sex == "f");
    EXPECT_TRUE(extracted[1].Sex == "m");
    EXPECT_TRUE(extracted[2].Sex == "f");
    EXPECT_TRUE(extracted[3].Sex == "m");
}
