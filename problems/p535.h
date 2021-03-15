#pragma once
#include <charconv>
#include <string>
#include <unordered_map>
#include <vector>

namespace p535
{
    class Solution
    {
      public:
        // Encodes a URL to a shortened URL.
        std::string encode(std::string longUrl)
        {
            auto h = std::hash<std::string>{}(longUrl);

            auto pos = longUrls.find(h);
            if (pos == longUrls.end())
                pos = longUrls.insert({h, std::vector<std::string>{std::move(longUrl)}}).first;
            else
                pos->second.push_back(std::move(longUrl));

            return std::to_string(h) + "_" + std::to_string(pos->second.size() - 1);
        }

        // Decodes a shortened URL to its original URL.
        std::string decode(std::string shortUrl)
        {
            auto pos = shortUrl.find('_');

            size_t h = 0;
            std::from_chars(shortUrl.data(), shortUrl.data() + pos, h);

            size_t collide = 0;
            std::from_chars(shortUrl.data() + pos + 1, shortUrl.data() + shortUrl.size(), collide);

            return longUrls[h][collide];
        }

        std::unordered_map<size_t, std::vector<std::string>> longUrls;
    };
}
