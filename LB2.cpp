#include <iostream>
#include <unordered_map>
#include "pipe.h"
#include "pumping_station.h"
#include "utils.h"

using namespace std;

unordered_map<int, Pipe> pipes;
unordered_map<int, PumpingStation> ps;

int main() {
    Pipe pipe;
    PumpingStation pumpingStation;
    int choice;

    do {
        cout << "\nMenu:\n"
            << "1. Add Pipe\n"
            << "2. Add Pumping Station\n"
            << "3. View All Objects\n"
            << "4. Edit Pipe\n"
            << "5. Edit Pumping Station\n"
            << "6. Save to File\n"
            << "7. Load from File\n"
            << "0. Exit\n"
            << "Choose an action: ";

        choice = GetCorrectNumber<int>(0, 7);

        switch (choice) {
        case 1:
            cin >> pipe;
            pipes[pipe.get_id()] = pipe;
            break;
        case 2:
            cin >> pumpingStation;
            ps[pumpingStation.get_id()] = pumpingStation;
            break;
        case 3:
            for (const auto& p : pipes) {
                cout << p.second << endl;
            }
            for (const auto& s : ps) {
                cout << s.second << endl;
            }
            break;
        case 4:
        {
            int pipeId;
            cout << "Enter pipe ID to edit: ";
            cin >> pipeId;
            if (pipes.find(pipeId) != pipes.end()) {
                bool repairStatus = !pipes[pipeId].get_repair();
                pipes[pipeId].set_repair(repairStatus);
                cout << "Pipe repair status updated.\n";
            }
            else {
                cout << "Pipe not found.\n";
            }
        }
        break;
        case 5:
        {
            int psId;
            cout << "Enter pumping station ID to edit: ";
            cin >> psId;
            if (ps.find(psId) != ps.end()) {
                int action;
                cout << "1. Activate Shop\n2. Deactivate Shop\nChoose action: ";
                cin >> action;
                if (action == 1) {
                    if (ps[psId].get_activeShops() < ps[psId].get_totalShops()) {
                        ps[psId].set_activeShops(ps[psId].get_activeShops() + 1);
                    }
                }
                else if (action == 2) {
                    if (ps[psId].get_activeShops() > 0) {
                        ps[psId].set_activeShops(ps[psId].get_activeShops() - 1);
                    }
                }
            }
            else {
                cout << "Pumping station not found.\n";
            }
        }
        break;
        case 6:
            // Implement saving to file
            break;
        case 7:
            // Implement loading from file
            break;
        case 0:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}