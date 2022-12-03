#include <iostream>
#include <cstring>
#include "videogame.h"

using namespace std;

Videogame::Videogame() {
  //never should be called but vectors might need it
}

Videogame::Videogame(char* newtitle, int newyear,
		     char* newpublisher, char* newrating
		     ):Media(newtitle, newyear){
  
  publisher = new char[80];
  rating = new char[80];
  strcpy(publisher, newpublisher);
  strcpy(rating, newrating);
}

Videogame::~Videogame() {
  free(publisher);
  free(rating);
}

char* Videogame::getPublisher() {
  return publisher;
}

char* Videogame::getRating() {
  return rating;
}


char* Media::getTitle() {
  return title;
}

int Media::getYear() {
  return year;
}
