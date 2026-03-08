#include <fcntl.h>
#include <print>
#include <sched.h>
#include <sys/time.h>
#include <unistd.h>

int main()
{
    struct timeval tv1, tv2;

    // measure cost of a system call
    // time of a 0-byte read in microseconds
    gettimeofday(&tv1, nullptr);
    for (int i{ 0 }; i < 100000; i++)
    {
        read(0, nullptr, 0);
    }
    gettimeofday(&tv2, nullptr);

    long delta_us = (tv2.tv_sec - tv1.tv_sec) * 1'000'000L + (tv2.tv_usec - tv1.tv_usec);
    std::println("{} us / read", static_cast<double>(delta_us) / 100'000);

    struct timeval tv;
    struct timezone tz;

    // average time gap between gettimeofday() calls in microseconds
    long prev_us{ 0 };
    long timeGapAcc{ 0 };
    for (int i{}; i < 100000; i++)
    {
        gettimeofday(&tv, &tz);
        long time_us { tv.tv_sec * 1'000'000 + tv.tv_usec };
        if (i > 0)
        {
            timeGapAcc += time_us - prev_us;
        }
        prev_us = time_us;
    }
    std::println("Average time gap between gettimeofday() calls: {} us", static_cast<double>(timeGapAcc) / 100000);

    return 0;
}
