#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main() {
    int n, mypid, parpid;
    printf("Enter the value of n: "); scanf("%d", &n);

    if(fork()) {
        mypid = getpid();
        parpid = getppid();
        printf("Parent: %u, PPID: %u\n", mypid, parpid);
    } else {
        mypid = getpid();
        parpid = getppid();
        printf("Child: %u, PPID: %u\n", mypid, parpid);
        n = n*n;
    }

    printf("Process PID: %u, n = %d\n", mypid, n);
}