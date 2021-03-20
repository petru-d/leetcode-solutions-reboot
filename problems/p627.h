#pragma once
#include <string>

namespace p627
{

    std::string query()
    {
        return "UPDATE Salary\n"
               "SET sex = case sex when 'm' then 'f' else 'm' end";

        // other option
        // #update salary set sex = CHAR(ASCII('f') ^ ASCII('m') ^ ASCII(sex));
    }

}
