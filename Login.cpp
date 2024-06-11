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

bool login(map<string, Account>& accounts, string& username) { 
    clearScreen();
    string password;
    cout << "\n\n\n\n";
    cout << "	    Login" << endl;
    cout << "	=============" << endl;
    cout << "	Masukkan username : ";
    cin >> username;
    cout << "	Masukkan password : ";
    cin >> password;
    if (accounts.find(username) != accounts.end() && accounts[username].password == password) { 
        cout << "	Login berhasil! \n" << endl;
        
        cout << "	Tekan enter untuk melanjutkan!";
    	cin.ignore();  
    	cin.get();
        return true;
    }
    cout << "	Username atau password salah. Silakan coba lagi. \n" << endl;
    
    cout << "	Tekan enter untuk melanjutkan!";
    cin.ignore();  
    cin.get(); 
    
    clearScreen();
    return false;
    
}