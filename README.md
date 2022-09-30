## Shell

*Código*
<p>
  <ul>
    <li>O código apresentar um shell funcional interativo ou por batch.<br />
    <li>É criado um processo filho que executará os comandos que serão passados no shell.<br />
   </ul></p>
   

*Processo filho*
```c
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

