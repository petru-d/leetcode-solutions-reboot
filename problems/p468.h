#pragma once
#include <regex>
#include <string>

namespace p468
{
    class Solution
    {
      public:
        std::string validIPAddress(std::string IP)
        {
            std::string ipv4_number("(([1-9][0-9]{0,3})|0)");
            std::regex ipv4(ipv4_number + "\\." + ipv4_number + "\\." + ipv4_number + "\\." + ipv4_number);

            std::string ipv6_number("([0-9a-fA-F]{1,4})");
            std::regex ipv6(ipv6_number + "\\:" + ipv6_number + "\\:" + ipv6_number + "\\:" + ipv6_number + "\\:" + ipv6_number +
                            "\\:" + ipv6_number + "\\:" + ipv6_number + "\\:" + ipv6_number);

            if (std::regex_match(IP, ipv6))
                return "IPv6";

            std::smatch base_match_ipv4;
            if (!std::regex_match(IP, base_match_ipv4, ipv4))
                return "Neither";

            for (size_t i = 1; i <= 4; ++i)
            {
                std::string n = base_match_ipv4[2 * i - 1].str();

                try
                {
                    int nn = std::stoi(n);
                    if (nn < 0 || nn > 255)
                        return "Neither";
                }
                catch (std::invalid_argument&)
                {
                    return "Neither";
                }
                catch (std::out_of_range&)
                {
                    return "Neither";
                }
            }

            return "IPv4";
        }
    };
}
