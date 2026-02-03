#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <print>

int main() {
    int rc = fork();

    if (rc < 0)
    {
        std::println("fork failed");
        exit(1);
    }
    else if (rc == 0)
    {
        int rc_wait = wait(nullptr);
        std::println("child (pid:{0}) (rc_wait: {1}): {2}", static_cast<int>(getpid()), rc_wait, "hello");
    }
    else
    {
        int rc_wait = wait(nullptr);
        std::println("parent of {0} (rc_wait: {1}) (pid:{2}): {3}", rc, rc_wait, static_cast<int>(getpid()), "goodbye");
    }
    
    return 0;
}
