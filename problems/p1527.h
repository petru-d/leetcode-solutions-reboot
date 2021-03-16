#pragma once

namespace p1527
{
    std::string query()
    {
        return "SELECT * from Patients WHERE conditions LIKE 'DIAB1%' or conditions LIKE '% DIAB1%'";
    }
}
