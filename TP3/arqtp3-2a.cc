#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NumberOfThreads 2
#define CantidadInicialHamburguesas 20

int cantidadRestanteHamburguesas = CantidadInicialHamburguesas
int turno = 0;  
void *comerHamburguesa(void *tid)
{ 
    while (1 == 1)
    {
        while (turno != (int)tid);

        if (cantidadRestanteHamburguesas > 0)
        {
            printf ("Hola soy el hilo(comensal), me voy a comer una hamburguesa! todavia quedan /n", (int)tid, cantidadRestanteHamburguesas);
            cantidadRestanteHamburguesas--; 
        }
        else
        {
            printf("se terminaron las hamburguesas /n");
            turno= (turno + 1) NumberOfThreads
            pthread_exit(NULL);
        }
        truno = (truno + 1) NumberOfThreads;
    }

}

int main (int argc, char *argv[])

    pthread_t threads[NumberOfThreads];
    int status, i, ret;

    for (int i = 0; i < NumberOfThreads; i++)
    {
        printf("hola, soy hilo principal. Estoy creando el hilo /n", i);
        status = pthread_create(&threads[i], NULL, comerHamburguesa, (void *)i);
        if (status !=0)
        {
            printf ("algo salio mal, al crear el hilo me dio error /n", status);
            exit(-1);
        }
    }

    for (i = 0, i < NumberOfThreads; i++)
    {
        void *retval;
        ret = pthread_join(threads[i],&retval);
    }

    pthread_exit(NULL); //termina el programa