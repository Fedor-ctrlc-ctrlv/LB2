#pragma once

#include <unordered_map>
#include <string>
#include "pipe.h"
#include "pumping_station.h"

void loadDataFromFile(std::unordered_map<int, Pipe>& pipes, std::unordered_map<int, PumpingStation>& stations, const std::string& filename);
void saveDataToFile(const std::unordered_map<int, Pipe>& pipes, const std::unordered_map<int, PumpingStation>& stations, const std::string& filename);
