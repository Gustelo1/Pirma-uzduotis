#include "my_lib1.h"

struct Studentas {
    string Vardas, Pavarde;
    vector <int> Pazymiai;
    int Egzaminas;
    double Galutinis;
    double mediana;
};

void spausdVidurki(Studentas &temp){
    
    printf("%-10s%-15s%-10.2f\n", temp.Vardas.c_str(), temp.Pavarde.c_str(), temp.Galutinis, "");
}
  
void spausdMediana(Studentas &temp){
    printf("%-10s%-15s%-10s%-10.2f\n", temp.Vardas.c_str(), temp.Pavarde.c_str(), "", temp.mediana);
}

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


void pildymas(Studentas &temp, vector<Studentas> &studentai){
    char generuoti = 'n';
    int n = 0;
    int x; 
    cout <<" Kiek norite ivesti studentu?" << endl;
    cin >> n;
    for (int k=0; k<n; k++){
    cout <<"Iveskite varda ir pavarde"<<endl;
    cin >> temp.Vardas >> temp.Pavarde;
    cout << " Ar norite sugeneruoti nd pazymius? Jei taip - Y, jei ne - N" << endl;
    cin >> generuoti;
    if (generuoti == 'Y' || generuoti == 'y'){
    cout << "Kiek pazymiu uz namu darbus norite sugeneruoti?" <<endl;
    cin >> x;
    for (int i = 0; i<x; i++){
        int pazymys = rand() % 10 +1;
        temp.Pazymiai.push_back(pazymys);
    }
    temp.Egzaminas = rand() % 10 +1;
    }
    else if (generuoti == 'N' || generuoti == 'n')
    {
    cout<<"Iveskite egzamino paz."; 
    cin>>temp.Egzaminas; 
    cout << " Iveskite studento pazymius, jei pazymiu nebera, iveskite raide: " << endl;
    float x;
    while (cin>>x){
        if (x>10) {
            cout<< " Ivestas neteisingas pazymys, bandykite dar karta"<<endl;
        }
        else{
            temp.Pazymiai.push_back(x);
        }
    }
    }

    vidurkis(temp);
    mediana(temp);
    studentai.push_back(temp);
    cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
}

int main() {
    Studentas temp;
    vector <Studentas> studentai;
    char uzkl='n';
    char generuoti = 'y';
    char pasirinkimas = 'm';
    pildymas(temp, studentai);
    
        temp.Pazymiai.clear();
        cout << "Ar norite medianos (M) ar vidurkio (V)?" <<endl;
        cin >> pasirinkimas;
        printf("%-10s%-15s%-10s%-10s%-10s\n", "Vardas", "Pavarde", "Vidurkis", "Mediana", "");
        for (int i = 0; i < 50; i++) {
        cout << "-";
        }
        cout <<endl;
        if (pasirinkimas == 'm' || pasirinkimas == 'M'){
        for (auto &i : studentai){
        spausdMediana(i);
        }
        }
        else{
        for (auto &i : studentai){
        spausdVidurki(i);
     }
    }
    }
    
