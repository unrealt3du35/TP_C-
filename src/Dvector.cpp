#include "Dvector.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <random>
#include <fstream>
#include <cstdint>
#include <cstring>

Dvector::Dvector(){
  dim=0;
  tab=NULL;
}

Dvector::Dvector(int t,double def){
  dim = t;
  tab = new double[dim];
  for(int i = 0;i<dim;i++){
    tab[i]=def;
  }
}

Dvector::Dvector(Dvector &source){
  dim = source.lireDim();
  tab = source.lireTab();
}

int Dvector::lireDim() const{
  return dim;
}

double* Dvector::lireTab(){
  return tab;
}


Dvector::~Dvector(){
  delete[] tab;
}

void Dvector:: display (std::ostream& str){
  str << std::fixed << std::setprecision(2); // voir si ça fixe pas indéfiniment !
  for(int i = 0;i<dim;i++){
      str<<tab[i]<<std::endl;
  }
}

int Dvector::size(){
  return dim;
}

void Dvector::fillRandomly(){
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_real_distribution<double> dist(0.0, 1.0);
  for(int i = 0;i<size();i++){
    tab[i]=dist(mt);
  }
}

Dvector::Dvector(std::string &s){
  std::ifstream fichier(s);
  dim = 0;
  if(fichier){
    std::string contenu;
    while(getline(fichier,contenu)){
      dim++;
    }
  } else {
    tab = new double[dim];
  }
  //tab = new double[dim-1];
  fichier.close();
  std::ifstream fichier1(s);
  int i=0;
  if(fichier1){
    std::string contenu;

    std::string::size_type sz;
    while(getline(fichier1, contenu)){
      double d = std::stod(contenu);
      tab[i]=d;
      i++;
    }
  }
  fichier1.close();
}

double& Dvector::operator()(int i){
  return tab[i];
}

Dvector& Dvector::operator=(const Dvector & v){ // verifier dim = 0 , et a = a
  dim=v.dim;
  tab=new double[dim];
  std::memcpy(tab,v.tab,dim*sizeof(double));
  return *this;

}

Dvector operator+( Dvector & v,double d){
  Dvector k(v.size());
  for (int i=0; i<v.size(); i++){
    k.lireTab()[i] = v.lireTab()[i] + d;
  }
  return k;
}

Dvector operator-( Dvector & v,double d){
  Dvector k(v.size());
  for (int i=0; i<v.size(); i++){
    k.lireTab()[i] = v.lireTab()[i] - d;
  }
  return k;
}

Dvector operator*( Dvector & v,double d){
  Dvector k(v.size());
  for (int i=0; i<v.size(); i++){
    k.lireTab()[i] = v.lireTab()[i] * d;
  }
  return k;
}

Dvector operator/( Dvector & v,double d){
  Dvector k(v.size());
  if (d==0){
    throw Dvector::Erreur();
  }
  for (int i=0; i<v.size(); i++){
    k.lireTab()[i] = v.lireTab()[i] / d;
  }
  return k;
}



Dvector operator+( Dvector & v,Dvector & w){
  Dvector k(v.size());
  if (k.lireDim() != v.lireDim()){
    throw Dvector::Erreur();
  }
  for (int i=0; i<v.size(); i++){
    k.lireTab()[i] = v.lireTab()[i] + w.lireTab()[i];
  }
  return k;
}


Dvector operator-( Dvector & v,Dvector & w){
  Dvector k(v.size());
  if (k.lireDim() != v.lireDim()){
    throw Dvector::Erreur();
  }
  for (int i=0; i<v.size(); i++){
    k.lireTab()[i] = v.lireTab()[i] - w.lireTab()[i];
  }
  return k;
}


Dvector operator-( Dvector & v){
  Dvector k(v.size());
  for (int i=0; i<v.size(); i++){
    k.lireTab()[i] = -v.lireTab()[i];
  }
  return k;
}

std::ostream & operator <<(std::ostream &out, Dvector & v){
  out<<"Dvector : ";
  for(int i =0; i<v.lireDim(); i++){
    out<<v.lireTab()[i]<<" ";
  }
  out<<std::endl;
  return out;
}




std::istream & operator >>(std::istream &in, Dvector &v){
  for(int i =0; i<v.lireDim(); i++){
    in>>v.lireTab()[i];
  }
  return in;
}

Dvector & Dvector::operator += (const Dvector & v){
  Dvector &k=*this;
  if (k.lireDim() != v.lireDim()){
    throw Erreur();
  }
  for(int i =0;i<v.dim;i++){
    k.tab[i]+=v.tab[i];
  }
  return k;
}

Dvector & Dvector::operator += (double d){
  Dvector &k=*this;
  for(int i =0;i<k.dim;i++){
    k.tab[i]+=d;
  }
  return k;
}


Dvector & Dvector::operator *= (double d)
{
  Dvector &k=*this;
  for(int i =0;i<k.dim;i++){
    k.tab[i]*=d;
  }
  return k;
}


Dvector & Dvector ::operator /= (double d)
{
  Dvector &k=*this;
  if (d==0){
    throw Erreur();
  }
  for(int i =0;i<k.dim;i++){
    k.tab[i]/=d;
  }
  return k;
}


Dvector & Dvector ::operator -= ( const Dvector & v)
{
  Dvector &k=*this;
  if (k.lireDim() != v.lireDim()){
    throw Erreur();
  }
  for(int i =0;i<v.dim;i++){
    k.tab[i]-=v.tab[i];
  }
  return k;
}

Dvector & Dvector::operator -= (double d){
  Dvector &k=*this;
  for(int i =0;i<k.dim;i++){
    k.tab[i]-=d;
  }
  return k;
}


bool Dvector::operator == (Dvector & v){
  Dvector &k=*this;
  if (k.lireDim() != v.lireDim()){
    throw Erreur();
  }
  bool eg = true;
  for(int i =0;i<k.dim;i++){
    eg = eg && (k.lireTab()[i]==v.lireTab()[i]);
  }
  return eg;
}

void Dvector::resize(int dime, double n){
  Dvector &k=*this;
  Dvector w(dime);
  if (k.lireDim()>=dime){
    for(int i =0;i<w.lireDim();i++){
      w.lireTab()[i]=k.lireTab()[i];
    }
  } else {
    for(int i =0;i<k.lireDim();i++){
      w.lireTab()[i]=k.lireTab()[i];
    }
    for (int j=k.lireDim(); j<w.lireDim(); j++){
      w.lireTab()[j]=n;
    }
  }
  k = w;
}
