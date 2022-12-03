#ifndef Media_H
#define Media_H

#include <iostream>

using namespace std;

class Media {
public:
  Media();
  Media(char* newtitle, int newyear);
  ~Media(); //deconstructor delaration
  virtual char* getTitle();
  virtual int getYear();
protected:
  char* title;
  int year;
};

#endif
