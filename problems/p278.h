#pragma once

namespace p278
{
    class Solution
    {
      public:
        int firstBadVersion(int n)
        {
            if (isBadVersion(1))
                return 1;

            return bsearch(1, n);
        }

        int bsearch(int start, int end)
        {
            if (start + 1 >= end)
                return isBadVersion(start) ? start : end;

            auto p = int((size_t(start) + end) / 2);

            if (isBadVersion(p))
                return bsearch(start, p);
            return bsearch(p, end);
        }

        void set_bad_version(int version)
        {
            _first_bad = version;
        }

        bool isBadVersion(int version)
        {
            return version >= _first_bad;
        }

      private:
        int _first_bad = 0;
    };

}