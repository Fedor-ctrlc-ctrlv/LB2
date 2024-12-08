#include "Filter.h"
#include <iostream>
#include <algorithm>


std::vector<Pipe> Filter::filterPipesByName(const std::vector<Pipe>& pipes, const std::string& name) {
    std::vector<Pipe> result;
    for (const auto& pipe : pipes) {
        if (pipe.getName() == name) {
            result.push_back(pipe);
        }
    }
    return result;
}


std::vector<Pipe> Filter::filterPipesByRepairStatus(const std::vector<Pipe>& pipes, bool underRepair) {
    std::vector<Pipe> result;
    for (const auto& pipe : pipes) {
        if (pipe.isUnderRepair() == underRepair) {
            result.push_back(pipe);
        }
    }
    return result;
}


std::vector<PumpingStation> Filter::filterPumpStationsByName(const std::vector<PumpingStation>& ps, const std::string& name) {
    std::vector<PumpingStation> result;
    for (const auto& station : ps) {
        if (station.getName() == name) {
            result.push_back(station);
        }
    }
    return result;
}


std::vector<PumpingStation> Filter::filterPumpStationsByInactiveShops(const std::vector<PumpingStation>& ps, double maxInactivePercent) {
    std::vector<PumpingStation> result;
    for (const auto& station : ps) {
        double inactivePercent = calculateInactiveShopsPercentage(station.getTotalShops(), station.getTotalShops() - station.getActiveShops());
        if (inactivePercent <= maxInactivePercent) {
            result.push_back(station);
        }
    }
    return result;
}


double Filter::calculateInactiveShopsPercentage(int totalShops, int activeShops) {
    if (totalShops == 0) return 0.0;
    return static_cast<double>(totalShops - activeShops) / totalShops * 100;
}