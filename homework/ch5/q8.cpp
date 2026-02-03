#include <fcntl.h>
#include <print>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int pip[2];
    int pipeRes = pipe(pip);
    if (pipeRes < 0)
    {
        std::println("pipe failed");
        exit(1);
    }

    // first child process
    int rc1 = fork();
    if (rc1 < 0)
    {
        std::println("fork failed");
        exit(1);
    }
    else if (rc1 == 0)
    {
        std::println("child (pid:{0})", static_cast<int>(getpid()));
        write(pip[1], "hello", 5);
        exit(0);
    }

    // second child process
    int rc2 = fork();
    if (rc2 < 0)
    {
        std::println("fork failed");
        exit(1);
    }
    else if (rc2 == 0)
    {
        std::println("child (pid:{0})", static_cast<int>(getpid()));
        char buf[6]{ 0 };
        read(pip[0], buf, 5);
        std::println("message from child 1: {}", buf);
        exit(0);
    }

    // parent process
    else
    {
        int rc1_wait = waitpid(rc1, nullptr, 0);
        int rc2_wait = waitpid(rc2, nullptr, 0);
        std::println("parent of {0} and {5} (rc1_wait: {1}) (rc2_wait: {2}) (pid:{3}): {4}", rc1, rc1_wait, rc2_wait,
                     static_cast<int>(getpid()), "goodbye", rc2);
    }

    return 0;
}
