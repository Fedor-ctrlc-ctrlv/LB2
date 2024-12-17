#include <iostream> 
#include <unordered_map> 
#include "pipe.h" 
#include "pumping_station.h" 
#include "utils.h" 
#include "pipe_act.h" 

using namespace std;

unordered_map<int, Pipe> pipes;
unordered_map<int, PumpingStation> ps;

void pipeMenu() {
    int choice;
    do {
        cout << "\nPipe Menu:\n"
            << "1. Add Pipe\n"
            << "2. View All Pipes\n"
            << "3. Modify Pipe Repair Status\n"
            << "4. Delete Pipe\n"
            << "0. Return to Main Menu\n"
            << "Choose an action: ";

        choice = GetCorrectNumber<int>(0, 4);

        switch (choice) {
        case 1:
            addPipe(pipes);
            break;
        case 2:
            viewPipes(pipes);
            break;
        case 3:
            modifyPipeRepairStatus(pipes);
            break;
        case 4:
            deletePipe(pipes);
            break;
        case 0:
            cout << "Returning to main menu.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}

int main() {
    int choice;

    do {
        cout << "\nMain Menu:\n"
            << "1. Add Pumping Station\n"
            << "2. View All Pumping Stations\n"
            << "3. Pipe Operations\n"
            << "4. Save to File\n"
            << "5. Load from File\n"
            << "0. Exit\n"
            << "Choose an action: ";

        choice = GetCorrectNumber<int>(0, 5);

        switch (choice) {
        case 1:
        {
            PumpingStation pumpingStation;
            cin >> pumpingStation;
            ps[pumpingStation.get_id()] = pumpingStation;
            break;
        }
        case 2:
            for (const auto& s : ps) {
                cout << s.second << endl;
            }
            break;
        case 3:
            pipeMenu();  // Sub-menu for pipe operations 
            break;
        case 4:
            // Implement saving to file 
            break;
        case 5:
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