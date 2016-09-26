#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main () {

	pid_t hijo;

	hijo = fork ();

	switch (hijo) {

		case -1 :

			perror("Error al crear el proceso con fork");

		break;

		case 0 :

			printf ("Proceso hijo, mi PID es %d\n", getpid());
			execlp("ls","ls","-l",NULL);

		break;

		default :

    		printf ("Proceso padre, PID: %d \n", getpid());
    		printf ("El PID de mi hijo es %d \n", hijo);

		break;

	}

	return 0;

}
