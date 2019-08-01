#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct commandstruct_def
{
    char command[10];
    char channellayer[5];
    char extraparams[50];
}commandstruct;

char* playCommand(char *filename)
{
    char *command;
    command = (char*)malloc(50 * sizeof(char));
    strcat(command,"play 1-1 ");
    strcat(command, filename);
    strcat(command, "\r\n");
    return command;
}

char* stopCommand()
{
    char *command;
    command = (char*)malloc(50 * sizeof(char));
    strcat(command,"stop 1-1");
    strcat(command, "\r\n");
    return command;
}
char* pauseCommand()
{
    char *command;
    command = (char*)malloc(50 * sizeof(char));
    strcat(command,"pause 1-1");
    strcat(command, "\r\n");
    return command;
}
char* resumeCommand()
{
    char *command;
    command = (char*)malloc(50 * sizeof(char));
    strcat(command,"resume 1-1");
    strcat(command, "\r\n");
    return command;
}
char* clearCommand(char* channellayer)
{
    char *command;
    command = (char*)malloc(50 * sizeof(char));
    strcat(command,"clear ");
    strcat(command, channellayer);
    strcat(command, "\r\n");
    return command;
}
char* printCommand(char *channel)
{
    char *command;
    command = (char*)malloc(50 * sizeof(char));
    strcat(command,"print ");
    strcat(command, channel);
    strcat(command, "\r\n");
    return command;
}
char* clsCommand()
{
    char *command;
    command = (char*)malloc(50 * sizeof(char));
    strcat(command,"cls");
    strcat(command, "\r\n");
    return command;
}
char* setLogo(char *filename)
{
    char *command;
    command = (char*)malloc(50 * sizeof(char));
    strcat(command,"play 1-2 ");
    strcat(command, filename);
    strcat(command, "\r\n");
    return command;
}

//las funciones anteriores se encargan de confeccionar los comandos a ser enviados, provisto de los argumentos necesarios

char* readCommandsFromFile(char *filename)//lee comandos desde archivo y los devuelve como texto a un puntero de caracteres
{
    int HowManyCommands;
    char *buffer;
    buffer = (char*)malloc(512 * sizeof(char));
    FILE *commandList;
    commandList = fopen(filename, "rb");
    if (commandList == NULL)
    {
        printf("Error while opening file");
        return "0";
    }
    fread(&HowManyCommands, sizeof(int), 1, commandList);
    commandstruct *commandsfromfile;
    commandsfromfile = (commandstruct*)malloc(100 * sizeof(commandstruct));
    fread(commandsfromfile, sizeof(commandstruct), HowManyCommands, commandList);
    for (int i = 0; i < HowManyCommands; i++)
    {
        strcat(buffer, i+commandsfromfile->command);
        strcat(buffer, " ");
        strcat(buffer, i+commandsfromfile->channellayer);
        strcat(buffer, " ");
        strcat(buffer, i+commandsfromfile->extraparams);
        strcat(buffer, "\r\n");
    }
    fclose(commandList);
    printf("%s", buffer+1);
    return buffer+1;
}

void writeCommandsToFile(char *filename)//crea el archivo de comandos y almacena los susodichos como estructuras
{
    int option = 1;
    FILE *commandList;
    commandList = fopen(filename, "w+b");
    if (commandList == NULL)
    {
        printf("Error while opening file");
        return;
    }
    printf("Enter list of commands to save on file\n");
    int i=0;
    commandstruct *commandstosave;
    commandstosave = (commandstruct*)malloc(100 * sizeof(commandstruct));
    while (option != 0)
    {
        printf("%d:\n",i);
        printf("Command:");
        scanf("%s", i+commandstosave->command);
        printf("\nChannel and layer (C-L):");
        scanf("%s", i+commandstosave->channellayer);
        printf("\nExtra parameters(depends on command; if none, press Space + Enter):");
        scanf("%s", i+commandstosave->extraparams);
        printf("\nSave another command? (1->yes,0->no):");
        scanf("%d",&option);
        i++;
    }
    fwrite(&i, sizeof(int), 1, commandList);
    fwrite(commandstosave, sizeof(commandstruct), i, commandList);
    fclose(commandList);
    return;
}


int procesador_implementado (char *buffer)//menu mediante el cual se controlan los comandos que se envian a traves de la sesion activa de la conexion telnet
{                                       //el buffer aqui es el mismo que el de la sesion activa. se escribe en este buffer y se envia la longitud de lo escrito para enviar el comando
    system("clear");//la funcion se llama en cada bucle de envio y recepcion de mensajes, esto limpia la pantalla para mas estetica
    char *tmpmedianame;
    char *layertmp;
    layertmp = (char*)malloc(50 * sizeof(char));
    tmpmedianame = (char*)malloc(50 * sizeof(char));
    char option;

    do
    {
        printf("Select command\r\n1 - play \r\n2 - stop \r\n3 - pause\r\n4 - resume\r\n");
        printf("5 - clear layer/channel\r\n6 - take a snapshot\r\n7- send commands from file\r\n");
        printf("8 - get media list\r\n9 - set logo\r\ne - exit \r\n");
        fflush(stdin);
        //scanf("%c", &option);
        option = getchar();
        switch (option)
        {
        case '1'://play a file
            {
                printf("Enter name of media file\r\n");
                scanf("%s", tmpmedianame);
                strcpy(buffer, playCommand(tmpmedianame));
                printf("sent play command\r\n");
                return strlen(buffer);//cada comando termina con esta instruccion, que devuelve la longitud de lo escrito en el buffer
            }
        case '2'://stop media on layer
            {
                strcpy(buffer, stopCommand());
                printf("sent stop command\r\n");
                return strlen(buffer);
            }
        case '3'://pause
            {
                strcpy(buffer, pauseCommand());
                printf("sent pause command\r\n");
                return strlen(buffer);
            }
        case '4'://resume
            {
                strcpy(buffer, resumeCommand());
                printf("sent resume command\r\n");
                return strlen(buffer);
            }
        case '5'://clear channel or layer
            {

                printf("Enter channel and/or layer to clear\r\n");
                scanf("%s", layertmp);
                strcpy(buffer, clearCommand(layertmp));
                printf("sent clear layer/channel command\r\n");
                return strlen(buffer);

            }
        case '6'://snapshot
            {
                printf("Enter channel to do a snapshot in\r\n");
                scanf("%s", layertmp);
                strcpy(buffer, printCommand(layertmp));
                printf("snapshot taken\r\n");
                return strlen(buffer);

            }
        case '7' ://read from file
            {
                int option1;
                while (option1 != 1)
                {
                    printf("Enter command list filename\r\n");
                    scanf("%s", tmpmedianame);
                    strcpy(buffer, readCommandsFromFile(tmpmedianame));
                    printf("Is this correct? 1->yes, 0->no\r\n");
                    scanf("%d", &option1);
                }
                printf("sent command list\r\n");
                return strlen(buffer);
            }
        case '8'://get media file list
            {
                strcpy(buffer, clsCommand());
                printf("get media file list\r\n");
                return strlen(buffer);
            }
        case '9'://set logo
            {
                printf("Enter name of logo media file\r\n");
                scanf("%s", tmpmedianame);
                strcpy(buffer, setLogo(tmpmedianame));
                printf("sent play command (logo)\r\n");
                return strlen(buffer);
            }
        case 'e'://close session
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

