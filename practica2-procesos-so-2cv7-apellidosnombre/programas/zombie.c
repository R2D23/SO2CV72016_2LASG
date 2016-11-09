#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main () {

	pid_t hijo;

	hijo = fork ();

	switch (hijo) {

		case -1 :
			perror("Error en fork");
		break;

		case 0 :
			return (0);
		break;

		default :
        sleep (60);
    break;

  }

  return 0;

}
