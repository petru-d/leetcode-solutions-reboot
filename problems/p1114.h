#pragma once

#include <condition_variable>
#include <functional>

namespace p1114
{
    class Foo
    {
      public:
        Foo()
        {
        }

        std::condition_variable cv;
        std::mutex cv_m;

        bool first_done = false;
        bool second_done = false;

        void first(std::function<void()> printFirst)
        {
            std::lock_guard<std::mutex> lk(cv_m);

            // printFirst() outputs "first". Do not change or remove this line.
            printFirst();

            first_done = true;
            cv.notify_all();
        }

        void second(std::function<void()> printSecond)
        {
            std::unique_lock<std::mutex> lk(cv_m);
            cv.wait(lk, [this] { return first_done; });

            // printSecond() outputs "second". Do not change or remove this line.
            printSecond();

            second_done = true;
            cv.notify_all();
        }

        void third(std::function<void()> printThird)
        {
            std::unique_lock<std::mutex> lk(cv_m);
            cv.wait(lk, [this] { return second_done; });

            // printThird() outputs "third". Do not change or remove this line.
            printThird();
        }
    };
}