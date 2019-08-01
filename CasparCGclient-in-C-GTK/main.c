#include <stdio.h>
#include <stdlib.h>
#include "telnet-client.h"
#include <string.h>
#include "otherfunctions.h"


int main()
{
    char **ipport;
    ipport = malloc(5 * sizeof(*ipport));
    *ipport = malloc(50 * sizeof(**ipport));
    char *hostname;
    hostname = (char*)malloc(50 * sizeof(char));
    *(ipport+1) = hostname;
    *(ipport+2) = "5250";
    char option;
    do
    {
        printf("CasparCG client in C and libtelnet!\n1 - Enter hostname for Telnet connection\n");//menu principal
        printf("2 - Create file with preset commands\ne - Exit\n");
        printf("->");
        fflush(stdin);
        option = getchar();
        switch (option)
        {
            case '1':
            {
                printf("Hostname:");
                scanf("%s", hostname);//recibe el nombre de host. el puerto es el de por defecto de CasparCG
                telnet_client(3, ipport, procesador_implementado); //carga los argumentos recolectados del doble puntero y corre la funcion con estos argumentos. tambien, pasa un puntero a funcion para controlar los comandos a enviar
                return 0;
            }
            case '2':
            {
                printf("Enter name of command file:");//recibe el nombre del archivo donde se almacenarán los comandos
                scanf("%s", hostname);
                writeCommandsToFile(hostname);//llama la funcion con el nombre de archivo

                break;
            }
            case 'e':
            {
                return 0;
            }
        }
    }while (option != 'e');
    return 0;


}

