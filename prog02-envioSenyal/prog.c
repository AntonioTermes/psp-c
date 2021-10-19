#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char const *argv[]){

    pid_t pid = atoi(argv[1]);
    printf("%d",pid);
    kill(pid,SIGINT);
    return 0;

}