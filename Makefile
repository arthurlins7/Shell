all:
	gcc shell.c -o shell

run: 
	./shell

clean:
	rm shell