#include <stdio.h>
#include <stdlib.h>
void shLoop(void);
int main(int argc, char **argv)
{
    shLoop();
    return EXIT_SUCCESS;
}
// read input until 
void shLoop(void)
{
    char *line;
    char **args;
    int status;
    do
    {
        printf("> ");
        line = shReadLine();
        args = shSplitLine();
        status = shExecute();
        
        free(line);
        free(args);
    }while(status);
}
#define LSH_RL_BUFSIZE 1024
char* shReadLine(void)
{
    int buffSize = LSH_RL_BUFSIZE;
    int position = 0;
    char* buffer = malloc(sizeof(char) *buffSize);
    int c;
    // ensures the malloc correctly allocated bytes and did not fault
    if(!buffer){
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        c = getchar();
        if(c== EOF || c == '\n')
        {
            buffer[position] = '\0';
            return buffer;
        }
        else
        {
            buffer[position] = c;
        }
        position++;
        // make more space if needed to store the characters
        if (position >= buffSize)
        {
            buffSize += LSH_RL_BUFSIZE;
            buffer = realloc(buffer, buffSize);
            if (!buffer) 
            {
                fprintf(stderr, "lsh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }

}
char** shSplitLine(void)
{

}
