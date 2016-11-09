#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<stdlib.h>
#include<stdio.h>

int main () {

	pid_t hijo;
	int valRetorno;

	hijo = fork();

	switch (hijo) {

		case -1:

			perror("Error en la creacion del proceso con fork");
			exit(EXIT_FAILURE);

		break;

		case 0:

			sleep(30);

		break;

		default:

			printf("Se envIa la SeNal SIGCHLD a mi hijo %d \n", hijo);

			valRetorno = kill(hijo,SIGCHLD);

			if (valRetorno < 0)
				perror("Error al enviar la seNal SIGCHLD mediante KILL");
			else
				printf("Mi hijo %d esta vivo \n",hijo);

			printf("Se envIa la seNal SIGTERM a mi hijo %d \n",hijo);

			valRetorno = kill(hijo, SIGTERM);

			if(valRetorno < 0)
				perror("Eroror al enviar la seNal SIGTERM mediante KILL");
			else
				printf("Mi hijo %d ha culminado por medio de la seNal SIGTERM \n",hijo);

		break;

	}

	exit (EXIT_SUCCESS);

}
