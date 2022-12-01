#include <iostream>
#include "media.h"
#include "videogame.h"

#include <cstring>

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
    //cin.ignore(80,'\n'); 
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
  cout << "If you would like to add a Video Game type 1" << endl;
  cout << "If you would like to add a Song(Music) type 2" << endl;
  cout << "If you would like to add a Movie type 3" << endl;
  int number = 0;
  cin >> number;
  if (number == 1)
    {
      char title[80];
      int year;
      char publisher[80];
      char rating[80]; 
      cout << "please enter the title of the videogame" << endl;
      cin >> title;
      cout << "please enter the year  the videogame was made" << endl;
      cin >> year;
      cout << "please enter the publisher of the videogame" << endl;
      cin >> publisher;
      cout << "please enter the rating of the videogame" << endl;
      cin >> rating; 
      
      Videogame* newchild = new Videogame(title, year, publisher, rating);
      //title
      //year
      //publisher
      //rating
    }
  else if (number == 2)
    {
      //title
      //artist
      //year
      //duration
      //publisher
    }
  else if (number == 3)
    {
      //title
      //director
      //year
      //duration
      //rating
    }
  
  /*
  char title[6];
  for (int a = 0; a < 6; a++)
    {
      title[a] = ' ';
    }
    cin.get(title, 7); //6 chars
    cin.ignore(80,'\n');
  */
}

void searchMedia()
{
  //search by title or year? (if statement)
  //get search term(cin)
  //go though the vector/list/pointers with the given criteria
} 

void deleteMedia()
{
  //search as above
  //double check on selected resultes
}
