#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

Media::Media() {
  //never should be called but vector might need it
}

Media::Media(int newidentity, char* newtitle, int newyear) {
  identity = newidentity;
  title = new char[80];
  strcpy(title, newtitle);
  year = newyear;
}

Media::~Media() {
  delete title;
  //free(title);
  //year is not a pointer
}

char* Media::getTitle() {
  return title;
}

int Media::getYear() {
  return year;
}

int Media::getIdentity() {
  return identity;
}
