#ifndef ParkMiller_H
#define ParkMiller_H



class ParkMiller{
int seed=3;
//int a = 16807;
//int m = 2147483647;
public:
~ParkMiller();
ParkMiller(int s);
ParkMiller();
ParkMiller(ParkMiller &);
ParkMiller & operator =(const ParkMiller &);
void set_seed(int s);
int lire_seed();
int gene();
};

#endif
