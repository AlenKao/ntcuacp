#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person {
public:
    Person(int = -1, int = 0, string = "unassigned", string = "");

    void setId(int);
    int getId() const;

    void setLastName(const string&);
    string getLastName() const;

    void setFirstName(const string&);
    string getFirstName() const;

    void setAge(int);
    int getAge() const;

private:
    char lastName[15];
    char firstName[15];
    int age;
    int id;
};

#endif