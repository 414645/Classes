#include <iostream>
#include <cstring>
#include "music.h"

using namespace std;

Music::Music() {
  //never should be called but vectors might need it
}

Music::Music(int newidentity,
	     char* newtitle, int newyear,
	     char* newartist, char* newduration,
	     char* newpublisher
	     ):Media(newidentity, newtitle, newyear){
  
  artist = new char[80];
  duration  = new char[80];
  publisher = new char[80];
  strcpy(artist, newartist);
  strcpy(duration, newduration);
  strcpy(publisher, newpublisher);
}

Music::~Music() {
  delete artist;
  delete duration;
  delete publisher;
}

char* Music::getArtist() {
  return artist;
}

char* Music::getDuration() {
  return duration;
}

char* Music::getPublisher() {
  return publisher;
}
