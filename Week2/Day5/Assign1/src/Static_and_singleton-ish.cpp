#include <iostream>
#include <string>

#include "Person.h"
/*Ethan Seiber
Date: 12/16/20*/

std::string tolower(std::string);



int main(void) {

    std::string persons1[] = {"James", "Tom", "Jamie", "Thomas", "James", "Tome", 
        "Ethan", "John", "Eric", "James", "Tanya", "Tallia", "Chris"};
    
    std::string persons2[] = {"James", "Tom", "Jamie", "Thomas", "Tome", "Ethan", "John", 
                              "Eric", "Tanya", "Tallia", "Chris"};
    for (int i = 0; i < 13; i++) {
        std::cout << "Adding " << persons1[i] << " to list" << std::endl;
        new Person(persons1[i]);
    }

    for (int i = 0; i < 11; i++) {
        Person* p = Person::getPerson(persons2[i]);
        if (p != nullptr)
            std::cout << "\n\nPerson's name: " << p->name << "\nPerson count: " << p->count << std::endl;
        else
            std::cout << "\nSorry, "<< persons2[i] << " was not on the list.\n";
    }

    Person::DeletePersons(); 
	return 0;
}

std::string tolower(std::string name) {

    for (std::string::iterator it = name.begin(); it < name.end(); it++) {
        *it = std::tolower(*it);
    }
    return name;
}
