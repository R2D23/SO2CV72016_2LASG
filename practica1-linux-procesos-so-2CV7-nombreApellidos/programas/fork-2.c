#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {

    pid_t hijo;
    char *mensaje;
    int n;

    hijo = fork();

    switch (hijo) {

        case -1:
            perror("Error en fork \n");
		break;

        case 0:
            mensaje = "Soy el hijo";
            n = 5;
        break;

        default:
            mensaje = "Soy el padre";
            n = 3;
        break;
    }

    for(; n > 0; n--) {
        puts(mensaje);
    }

    return (0);

}
