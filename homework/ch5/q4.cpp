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
        std::println("child (pid:{0}): {1}", static_cast<int>(getpid()), "hello");
        char* args[3];
        args[0] = strdup("/bin/ls");
        // args[1] = strdup("ls");
        args[1] = nullptr;
        args[2] =  nullptr;
        execv(args[0], args);
    }
    else
    {
        int rc_wait = wait(nullptr);
        std::println("parent of {0} (pid:{1}): {2}", rc, static_cast<int>(getpid()), "goodbye");
    }
    
    return 0;
}
