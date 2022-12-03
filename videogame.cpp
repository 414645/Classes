#include <iostream>
#include <cstring>
#include "videogame.h"

using namespace std;

Videogame::Videogame() {
  //never should be called but vectors might need it
}

Videogame::Videogame(int newidentity,
		     char* newtitle, int newyear,
		     char* newpublisher, char* newrating
		     ):Media(newidentity, newtitle, newyear){
  
  publisher = new char[80];
  rating = new char[80];
  strcpy(publisher, newpublisher);
  strcpy(rating, newrating);
}

Videogame::~Videogame() {
  delete publisher;
  delete rating;
  //free(rating); //not malloc
}

char* Videogame::getPublisher() {
  return publisher;
}

char* Videogame::getRating() {
  return rating;
}
