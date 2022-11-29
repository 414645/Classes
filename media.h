#include <iostream>

using namespace std;

class Media {
public:
  Media(char*, int);
  char* getTitle();
  int getYear();
private:
  char* title;
  int year;
};
