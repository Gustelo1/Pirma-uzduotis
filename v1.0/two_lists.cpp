#include "my_lib.h"
#include <chrono>
#include <list>

void sortStudents(list<Studentas>& studentai, list<Studentas>& smartStudents, list<Studentas>& stupidStudents) {
    for (const auto& student : studentai) {
        if (student.Galutinis >= 5.0) {
            smartStudents.push_back(student);
        } else {
            stupidStudents.push_back(student);
        }
    }
}


int main() {
    Studentas temp;
    list<Studentas> studentai;
    list<Studentas> smartStudents, stupidStudents;
    const std::string FILENAMES[] = {"students_1000.txt", "students_10000.txt", "students_100000.txt", "students_1000000.txt", "students_10000000.txt"};
    for(const std::string& filename : FILENAMES){
        studentai.clear();
        smartStudents.clear();
        stupidStudents.clear();
        cout << "Failas: " + std::string(filename) << endl;
        auto startRead = std::chrono::high_resolution_clock::now();
        skaitytiIsFailo(filename, studentai);
        auto endRead = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationRead = endRead - startRead;
        std::cout << "Time taken: " << durationRead.count() << " seconds for opening file" << std::endl;

        auto startSort = std::chrono::high_resolution_clock::now();
        sortStudents(studentai, smartStudents, stupidStudents);
        auto endSort = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationSort = endSort - startSort;
        std::cout << "Time taken: " << durationSort.count() << " seconds for sorting students" << std::endl;


    }

    return 0;
}
