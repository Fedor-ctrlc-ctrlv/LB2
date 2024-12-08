#pragma once
#ifndef FILTER_H
#define FILTER_H

#include <map>
#include <unordered_map>
#include <vector>
#include "Pipe.h"
#include "PumpingStation.h"

class Filter {
public:

    static std::vector<Pipe> filterPipesByName(const std::vector<Pipe>& pipes, const std::string& name);
    static std::vector<Pipe> filterPipesByRepairStatus(const std::vector<Pipe>& pipes, bool underRepair);


    static std::vector<PumpingStation> filterPumpStationsByName(const std::vector<PumpingStation>& ps, const std::string& name);
    static std::vector<PumpingStation> filterPumpStationsByInactiveShops(const std::vector<PumpingStation>& ps, double maxInactivePercent);

private:

    static double calculateInactiveShopsPercentage(int totalShops, int activeShops);
};

#endif