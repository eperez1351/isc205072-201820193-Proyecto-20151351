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
        printf("CasparCG client in C and libtelnet!\n1 - Enter hostname for Telnet connection\n");
        printf("2 - Create file with preset commands\ne - Exit\n");
        printf("->");
        fflush(stdin);
        option = getchar();
        switch (option)
        {
            case '1':
            {
                printf("Hostname:");
                scanf("%s", hostname);
                printf("%s\n", *(ipport+1));
                telnet_client(3, ipport, procesador_implementado);
                return 0;
            }
            case '2':
            {
                printf("Enter name of command file:");
                scanf("%s", hostname);
                writeCommandsToFile(hostname);

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

