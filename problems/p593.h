#pragma once
#include <vector>

namespace p593
{
    class Solution
    {
      public:
        bool validSquare(std::vector<int>& p1, std::vector<int>& p2, std::vector<int>& p3, std::vector<int>& p4)
        {
            return validSquareSide(p1[0], p1[1], p2[0], p2[1], p3[0], p3[1], p4[0], p4[1]) ||
                   validSquareSide(p1[0], p1[1], p3[0], p3[1], p2[0], p2[1], p4[0], p4[1]);
        }

        // test if we have a square with AB as a side and CD the other points
        bool validSquareSide(int Ax, int Ay, int Bx, int By, int Cx, int Cy, int Dx, int Dy)
        {
            auto dX = Bx - Ax;
            auto dY = By - Ay;

            if (dX == 0 && dY == 0)
                return false;

            auto X0x = Ax - dY;
            auto X0y = Ay + dX;
            auto X2x = Bx - dY;
            auto X2y = By + dX;

            if (Cx == X0x && Cy == X0y && Dx == X2x && Dy == X2y)
                return true;
            if (Dx == X0x && Dy == X0y && Cx == X2x && Cy == X2y)
                return true;

            auto X1x = Ax + dY;
            auto X1y = Ay - dX;
            auto X3x = Bx + dY;
            auto X3y = By - dX;

            if (Cx == X1x && Cy == X1y && Dx == X3x && Dy == X3y)
                return true;
            if (Dx == X1x && Dy == X1y && Cx == X3x && Cy == X3y)
                return true;

            return false;
        }
    };
}
