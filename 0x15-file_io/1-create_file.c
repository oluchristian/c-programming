#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t parent_pid;
    pid_t shell_pid;

    parent_pid = getppid();
    shell_pid = getpid();

    printf("PID of Parent Process: %d\n", parent_pid);
    printf("PID of Current Shell (echo $$): %d\n", shell_pid);

    if (parent_pid == shell_pid) {
        printf("The PID of the parent process and the current shell are the same.\n");
    } else {
        printf("The PID of the parent process and the current shell are different.\n");
    }

    return 0;
}
