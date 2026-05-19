#include <iostream>
#include "Dyhotomia_class.h"
#include <windows.h>
#include <cmath>

using namespace std;

int main(){

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    Dyhotomia_class dyh;
    dyh.setVolums(-1, 1);
    dyh.setTolerance(1e-9);
    cout << "Метод дихотомії: " << dyh.Dyhotomia() << endl;
    cout << "Метод Ньютона: " << dyh.Newtonmet() << endl;
    
    return 0;
}