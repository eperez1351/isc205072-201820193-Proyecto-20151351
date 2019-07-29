#include <stdio.h>
#include <stdlib.h>
#include "telnet-client.h"
#include <string.h>

void getHostname_terminal(char *hostname);
int procesador_implementado (char * buffer);

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
    telnet_client(3, ipport, procesador_implementado);
    //telnet_client(int argc, char **argv, procesador_implementado)
    return 0;


}


int procesador_implementado (char * buffer)
{
    system("clear");
    int option=0;
    do
    {
        printf("Select command\r\n1 - play \r\n2 - stop \r\n5 - exit \r\n");
        scanf("%d", &option);
        //strcpy(buffer, "play 1-1 amb\r\n");
        switch (option)
        {
        case 1:
            {
                strcpy(buffer, "play 1-1 amb\r\n");
                printf("sent play command\n");
                return strlen(buffer);
            }
        //case 2:
         //   {

         //   }
        case 5:
            {
                strcpy(buffer, "bye\r\n");
                return strlen(buffer);
            }
        }
    }
    while (option >= 5);
    option =0;
    return 0;
}

//void copyCharByChar(char *string1, char *string2)
