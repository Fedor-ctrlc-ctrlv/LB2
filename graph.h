#pragma once
#include <unordered_map>
#include <vector>
#include <stack>
#include <unordered_set>
#include "pipe.h"
#include "pumping_station.h"


struct Connection {
    int id;          
    int pipeId;      
    int sourceId;    
    int targetId;    
};

void connectStations(std::unordered_map<int, Pipe>& pipes,
    std::unordered_map<int, PumpingStation>& stations,
    std::unordered_map<int, std::vector<Connection>>& graph);

void topologicalSort(std::unordered_map<int, std::vector<Connection>>& graph,
    std::unordered_map<int, PumpingStation>& stations);