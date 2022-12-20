#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>

#define ARQUIVO_INTERMEDIARIO "correct.txt"
#define BUFFER_SIZE 1000
#define menuseq "seq> "
#define menupar "par> "
#define MAX_LINE 80 /* 80 chars per line, per command */

int parseInput(char* args[MAX_LINE/2+1], char word[MAX_LINE]);
int isParallel(char* str);   
void replaceAll(char *str, const char *word, const char *newWord);
int findSymbol(char* args[MAX_LINE/2+1], char* ch);

int main(int argc, char *argv[])
{
    char *args[MAX_LINE/2 + 1];  
    char line[MAX_LINE];
    int should_run = 1;         
    char word[MAX_LINE];
    char *list[MAX_LINE];
    int n = 0;
    int num = 0;
    int i = 0;
    int argsize;
    int style = 0;
    int id = 1234;
    int f[2];
    int pfd[2];
    pid_t ppid;
    pid_t pid;
    int fd;
    int p;
    char background[MAX_LINE];
    int count = 0;
    int count2 = 1;
    FILE *fptr;
    FILE *fptw;
    FILE *fptrf;

   if ((fptw = fopen(ARQUIVO_INTERMEDIARIO, "w")) == NULL) {
          printf("Error! opening intermediary file");
          exit(1);  
        }

   if ((fptrf = fopen(ARQUIVO_INTERMEDIARIO,"r")) == NULL) {
          printf("Error! opening intermediary file");
          exit(1);  
        }
  
   if((fptr = fopen(argv[1],"r")) != NULL){
     while (fscanf(fptr, "%s", line) > 0){
        char *teste = strtok(line,";");
        fprintf(fptw, "%s\n", teste);    
        teste = strtok(NULL, "; ");
      } 
    fclose(fptw);
    printf("Sequential:\n\n");
    while(fscanf(fptrf, "%s", line) > 0){
      if(strcmp(line, "exit") == 0){
        exit(0);
      }
      system(line);
      }
    }
  if((fptr = fopen(argv[1],"r")) != NULL){
    printf("\nParallel:\n\n");
    while (fscanf(fptr, "%s", line) > 0){
      replaceAll(line, ";", "&");
      system(line);
      }
    }
  unlink(ARQUIVO_INTERMEDIARIO);
  
    while (1) {
      if(style == 0){
        printf("alg2 seq> ");
      }
      else if(style == 1){
        printf("alg2 par> ");
      }
      
      fflush(stdout);
      fflush(stdin);
	    fgets(word,MAX_LINE,stdin);
    	for (int i = 0; ; i++)
    	{
    		if (word[i] == '\n')
    		{
    			word[i] = '\0';
    			break;
    		}
    	}
		  if (!strcmp(word,"exit")){  
        exit(0);
      }
      argsize = parseInput(args,word);
  
      if ( (p = findSymbol(args, "&")) >= 0 ) 
			{
				list[n] = args[0];
        printf("\n[%d] %d\n", n, id);
        n += 1;
        id += 1;
			}
      else{
    if(pipe(f)<0) {
        perror("o pipe falhou") ;
        return -1 ;
    }
      pid = fork();
     if(pid < 0){
          printf("Não foi possível criar os filhos");
        }
      else if(pid > 0){
         wait(NULL);
        }
      else if(pid == 0){
          if(strcmp(args[0], "fg") == 0){
            num = atoi(args[1]);
            system(list[num]);
            break;
          }
        if(strcmp(word, "style parallel") == 0){
            style = 1;
          }
		else if(style == 0 && !(strcmp(word, "style parallel") == 0) && !(strcmp(word, "style sequential") == 0)){
           system(word); 
          }
        else if(strcmp(word, "style sequential") == 0){
            style = 0;
          }
        else if(style == 1 && !(strcmp(word, "style parallel") == 0) && !(strcmp(word, "style sequential") == 0)){
            replaceAll(word, ";", "&");
            system(word);
          }
        
        /*for(count = 0; count < argsize; count++){
        char *list[] = {args[count], NULL };
        pid = fork();
        if(pid < 0){
            printf("Não foi psível criar os filhos");
          }
        else if(pid > 0){
           if(!(style == 1))wait(NULL);
          }
        else if(pid == 0){
  			if(style == 0 && !(strcmp(word, "style parallel") == 0) && !(strcmp(word, "style sequential") == 0)){
           execvp(list[0], list);
        else if(style == 1 && !(strcmp(word, "style parallel") == 0) && !(strcmp(word, "style sequential") == 0)){
            execvp(list[0], list);
            }*/
    
					printf("\n");
					fflush(stdout);
          }
        }
      }
  if ( (p = findSymbol(args, ">")) >= 0 ) 
			{
				fd = open(args[p+1], O_CREAT | O_WRONLY);
				dup2(fd, STDOUT_FILENO);   
				close(fd);

				args[p] = NULL;
			}
	else if ( (p = findSymbol(args,"<")) >= 0 ) 
			{
				fd = open(args[p+1], O_RDONLY);
				dup2(fd, STDIN_FILENO);    
				close(fd);

				args[p] = NULL;
			}
  else if ((p = findSymbol(args,"|")) >= 0)
			{	
				if (pipe(pfd) == -1)
				{
					printf("O pipe falhou");
					fflush(stdout);
					exit(1);
				}

				ppid = fork();
				if (ppid < 0)  
				{
					printf("Não foi psível criar os filhos");
					fflush(stdout);
				}

				else if (ppid > 0) 
				{
					dup2(pfd[0],STDIN_FILENO); 
					close(pfd[1]);
					wait(NULL);
				}
      }
          return 0;
}

int parseInput(char* args[MAX_LINE/2+1], char word[MAX_LINE])
{
	int size;
	int p = 0;
	char temp[MAX_LINE];
	strcpy(temp,word);
	
	char* y = strtok(temp, " ");
	while (y != NULL)
	{
		size = 0;
		for (int i = 0; ; i++)
		{
			size++;
			if (y[i] == '\0')
			{
				break;
			}
		}
		args[p] = malloc(size * sizeof(char));
		strcpy(args[p], y);
		y = strtok(NULL, "; ");
		p++;
	}
	args[p] = NULL;
	return p;
}

int findSymbol(char* args[MAX_LINE/2+1], char* ch)
{
    for (int i = 0; args[i] != NULL; i++)
    {
        if (!strcmp(args[i], ch))
        {
            return i;
        }
    }
    return -1;
}

void replaceAll(char *str, const char *word, const char *newWord)
{
    char *p, temp[BUFFER_SIZE];
    int index = 0;
    int len;
  
    len = strlen(word);
    if (!strcmp(word, newWord)) {
        return;
    }
    while ((p = strstr(str, word)) != NULL)
    {
        strcpy(temp, str);
        index = p - str;
        str[index] = '\0';
        strcat(str, newWord);
        strcat(str, temp + index + len);
    }
  }
