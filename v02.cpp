#include "my_lib.h"
#include <chrono>


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
    skaitytiIsFailo(filename, studentai);


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
