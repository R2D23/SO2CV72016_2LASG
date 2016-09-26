#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {

	pid_t hijo;

	hijo = fork();

	switch (hijo) {

		case -1:

			perror("Error en fork \n");

		break;

		case 0:

			printf("Soy el proceso hijo, mi PID es: %d \n", getpid());

		break;

		default:

			printf("Soy el proceso padre, mi PID es: %d \n", getpid());
			printf("El PID de mi hijo es: %d \n", hijo);

		break;

	}

	return (0);

}
