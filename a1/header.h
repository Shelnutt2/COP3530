#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int compute_factorial(long int a){
if(a<0)
  return -1;

if(a==1)
  return 1;

return a*compute_factorial(a-1);

}

void print_factorial(){

char buf[BUFSIZ]; //create a buffer with the defined buffer size
char *c; //character used for checking to make sure user entered an integer

long int x; //user inputed x
while(1<2){
  printf("Enter a number(or enter ‘q’ to quit): "); //ask for user input

  if (fgets(buf, sizeof(buf), stdin) != NULL) //get user input and store in buffer
  {
    x = strtol(buf, &c, 10); //convert to long

    if (buf[0] != '\n' && (*c == '\n' || *c == '\0')){ //check to make sure user actually entered a value and that value is an integer
      if(x<0)
         printf("Please enter only a positive integer value or q\n");
      else
         printf ("%ld!= %ld\n", x,compute_factorial(x)); //display output
    } 
    else if(*c =='q')
    {
       printf("You have left the game!\n");
       return;
    }
    else{
       printf ("Please enter only a positive integer value or q\n"); //user entered and invalid integer, loop repeats.
    }
  }
 }

}

