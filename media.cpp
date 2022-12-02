#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

Media::Media() {
  //never should be called but vector might need it
}

Media::Media(char* newtitle, int newyear) {
  title = new char[80];
  strcpy(title, newtitle);
  year = newyear;
}

Media::~Media() {
  free(title);
  //free(year); //it is int not pointer so no free
}

char* Media::getTitle() {
  return title;
}

int Media::getYear() {
  return year;
}

