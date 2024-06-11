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

void registerAccount(map<string, Account>& accounts) { 
    clearScreen();
    string username, password;
    cout << "\n\n\n\n";
    cout << "	    Registrasi" << endl;
    cout << "	==================" << endl;
    cout << "	Masukkan username : ";
    cin >> username;
    cout << "	Masukkan password : ";
    cin >> password;
    accounts[username] = {username, password}; 
    cout << "	Akun berhasil dibuat!\n" << endl;

    cout << "	Tekan enter untuk melanjutkan! ";
    cin.ignore();
    cin.get();    
    clearScreen();
}
