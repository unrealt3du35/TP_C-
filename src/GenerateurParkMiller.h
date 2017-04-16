#ifndef GenerateurParkMiller_H
#define GenerateurParkMiller_H
#include "GenerateurNombreAleatoire.h"
#include "ParkMiller.h"

class GenerateurParkMiller : public GenerateurNombreAleatoire
{
  ParkMiller p;
  public :
  ~GenerateurParkMiller();
  GenerateurParkMiller(const GenerateurParkMiller &);
  GenerateurParkMiller & operator=(const GenerateurParkMiller &);
  GenerateurParkMiller(ParkMiller p);
  void  set_seed(int i);
  int  get_seed();
  void  reset_seed();
  int* gen_tab(int taille);
  //GenerateurParkMiller clone();
};


#endif
