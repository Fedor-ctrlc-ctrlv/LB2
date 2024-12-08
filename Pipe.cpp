#include "Pipe.h"

int Pipe::id_counter = 1;  // Инициализация статического счетчика

Pipe::Pipe() : id(id_counter++), name("None"), length(0), diameter(0), underRepair(false) {}

Pipe::Pipe(const std::string& name, int length, int diameter, bool underRepair)
    : id(id_counter++), name(name), length(length), diameter(diameter), underRepair(underRepair) {}

int Pipe::getId() const {
    return id;
}

std::string Pipe::getName() const {
    return name;
}

int Pipe::getLength() const {
    return length;
}

int Pipe::getDiameter() const {
    return diameter;
}

bool Pipe::isUnderRepair() const {
    return underRepair;
}

void Pipe::setName(const std::string& name) {
    this->name = name;
}

void Pipe::setLength(int length) {
    this->length = length;
}

void Pipe::setDiameter(int diameter) {
    this->diameter = diameter;
}

void Pipe::setUnderRepair(bool underRepair) {
    this->underRepair = underRepair;
}

void Pipe::resetIdCounter() {
    id_counter = 1;  // Сброс идентификаторов
}

void Pipe::display() const {
    std::cout << "Pipe ID: " << id << "\n"
        << "Name: " << name << "\n"
        << "Length: " << length << " km\n"
        << "Diameter: " << diameter << " mm\n"
        << "Under Repair: " << (underRepair ? "Yes" : "No") << "\n";
}

void Pipe::toggleRepairStatus() {
    underRepair = !underRepair;
    std::cout << "Repair status changed.\n";
}