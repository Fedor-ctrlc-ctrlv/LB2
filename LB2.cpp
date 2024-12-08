#include <iostream>
#include <vector>
#include <fstream>
#include "Pipe.h"
#include "PumpingStation.h"
#include "Filter.h"

class System {
private:
    std::vector<Pipe> pipes;
    std::vector<PumpingStation> pumpingStations;

public:
    void logAction(const std::string& action) {
        std::ofstream logFile("action_log.txt", std::ios::app);
        if (logFile.is_open()) {
            logFile << action << std::endl;
        }
    }

    Pipe* findPipeById(int id) {
        for (auto& pipe : pipes) {
            if (pipe.getId() == id) {
                return &pipe;
            }
        }
        return nullptr;
    }

    PumpingStation* findPumpingStationById(int id) {
        for (auto& ps : pumpingStations) {
            if (ps.getId() == id) {
                return &ps;
            }
        }
        return nullptr;
    }

    void displayAll() {
        for (const auto& pipe : pipes) {
            pipe.display();
        }

        for (const auto& ps : pumpingStations) {
            ps.display();
        }
    }

    void addPipe() {
        std::string name;
        int length, diameter;
        bool underRepair;

        std::cout << "Enter Pipe Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        std::cout << "Enter Pipe Length: ";
        std::cin >> length;

        std::cout << "Enter Pipe Diameter: ";
        std::cin >> diameter;

        std::cout << "Is the Pipe under Repair? (1/0): ";
        std::cin >> underRepair;

        Pipe newPipe(name, length, diameter, underRepair);
        pipes.push_back(newPipe);

        logAction("Added Pipe: " + name);
    }

    void addPumpingStation() {
        std::string name;
        int totalShops, activeShops;
        double efficiency;

        std::cout << "Enter Pumping Station Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        std::cout << "Enter Total Shops: ";
        std::cin >> totalShops;

        std::cout << "Enter Active Shops: ";
        std::cin >> activeShops;

        std::cout << "Enter Efficiency: ";
        std::cin >> efficiency;

        PumpingStation ps(name, totalShops, activeShops, efficiency);
        pumpingStations.push_back(ps);

        logAction("Added Pumping Station: " + name);
    }

    void saveToFile() {
        std::ofstream file;
        std::string filename;

        std::cout << "Enter filename to save: ";
        std::cin >> filename;

        file.open(filename);
        if (!file.is_open()) {
            std::cout << "Error opening file.\n";
            return;
        }

        for (const auto& pipe : pipes) {
            pipe.saveToFile(file);
        }

        for (const auto& ps : pumpingStations) {
            ps.saveToFile(file);
        }
    }

    void loadFromFile() {
        std::ifstream file;
        std::string filename;

        std::cout << "Enter filename to load: ";
        std::cin >> filename;

        file.open(filename);
        if (!file.is_open()) {
            std::cout << "Error opening file.\n";
            return;
        }

        pipes.clear();
        pumpingStations.clear();

        std::string line;
        while (std::getline(file, line)) {
            if (line == "Pipe") {
                pipes.push_back(Pipe::loadFromFile(file));
            }
            else if (line == "PumpStation") {
                pumpingStations.push_back(PumpingStation::loadFromFile(file));
            }
        }
    }
};

int main() {
    System system;
    int choice;
    do {
        std::cout << "\nMenu:\n"
            << "1. Add Pipe\n"
            << "2. Add Pumping Station\n"
            << "3. Display All\n"
            << "4. Save to File\n"
            << "5. Load from File\n"
            << "0. Exit\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            system.addPipe();
            break;
        case 2:
            system.addPumpingStation();
            break;
        case 3:
            system.displayAll();
            break;
        case 4:
            system.saveToFile();
            break;
        case 5:
            system.loadFromFile();
            break;
        case 0:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}