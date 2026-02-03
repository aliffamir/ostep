#include <print>
#include <unistd.h>

int main()
{
    int x{ 100 };

    int rc = fork();

    if (rc < 0)
    {
        std::println("fork failed");
        exit(1);
    }
    else if (rc == 0)
    {
        std::println("child (pid:{0}): int = {1}", static_cast<int>(getpid()), x);
    }
    else
    {
        int rc_wait = wait(nullptr);
        std::println("parent of {0} (rc_wait:{1}) (pid:{2}): int = {3}", rc, rc_wait, static_cast<int>(getpid()), x);
    }

    return 0;
}
