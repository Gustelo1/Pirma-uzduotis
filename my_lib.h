#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <limits> 
#include <cstdio>
#include <numeric>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::right;
using std::setw;
using std::setprecision;
using std::string;
using std::copy;
using std::vector;
using std::accumulate;
using std::ios;
using std::istringstream;
using std::fstream;
using std::ws;

using namespace std;

struct Studentas {
    string Vardas, Pavarde;
    vector <int> Pazymiai;
    int Egzaminas;
    double Galutinis;
    double mediana;
};
void skaitytiIsFailo(const std::string& filename, std::vector<Studentas>& studentai);
void vidurkis(Studentas &temp);
void mediana(Studentas &temp);
void spausdVidurki(Studentas &temp);
void spausdMediana(Studentas &temp);