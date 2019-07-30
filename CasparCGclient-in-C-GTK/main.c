#include <stdio.h>
#include <stdlib.h>
#include "telnet-client.h"
#include <string.h>

typedef struct command
{
    char channellayer[5];
    char command[10];
    char extraparams[20];
};

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
    char option = '0';
    do
    {
        printf("CasparCG client in C and libtelnet!\n1 - Enter hostname for Telnet connection\n");
        printf("2 - Create file with preset commands\ne - Exit\n");
        printf("->");
        scanf("%c", &option);
        switch (option)
        {
            case '1':
            {
                printf("Hostname:");
                scanf("%s", hostname);
                printf("%s\n", *(ipport+1));
                telnet_client(3, ipport, procesador_implementado);
            }
            case '2':
            {

            }
            case 'e':
            {
                return 0;
            }
        }
    }while (option != 'e');






    //telnet_client(int argc, char **argv, procesador_implementado)
    return 0;


}


int procesador_implementado (char *buffer)
{
    system("clear");
    char *tmpmedianame;
    char *commandtmp;
    commandtmp = (char*)malloc(50 * sizeof(char));
    tmpmedianame = (char*)malloc(50 * sizeof(char));
    char option;

    do
    {
        printf("Select command\r\n1 - play \r\n2 - stop \r\n3 - pause\r\n4 - resume\r\n");
        printf("5 - move layer\r\n6 - resize layer\r\n7- send commands from file\r\n");
        printf("8 - get media list\r\n9 - set logo\r\nc - clear channel 1\r\ne - exit \r\n");
        fflush(stdin);
        //scanf("%c", &option);
        option = getchar();
        switch (option)
        {
        case '1'://play a file
            {
                printf("Enter name of media file\r\n");
                scanf("%s", tmpmedianame);
                strcpy(commandtmp, "play 1-1 ");
                strcat(commandtmp, tmpmedianame);
                strcat(commandtmp, "\r\n");
                strcpy(buffer, commandtmp);
                printf("sent play command\r\n");
                return strlen(buffer);
            }
        case '2'://stop media on layer
            {
                strcpy(buffer, "stop 1-1\r\n");
                printf("sent stop command\r\n");
                return strlen(buffer);
            }
        case '3':
            {
                strcpy(buffer, "pause 1-1\r\n");
                printf("sent pause command\r\n");
                return strlen(buffer);
            }
        case '4':
            {
                strcpy(buffer, "resume 1-1\r\n");
                printf("sent resume command\r\n");
                return strlen(buffer);
            }
        case '5'://move on layer
            {

                printf("Enter name of logo media file\r\n");
                scanf("%s", tmpmedianame);
                strcpy(commandtmp, "play 1-2 ");
                strcat(commandtmp, tmpmedianame);
                strcat(commandtmp, "\r\n");
                strcpy(buffer, commandtmp);
                printf("sent play command (logo)\r\n");
                return strlen(buffer);

            }
        case '6'://resize layer
            {
                printf("Enter name of logo media file\r\n");
                scanf("%s", tmpmedianame);
                strcpy(commandtmp, "play 1-2 ");
                strcat(commandtmp, tmpmedianame);
                strcat(commandtmp, "\r\n");
                strcpy(buffer, commandtmp);
                printf("sent play command (logo)\r\n");
                return strlen(buffer);

            }
        case '7' ://read from file
            {
                strcpy(buffer, "stop 1-1\r\n");
                printf("sent stop command\r\n");
                return strlen(buffer);
            }
        case '8'://get media file list
            {
                strcpy(buffer, "cls\r\n");
                printf("get media file list\r\n");
                return strlen(buffer);
            }
        case '9'://set logo
            {
                printf("Enter name of logo media file\r\n");
                scanf("%s", tmpmedianame);
                strcpy(commandtmp, "play 1-2 ");
                strcat(commandtmp, tmpmedianame);
                strcat(commandtmp, "\r\n");
                strcpy(buffer, commandtmp);
                printf("sent play command (logo)\r\n");
                return strlen(buffer);
            }
        case 'c':
            {
                strcpy(buffer, "clear 1\r\n");
                printf("cleared all media from channel 1\r\n");
                return strlen(buffer);
            }
        case 'e':
            {
                strcpy(buffer, "bye\r\n");
                return strlen(buffer);
            }
        }
    }
    while (option >= 'e');
    option = 0;
    return 0;
}
/*
void readCommandsFromFile(char * filename)
{
    FILE *commandList;
    commandList = fopen(filename, "rb");
    if (commandList == NULL)
    {
        printf("Error while opening file");
        return;
    }

    return;
}*/
/*

void getCharStringOnPointer(char *p)
{
    int i = 0;
    int c;
    while ((c = getchar() )!= '\n')
    {
        *(p+i) = c;
        i++;
    }
    *(p+i+1) = '\r';
}*/
