#include "PumpingStation.h"

int PumpingStation::id_counter = 1;  // Инициализация статического счетчика

PumpingStation::PumpingStation() : id(id_counter++), name("None"), totalShops(0), activeShops(0), efficiency(0.0) {}

PumpingStation::PumpingStation(const std::string& name, int totalShops, int activeShops, double efficiency)
    : id(id_counter++), name(name), totalShops(totalShops), activeShops(activeShops), efficiency(efficiency) {}

int PumpingStation::getId() const {
    return id;
}

std::string PumpingStation::getName() const {
    return name;
}

int PumpingStation::getTotalShops() const {
    return totalShops;
}

int PumpingStation::getActiveShops() const {
    return activeShops;
}

double PumpingStation::getEfficiency() const {
    return efficiency;
}

void PumpingStation::setName(const std::string& name) {
    this->name = name;
}

void PumpingStation::setTotalShops(int totalShops) {
    this->totalShops = totalShops;
}

void PumpingStation::setActiveShops(int activeShops) {
    this->activeShops = activeShops;
}

void PumpingStation::setEfficiency(double efficiency) {
    this->efficiency = efficiency;
}

void PumpingStation::resetIdCounter() {
    id_counter = 1;  // Сброс идентификаторов
}

void PumpingStation::display() const {
    std::cout << "Pumping Station ID: " << id << "\n"
        << "Name: " << name << "\n"
        << "Total Shops: " << totalShops << "\n"
        << "Active Shops: " << activeShops << "\n"
        << "Efficiency: " << efficiency << "\n";
}

void PumpingStation::adjustShops(bool activate) {
    if (activate) {
        if (activeShops < totalShops) {
            activeShops++;
            std::cout << "Shop activated.\n";
        }
        else {
            std::cout << "All shops are already active.\n";
        }
    }
    else {
        if (activeShops > 0) {
            activeShops--;
            std::cout << "Shop deactivated.\n";
        }
        else {
            std::cout << "No active shops to deactivate.\n";
        }
    }
}