#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

#define MAX 256

int main () {

	pid_t hijo;
	int tuberiaPaH[2];
	int tuberiaHaP[2];

	char mensaje[MAX];

	if ( pipe (tuberiaPaH) == -1 || pipe (tuberiaHaP) == -1 ) {

		perror("Error al crear las tuberias con pipe");
		return (-1);

	} else {

		hijo = fork();

		switch (hijo) {

			case -1 :

				perror("Error al crear el proceso hijo con fork");
				return (-1);

			break;

			case 0 :

				while( read (tuberiaPaH[0], mensaje, MAX) > 0 && strcmp (mensaje, "FIN\n") != 0 ) {
					
					printf("\n El proceso hijo recibe el mensaje: %s \n", mensaje);

					strcpy(mensaje,"LEIDO");

					write(tuberiaHaP[1],mensaje,strlen(mensaje)+1);

				}

				close(tuberiaPaH[0]);
				close(tuberiaPaH[1]);
				close(tuberiaHaP[0]);
				close(tuberiaHaP[1]);

				return (0);

			break;

			default :

				while( printf("\n Escriba el mensaje del padre: ") != 0 && fgets (mensaje, sizeof(mensaje),stdin) != NULL && write (tuberiaPaH[1], mensaje, strlen(mensaje) + 1) != 0 && strcmp (mensaje,"FIN\n") != 0 )
					do {
						read(tuberiaHaP[0],mensaje,MAX);
					} while( strcmp(mensaje, "LEIDO") != 0 );

				close(tuberiaPaH[0]);
				close(tuberiaPaH[1]);
				close(tuberiaHaP[0]);
				close(tuberiaHaP[1]);

				return (0);

			break;

		}

	}

	return (0);

}
