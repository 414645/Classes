#include <iostream>
#include "media.h"
#include "videogame.h"
#include <vector>

#include <cstring>

using namespace std;

void addMedia(vector<Media*> &mediaList);
void searchMedia(vector<Media*> &mediaList);
void deleteMedia(vector<Media*> &mediaList);
//void quit(); just quit

int main() {
  cout << "hello world" << endl;
  
  //initialize vaiables
  char* input = new char[6];
  for (int a = 0; a < 6; a++)
    {
      input[a] = ' ';
    }
  bool quit = false;

  vector<Media*> mediaList;
  
  //User input, what do you want to do?
  while (quit == false) {
    //cin.ignore(80,'\n'); 
    cin.getline(input, 6); //6 chars
    //cin.ignore(80,'\n');
    //cin >> input;
    
    //check for each command and run the correct function
    if (input[0] == 'A' &&
	input[1] == 'D' &&
	input[2] == 'D' )
      {
	addMedia(mediaList);
      }
    else if (input[0] == 'S' &&
	     input[1] == 'E' &&
	     input[2] == 'A' &&
	     input[3] == 'R' &&
	     input[4] == 'C' &&
	     input[5] == 'H')
      {
	searchMedia(mediaList);
      }
    else if (input[0] == 'D' &&
	     input[1] == 'E' &&
	     input[2] == 'L' &&
	     input[3] == 'E' &&
	     input[4] == 'T' &&
	     input[5] == 'E' )
      {
	deleteMedia(mediaList);
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
	//they entered a invalid command, display comands for them
	cout << "Cannot find that command" << endl;
	cout << "The possible commands are: " <<endl;
	cout << "ADD" << endl;
	cout << "SEARCH" << endl;
	cout << "DELETE" << endl;
	cout << "QUIT" << endl;
      }
  }
  
}

void addMedia(vector<Media*> &mediaList)
{
  //variables needed (yes they could be resused but speed is not a problem)
  int number = 0;
  char* title = new char[80];
  int year;
  char* publisher = new char[80];
  char* rating = new char[80];
  char* artist = new char[80];
  char* duration = new char[80]; //char since ##:##
  char* director = new char[80];
  
  //What type of media
  cout << "If you would like to add a Video Game type 1" << endl;
  cout << "If you would like to add a Song(Music) type 2" << endl;
  cout << "If you would like to add a Movie type 3" << endl;
  //cin.ignore
  cin >> number;

  //default media questions
  cout << "please enter the title of the videogame" << endl;
  cin.getline(title, 80);
  //cin.get(title, 81); //80 chars
  //cin.ignore(80,'\n');
  
  cout << "please enter the year the videogame was made" << endl;
  cin >> year;

  //the folowing could be reorgainsed so each type of meadia has it's own if
  //for some reason that format annoyed me so...
  //reminder: 1 is vedio game, 2 is music, 3 is movie

  //publisher 1,2
  if (number == 1 || number == 2)
    {
      cout << "please enter the publisher" << endl;
      cin.getline(publisher, 80);
    }
  
  //rating 1,3
  if (number == 1 || number == 3)
    {
      cout << "please enter the rating" << endl;
      cin.getline(rating, 80);
    }
  
  //artist 2
  if (number == 2)
    {
      cout << "please enter the artist" << endl;
      cin.getline(artist, 80);
    }
  
  //duration 2,3
  if (number == 2 || number == 3)
    {
      cout << "please enter the duration" << endl;
      cin.getline(duration, 80);
    }
  
  //director 3
  if (number == 3)
    {
      cout << "please enter the director" << endl;
      cin.getline(director, 80);
    }

  //make the information into a class
  if (number == 1) {
    //title, year, publisher, rating
    //Videogame* newchild = new Videogame(title, year, publisher, rating);
    //mediaList.push_back(newchild);
    //add it to vector now since otherwise it is out of scope
    
  }
  else if (number == 2) {
    //title, artist, year, duration, publisher
    //Videogame* newchild = new Videogame(title, year, publisher, rating);
  }
  else if (number == 3) {
    //title, director, year, dration, rating
    //Videogame* newchild = new Videogame(title, year, publisher, rating);
  }
  
  //want add the newly created class to the vector
  //exept we had to do it earlier so it is not out of scope
  //mediaList.push_back(*newchild);
}

void searchMedia(vector<Media*> &mediaList)
{
  //search by title or year? (if statement)
  //get search term(cin)
  //go though the vector with the given criteria
  
  //needed variables
  int number = 0;
  char title[80];
  int year;
  
  
  //Title or Year?
  //also coding reminder do not flip the << (>> is bad)
  cout << "If you would like to search by title type 1" << endl;
  cout << "If you would like to search by year type 2" << endl;
  
  cin >> number;
  
  if (number == 1) {
    cout << "Please type the title you are looking for" << endl;
    cin >> title;
  }
  if (number == 2) {
    cout << "Please type the year you are looking for" << endl;
    cin >> year;
  }

  int avalue = -1;
  for (int a = 0; a < mediaList.size(); a++) {
    
    if (number == 1) {
      if (strcmp(mediaList[a]->getTitle(), title) == 0) {
	avalue = a;
      }
      /*
      if (strcmp(mediaList[a]->getTitle(), title) == 0) {
      	cout << mediaList[a]->getTitle() << ", ";
	cout << mediaList[a]->getYear() << ", ";
	//if
	
	cout << mediaList[a]->getPublisher << endl;
	//Videogame* a = (static_cast<Videogame>(mediaList[a]));
	//cout << videoGame->getPublisher << " yay!" << endl;
	//cout << (static_cast<Videogame*>(mediaList[a])->getPublisher)) << ", ";

	//end if

	//virtual class woould be add the virtual keyword to Media
	//and then move the actua; function to the child classes so they
	//have all of the information for cout
      }
      */
    }
    else if (number == 2) {	
      if (mediaList[a]->getYear() == year) {
	avalue = a;
	//same cout as above.
      }
    }
    if (avalue > -1) {
      cout << "found t" << endl;
    }

    
  }
} 

void deleteMedia(vector<Media*> &mediaList)
{
  //same search as above
  //double check on selected resultes
  //call a deconstuctor
}
