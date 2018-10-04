#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char**argv)
{
    //printf("%d\n", argc);
    int i = 0; // value that will receive the loop while
    char bash[256]; //string of cmd space
    int pid = fork(); // pid is a variable that will receive the fork fuction
    char command_ps[15] = "ps -p"; //cpu monitory commands
    char command_ps_aux[35] = "-o %cpu | grep -v CPU"; //complementy of the last line
    sprintf(bash, "%s %d %s", command_ps, pid, command_ps_aux); //This line I will set the args of command_ps and command_ps_aux in a function sprintf

    char command_pmap[15] = "pmap"; // First line of command "pmap"
    char command_pmap_aux[35] = "| grep -i total"; //complementy of the last line
    char bash2 [256]; //second string of cmd space for the next function
    sprintf(bash2,"%s %d %s",command_pmap,pid,command_pmap_aux); //this line make the sprintf in the bash2


    if( pid < 0)// fork was failed
    {
        perror("Erro: falha na chamada do fork");
        exit(-1);
    }
    else if(pid > 0)// process parent
    {
        while(i < 10)
        {
            system(bash);
            i += 1;
            if (strcmp(argv[1], "cpu") == 0)
            {
                for(;;)
                {

                }
            }
            sleep(1);
        }
        kill(0,SIGKILL);
    }
    else// pid == 0, this is, it is the child process
    {
        if (strcmp(argv[1],"cpu") == 0)
        {
            for(;;)
            {

            }
        }
        else
        {
            for(;;)
            {
                malloc(sizeof(1));
            }
        }
    }

    return 0;
}
