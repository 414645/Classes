#include <iostream>
#include "media.h"
#include "videogame.h"
#include "music.h"
#include "movie.h"
#include <vector>

#include <cstring>

using namespace std;

//by Ryan Veith
//12/2/2022
//this is the main class of the "classes" assigment
//it takes in input and deals with the user interaction
//it had addmedia which adds media types to the vector
//search media which calls print of all of the media meeting search terms
//it has delete media which delets a piece of media
//it also has printmedia which takes a piece of media and prints its characteristcs

//It takes in information seperated with spaces which lets you
//add media in one iline, but means you need to use '_' instead of ' '

void addMedia(vector<Media*> &mediaList);
void searchMedia(vector<Media*> &mediaList);
void deleteMedia(vector<Media*> &mediaList);
//void quit(); just quit

//this was added since cout << happens alot
//i would make the child classes do it put formating endl
//is harder in them because what get is the last changes
void printMedia(Media* media);

int main() {
  cout << "Welcome to the Assignment Classes" << endl;
  cout << "The commands are ADD, SEARCH, DELETE, and QUIT" << endl;
  cout << "A space will sepereate commands if you want to enter multiple" << endl;
  cout << "(this means don't type it unless you want to do multiple commands)" << endl;
  
  //initialize vaiables
  char input[6];
  for (int a = 0; a < 6; a++)
    {
      input[a] = ' ';
    }
  bool quit = false;

  vector<Media*> mediaList;
  
  //User input, what do you want to do?
  while (quit == false) {
    //different ways to do User Input, I like cin >> variable
    //cin.ignore(80,'\n'); 
    //cin.get(input, 7); //6 chars
    //cin.ignore(80,'\n');
    cin >> input;
    
    //check for each command and run the correct function
    //yes strcmp  works too but this will will work for Zuul
    //though I could also split string by spaces for zuul
    
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
  char title[80];
  int year;
  char publisher[80];
  char rating[80];
  char artist[80];
  char duration[80]; //char since ##:##
  char director[80];
  
  //What type of media
  cout << "If you would like to add a Video Game type 1" << endl;
  cout << "If you would like to add a Song(Music) type 2" << endl;
  cout << "If you would like to add a Movie type 3" << endl;
  cin >> number;

  //default media questions
  cout << "please enter the title" << endl;
  cin >> title;
  cout << "please enter the year the it was made" << endl;
  cin >> year;

  //the folowing could be reorgainsed so each type of meadia has it's
  //own if for some reason that format annoyed me so...
  //reminder: 1 is vedio game, 2 is music, 3 is movie

  //publisher 1,2
  if (number == 1 || number == 2)
    {
      cout << "please enter the publisher" << endl;
      cin >> publisher;
    }
  
  //rating 1,3
  if (number == 1 || number == 3)
    {
      cout << "please enter the rating" << endl;
      cin >> rating;
    }
  
  //artist 2
  if (number == 2)
    {
      cout << "please enter the artist" << endl;
      cin >> artist;
    }
  
  //duration 2,3
  if (number == 2 || number == 3)
    {
      cout << "please enter the duration" << endl;
      cin >> duration;
    }
  
  //director 3
  if (number == 3)
    {
      cout << "please enter the director" << endl;
      cin >> director;
    }

  //make the information into a class
  if (number == 1) {
    //title, year, publisher, rating
    Videogame* newchild = new Videogame(1, title, year,
					publisher, rating);
    mediaList.push_back(newchild);
    //add it to vector now since otherwise it is out of scope
  }
  else if (number == 2) {
    //title, artist, year, duration, publisher
    Music* newchild = new Music(2, title, year,
				artist, duration, publisher);
    mediaList.push_back(newchild);
  }
  else if (number == 3) {
    //title, director, year, dration, rating
    Movie* newchild = new Movie(3, title, year,
			        director, duration, rating);
    mediaList.push_back(newchild);
  }
}

void searchMedia(vector<Media*> &mediaList)
{
  //search by title or year? (if statement)
  //get search term(cin)
  //go though the vector with the given criteria
  //print results
  
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
  int location = -1;
  for (int a = 0; a < mediaList.size(); a++) {
    
    if (number == 1) { 
      if (strcmp(mediaList[a]->getTitle(), title) == 0) {
	location = a;
	//print out what we found
	printMedia(mediaList[a]);
      }
    }
    if (number == 2) {
      if (mediaList[a]->getYear() == year) {
	location = a;
	//print out what we found
	printMedia(mediaList[a]);
      }
    }
  }
  //did we find it?
  //my first idea was only do the cout one at the end,
  //but we have to print out all results so...
  if (location > -1) {
    //we found it no message needed 
  }
  else {
    cout << "we do not have any files" << endl;
  }
  
}

void printMedia(Media* media) {
  cout << media->getTitle() << ", ";
  cout << media->getYear() << ", ";
  if (media->getIdentity() == 1) {
    Videogame* name = static_cast<Videogame*>(media);
    cout << name->getPublisher() << ", ";
    cout << name->getRating() << endl;
  }
  else if (media->getIdentity() == 2) {
    Music* name = static_cast<Music*>(media);
    cout << name->getArtist() << ", ";
    cout << name->getDuration() << ", ";
    cout << name->getPublisher() << endl;
  }
  else if (media->getIdentity() == 3) {
    Movie* name = static_cast<Movie*>(media);
    cout << name->getDirector() << ", ";
    cout << name->getDuration() << ", ";
    cout << name->getRating() << endl;
  }
}

void deleteMedia(vector<Media*> &mediaList)
{
  //same search as above
  //double check on selected resultes
  //call a deconstuctor

  //search as above starts
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
  int location = -1;
  for (int a = 0; a < mediaList.size(); a++) {
    
    if (number == 1) { 
      if (strcmp(mediaList[a]->getTitle(), title) == 0) {
	location = a;
	//we found it
	//ask do delete stuff individual so it goes in loop
	cout << "are you sure you want to delete(y/n): ";
	printMedia(mediaList[a]);
	//cout << "?" << endl; //this would be next line so...

	char input[80];
	cin >> input;
	if (input[0] == 'y') {
	  //delete it now
	  delete mediaList[a];
	  mediaList.erase(mediaList.begin()+a);
	}
      }
    }
    if (number == 2) {
      if (mediaList[a]->getYear() == year) {
	location = a;
	//we found it
	//ask do delete stuff individual so it goes in loop
	cout << "are you sure you want to delete(y/n): ";
	printMedia(mediaList[a]);
	//cout << "?" << endl; //this would be next line so...

	char input[80];
	cin >> input;
	if (input[0] == 'y') {
	  //delete it now
	  delete mediaList[a];
	  mediaList.erase(mediaList.begin()+a);
	}
      }
    }
  }
  //did we find it?
  if (location < 0) {
    cout << "we could not find any files that match that crieria" << endl;
    cout << "please check your search criteria and try agian" << endl;
  }
}
