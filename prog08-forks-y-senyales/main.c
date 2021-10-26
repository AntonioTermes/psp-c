#include <unistd.h> //
#include <sys/types.h> //pid_t
#include <sys/wait.h> //wait y waitpid
#include <signal.h> //signal y codigos
#include <stdio.h> //printf
#include <stdlib.h> //exit

//declaramos el manejador de la señal
void manejadorHijo(int num_senyal);
void manejadorPadre(int num_senyal);

int main(int argc, char const *argv[])
{
    pid_t pid = fork();
    if (pid == -1) { //gestionamos un posible error

        perror("Error en el fork");
        exit(1);

    }
    if (pid == 0) { //hijo

        signal(SIGUSR1, manejadorHijo);
        printf("[Proceso: %d]: Manejador activado.\n", getpid());
        pause();

    } else { //padre

        signal(SIGUSR1, manejadorPadre);
        printf("[Proceso: %d]: Manejador activado.\n", getpid());
        pause();
        pid_t pid_hijo = wait(NULL);

    }

    return 0;

}

void manejadorHijo(int num_senyal){

    printf("Soy el manejador de la señal del hijo.\n");

}

void manejadorPadre(int num_senyal){

    printf("Soy el manejador de la señal del padre.\n");

}