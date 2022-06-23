#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

#include "Person.h"

using namespace std;

void init();
void listAll(fstream&);
void updateRecord(fstream&);
void deleteRecord(fstream&);

int main () {
    while (1) {
        char cmd;
        cout << "Should the file be initialized (Y or N): ";
        cin >> cmd;

        if (cmd == 'y' || cmd == 'Y') {
            init();
            break;
        } else if (cmd == 'n' || cmd == 'N') {
            break;
        }
    }

    int cmd = 0;
    fstream file("nameage_info.dat", ios::in|ios::out|ios::binary);
    while (cmd != 4) {
        cout << "Enter a choice:\n"
            << "1.  List all tools.\n"
            << "2.  Update record.\n"
            << "3.  Delete record.\n"
            << "4.  End program.\n"
            << "?";
        cin >> cmd;

        switch(cmd) {
            case 1:
                listAll(file);
                break;
            case 2:
                updateRecord(file);
                break;
            case 3:
                deleteRecord(file);
                break;
        }
    }
    return 0;
}

void clearfile(fstream &f) {
    for (int i=0; i<100; i++) {
        Person p;
        f.seekp(i * sizeof(Person));
        f.write(reinterpret_cast<char*>(&p), sizeof(Person));
    }
}

void setRecord(fstream &f, int id, Person &p) {
    int pos = id * sizeof(Person);
    f.clear();
    f.seekp(pos);
    f.write(reinterpret_cast<char*>(&p), sizeof(Person));
}

Person getRecord(fstream &f, int id) {
    int pos = id * sizeof(Person);
    Person p;
    f.clear();
    f.seekp(pos);
    f.read(reinterpret_cast<char*>(&p), sizeof(Person));
    return p;
}

void init() {
    fstream file("nameage_info.dat", ios::out|ios::binary);
    clearfile(file);

    while (1) {
        int id = 0, age;
        string ln, fn;
        cout << "Enter the number of id (0 - 99, -1 to end input): ";
        cin >> id;
        if (id == -1) {
            break;
        } else if (id < 0 || id >99) {
            continue;
        } 

        cout << "Enter last name: ";
        getchar();
        getline(cin, ln);
        
        cout << "Enter first name: ";
        getline(cin, fn);

        cout << "Enter age: ";
        cin >> age;

        Person p{id, age, ln, fn};
        setRecord(file, id, p);
    }

    file.close();
    cout << "\n";
}

void updateRecord(fstream &f) {
    int id = 0, age;
    string fn, ln;

    cout << "Enter the number of id (0 - 99): ";
    cin >> id;
    while (id < 0 || id > 99) {
        cout << "Enter the number of id (0 - 99): ";
        cin >> id;
    }

    if (getRecord(f, id).getId() == -1) {
        cout << "NO info.\n";
    } else {
        cout << "Enter last name: ";
        getchar();
        getline(cin, ln);

        cout << "Enter first name: ";
        getline(cin, fn);

        cout << "Enter age: ";
        cin >> age;

        Person p{id, age, ln, fn};
        setRecord(f, id, p);
    }
    cout << "\n";
}

void deleteRecord(fstream &f) {
    int id = 0;
    cout << "Enter the number of id (0 - 99): ";
    cin >> id;
    while (id < 0 || id > 99) {
        cout << "Enter the number of id (0 - 99): ";
        cin >> id;
    }

    Person p;
    setRecord(f, id, p);
    cout << "\n";
}

void print(const Person& p) {
    string name = p.getLastName() + "-" + p.getFirstName();
    cout << left << setw(6) << p.getId();
    cout << setw(20) << name;
    cout << setw(3) << p.getAge() << "\n";
}

void listAll(fstream& f) {
    cout << "Id#   Name                Age\n";

    Person p;
    f.clear();
    f.seekg(0, ios::beg);
    f.read(reinterpret_cast<char*>(&p), sizeof(Person));
    bool iseof = f.eof();
    while (!iseof) {
        if (p.getId() != -1) {
            print(p);
        }
        f.read(reinterpret_cast<char*>(&p), sizeof(Person));
        iseof = f.eof();
    }
    cout << "\n";
}