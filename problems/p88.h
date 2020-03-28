#include <algorithm>
#include <vector>

using namespace std;

namespace p88
{
    class Solution
    {
      public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
        {
            // merge in place in nums1, working backwards

            int current_merged = m + n - 1;
            int current_1 = m - 1;
            int current_2 = n - 1;
            while (true)
            {
                // if stuff from nums1 is finished, just copy what's not merged yet from nums2 into the start of nums1
                if (current_1 == -1)
                {
                    std::copy(nums2.begin(), nums2.begin() + current_2 + 1, nums1.begin());
                    break;
                }

                // if stuff from nums2 is finished, just exit
                if (current_2 == -1)
                {
                    break;
                }

                if (nums1[current_1] < nums2[current_2])
                {
                    nums1[current_merged] = nums2[current_2];
                    --current_2;
                }
                else
                {
                    nums1[current_merged] = nums1[current_1];
                    --current_1;
                }
                --current_merged;
            }
        }
    };
}