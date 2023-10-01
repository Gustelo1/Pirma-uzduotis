#include "my_lib.h"

void pildymas(Studentas& temp, vector<Studentas>& studentai) {
    char generuoti = 'n';
    int n = 0;
    int x;
    cout << "Kiek norite ivesti studentu?" << endl;
    while (!(cin >> n) || n <= 0) {
        cout << "Klaida. Iveskite teigiama skaiciu: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    for (int k = 0; k < n; k++) {
        temp.Pazymiai.clear();
        cout << "Iveskite varda ir pavarde" << endl;
        cin >> temp.Vardas >> temp.Pavarde;
        cout << "Ar norite sugeneruoti nd pazymius? Jei taip - Y, jei ne - N" << endl;
        while (!(cin >> generuoti) || (generuoti != 'Y' && generuoti != 'y' && generuoti != 'N' && generuoti != 'n')) {
            cout << "Klaida. Iveskite Y arba N: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (generuoti == 'Y' || generuoti == 'y') {
            cout << "Kiek pazymiu uz namu darbus norite sugeneruoti?" << endl;
            while (!(cin >> x) || x <= 0) {
                cout << "Klaida. Iveskite teigiama skaiciu: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            for (int i = 0; i < x; i++) {
                int pazymys = rand() % 10 + 1;
                temp.Pazymiai.push_back(pazymys);
            }
            temp.Egzaminas = rand() % 10 + 1;
        }
        else if (generuoti == 'N' || generuoti == 'n') {
            cout << "Iveskite egzamino paz." << endl;
            while (!(cin >> temp.Egzaminas) || temp.Egzaminas < 0 || temp.Egzaminas > 10) {
                cout << "Klaida. Iveskite skaiciu nuo 0 iki 10: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Iveskite studento pazymius, jei pazymiu nebera, iveskite raide: " << endl;
            float x;
            while (cin >> x) {
                if (x < 0 || x > 10) {
                    cout << "Klaida. Iveskite skaiciu nuo 0 iki 10: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    temp.Pazymiai.push_back(x);
                }
            }
        }
        vidurkis(temp);
        mediana(temp);
        studentai.push_back(temp);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    Studentas temp;
    vector<Studentas> studentai;
    char uzkl = 'n';
    char generuoti = 'y';
    char pasirinkimas = 'm';
    char skaitymas = 'n';

    cout << "Ar norite skaityti duomenis is failo (Y), ar rasyti pats (N)?" << endl;

    while (!(cin >> skaitymas) || (skaitymas != 'y' && skaitymas != 'Y' && skaitymas != 'n' && skaitymas != 'N')) {
        cout << "Klaida. Iveskite Y arba N: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (skaitymas == 'y' || skaitymas == 'Y') {
        skaitytiIsFailo("duomenys.txt", studentai);
    }
    else {
        pildymas(temp, studentai);
    }

    temp.Pazymiai.clear();

    cout << "Ar norite medianos (M) ar vidurkio (V)?" << endl;

    while (!(cin >> pasirinkimas) || (pasirinkimas != 'm' && pasirinkimas != 'M' && pasirinkimas != 'v' && pasirinkimas != 'V')) {
        cout << "Klaida. Iveskite M arba V: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    printf("%-10s%-15s%-10s%-10s%-10s\n", "Vardas", "Pavarde", "Vidurkis", "Mediana", "");
    for (int i = 0; i < 50; i++) {
        cout << "-";
    }
    cout << endl;

    if (pasirinkimas == 'm' || pasirinkimas == 'M') {
        for (auto &i : studentai) {
            spausdMediana(i);
        }
    }
    else {
        for (auto &i : studentai) {
            spausdVidurki(i);
        }
    }

    return 0;
}
