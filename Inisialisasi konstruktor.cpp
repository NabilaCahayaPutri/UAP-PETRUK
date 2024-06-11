#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <cstdlib>

using namespace std;

enum CakeSize {
    Kecil,
    Besar
};

struct Cake {
    string name;  
    string flavor;  
    CakeSize size;
    double price;

    Cake(string n, string f, CakeSize s, double p) : name(n), flavor(f), size(s), price(p) {}
};

struct Account {
    string username; 
    string password; 
};

void clearScreen() {
    #if defined(_WIN32)
        system("cls");
    #else
        system("clear");
    #endif
}