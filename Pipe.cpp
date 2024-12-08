#include "Pipe.h"
#include <fstream>

int Pipe::id_counter = 1;

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
    id_counter = 1;
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

void Pipe::saveToFile(std::ofstream& outFile) const {
    outFile << "Pipe\n"
        << id << "\n"
        << name << "\n"
        << length << "\n"
        << diameter << "\n"
        << underRepair << "\n";
}

Pipe Pipe::loadFromFile(std::ifstream& inFile) {
    int id, length, diameter;
    bool underRepair;
    std::string name;

    inFile >> id;
    inFile.ignore();
    std::getline(inFile, name);
    inFile >> length >> diameter >> underRepair;

    Pipe pipe(name, length, diameter, underRepair);
    pipe.id = id;
    return pipe;
}