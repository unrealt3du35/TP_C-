#include "GenerateurParkMiller.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <fstream>
#include <cstdint>
#include <cstring>

GenerateurParkMiller::~GenerateurParkMiller(){
}

GenerateurParkMiller & GenerateurParkMiller::operator=(const GenerateurParkMiller & g){
  p = g.p;
  return *this;
}


void GenerateurParkMiller::set_seed(int i){
  p.set_seed(i);
}

void GenerateurParkMiller::reset_seed(){
  p.set_seed((16807*(p.lire_seed()-(p.lire_seed()/127773)*127773) - 2836*(p.lire_seed()/127773)*127773)%2147483647);
}

int GenerateurParkMiller::get_seed(){
  return p.lire_seed();
}

int* GenerateurParkMiller::gen_tab(int taille){
  int * tab = new int[taille];
  for(int i = 0;i<taille;i++){
    tab[i]=p.gene();
    std::cout<<tab[i]<<std::endl;
  }
  return tab;
}

GenerateurParkMiller::GenerateurParkMiller(ParkMiller par){
  p = par;
}

GenerateurParkMiller::GenerateurParkMiller(const GenerateurParkMiller & g){
  p = g.p;
}

/*GenerateurParkMiller GenerateurParkMiller::clone(){
  return new GenerateurParkMiller(*this);
}
*/
