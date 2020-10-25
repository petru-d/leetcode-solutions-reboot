#pragma once
#include <optional>
#include <vector>

namespace p1007
{
    class Solution
    {
      public:
        int minDominoRotations(std::vector<int>& A, std::vector<int>& B)
        {
            auto L = A.size();
            if (L <= 1)
                return 0;

            struct Choice
            {
                std::pair<int, int> First = {};
                std::pair<int, int> Second = {};

                bool FirstOk = false;
                bool SecondOk = false;

                Choice(const std::pair<int, int> piece)
                {
                    First = {piece.first, 0};
                    if (piece.first != piece.second)
                    {
                        Second = {piece.second, 1};
                    }
                    FirstOk = SecondOk = true;
                }

                bool Good() const
                {
                    return FirstOk || SecondOk;
                }

                void Add(const std::pair<int, int> piece)
                {
                    auto to_choice = [](bool& ok, auto& choice, auto piece) {
                        if (!ok)
                            return;
                        if (piece.first == choice.first)
                            ;
                        else if (piece.second == choice.first)
                            ++choice.second;
                        else
                            ok = false;
                    };
                    to_choice(FirstOk, First, piece);
                    to_choice(SecondOk, Second, piece);
                }
                int GetBest() const
                {
                    if (!Good())
                        return -1;

                    int result = std::numeric_limits<int>::max();
                    if (FirstOk)
                        result = First.second;
                    if (SecondOk)
                        result = std::min(result, Second.second);

                    return result;
                }
            };

            Choice ca({A[0], B[0]});
            Choice cb({B[0], A[0]});

            for (size_t i = 1; i < L; ++i)
            {
                if (ca.Good())
                    ca.Add({A[i], B[i]});
                if (cb.Good())
                    cb.Add({B[i], A[i]});
                if (!ca.Good() && !cb.Good())
                    return -1;
            }

            int result = std::numeric_limits<int>::max();
            if (ca.Good())
                result = ca.GetBest();
            if (cb.Good())
                result = std::min(result, cb.GetBest());

            return result;
        }
    };
}
