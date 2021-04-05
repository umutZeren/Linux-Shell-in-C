#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char **get_input(char *input) 
{
    char **command = malloc(8 * sizeof(char *));
    char *separator = " ";
    char *parsed;
    int index = 0;

    parsed = strtok(input, separator);
   // is_char can be usabel or pass if see second "  "
    while (parsed != NULL) {
        command[index] = parsed;
        index++;
	// executes at most 47 right side argumetns -> docs.
        parsed = strtok(NULL, separator);
    	if(index>48) 
	{
		printf("You passed the maximum number of arguments");
		break;
	}
    }

    command[index] = NULL;
    return command;
}

int main(int argc, char* argv[]){
  char input[50];
  char command[50];
  char *inputptr;
  int i;	
  pid_t child_pid;
  int stat_loc;
  // TO DO-----------------------------------------------------------------
  // DONE | argument parse -> "-" başltacak boşluk olmayana kadar" ar[i]=str_ 
  //  DONEif argument count >50 execpetion yoksa elle if print("no more 50")
  //  DONE quit;
  // 1.parallel main DONE thread loop	";"-> "|" while loopda ll be implemented. 
  // 	2. sequential %90 DONE  | varken sequential
  // 	3. quit swap ls;echo -> arrayde quit görünce sondakiyle swap
  //  TEST check if batch file exist else print error
  	//  check perorr for error handling
  	// cok boslukda sadece optional. multiplte empty char check -a   -b
  //  batch modu
  //  suggestions part read.
  inputptr = input;
  printf("myshell:>");
  char *d="ls;                             ls  -l;";
  int b;
  for (b = 0; d[b] != '\0'; b++);
		 printf("THIS IS A %d",b);
  
   while ( strcmp(input,"quit")!=0 ) 
   {
     	sprintf(command, "echo \"%s\"", input);
     	//printf("PR_out:%s\n", command);
     	printf("myshell:>");
		
	int i=0,startIndex=0,substrL=0;
	// for(int i=0;i< ;i++)
	// içinde pipe varsa yeni bir arrayde collect [cmd1,cmd2]
	while(input[i]!='\0'){
	
		if(input[i]==';')
		{	
	 	  char *substr=(char*) malloc((i+3)*sizeof(char));
		  printf("%d\n",i-startIndex);
		  memcpy( substr, &input[substrL],i-substrL );
		  substr[i-substrL] = '\0';
		  
		  printf("i-subst  %d\n",i-substrL);
		  //strncpy(substr,input+,i-substrl);	  
		  printf("SUBSTRING %s\n",substr);
		  int a;
    		  for (a = 0; substr[a] != '\0'; a++);
		  printf("THIS IS A %d\n",a);
		  substrL +=a+2;

		  char **str= get_input(substr);
		  //printf("STR %s\n ",str);
		 
		  child_pid = fork();// 1.main process 2. command_N 
        	  if (child_pid == 0) {
        	  // Never returns if the call is successful 
        	   execvp(str[0], str);
        	   printf("This won't be printed if execvp is successul\n");
        	  } 	
		  else {
        	    waitpid(child_pid, &stat_loc, WUNTRACED);
        	  }
		free(substr);
		}
		i++;
	}//inner while end
  gets(inputptr);
 }// outer while
    
    return 0;
 }

