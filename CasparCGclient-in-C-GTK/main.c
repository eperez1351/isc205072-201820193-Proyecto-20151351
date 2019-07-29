#include <stdio.h>
#include <stdlib.h>
#include "telnet-client.h"
#include <string.h>

void getHostname_terminal(char *hostname);
void procesador_implementado (char * buffer);

/*
void procesador_implementado (char * buffer){
//Aqui hago lo que tenga que hacer con el buffer
}
*/

int main()
{
    char **ipport;
    ipport = malloc(5 * sizeof(*ipport));
    *ipport = malloc(50 * sizeof(**ipport));
    char *hostname;
    hostname = (char*)malloc(50 * sizeof(char));
    *(ipport+1) = hostname;
    *(ipport+2) = "5250";
    printf("Hello world!\nEnter hostname for Telnet connection\n");
    printf("->");
    scanf("%s", hostname);
    printf("%s\n", *(ipport+1));
    //telnet_client(3, ipport);
    //telnet_client(int argc, char **argv, procesador_implementado)
    return 0;


}


void procesador_implementado (char * buffer)
{
    int option=0;
    do
    {
        printf("Select command\n1 - play \n2 - stop \n5 - exit \n");
        scanf("%d", &option);
        //strcpy(buffer, "play 1-1 amb\r\n");
        switch (option)
        {
        case 1:
            {
                strcpy(buffer, "play 1-1 amb\r\n");
            }
        //case 2:
         //   {

         //   }
        }
    }
    while (option != 5);
    return;
}

//void copyCharByChar(char *string1, char *string2)
