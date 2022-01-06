#include "Person.h"
Person** Person::persons = new Person*[]{
					nullptr, nullptr, nullptr, nullptr,
                                          nullptr, nullptr,nullptr, nullptr,
					  nullptr, nullptr};

Person::Person(std::string n) {

    this->count = 1;
    this->name = n;
    for (int i = 0; i < 10; i++) {
        if (persons[i] == nullptr) {
            this->index = i;
            persons[i] = this;
            return;
        }

        else if (this->name == persons[i]->name) {

            this->count += persons[i]->count;
            this->index = i;

            delete persons[i];
            persons[i] = this;
            return;
        }

    }
    std::cout << "Sorry, no more room. Failed to add " << n << " to the list.\n";
    delete this;
    return;
}

void Person::DeletePersons() {
    for (int i = 0; i < 10; i++)
        delete persons[i];
}

Person* Person::getPerson(std::string n) {
    
    for (int i = 0; i < 10; i++) {
        if (n == persons[i]->name) {
            return persons[i];
        }
    }
    return nullptr;
}
