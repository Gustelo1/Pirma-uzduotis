#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <chrono>

const int NUM_FILES = 5;
const std::string FILENAMES[NUM_FILES] = {"students_1000.txt", "students_10000.txt", "students_100000.txt", "students_1000000.txt", "students_10000000.txt"};
const int NUM_RECORDS[NUM_FILES] = {1000, 10000, 100000, 1000000, 10000000};

std::string generateName(int index) {
    return "Vardas" + std::to_string(index) + " Pavarde" + std::to_string(index);
}

int skaicius;

void generateRandomStudentData(int numRecords, const std::string& filename) {
    std::ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        std::cerr << "Nepavyko atidaryti failo " << filename << " rasymui." << std::endl;
        return;
    }

    srand(time(0)); // Inicializuojame atsitiktinių skaičių generatorių


    outputFile << "Vardas" + std::string("   ") + "Pavarde" + std::string("       ");
    for(int i=0; i<skaicius; i++){ 
         outputFile << "ND" + std::to_string(i+1) + std::string("   ");
    } 
    outputFile << std::string("\n");

    for (int i = 0; i < numRecords; ++i) {
        outputFile << generateName(i+1) << std::string("       ");
        for(int i = 0; i < skaicius; i++){
            int pazymys = rand() % 10 + 1;
            outputFile << std::to_string(pazymys) + "     ";
        }
        outputFile << "\n";

    }

    outputFile.close();
}

int main() {
    std::cout << "Kiek nd norite sugeneruoti?" << std::endl;
    std::cin >> skaicius;
    for (int i = 0; i < NUM_FILES; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        generateRandomStudentData(NUM_RECORDS[i], FILENAMES[i]);
        std::cout << "Sukurtas failas " << FILENAMES[i] << " su " << NUM_RECORDS[i] << " įrašais." << std::endl;
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;
    }

    return 0;
}