#include "graph.h"
#include <iostream>
#include "pipe_act.h"


void connectStations(std::unordered_map<int, Pipe>& pipes,
    std::unordered_map<int, PumpingStation>& stations,
    std::unordered_map<int, std::vector<Connection>>& graph) {
    int sourceId, targetId, diameter;
    std::cout << "Enter source station ID: ";
    std::cin >> sourceId;
    std::cout << "Enter target station ID: ";
    std::cin >> targetId;
    std::cout << "Enter pipe diameter (500, 700, 1000, 1400): ";
    std::cin >> diameter;

    
    if (diameter != 500 && diameter != 700 && diameter != 1000 && diameter != 1400) {
        std::cerr << "Invalid diameter. Allowed values: 500, 700, 1000, 1400.\n";
        return;
    }

    
    int pipeId = -1;
    for (const auto& pipe : pipes) {
        if (pipe.second.get_diameter() == diameter && !pipe.second.get_repair()) {
            pipeId = pipe.first;
            break;
        }
    }

    if (pipeId == -1) {
        std::cout << "No available pipe with diameter " << diameter << ". Create a new pipe.\n";
        addPipe(pipes);
        pipeId = Pipe::get_MaxID(); 
    }


    Connection connection;
    connection.id = graph.size() + 1; 
    connection.pipeId = pipeId;
    connection.sourceId = sourceId;
    connection.targetId = targetId;

    
    graph[sourceId].push_back(connection);

    std::cout << "Stations connected successfully.\n";
}

void topologicalSortUtil(int stationId,
    std::unordered_map<int, std::vector<Connection>>& graph,
    std::unordered_set<int>& visited,
    std::stack<int>& stack) {
    visited.insert(stationId);

    for (const auto& connection : graph[stationId]) {
        if (visited.find(connection.targetId) == visited.end()) {
            topologicalSortUtil(connection.targetId, graph, visited, stack);
        }
    }

    stack.push(stationId);
}


void topologicalSort(std::unordered_map<int, std::vector<Connection>>& graph,
    std::unordered_map<int, PumpingStation>& stations) {
    std::stack<int> stack;
    std::unordered_set<int> visited;

    for (const auto& station : stations) {
        if (visited.find(station.first) == visited.end()) {
            topologicalSortUtil(station.first, graph, visited, stack);
        }
    }

    std::cout << "Topological order of stations:\n";
    while (!stack.empty()) {
        int stationId = stack.top();
        std::cout << "Station ID: " << stationId << ", Name: " << stations[stationId].get_name() << "\n";
        stack.pop();
    }
}