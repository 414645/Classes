#include <iostream>
#include <cstring>
#include "videogame.h"

using namespace std;

Videogame::Videogame() {
  //never should be called but vectors might need it
}

Videogame::Videogame(char* newtitle, int newyear,
		     char* newpublisher, char* newrating) {
  //title = new char[80];
  //int year;
  publisher = new char[80];
  rating = new char[80];
  //title = strcpy(title, newtitle);
  //year = newyear;
  publisher = strcpy(publisher, newpublisher);
  rating = strcpy(rating, newrating);
}

char* Videogame::getPublisher() {
  return publisher;
}

char* Videogame::getRating() {
  return rating;
}
