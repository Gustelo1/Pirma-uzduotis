#include "my_lib.h"
#include "chrono"
void skaitytiIsFailo(const std::string& filename, std::vector<Studentas>& studentai) {
auto start = std::chrono::high_resolution_clock::now();
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open the file: " << filename << std::endl;
        return;
    }

    std::string line;
    std::getline(inputFile, line);

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        Studentas temp;
        if (!(iss >> temp.Vardas >> temp.Pavarde)) {
            std::cerr << "Error reading data from the file." << std::endl;
            inputFile.close();
            return;
        }

        int nd;
        std::vector<int> get;
        while (iss >> nd) {
            get.push_back(nd);
        }

        for (int i = 0; i < get.size() - 1; i++) {
            temp.Pazymiai.push_back(get[i]);
        }
        temp.Egzaminas = get.back();

        vidurkis(temp);
        mediana(temp);

        studentai.push_back(temp);
    }

    inputFile.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken: " << duration.count() << " seconds for reading file" << std::endl;
}
