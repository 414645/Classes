#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

Media::Media(char* newtitle, int newyear) {
  title = new char[80];
  int year;
  title = strcpy(title, newtitle);
  year = newyear;
}

char* Media::getTitle() {
  return title;
}

int Media::getYear() {
  return year;
}
