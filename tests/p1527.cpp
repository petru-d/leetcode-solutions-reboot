#include "pch.h"

#include "../problems/p1527.h"

#include <sqlite3.h>

struct Patient
{
    int Id = 0;
    std::string Name;
    std::string Conditions;
};

std::vector<Patient> extracted;

int callback(void* data, int argc, char** argv, char** azColName)
{
    extracted.push_back(Patient{atoi(argv[0]), std::string(argv[1]), std::string(argv[2])});
    return 0;
}

TEST(p1527, t0)
{
    sqlite3* DB = nullptr;
    auto ret = sqlite3_open(":memory:", &DB);
    ASSERT_TRUE(ret == SQLITE_OK);

    std::string sql = "CREATE TABLE Patients("
                      "patient_id INT PRIMARY KEY NOT NULL, "
                      "patient_name varchar NOT NULL, "
                      "conditions varchar);";

    char* err = nullptr;
    ret = sqlite3_exec(DB, sql.c_str(), nullptr, 0, &err);
    ASSERT_TRUE(ret == SQLITE_OK);

    sql = "INSERT INTO Patients VALUES(1, 'Daniel', 'YFEV COUGH');"
          "INSERT INTO Patients VALUES(2, 'Alice', '');"
          "INSERT INTO Patients VALUES(3, 'Bob', 'DIAB100 MYOP');"
          "INSERT INTO Patients VALUES(4, 'George', 'ACNE DIAB100');"
          "INSERT INTO Patients VALUES(5, 'Alain', 'DIAB201');";

    ret = sqlite3_exec(DB, sql.c_str(), nullptr, 0, &err);
    ASSERT_TRUE(ret == SQLITE_OK);

    sql = p1527::query();

    ret = sqlite3_exec(DB, sql.c_str(), callback, nullptr, nullptr);
    ASSERT_TRUE(ret == SQLITE_OK);

    ASSERT_TRUE(extracted.size() == 2);
    EXPECT_TRUE(extracted[0].Id == 3);
    EXPECT_TRUE(extracted[1].Id == 4);
}
