#pragma once
#include <iostream>
#include <string>

class Person {
private:
    int index;

public:
    std::string name;
    int count;
    static Person** persons;
    Person() {}
    Person(std::string name);
    ~Person() {}

    static void DeletePersons();
    static Person* getPerson(std::string);
};
