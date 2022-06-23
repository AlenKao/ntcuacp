#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

#include "Hardware.h" 

using namespace std;

void init();
void listAll(fstream&);
void updateRecord(fstream&);
void insertRecord(fstream&);
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
    fstream hwfile("hardware_info.dat", ios::in|ios::out|ios::binary);
    while (cmd != 5) {
        cout << "Enter a choice:\n"
            << "1.  List all tools.\n"
            << "2.  Update record.\n"
            << "3.  Insert record.\n"
            << "4.  Delete record.\n"
            << "5.  End program.\n"
            << "?";
        cin >> cmd;

        switch(cmd) {
            case 1: 
                listAll(hwfile);
                break;
            case 2:
                updateRecord(hwfile);
                break;
            case 3:
                insertRecord(hwfile);
                break;
            case 4:
                deleteRecord(hwfile);
                break;
        }
    }
    return 0;
}

void clearFile(fstream& f) {
    for (int i=0; i<100; i++) {
        Hardware hw;
        f.seekp(i * sizeof(Hardware));
        f.write(reinterpret_cast<char*>(&hw), sizeof(Hardware));
    }
}

void setRecord(fstream &f, int num, Hardware &h) {
    int pos = num * sizeof(Hardware);
    f.clear();
    f.seekp(pos);
    f.write(reinterpret_cast<const char*>(&h), sizeof(Hardware));
}

Hardware getRecord(fstream& f, int num) {
    int pos = num * sizeof(Hardware);
    Hardware hw;
    f.clear();
    f.seekp(pos);
    f.read(reinterpret_cast<char*>(&hw), sizeof(Hardware));
    return hw;
}

void init() {
    fstream file("hardware_info.dat", ios::out|ios::binary);
    clearFile(file);

    while (1) {
        int num = 0, quantity;
        double price;
        string name;
        cout << "Enter the part number (0 - 99, -1 to end input): ";
        cin >> num;
        if (num == -1) {
            break;
        } else if (num < 0 || num > 99) {
            continue;
        }

        cout << "Enter the tool name : ";
        getchar();
        getline(cin, name);

        cout << "Enter quantity and price: ";
        cin >> quantity >> price;

        Hardware hw(num, name, quantity, price);
        setRecord(file, num, hw);
    }

    file.close();
    cout << "\n";
}

void print(const Hardware& hw) {
    cout << left << setw(12) << hw.getId();
    cout << setw(25) << hw.getToolName();
    cout << setw(13) << hw.getQuantity();
    cout << fixed << setprecision(2) << hw.getPrice() << "\n";
}

void listAll(fstream& f) {
    cout << "Record#     Tool name                Quantity     cost\n";

    Hardware hw;
    f.clear();
    f.seekg(0, ios::beg);
    f.read(reinterpret_cast<char*>(&hw), sizeof(Hardware));
    bool iseof = f.eof();
    while (!iseof) {
        if (hw.getId() != -1) {
            print(hw);
        }
        f.read(reinterpret_cast<char*>(&hw), sizeof(Hardware));
        iseof = f.eof();
    }
    cout << "\n";
}

void updateRecord(fstream& f) {
    int num = 0, quantity;
    string name;
    double price;

    cout << "Enter the part number (0 - 99): ";
    cin >> num;
    while (num < 0 || num >99) {
        cout << "Enter tht part number (0 - 99): ";
        cin >> num;
    }

    if (getRecord(f, num).getId() == -1) {
        cout << "No information.\n";
    } else {
        cout << "Enter the tool name: ";
        getchar();
        getline(cin, name);

        cout << "Enter quantity and price: ";
        cin >> quantity >> price;


        Hardware hw{num, name, quantity, price};
        setRecord(f, num, hw);
    }
    cout << "\n";
}

void insertRecord(fstream& f) {
    int num = 0, quantity;
    double price;
    string name;

    cout << "Enter the part number (0 - 99): ";
    cin >> num;

    while (num < 0 || num > 99) {
        cout << "Enter the part number (0 - 99): ";
        cin >> num;
    }

    cout << "Enter the tool name: ";
    getchar();
    getline(cin, name);

    cout << "Enter quantity and price: ";
    cin >> quantity >> price;

    Hardware hw{num, name, quantity, price};
    setRecord(f, num, hw);
    cout << "'\n'";
}

void deleteRecord(fstream& f) {
    int num = 0;
    cout << "Enter the part number (0 - 99): ";
    cin >> num;
    while (num < 0 || num > 99) {
        cout << "Enter the part number (0 - 99): ";
        cin >> num;
    }

    Hardware hw;
    setRecord(f, num, hw);
    cout << "\n";
}