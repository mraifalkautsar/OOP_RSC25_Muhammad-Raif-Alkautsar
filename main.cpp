#include "PhoneBook.hpp"

int main() {
    const string yellow = "\033[33m";       // teks kuning
    const string light_blue = "\033[94m";   // teks biru muda
    const string reset = "\033[0m";         // reset warna
    PhoneBook book;
    string input = " ";
    cout << yellow;
    cout << "Opsi yang tersedia:" << endl;
    cout << "ADD -- Menambahkan kontak ke buku." << endl;
    cout << "SEARCH -- Menampilkan semua kontak dan memilih salah satu secara spesifik." << endl;
    cout << "EXIT -- Keluar dari program." << endl; 
    cout << reset;

    while (true) {
        cout << light_blue;
        cout << "Masukkan input: ";
        cout << reset;
        cin >> input;
        
        if (input == "ADD") {
            book.inputNewContact();
        }
        else if (input == "SEARCH") {
            book.searchPhoneBook();
        }
        else if (input == "EXIT") {
            break;
        }
        else {
            cout << "Masukan salah!";
        }

        cout << light_blue;
        cout << "Opsi yang tersedia: ADD, SEARCH, EXIT." << endl;
        cout << reset;
    }

    return 0;
}