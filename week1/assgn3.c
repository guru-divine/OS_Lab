#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_CHILD 10

int main() {
    int no_child, status, wtime;
    pid_t cpid, mypid, parpid;

    mypid = getpid();
    parpid = getppid();
    printf("Parent: PID = %u, PPID = %u\n", mypid, parpid);

    printf("Number of child proces: "); scanf("%d", &no_child);
    if(no_child<0 || no_child>10) no_child = 5;

    for(int i=0; i<no_child; ++i) {
        cpid = fork();
        if(cpid==0) {
            mypid = getpid();
            parpid = getppid();
            srand(mypid);
            wtime = 1+rand()%5;
            printf("Child = %d, PID = %u, PPID = %u, work time = %d\n", i, mypid, parpid, wtime);
            sleep(wtime);
            printf("Child %d: Work done ...\n", i);
            exit(i);
        }
    }

    for(int i=0; i<no_child; ++i) {
        wait(&status);
        printf("Parent: Child %d terminates..\n", WEXITSTATUS(status));
    }
    printf("Parent terminates..\n");

    exit(0);
}