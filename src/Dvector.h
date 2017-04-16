#ifndef Dvector_H
#define Dvector_H

#include <iostream>
#include <string>
#include <exception>



class Dvector
{
int dim;
double* tab;
public :

  class Erreur : public std::exception {
    public:
      virtual const char * what(void) const throw(){
        return "Erreur dans les vecteurs";
      }
  };

Dvector();
Dvector(int t,double def=0.0);
Dvector(Dvector &);
int lireDim() const;
double* lireTab();
~Dvector();
void display (std::ostream& str);
int size();
void fillRandomly();
Dvector(std::string &s);
double& operator()(int i);
Dvector & operator=(const Dvector & );

Dvector &operator += (const Dvector & v);
Dvector &operator += (double d);
Dvector &operator -= (const Dvector & v);
Dvector &operator -= (double d);
Dvector &operator *= (double d);
Dvector &operator /= (double d);
bool operator==(Dvector & v);
void resize(int dime, double n=0.0);

};

Dvector  operator+(Dvector & v,double d);
Dvector  operator-(Dvector & v,double d);
Dvector  operator*(Dvector & v,double d);
Dvector  operator/(Dvector & v,double d);

Dvector operator+(Dvector & v, Dvector & w);
Dvector operator-(Dvector & v, Dvector & w);

Dvector operator-(Dvector & v);


std::ostream & operator <<(std::ostream &, Dvector &);
std::istream & operator >>(std::istream &, Dvector &);


#endif
