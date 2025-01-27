#include <iostream>
using namespace std;

class Contact {
    public:
    /* ctor, cctor, dtor, oper= */
    Contact();
    Contact(string, string, string, string);
    Contact(const Contact&);
    ~Contact();
    Contact& operator=(const Contact&);

    /* getter & setter */
    string getNama();
    string getTempatTinggal();
    string getAlamat();
    string getKekuatan();
    void setNama(string);
    void setTempatTinggal(string);
    void setAlamat(string);
    void setKekuatan(string);

    private:
    string nama, tempat_tinggal, alamat, kekuatan;
};

class PhoneBook {
    public:
    /* ctor, cctor, dtor, oper= */
    PhoneBook();
    PhoneBook(const PhoneBook&);
    ~PhoneBook();
    PhoneBook& operator=(const PhoneBook&);

    /* getter & setter */
    void setContact(int, Contact);
    Contact getContact(int);

    /* intermediate methods */
    void addContact(Contact);
    void showAllContact();
    void showSpecificContact(int);

    /* methods meminta input user */
    void searchPhoneBook();
    void inputNewContact();
    
    private:
    int current_index = 0;
    Contact buffer[8];
};