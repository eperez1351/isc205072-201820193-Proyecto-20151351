#ifndef OTHERFUNCTIONS_H_INCLUDED

int procesador_implementado (char * buffer);
char* playCommand(char *filename);
char* stopCommand();
char* pauseCommand();
char* resumeCommand();
char* clearCommand(char *channellayer);
char* printCommand(char *channel);
char* clsCommand();
char* setLogo(char *filename);
void writeCommandsToFile(char* filename);
char* readCommandsFromFile(char *filename);

#endif // OTHERFUNCTIONS_H_INCLUDED
