#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int a = 3;
    pid_t pid = fork();
    if(pid == 0){ //Proceso hijo

        printf("[Hijo] Mi PID es: %d\n\tVariable a: %d\n", getpid(), a);
        printf("[Hijo]El PID de mi padre es %d\n", getppid());
        sleep(1);

    } else {//Proceso Padre
        
        int estado_hijo = -4;
        printf("[Padre]Mi PID es: %d\n\tVariable a: %d\n", getpid(), a);
        printf("[Padre]El PID de mi padre es %d\n", getppid());
        printf("[Padre]El hijo %d ha terminado\n", wait(&estado_hijo));
        printf("[Padre] El estado de fnalización ha sido: %d\n", estado_hijo);

    }

    //Parte común a ambos procesos
    return 1;

}
