#pragma once
#ifndef PUMPINGSTATION_H
#define PUMPINGSTATION_H

#include <string>
#include <iostream>

class PumpingStation {
private:
    static int id_counter; // Статический счетчик для уникальных ID
    int id;  // Уникальный идентификатор для каждой насосной станции
    std::string name;
    int totalShops;
    int activeShops;
    double efficiency;

public:
    PumpingStation();
    PumpingStation(const std::string& name, int totalShops, int activeShops, double efficiency);

    int getId() const;
    std::string getName() const;
    int getTotalShops() const;
    int getActiveShops() const;
    double getEfficiency() const;

    void setName(const std::string& name);
    void setTotalShops(int totalShops);
    void setActiveShops(int activeShops);
    void setEfficiency(double efficiency);

    static void resetIdCounter();

    void display() const;
    void adjustShops(bool activate);
};

#endif
