#ifndef GenerateurNombreAleatoire_H
#define GenerateurNombreAleatoire_H
#include <iostream>
#include <string>
#include <exception>

class GenerateurNombreAleatoire {
int dim;
public:
/*~GenerateurNombreAleatoire();
GenerateurNombreAleatoire(const GenerateurNombreAleatoire &);
//virtual GenerateurNombreAleatoire clone();
//GenerateurNombreAleatoire & operator=(const GenerateurNombreAleatoire &);
 GenerateurNombreAleatoire(int d);*/
//GenerateurNombreAleatoire();
int liredim() const;
virtual void  set_seed(int i) = 0;
virtual int  get_seed() = 0;
virtual void  reset_seed() = 0;
virtual int* gen_tab(int taille) =0 ;
};

#endif
