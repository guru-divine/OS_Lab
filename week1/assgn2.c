#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    pid_t pid1, pid2;
    int x = 10, status;
    printf("Value of x before fork: %d\n", x);
    if((pid1=fork())==0) {    // first child
        for(int i=0; i<5; ++i) {
            printf("\tAt first child: x = %d\n", x);
            x = x+10;
            sleep(1);
        }
    } else {    // parent
        if((pid2=fork())==0) {  // second child
            for(int i=0; i<5; ++i) {
                printf("\t\tAt second child: x = %d\n", x);
                x = x-1;
                sleep(1);
            }
        } else {                // parent process
            for(int i=0; i<5; ++i) {
                printf("At Parent: x = %d\n", x);
                x = x+20;
                sleep(1);
            }
            waitpid(pid1, &status, 0);
            waitpid(pid2, &status, 0);
        }
    }
    exit(0);
}