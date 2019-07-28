#include <stdio.h>
#include <stdlib.h>
#include "telnet-client.h"

void getHostname_terminal(char *hostname);
char* sendCommandTest();

int main()
{
    char **ipport;
    ipport = malloc(5 * sizeof(*ipport));
    *ipport = malloc(50 * sizeof(**ipport));
    char *hostname;
    hostname = (char*)malloc(50 * sizeof(char));
    *(ipport+1) = hostname;
    *(ipport+2) = "5250";
    char *command;
    command = (char *)malloc(100 * sizeof(char));
    printf("Hello world!\nEnter hostname for Telnet connection\n");
    printf("->");
    scanf("%s", hostname);
    printf("%s\n", *(ipport+1));
    telnet_client(3, ipport, sendCommandTest());
    return 0;


}

char* sendCommandTest()
{
    return "play 1-1 amb \r\n";

}

/*
void sendCommandMenu()
{
    int option=0;
    do
    {
        printf("Select command\n1 - play \n2 - stop \n3 - exit \n");
        scanf("%d", &option);

        switch(option)
        {
        case 1 :
        {

        }
        case 2 :

        case 3 :
            return;

        }
        while

    }


}

void saveBufferToFile()
{



}
*/
