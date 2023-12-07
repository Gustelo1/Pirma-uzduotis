#include "my_lib.h"

void vidurkis(Studentas &temp){
double vidurkis = accumulate(temp.Pazymiai.begin(), temp.Pazymiai.end(), 0.0) / temp.Pazymiai.size();
temp.Galutinis = 0.4 * vidurkis + 0.6 * temp.Egzaminas;
}

void mediana(Studentas &temp) {
    vector <int> laikina;
    int size = temp.Pazymiai.size();
    laikina = temp.Pazymiai;
    sort(laikina.begin(), laikina.end());
    if (size % 2 == 0){ 
        temp.mediana = static_cast<double>(laikina[size/2] + laikina[size/2-1]) /2;
    }
    else{
        temp.mediana = laikina[size/2];
    }
}
