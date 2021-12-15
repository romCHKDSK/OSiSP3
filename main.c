#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include "errors.h"

#define N 15

int main(int argc, char* argv[])
{
	pid_t pid;
	char tmp[256];
	if (argc==1)
	{
	  sprintf(tmp, "Erorr. You should enter filename, when calling %s", argv[0]);
	  print_error(argv[0],tmp , 1); 
	}
	pid = fork();
	if (pid == 0)
	{
		FILE* f = fopen(argv[1], "r");
		//while(f == NULL) f = fopen(argv[1], "r");
		if (f == NULL)
		{
		  sprintf(tmp, "Child error: Cann't close file %s\n", argv[1]);
		  print_error(argv[0], tmp, 1);
		}
		int i = 0;
		while(i != N)
		{
		    if(fgets(tmp, 256, f) != NULL)
		    {
			printf("\t\t\t\t\t\t\t%d %s", getpid(), tmp);
			i++;
		    }
		}
		if(fclose(f) != 0)
		{
			sprintf(tmp, "Child error: Cann't close file %s\n", argv[1]);
			print_error(argv[0], tmp, 1);
		}
	}else if (pid > 0)
	{
		FILE* f = fopen(argv[1], "w");
		if(f == NULL)
		{
			sprintf(tmp, "Parent errort: Cann't open file %s\n", argv[1]);
			print_error(argv[0], tmp, 1);
		}
		int i;
		for(i = 0; i < N; i++)
		{
		    fprintf(f, "%d aaa bbb\n", i);
		    printf("%d %d aaa bbb\n", i, getpid());		
		}
		if(fclose(f) != 0)
		{
			sprintf(tmp, "Parent error: Cann't close file %s\n", argv[1]);
			print_error(argv[0], tmp, 1);
		}
		wait((int*)0);
	}
	else
	{
		print_error(argv[0], "Error during call fork()\n", 1);
	}
} 
