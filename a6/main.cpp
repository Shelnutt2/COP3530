/*Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _BinPacking
#define _BinPacking
#include <BinPacking.h>
#endif

using namespace std;

int main(){
  long int algorithm;
  char* algorithmName;
  int* oArray;
  long int numObjects;
  long int binCap;
  long int x = 0;
  BinPacking* bp = new BinPacking();

  char buf[BUFSIZ]; //create a buffer with the defined buffer size
  char *c = NULL; //character used for checking to make sure user entered an integer


  while(1<2){ //Loop for input and computation until user wishes to quit
   printf("Please choose the algorithm for test: 1. Firstfit; 2. Bestfit; 3. Quit? "); //ask for user input

   if (fgets(buf, sizeof(buf), stdin) != NULL) //get user input and store in buffer
   {
    x = strtol(buf, &c, 10); //convert to long

    if (buf[0] != '\n' && (*c == '\n' || *c == '\0')){ //check to make sure user actually entered a value and that value is an integer
      switch(x){

      case 1:{
        algorithm = 0;
        algorithmName = "Firstfit";
        break;
      }
      case 2:{
        algorithm = 1;
        algorithmName = "Bestfit";
        break;
      }
      case 3:{
        return 0;
      }
      default:{
        printf("Please enter only a valid selection, 1,2 or 3\n");
        break;
      }

      }
    }
   }
    if(algorithm == 0 || algorithm == 1)
        break;
 }
  int i = 0;
   printf("Enter number of objects and bin capacity for %s\n",algorithmName); //ask for user input
  while(i<2){ //Loop for input and computation until user wishes to quit

   if (fgets(buf, sizeof(buf), stdin) != NULL) //get user input and store in buffer
   {
    x = strtol(buf, &c, 10); //convert to long
    if (buf[0] != '\n' && (*c == '\n' || *c == '\0')){ 
      if(i == 0) // 
         numObjects = x;
      else if(i == 1)
         binCap = x;
    i++;
    }
   }
  }

  oArray = new int[numObjects];
  for(i = 0; i<numObjects;i++){
  printf("Enter space requirement of object %d\n", i+1); //ask for user input
   if (fgets(buf, sizeof(buf), stdin) != NULL) //get user input and store in buffer
   {
    x = strtol(buf, &c, 10); //convert to long

    if (buf[0] != '\n' && (*c == '\n' || *c == '\0')){ //check to make sure user actually entered a value and that value is an integer
      oArray[i] = x;
    }
   }

  }
#ifdef PRIMARY
  if(algorithm == 0)
    bp->firstFitPack(oArray, numObjects, binCap);
  else if(algorithm == 1)
    bp->bestFitPack(oArray, numObjects, binCap);
#else
  if(algorithm == 0)
    bp->firstFitPack2(oArray, numObjects, binCap);
  else if(algorithm == 1)
    bp->bestFitPack2(oArray, numObjects, binCap);
#endif
}

/*Please choose the algorithm for test: 1. Firstfit; 2. Bestfit; 3. Quit?1
Enter number of objects and bin capacity for First Fit
12
6
Enter space requirement of object 1
2
Enter space requirement of object 2
5
Enter space requirement of object 3
5
Enter space requirement of object 4
1
Enter space requirement of object 5
1
Enter space requirement of object 6
3
Enter space requirement of object 7
4
Enter space requirement of object 8
6
Enter space requirement of object 9
2
Enter space requirement of object 10
5
Enter space requirement of object 11
6
Enter space requirement of object 12
1
Pack object 1 in bin 1*/
