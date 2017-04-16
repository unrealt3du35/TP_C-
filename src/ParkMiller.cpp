#include "ParkMiller.h"

ParkMiller::ParkMiller(int s){
  seed = s;
}

ParkMiller::ParkMiller(){
}


ParkMiller::~ParkMiller(){

}

ParkMiller & ParkMiller::operator =(const ParkMiller & p){
  seed=p.seed;
  return *this;
}


ParkMiller::ParkMiller(ParkMiller &source){
  seed = source.lire_seed();
}

int ParkMiller::lire_seed(){
  return seed;
}

int ParkMiller::gene(){
  seed = (16807*seed) % 2147483647;
  return seed;
}

void ParkMiller::set_seed(int s){
  seed = s;
}
