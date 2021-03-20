#pragma once
#include <random>
#include <vector>

namespace p478
{
    // other ideas:
    // - rejection sampling (gen points in square)
    // - get points in random isosceles triangles with sides radii of the circle. rolling in this kind of triangle is like rolling
    //   in a rhombus and then flipping the point if it is outside of the triangle
    //   when the angle at the center of the circle tends to zero, it is like rolling two times on the radius and summing and then
    //   folding back if we get outside of the cirle. brilliant !
    class Solution
    {
      public:
        Solution(double radius, double x_center, double y_center)
        {
            // to get a closed interval for the radius
            auto next_after_1 = std::nextafter(1, std::numeric_limits<double>::max());
            _radGen = std::uniform_real_distribution<double>(0, next_after_1);

            _angGen = std::uniform_real_distribution<double>(0, pi() / 2);
            _quadGen = std::uniform_int_distribution<int>(0, 3);

            std::random_device rd;
            _re = std::mt19937(rd());

            _cx = x_center;
            _cy = y_center;
            _r = radius;
        }

        std::vector<double> randPoint()
        {
            // if we distribute the distance uniformly, we will get a bias towards the center
            // (explanation: e.g. there is 1/2 change that the distance will be less than half the radius,
            //  but the area covered by the circle with half the radius is only 1/4 of the big cirle)
            // so (bit hand wavy) square rooting the thing will "repair" the bias -
            //  it pulls harder towards the edge of the circle
            auto r = sqrt(_radGen(_re)) * _r;
            auto a = _angGen(_re);
            auto q = _quadGen(_re);

            auto x = r * std::cos(a);
            auto y = r * std::sin(a);

            if (q & 1)
                x = -x;
            if (q & 2)
                y = -y;

            return {x + _cx, y + _cy};
        }

        constexpr double pi()
        {
            return std::atan(1) * 4;
        }

      private:
        std::mt19937 _re;
        std::uniform_real_distribution<double> _radGen;
        std::uniform_real_distribution<double> _angGen;
        std::uniform_int_distribution<int> _quadGen;
        double _cx = 0;
        double _cy = 0;
        double _r = 0;
    };

    /**
     * Your Solution object will be instantiated and called as such:
     * Solution* obj = new Solution(radius, x_center, y_center);
     * vector<double> param_1 = obj->randPoint();
     */
}
