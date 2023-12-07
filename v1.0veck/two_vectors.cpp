#include "my_lib.h"
#include <chrono>
#include <vector>

void sortStudents(std::vector<Studentas>& studentai, std::vector<Studentas>& smartStudents) {
    std::vector<Studentas> tempStudents;  
    for (auto it = studentai.begin(); it != studentai.end();) {
        if (it->Galutinis >= 5.0) {
            smartStudents.push_back(std::move(*it));
            it = studentai.erase(it);
        } else {
            ++it;
        }
    }
}



int main() {
    Studentas temp;
    std::vector<Studentas> studentai;
    std::vector<Studentas> smartStudents;
    const std::string FILENAMES[] = {"students_1000.txt", "students_10000.txt", "students_100000.txt", "students_1000000.txt", "students_10000000.txt"};

    for (const std::string& filename : FILENAMES) {
        studentai.clear();
        smartStudents.clear();
        std::cout << "Failas: " + filename << std::endl;

        auto startRead = std::chrono::high_resolution_clock::now();
        skaitytiIsFailo(filename, studentai);
        auto endRead = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationRead = endRead - startRead;
        std::cout << "Time taken: " << durationRead.count() << " seconds for opening file" << std::endl;

        auto startSort = std::chrono::high_resolution_clock::now();
        sortStudents(studentai, smartStudents);
        auto endSort = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationSort = endSort - startSort;
        std::cout << "Time taken: " << durationSort.count() << " seconds for sorting students" << std::endl;

    return 0;
}
}