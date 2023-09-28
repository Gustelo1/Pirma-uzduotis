#include "my_lib.h"
void spausdVidurki(Studentas &temp){
    
    printf("%-10s%-15s%-10.2f\n", temp.Vardas.c_str(), temp.Pavarde.c_str(), temp.Galutinis, "");
}
  
void spausdMediana(Studentas &temp){
    printf("%-10s%-15s%-10s%-10.2f\n", temp.Vardas.c_str(), temp.Pavarde.c_str(), "", temp.mediana);
}