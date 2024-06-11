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

void showCakeCatalog(const vector<Cake>& cakes) { 
    clearScreen();
	cout << "\n\n\n\n";
    cout << "========================================================================================================================\n";
    cout << "==============================================|     SELAMAT DATANG    |=================================================\n";
    cout << "==============================================|   TOKO HAMMER BAKERY  |=================================================\n";
    cout << "========================================================================================================================\n";
    cout << "\n\n\n\n";
    cout << "	Katalog Kue" << endl;
    cout << "	===========" << endl;
    for (const auto& cake : cakes) { 
        cout << "	Nama : " << cake.name << endl;
        cout << "	Ukuran : " << (cake.size == Kecil ? "Kecil" : "Besar") << endl;
        cout << "	Harga : Rp" << cake.price << endl <<endl;
    }
    cout << "	Tekan enter untuk melanjutkan!";
    cin.ignore();
    cin.get();
}

void showReceipt(const list<Cake>& cakes) { 
    clearScreen();
    cout << "\n\n\n\n";
    cout << "========================================================================================================================\n";
    cout << "==============================================|     SELAMAT DATANG    |=================================================\n";
    cout << "==============================================|   TOKO HAMMER BAKERY  |=================================================\n";
    cout << "========================================================================================================================\n";
    cout << "\n\n\n\n";
    cout << "	Struk Pembelian" << endl;
    cout << "	===============" << endl;
    double total = 0.0;
    for (const auto& cake : cakes) { 
        cout << "	Nama 	: " << cake.name << endl;
        cout << "	Rasa 	: " << cake.flavor << endl;
        cout << "	Ukuran 	: " << (cake.size == Kecil ? "Kecil" : "Besar") << endl;
        cout << "	Harga 	: Rp" << cake.price << endl;
        total += cake.price;
    }
    cout << endl;
    cout << "	Total : Rp" << total << endl << endl;
    
    cout << "	Tekan enter untuk melanjutkan!";
    cin.ignore(); 
    cin.get();  
}

void processOrder(vector<Cake>& cakes, list<Cake>& orderList) { 
    clearScreen();
    cout << "\n\n\n\n";
    cout << "========================================================================================================================\n";
    cout << "==============================================|     SELAMAT DATANG    |=================================================\n";
    cout << "==============================================|   TOKO HAMMER BAKERY  |=================================================\n";
    cout << "========================================================================================================================\n";
    cout << "\n\n\n\n";
    int choice;
    cout << "	Silakan pilih kue yang ingin Anda pesan (1-" << cakes.size() << "): ";
    cin >> choice;

    if (choice > 0 && choice <= cakes.size()) {
        Cake& cake = cakes[choice - 1];
        cout << "	Pilihan rasa kue :" << endl;
        cout << "	1. Vanilla" << endl;
        cout << "	2. Chocolate" << endl;
        cout << "	3. Strawberry" << endl;
        cout << "	4. Taro" << endl;
        cout << "	5. Keju" << endl;
        cout << " 	Silakan pilih rasa kue (1-5) : ";
        int flavorChoice;
        cin >> flavorChoice;
        switch (flavorChoice) {
            case 1:
                cake.flavor = "Vanilla";
                break;
            case 2:
                cake.flavor = "Chocolate";
                break;
            case 3:
                cake.flavor = "Strawberry";
                break;
            case 4:
                cake.flavor = "Taro";
                break;
            case 5:
                cake.flavor = "Keju";
                break;
            default:
                cout << "	Pilihan tidak valid." << endl;
                return;
        }
        cout << "	Silakan pilih ukuran kue (1 untuk Kecil, 2 untuk Besar): ";
        int sizeChoice;
        cin >> sizeChoice;
        if (sizeChoice == 1) {
            cake.size = Kecil;
        } else if (sizeChoice == 2) {
            cake.size = Besar;
        } else {
            cout << "	Pilihan tidak valid." << endl;
            return;
        }

        cout << "	Konfirmasi pemesanan? (y/n): ";
        char confirm;
        cin >> confirm;
        if (confirm == 'y') {
            orderList.push_back(cake);
            cout << "	Kue telah dipesan.\n" << endl;
        } else {
            cout << "	Pemesanan dibatalkan.\n" << endl;
        }
    	
    } else {
        cout << "	Pilihan tidak tersedia.\n" << endl << endl;
    }
    cout << "	Tekan enter untuk melanjutkan! ";
    cin.ignore();
    cin.get();
    
    clearScreen();
}

void showMainMenu() {
	
	cout << "\n\n\n\n";
    cout << "========================================================================================================================\n";
    cout << "==============================================|     SELAMAT DATANG    |=================================================\n";
    cout << "==============================================|   TOKO HAMMER BAKERY  |=================================================\n";
    cout << "========================================================================================================================\n";
    cout << "\n\n\n\n";
    cout << "	Menu Utama" << endl;
    cout << "	==========" << endl;
    cout << "	1. Registrasi" << endl;
    cout << "	2. Login" << endl;
    cout << "	3. Menampilkan katalog kue" << endl;
    cout << "	4. Memesan kue" << endl;
    cout << "	5. Keluar" << endl;
    cout << "	Pilih opsi: ";
}

void showLoginMenu() {
    clearScreen();
    cout << "\n\n\n\n";
    cout << "========================================================================================================================\n";
    cout << "==============================================|     SELAMAT DATANG    |=================================================\n";
    cout << "==============================================|   TOKO HAMMER BAKERY  |=================================================\n";
    cout << "========================================================================================================================\n";
    cout << "\n\n\n\n";
    cout << "	1. Menampilkan katalog kue" << endl;
    cout << "	2. Memesan kue" << endl;
    cout << "	3. Lihat struk pembelian" << endl;
    cout << "	4. Logout Akun" << endl;
    cout << "	Pilih opsi: ";
}