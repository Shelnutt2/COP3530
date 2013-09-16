/*
Name : Seth Shelnutt
UF ID: 42941969
Gator ID: s.shelnutt
Discussion section # : 1085
*/

#include <ArrayLinearList.h>
#include <stdio.h>
#include <string.h>

#ifndef exceptions //include exceptions onluindex once
#define exceptions
#include <exceptions.h>
#endif

using namespace std;

int get_int(){ //Function to get integers from user
  char buf[BUFSIZ]; //create a buffer with the defined buffer siuservaluee
  char *c = NULL; //character used for checking to make sure user entered an integer

  int uindex = 0;
  if (fgets(buf, sizeof(buf), stdin) != NULL) //get user input and store in buffer
  {
    uindex = strtol(buf, &c, 10); //convert to int
    if (buf[0] != '\n' && (*c == '\n' || *c == '\0')){
      return uindex;
    }
    else{
      throw illegalParameterValue();
      return -1;
    }
  }
  return -1;

}
uint get_index(){ //Get the index from user
  printf("Enter the index: ");
  return get_int(); //returns unsigned int
}

int get_value(){ //get the value from the user
  printf("Enter the value: ");
  return get_int(); //returns an int
}

//Main function to be run
int main()
{
char buf[BUFSIZ]; //create a buffer with the defined buffer siuservaluee
char *c = NULL; //character used for checking to make sure user entered an integer

uint uindex = 0; //usigned int for index
int uservalue = 0; //int for value

ArrayLinearList<int> ALL = ArrayLinearList<int>();
for(int i = 1;i<=10;i++) //Initialize the array
  ALL.insert(i-1,i);

while(1<2){ //Loop for input and computation until user wishes to quit
  printf("Please enter your command(I, D, P, E, S, M, Q): "); //ask for user input

  if (fgets(buf, sizeof(buf), stdin) != NULL) //get user input and store in buffer
  {
    uindex = strtol(buf, &c, 10); //convert to int
    switch(*c){

    case 'q': //Quit
    case 'Q':
      return 0;
      break;

    case 'i': //Insert Element
    case 'I':
      uindex = get_index(); //get index
      uservalue = get_value(); //get the users value
      ALL.insert(uindex,uservalue); //insert the value at the given index
      printf("After inserting the element %d at the index of %d, The updated linear list is: ",uindex,uservalue);
      ALL.printall(); //print new list
      break;

    case 'd': //Delete
    case 'D':
      ALL.del(get_index()); //delete given element
      break;

    case 'p': //Print
    case 'P':
      printf("The linear list is: ");
      ALL.printall(); //print the whole list
      break;

    case 'e': //Element
    case 'E':
      uindex = get_index();
      printf("The element at the index of %d is ",uindex);
      ALL.print(uindex);
      break;

    case 's': //Size
    case 'S':
      printf("The size of the list is: %d\n",ALL.size());
      break;

    case 'm': //MinMax
    case 'M':{
      int *i = ALL.minmax(); //Print the min and the maxs
      printf("The min is %d, the max is %d\n",i[0],i[1]); 
      break;
      }

    default: //Print help if invalid command
      printf("Invalid option, your options are: \n"
             "I...[I]nsert\n"
             "D...[D]elete\n"
             "P...[P]rint out the entire List\n"
             "E...Print any [E]lement \n"
             "S...Print the Current [S]size\n"
             "M...Print the [M]aximum and the [M]inimum\n");
    } 
  }
}  
    return 0;
}
