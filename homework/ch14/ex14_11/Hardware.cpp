#include <string>

#include "Hardware.h"

using namespace std;

Hardware::Hardware(int id, const string& name, int quantity, double price) 
: id{id}, quantity{quantity}, price{price} {
    setToolName(name);
}

void Hardware::setId(int id) {
    this->id = id;
}
int Hardware::getId() const {
    return id;
}

void Hardware::setToolName(string name) {
    int i;
    for (i=0; i<name.size(); i++) {
        toolName[i] = name[i];
    }
    toolName[i] = '\0';
}
string Hardware::getToolName() const {
    string name;
    for (int i=0; toolName[i]!='\0'; i++) {
        name += toolName[i];
    }
    return name;
}

void Hardware::setQuantity(int quantity) {
    this->quantity = quantity;
}
int Hardware::getQuantity() const {
    return quantity;
}

void Hardware::setPrice(double price) {
    this->price = price;
}
double Hardware::getPrice() const {
    return price;
}