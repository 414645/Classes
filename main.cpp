#include <iostream>
#include "media.h"

using namespace std;

void addMedia();
void searchMedia();
void deleteMedia();
//void quit(); just quit

int main() {
  //cout << "hello world" << endl;
  
  //initialize vaiables
  char input[6];
  for (int a = 0; a < 6; a++)
    {
      input[a] = ' ';
    }
  bool quit = false;
  
  //rest of code
  while (quit == false) {
    cin.get(input, 7); //6 chars
    cin.ignore(80,'\n');
    
    //check for each command and run the correct function
    if (input[0] == 'A' &&
	input[1] == 'D' &&
	input[2] == 'D' )
      {
	addMedia();
      }
    else if (input[0] == 'S' &&
	     input[1] == 'E' &&
	     input[2] == 'A' &&
	     input[3] == 'R' &&
	     input[4] == 'C' &&
	     input[5] == 'H')
      {
	searchMedia();
      }
    else if (input[0] == 'D' &&
	     input[1] == 'E' &&
	     input[2] == 'L' &&
	     input[3] == 'E' &&
	     input[4] == 'T' &&
	     input[5] == 'E' )
      {
	deleteMedia();
      }
    else if (input[0] == 'Q' &&
	     input[1] == 'U' &&
	     input[2] == 'I' &&
	     input[3] == 'T' )
      {
	quit = true;
      }
    else
      {
	cout << "Cannot find that command" << endl;
	cout << "The possible commands are: " <<endl;
	cout << "ADD" << endl;
	cout << "SEARCH" << endl;
	cout << "DELETE" << endl;
	cout << "QUIT" << endl;
      }
  }
  
}

void addMedia()
{

}

void searchMedia()
{

}

void deleteMedia()
{

}
