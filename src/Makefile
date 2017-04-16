CXX = g++
FLAGS = -std=c++11 -std=gnu++11


all :  Dvector.o GenerateurNombreAleatoire.o GenerateurParkMiller.o ParkMiller.o   test.o
	$(CXX) $(FLAGS) $^ -o test
#all :Dvector.o test.o
	#$(CXX) $(FLAGS) $^ -o test

Dvector.o :
	$(CXX) $(FLAGS) -c Dvector.cpp -o $@

GenerateurNombreAleatoire.o :
	$(CXX) $(FLAGS) -c GenerateurNombreAleatoire.cpp -o $@

GenerateurParkMiller.o :
	$(CXX) $(FLAGS) -c GenerateurParkMiller.cpp -o $@
ParkMiller.o:
	$(CXX) $(FLAGS) -c ParkMiller.cpp -o $@

test.o :
	$(CXX) $(FLAGS) -c test.cpp -o $@


clean:
		rm -rf *.o
