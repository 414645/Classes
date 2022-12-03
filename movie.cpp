#include <iostream>
#include <cstring>
#include "movie.h"

using namespace std;

Movie::Movie() {
  //never should be called but vectors might need it
}

Movie::Movie(int newidentity,
	     char* newtitle, int newyear,
	     char* newdirector, char* newduration,
	     char* newrating
	     ):Media(newidentity, newtitle, newyear){
  
  director = new char[80];
  duration = new char[80];
  rating = new char[80];
  strcpy(director, newdirector);
  strcpy(duration, newduration);
  strcpy(rating, newrating);
}

Movie::~Movie() {
  delete director;
  delete duration;
  delete rating;
}

char* Movie::getDirector() {
  return director;
}

char* Movie::getDuration() {
  return duration;
}

char* Movie::getRating() {
  return rating;
}
