#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void gestionar_interrupcion(int senyal){

    printf("Recibida la señal número %d\n", senyal);

}

int main(int argc, char const *argv[]){

    signal(SIGINT, gestionar_interrupcion);
    printf("Hola mundo\n");
    sleep(20);
    printf("Hola mundo 2\n");
    return 0;

}