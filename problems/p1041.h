#pragma once
#include <string>

namespace p1041
{
    class Solution
    {
      public:
        bool isRobotBounded(std::string instructions)
        {
            enum class FaceDirection
            {
                N,
                E,
                S,
                W
            };
            struct Coords
            {
                int x = 0;
                int y = 0;
            };

            Coords curr = {0, 0};
            FaceDirection face = FaceDirection::N;
            for (auto i : instructions)
            {
                if (i == 'G')
                {
                    if (face == FaceDirection::N)
                        ++curr.y;
                    else if (face == FaceDirection::E)
                        ++curr.x;
                    else if (face == FaceDirection::S)
                        --curr.y;
                    else if (face == FaceDirection::W)
                        --curr.x;
                }
                else if (i == 'L')
                {
                    if (face == FaceDirection::N)
                        face = FaceDirection::W;
                    else if (face == FaceDirection::E)
                        face = FaceDirection::N;
                    else if (face == FaceDirection::S)
                        face = FaceDirection::E;
                    else if (face == FaceDirection::W)
                        face = FaceDirection::S;
                }
                else if (i == 'R')
                {
                    if (face == FaceDirection::N)
                        face = FaceDirection::E;
                    else if (face == FaceDirection::E)
                        face = FaceDirection::S;
                    else if (face == FaceDirection::S)
                        face = FaceDirection::W;
                    else if (face == FaceDirection::W)
                        face = FaceDirection::N;
                }

                // cout << "x:" << curr.x << " y:" << curr.y << " face:" << static_cast<int>(face) << endl;
            }

            // ended up where started. face direction doesn't matter,
            // on running the cycle again we will return again to (0, 0)
            if (curr.x == 0 && curr.y == 0)
                return true;

            // advanced some squares and the face is turned towards N again
            // on running the cycle again, we will advance more, to infinity
            if (face == FaceDirection::N)
                return false;

            // we advanced some, but changed direction
            // on running the cycle 3 more times at most, we will end up at 0,0,N
            return true;
        }
    };
}
