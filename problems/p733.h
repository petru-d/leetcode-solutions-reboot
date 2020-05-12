#pragma once
#include <vector>
namespace p733
{
    class Solution
    {
      public:
        std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor)
        {
            int oldColor = image[sr][sc];
            if (oldColor != newColor)
                flood(image, sr, sc, image[sr][sc], newColor);

            return image;
        }

      private:
        void flood(std::vector<std::vector<int>>& image, int sr, int sc, int oldColor, int newColor)
        {
            image[sr][sc] = newColor;
            if (sr > 0 && image[sr - 1][sc] == oldColor)
                flood(image, sr - 1, sc, oldColor, newColor);
            if (sr < image.size() - 1 && image[sr + 1][sc] == oldColor)
                flood(image, sr + 1, sc, oldColor, newColor);
            if (sc > 0 && image[sr][sc - 1] == oldColor)
                flood(image, sr, sc - 1, oldColor, newColor);
            if (sc < image[0].size() - 1 && image[sr][sc + 1] == oldColor)
                flood(image, sr, sc + 1, oldColor, newColor);
        }
    };
}