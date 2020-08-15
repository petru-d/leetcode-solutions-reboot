#pragma once
#include <bitset>
#include <string>

namespace p1286
{
    class CombinationIterator
    {
      public:
        CombinationIterator(std::string characters, int combinationLength)
        {
            s = characters;
            K = size_t(combinationLength);
            N = characters.size();

            for (size_t i = 0; i < K; ++i)
                b.set(i);
        }

        std::string next()
        {
            auto res = format_bits();
            advance();
            return res;
        }

        bool hasNext()
        {
            return !end;
        }

      private:
        std::string format_bits()
        {
            std::string result(K, ' ');
            size_t curr = 0;
            for (size_t i = 0; i < N; ++i)
                if (b[i])
                {
                    result[curr] = s[i];
                    ++curr;
                }

            return result;
        }

        void advance()
        {
            if (!b[N - 1])
            {
                auto i = N;
                while (i > 0 && !b[i - 1])
                    --i;
                b.reset(i - 1);
                b.set(i);

                return;
            }

            auto i = N;
            while (i > 0 && b[i - 1])
                --i;
            if (i == N - K)
            {
                end = true;
                return;
            }

            auto j = i;
            while (j > 0 && !b[j - 1])
                --j;

            for (size_t k = i; k < N; ++k)
                b.reset(k);
            b.reset(j - 1);
            for (size_t k = 0; k < N - i + 1; ++k)
                b.set(j + k);
        }

        std::bitset<15> b = {};
        size_t N = size_t(-1);
        size_t K = size_t(-1);
        std::string s;

        bool end = false;
    };
}
