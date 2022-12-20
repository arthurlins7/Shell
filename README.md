## Shell

*Código*
<p>
  <ul>
    <li>O código apresentar um shell funcional interativo ou por batch.<br />
    <li>É criado um processo filho que executará os comandos que serão passados no shell.<br />
   </ul></p>
   

*Processo filho*
```c
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
```

*Processo pai*
```c
        }else{
        wait(NULL);
        if(strcmp(args,"exit") == 0){
                exit(0);
        }
        fflush(stdout);
}
```
   
*Makefile*

<p>
  <ul>
   <li>O Makefile é composto pelos comandos $make, $make run e $make clean.<br />
   <li>O comando $make compila o arquivo tipo C e gera um arquivo binário.<br />
   <li>O $make run usa o arquivo binário para executar o código.<br />
   <li>E o $make clean tem a função de apagar o arquivo binário que foi anteriormente gerado no $make.<br />
</ul></p>

