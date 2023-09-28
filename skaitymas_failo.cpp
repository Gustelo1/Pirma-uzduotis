#include "my_lib.h"
void skaitytiIsFailo(const std::string& filename, std::vector<Studentas>& studentai) {
    std::ifstream inputFile("duomenys.txt");
    if (inputFile.is_open()) {
        std::string line;
        std::getline(inputFile, line);
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            Studentas temp;
            iss >> temp.Vardas >> temp.Pavarde;
            int nd;
		    vector<int> get;
		    while (iss >> nd) {
			    get.push_back(nd);
		    }

            for (int i = 0; i < get.size() -1 ; i++) {
                temp.Pazymiai.push_back(get[i]);
            }
            temp.Egzaminas = get.back();

            vidurkis(temp);
            mediana(temp);

            studentai.push_back(temp);
        }
        inputFile.close();
    } else {
        std::cerr << "Unable to open the file." << std::endl;
    }
}