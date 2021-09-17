
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[])
{
    int i = 0;
    char **args = NULL;

    if(argc < 2)
    {
        printf("Requires arguments!\n");
        printf("%s <EXE> <EXE ARGS>\n", argv[0]);
        return 1;
    }

    if(daemon(1, 1)  < 0)
    {
        printf("Failed to daemon with error: %s\n", strerror(errno));
        return 1;
    }

    args = calloc(argc, sizeof(char *));
    if(!args)
    {
        printf("Failed to calloc with error: %s\n", strerror(errno));
        return 1;
    }
    
    for(i = 1; i < argc; i++)
    {
        args[i - 1] = strdup(argv[i]);
        if(!args[i - 1])
        {
            printf("Failed to strdup with error: %s\n", strerror(errno));
            goto CLEANUP;
        }
    }

    args[argc - 1] = NULL;

    execve(argv[1], args, envp);

CLEANUP:
    if(args)
    {
        for(i = 0; i < argc; i++)
        {
            if(args[i] != NULL)
            {
                free(args[i]);
            }
        }
        free(args);
    }
    return 1;
}
