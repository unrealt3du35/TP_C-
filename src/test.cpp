#include <stdio.h>
#include "Dvector.h"
#include <assert.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "ParkMiller.h"
#include "GenerateurParkMiller.h"

using namespace std;
int main( int argc, const char* argv[] )
{
  ParkMiller p(3);
  GenerateurParkMiller g(p);
  g.gen_tab(10);
  cout<<endl;
  g.reset_seed();
  g.gen_tab(10);

}
