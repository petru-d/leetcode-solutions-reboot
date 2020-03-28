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

            size_t current_merged = nums1.size() - 1;
            size_t current_1 = static_cast<size_t>(m) - 1;
            size_t current_2 = static_cast<size_t>(n) - 1;
            while (current_merged >= 0)
            {
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