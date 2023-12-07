#include "my_lib.h"

void vidurkis(Studentas &temp){
    double vidurkis = accumulate(temp.Pazymiai.begin(), temp.Pazymiai.end(), 0.0) / temp.Pazymiai.size();
    temp.Galutinis = 0.4 * vidurkis + 0.6 * temp.Egzaminas;
}

void mediana(Studentas &temp) {
    list<int> laikina(temp.Pazymiai.begin(), temp.Pazymiai.end());
    laikina.sort();
    int size = laikina.size();
    
    if (size % 2 == 0){ 
        auto it1 = std::next(laikina.begin(), size/2 - 1);
        auto it2 = std::next(laikina.begin(), size/2);
        temp.mediana = static_cast<double>(*it1 + *it2) / 2;
    }
    else{
        auto it = std::next(laikina.begin(), size/2);
        temp.mediana = *it;
    }
}
