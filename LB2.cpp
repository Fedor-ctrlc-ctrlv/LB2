#include <iostream> 
#include <fstream>
#include <unordered_map> 
#include "pipe.h" 
#include "pumping_station.h" 
#include "utils.h" 
#include "pipe_act.h" 
#include "pumping_station_act.h" 
#include "pipe_sort.h"
#include "pumping_station_sort.h"
#include "pipes_act.h" 
#include <chrono>
#include <format>
#include "file_io.h" 

using namespace std;

unordered_map<int, Pipe> pipes;
unordered_map<int, PumpingStation> stations;

void handleModifyMultiplePipes(std::unordered_map<int , Pipe>& pipes) {
    modifyMultiplePipesRepairStatus(pipes);
}

void pipeMenu() {
    int choice;
    do {
        cout << "\nPipe Menu:\n"
            << "1. Add Pipe\n"
            << "2. View All Pipes\n"
            << "3. Modify Pipe Repair Status\n"
            << "4. Delete Pipe\n"
            << "5. Sort/Filter Pipes\n"
            << "6. Modify Pipes Repair Status(All|selected pipes)\n"
            << "0. Return to Main Menu\n" 
            << "Choose an action: ";

        choice = GetCorrectNumber<int>(0, 6);

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
        case 5:
        {
            int filterChoice;
            cout << "\nSort/Filter Pipes Menu:\n"
                << "1. Sort by Name\n"
                << "2. Sort by Repair Status\n"
                << "3. Filter by Name\n"
                << "4. Filter by Repair Status\n"
                << "0. Return to Pipe Menu\n"
                << "Choose an action: ";
            filterChoice = GetCorrectNumber<int>(0, 4);

            switch (filterChoice) {
            case 1:
                sortPipesByName(pipes);
                break;
            case 2:
                sortPipesByRepairStatus(pipes);
                break;
            case 3:
                filterPipesByName(pipes);
                break;
            case 4:
                filterPipesByRepairStatus(pipes);
                break;
            case 0:
                cout << "Returning to Pipe Menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        } 
        break;
        case 6:
            handleModifyMultiplePipes(pipes);
            break;
        case 0:
            cout << "Returning to Main Menu.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}

void pumpingStationMenu() {
    int choice;
    do {
        cout << "\nPumping Station Menu:\n"
            << "1. Add Pumping Station\n"
            << "2. View All Pumping Stations\n"
            << "3. Modify Pumping Station Shops\n"
            << "4. Delete Pumping Station\n"
            << "5. Sort/Filter Pumping Stations\n"
            << "0. Return to Main Menu\n"
            << "Choose an action: ";

        choice = GetCorrectNumber<int>(0, 5);

        switch (choice) {
        case 1:
            addPumpingStation(stations);
            break;
        case 2:
            viewPumpingStations(stations);
            break;
        case 3:
            modifyPumpingStationStatus(stations);
            break;
        case 4:
            deletePumpingStation(stations);
            break;
        case 5:
        {
            int filterChoice;
            cout << "\nSort/Filter Pumping Stations Menu:\n"
                << "1. Sort by Name\n"
                << "2. Sort by Inactive Shops Percentage\n"
                << "3. Filter by Name\n"
                << "4. Filter by Inactive Shops Percentage\n"
                << "0. Return to Pumping Station Menu\n"
                << "Choose an action: ";
            filterChoice = GetCorrectNumber<int>(0, 4);

            switch (filterChoice) {
            case 1:
                sortPumpingStationsByName(stations);
                break;
            case 2:
                sortPumpingStationsByInactiveShopsPercentage(stations);
                break;
            case 3:
                filterPumpingStationsByName(stations);
                break;
            case 4:
                filterPumpingStationsByInactiveShopsPercentage(stations);
                break;
            case 0:
                cout << "Returning to Pumping Station Menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        }
        break;
        case 0:
            cout << "Returning to Main Menu.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}

int main() {
    redirect_output_wrapper cerr_out(std::cerr);
    std::string time = std::format("{:%d_%m_%Y %H_%M_%OS}", std::chrono::system_clock::now());
    std::ofstream logfile("log_" + time + ".txt");
    if (logfile)
        cerr_out.redirect(logfile);

    int choice;

    do {
        cout << "\nMain Menu:\n"
            << "1. Pipe Operations\n"
            << "2. Pumping Station Operations\n"
            << "3. Save to File\n"
            << "4. Load from File\n"
            << "0. Exit\n"
            << "Choose an action: ";

        choice = GetCorrectNumber<int>(0, 4);

        switch (choice) {
        case 1:
            pipeMenu(); 
            break;
        case 2:
            pumpingStationMenu();  
            break;
        case 3: {
            string filename;
            cout << "Enter filename to save data: ";
            cin >> filename;
            saveDataToFile(pipes, stations, filename);

            break;
        }
        case 4: 
        {
            string filename;
            cout << "Enter filename to load data: ";
            cin >> filename;
            loadDataFromFile(pipes, stations, filename);
            break;
        }
        case 0:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}