#include <unistd.h>
#include <fcntl.h>
#include <print>

int main() {
    int fd { open("text.txt", O_RDWR) };

    int rc = fork();

    if (rc < 0)
    {
        std::println("fork failed");
        exit(1);
    }
    else if (rc == 0)
    {
        std::println("child (pid:{0}): fd = {1}", static_cast<int>(getpid()), fd);
    }
    else
    {
        int rc_wait = wait(nullptr);
        std::println("parent of {0} (rc_wait:{1}) (pid:{2}): fd = {3}", rc, rc_wait, static_cast<int>(getpid()), fd);
    }
    
    close(fd);
    return 0;
}
