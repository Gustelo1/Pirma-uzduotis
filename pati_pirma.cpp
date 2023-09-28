#include  "my_lib1.h"

struct Studentas {
    string Vardas, Pavarde;
    vector <int> Pazymiai;
    int Egzaminas;
    double Galutinis;
    double mediana;
};

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

void spausdMediana(Studentas &temp){
    printf("%-10s%-15s%-10s%-10.2f\n", temp.Vardas.c_str(), temp.Pavarde.c_str(), "", temp.mediana);
}

void spausdVidurki(Studentas &temp){
    
    printf("%-10s%-15s%-10.2f\n", temp.Vardas.c_str(), temp.Pavarde.c_str(), temp.Galutinis, "");
}

int main() {
    int n;
    Studentas temp;
    vector <Studentas> studentai;
    cout << "Kiek studentu ivesite?" <<endl;
    cin >> n;
    for (int i=0; i<n; i++){
        cout <<"Iveskite varda ir pavarde"<<endl;
        cin >> temp.Vardas >> temp.Pavarde;
        cout << "Kiek pazymiu jis turi?" << endl;
        int m;
        cin >> m;
        for (int j=0; j<m; j++){
            int paz;
            cout << "Iveskite" <<j+1<< "pazymi"<<endl;
            cin >> paz;
            temp.Pazymiai.push_back(paz);
        }
        cout << "Iveskite egzamino pazymi" <<endl;
        cin >> temp.Egzaminas;
        vidurkis(temp);
        mediana(temp);
        studentai.push_back(temp);
        temp.Pazymiai.clear();
        
    }
    char pasirinkimas = 'm';
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