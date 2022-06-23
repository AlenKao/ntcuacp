#ifndef HARDWARE_H
#define HARDWARE_H

#include <string>
using namespace std;

class Hardware {
public:
    Hardware(int = -1, const string& = "unassigned", int = 0, double = 0.0);

    void setId(int);
    int getId() const;

    void setToolName(string);
    string getToolName() const;

    void setQuantity(int);
    int getQuantity() const;

    void setPrice(double);
    double getPrice() const;

private:
    int id;
    char toolName[20];
    int quantity;
    double price;
};

#endif