#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string name;
    std::string id;
    double gpa;

public:
    Student(std::string n, std::string i, double g) {
        name = n;
        id = i;
        gpa = g;
    }

    void setName(std::string n) {
        name = n;
    }

    void setId(std::string i) {
        id = i;
    }

    void setGpa(double g) {
        gpa = g;
    }

    std::string getName() {
        return name;
    }

    std::string getId() {
        return id;
    }

    double getGpa() {
        return gpa;
    }
};

#endif