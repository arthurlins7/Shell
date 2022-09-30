#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LINE 80 

int main(int argc, char *argv[])
{
    char args[MAX_LINE/2 + 1]; 
    int should_run = 1;         
    char *t;
    char* menu = "alg2 seq> ";
    char *fptr;

while (should_run) {
        if((fptr = fopen(argv[1],"r")) != NULL){
        fscanf(fptr, "%s", &*args);
        }
        else{
        printf("%s", menu);
        scanf("%s", &*args);
}
        t = strtok(args,";");
        if(fork() == 0){
        while(t != NULL){
        char *list[] = {t, "-l", NULL};
        int status = execvp(t, list);
                if(status != 0){
                        t = strtok(NULL,";");
                        system(t);
                }else{
                        break;
                }
}
        }else{
        wait(NULL);
        if(strcmp(args,"exit") == 0){
                exit(0);
        }
        fflush(stdout);
}
}
        return 0;
}