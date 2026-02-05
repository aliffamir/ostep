#include <fcntl.h>
#include <print>
#include <sched.h>
#include <sys/time.h>
#include <unistd.h>

int main()
{
    struct timeval tv;
    struct timezone tz;

    for (int i{}; i < 10; i++)
    {
        gettimeofday(&tv, &tz);

        std::println("Seconds since 1/1/1970: {}", tv.tv_sec);
        std::println("Microseconds: {}", tv.tv_usec);
        std::println("Minutes west of Greenwich: {}", tz.tz_minuteswest);
        std::println("Daylight Saving Time adjustment: {}", tz.tz_dsttime);

        std::println("");
    }

    int pip[2];
    if (pipe(pip) < 0)
    {
        std::println("pipe failed");
        exit(1);
    }

    // child 1
    int rc1 = fork();
    if (rc1 < 0)
    {
        std::println("child 1 fork failed");
        exit(1);
    }
    else if (rc1 == 0)
    {
        std::print("child 1 w/ pid {}", getpid());
        write(pip[1], "writing", 7);
    }

    // child 2
    int rc2 = fork();
    if (rc2 < 0)
    {
        std::println("child 2 fork failed");
        exit(1);
    }
    else if (rc2 == 0)
    {
        std::println("child 2 w/ pid {}", getpid());
    }
    else // parent
    {
        int rcWait1 = waitpid(rc1, nullptr, 0);
        int rcWait2 = waitpid(rc2, nullptr, 0);
        std::println("parent pid {}", getpid());
    }

    return 0;
}
