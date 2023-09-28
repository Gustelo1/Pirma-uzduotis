#include "my_lib.h"

void pildymas(Studentas &temp, vector<Studentas> &studentai){
    char generuoti = 'n';
    char v;
    int n = 0;
    int x; 
    cout <<" Kiek norite ivesti studentu?" << endl;
    cin >> n;
    for (int k=0; k<n; k++){
    temp.Pazymiai.clear();
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
    char skaitymas = 'n';
    cout << "Ar norite skaityti duomenis is failo (Y), ar rasyti pats (N)?"<< endl;
    cin >> skaitymas;
    if (skaitymas == 'y' || skaitymas == 'Y'){
        skaitytiIsFailo("duomenys.txt", studentai);
    }
    else{
    pildymas(temp, studentai);
    }
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
    
