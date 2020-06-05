#pragma once

#include <condition_variable>
#include <functional>

namespace p1117
{
    class H2O
    {
      public:
        H2O()
        {
        }

        std::mutex _mux;
        std::condition_variable _cv;

        struct molecule
        {
            size_t O = 0;
            size_t H = 0;
            bool empty() const
            {
                return O == 0 && H == 0;
            }
            bool full() const
            {
                return O == 1 && H == 2;
            }
            void clear()
            {
                O = 0;
                H = 0;
            }
        };
        molecule _mol = {};

        void hydrogen(std::function<void()> releaseHydrogen)
        {
            std::unique_lock<std::mutex> lk(_mux);
            _cv.wait(lk, [this] { return _mol.empty() || _mol.H < 2; });

            ++_mol.H;

            // releaseHydrogen() outputs "H". Do not change or remove this line.
            releaseHydrogen();

            if (_mol.full())
                _mol.clear();

            _cv.notify_all();
        }

        void oxygen(std::function<void()> releaseOxygen)
        {
            std::unique_lock<std::mutex> lk(_mux);
            _cv.wait(lk, [this] { return _mol.empty() || _mol.O < 1; });

            ++_mol.O;

            // releaseOxygen() outputs "O". Do not change or remove this line.
            releaseOxygen();

            if (_mol.full())
                _mol.clear();

            _cv.notify_all();
        }
    };
}