#pragma once
#include <algorithm>
#include <vector>
namespace p1564
{
    class Solution2
    {
      public:
        int maxBoxesInWarehouse(std::vector<int>& boxes, std::vector<int>& warehouse)
        {
            std::sort(boxes.begin(), boxes.end());

            auto W = warehouse.size();
            auto B = boxes.size();

            int ceiling = warehouse[0];
            for (size_t i = 1; i < W; ++i)
            {
                warehouse[i] = std::min(warehouse[i], ceiling);
                ceiling = warehouse[i];
            }

            size_t curr_box_i = 0;
            size_t curr_room = W;

            int added_boxes = 0;

            while (curr_room > 0 && added_boxes < B)
            {
                if (warehouse[curr_room - 1] >= boxes[curr_box_i])
                {
                    ++curr_box_i;
                    --curr_room;
                    ++added_boxes;
                }
                else
                {
                    --curr_room;
                }
            }

            return added_boxes;
        }
    };

    class Solution
    {
      public:
        /*
        For each position, we discard boxes that are too tall to fit in the current warehouse room,
        because they won't fit in any rooms further to the right.
        We put the tallest possible box that can fit in this room,
        and save the remaining boxes for warehouse rooms further to the right.
        */
        int maxBoxesInWarehouse(std::vector<int>& boxes, std::vector<int>& warehouse)
        {
            std::sort(boxes.begin(), boxes.end());
            auto i = boxes.size();
            int count = 0;
            for (int room : warehouse)
            {
                // Iterate through boxes from largest to smallest
                // Discard boxes that doesn't fit in the current warehouse
                while (i > 0 && boxes[i - 1] > room)
                    --i;

                if (i == 0)
                    return count;
                ++count;
                --i;
            }

            return count;
        }
    };
}
