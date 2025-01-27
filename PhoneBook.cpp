#include "PhoneBook.hpp"
#include <limits>

/*== IMPLEMENTASI CONTACT ==*/
/* ctor, cctor, dtor, oper= */
Contact::Contact() {
    nama = "";
    tempat_tinggal = "";
    alamat = "";
    kekuatan = "";
}

Contact::Contact(string temp_nama, string temp_tempat_tinggal, string temp_alamat, string temp_kekuatan) {
    nama = temp_nama;
    tempat_tinggal = temp_tempat_tinggal;
    alamat = temp_alamat;
    kekuatan = temp_kekuatan;
}

Contact::Contact(const Contact& other)
    : nama(other.nama), tempat_tinggal(other.tempat_tinggal), alamat(other.alamat), kekuatan(other.kekuatan) {}

Contact::~Contact() {}

Contact& Contact::operator=(const Contact& other) {
    if (this != &other) {
        nama = other.nama;
        tempat_tinggal = other.tempat_tinggal;
        alamat = other.alamat;
        kekuatan = other.kekuatan;
    }
    return *this;
}

/* Metode-metode getter */
string Contact::getNama() {return nama;}
string Contact::getTempatTinggal() {return tempat_tinggal;}
string Contact::getAlamat() {return alamat;}
string Contact::getKekuatan() {return kekuatan;}

/* Metode-metode setter */
void Contact::setNama(string nama) {this->nama = nama;}
void Contact::setTempatTinggal(string tempat_tinggal) {this->tempat_tinggal = tempat_tinggal;}
void Contact::setAlamat(string alamat) {this->alamat = alamat;}
void Contact::setKekuatan(string kekuatan) {this->kekuatan = kekuatan;}

/*== IMPLEMENTASI PHONEBOOK ==*/
/* ctor, cctor, dtor, oper= */

PhoneBook::PhoneBook() : current_index(0) {}

PhoneBook::PhoneBook(const PhoneBook& other) {
    current_index = other.current_index;
    for (int i = 0; i < 8; ++i) {
        buffer[i] = other.buffer[i];
    }
}

PhoneBook::~PhoneBook() {}

PhoneBook& PhoneBook::operator=(const PhoneBook& other) {
    if (this != &other) {
        current_index = other.current_index;
        for (int i = 0; i < 8; ++i) {
            buffer[i] = other.buffer[i];
        }
    }
    return *this;
}

/* Metode-metode setter */
void PhoneBook::setContact(int index, Contact contact) {
    if (index >= 0 && index < 8) {buffer[index] = contact;}
}

/* Metode-metode getter */
Contact PhoneBook::getContact(int index) {
    if (index >= 0 && index < 8) {return buffer[index];}
    return Contact();
}

/* Fungsi-fungsi perintah */
void PhoneBook::addContact(Contact new_contact) {
    setContact(current_index, new_contact);
    current_index++;
    if (current_index >= 8) {
        current_index = 0;
    }
}

void PhoneBook::showAllContact() {
    cout << "Daftar Kontak:" << endl;
    for (int i = 0; i < 8; i++) {
        if (!buffer[i].getNama().empty()) {
            cout << i + 1 << ". " << buffer[i].getNama() << endl;
        }
    }
}

void PhoneBook::showSpecificContact(int index) {
    Contact& contact = buffer[index];
    if (!contact.getNama().empty()) {
        cout << "INFORMASI KONTAK" << endl;
        cout << "Nama: " << contact.getNama() << endl;
        cout << "Tempat Tinggal: " << contact.getTempatTinggal() << endl;
        cout << "Alamat: " << contact.getAlamat() << endl;
        cout << "Kekuatan: " << contact.getKekuatan() << endl;
    } else {
        cout << "Kontak kosong!" << endl;
    }
}

void PhoneBook::searchPhoneBook() {
    int index = -1;
    showAllContact();

    do {
        cout << "Kontak yang ingin diperiksa: ";
        cin >> index;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Input tidak valid! Masukkan angka antara 1 dan 8." << endl;
            index = -1;
        } else if (index <= 0 || index > 8) {
            cout << "Indeks tidak valid! Masukkan angka antara 1 dan 8." << endl;
            index = -1;
        }
    } while (index <= 0 || index > 8);

    showSpecificContact(index - 1);
}

void PhoneBook::inputNewContact() {
    string input;
    Contact new_contact; 
    cout << "Nama: "; cin.ignore(); getline(cin, input);
    new_contact.setNama(input);
    cout << "Tempat Lahir: "; getline(cin, input);
    new_contact.setTempatTinggal(input);
    cout << "Alamat: "; getline(cin, input);
    new_contact.setAlamat(input);
    cout << "Kekuatan: "; getline(cin, input);
    new_contact.setKekuatan(input);

    addContact(new_contact);
    cout << "Penambahan kontak berhasil!" << endl;
}