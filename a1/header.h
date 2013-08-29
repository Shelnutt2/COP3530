/*
Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Recursive function to compute factorials
long int compute_factorial(long int a){
if(a<0) //Make sure long integer given is not a negative
  return -1;

if(a==1) //base case
  return 1;

//Recursively call compute_factorial and return final output
return a*compute_factorial(a-1);

}

//Function to print the factorial of a given user input
void print_factorial(){

char buf[BUFSIZ]; //create a buffer with the defined buffer size
char *c = NULL; //character used for checking to make sure user entered an integer

long int x = 0; //user inputed x
while(1<2){ //Loop for input and computation until user wishes to quit
  printf("Enter a number(or enter ‘q’ to quit): "); //ask for user input

  if (fgets(buf, sizeof(buf), stdin) != NULL) //get user input and store in buffer
  {
    x = strtol(buf, &c, 10); //convert to long

    if (buf[0] != '\n' && (*c == '\n' || *c == '\0')){ //check to make sure user actually entered a value and that value is an integer
      if(x<0) // Check for negative integers
         printf("Please enter only a positive integer value or q\n");
      else
         printf ("%ld!= %ld\n", x,compute_factorial(x)); //display output
    } 
    else if(*c =='q') //Check for signal to quit
    {
       printf("You have left the game!\n"); //Exit message
       return;
    }
    else{
       printf ("Please enter only a positive integer value or q\n"); //user entered and invalid integer, loop repeats.
    }
  }
 }

}

