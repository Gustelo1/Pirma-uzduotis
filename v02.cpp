#include "my_lib.h"
#include <chrono>

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

void sortStudents(vector<Studentas>& students, vector<Studentas>& smartStudents, vector<Studentas>& stupidStudents) {
    for (const auto& student : students) {
        if (student.Galutinis > 5.0) {
            smartStudents.push_back(student);
        } else {
            stupidStudents.push_back(student);
        }
    }
}

void saveStudentsToFile(const vector<Studentas>& students, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& student : students) {
            file << student.Vardas << " " << student.Pavarde << " - Vidurkis: " << student.Galutinis << endl;
        }
        file.close();

    } else {
        cout << "Unable to open file " << filename << endl;
    }
}

int main() {
    Studentas temp;
    vector<Studentas> studentai;
    vector<Studentas> smartStudents, stupidStudents;
    const std::string FILENAMES[] = {"students_1000.txt", "students_10000.txt", "students_100000.txt", "students_1000000.txt", "students_10000000.txt"};
    for(const std::string& filename : FILENAMES){

    cout << "Failas: " + std::string(filename) << endl;
    skaitytiIsFailo("students_100000.txt", studentai);


    temp.Pazymiai.clear();
    auto startSort = std::chrono::high_resolution_clock::now();
    sortStudents(studentai, smartStudents, stupidStudents);
    auto endSort = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationSort = endSort - startSort;
    std::cout << "Time taken: " << durationSort.count() << " seconds for sorting students" << std::endl;

    auto startSmart = std::chrono::high_resolution_clock::now();
    saveStudentsToFile(smartStudents, "smart_students.txt");
    auto endSmart = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationSmart = endSmart - startSmart;
    std::cout << "Time taken: " << durationSmart.count() << " seconds for saving smart students" << std::endl;

    auto startStupid = std::chrono::high_resolution_clock::now();
    saveStudentsToFile(stupidStudents, "stupid_students.txt");
    auto endStupid = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationStupid = endStupid - startStupid;
    std::cout << "Time taken: " << durationStupid.count() << " seconds for saving stupid students" << std::endl;
    }
    return 0;
}
