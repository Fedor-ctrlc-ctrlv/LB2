#pragma once 

#include <string> 
#include <iostream> 

class PumpingStation {
private:
    std::string name;
    int totalShops;
    int activeShops;
    double efficiency;

public:
    PumpingStation();

    std::string get_name() const;
    int get_totalShops() const;
    int get_activeShops() const;
    double get_efficiency() const;

    void set_activeShops(int new_activeShops);
    void set_efficiency(double new_efficiency);

    friend std::ostream& operator << (std::ostream& out, const PumpingStation& ps);
    friend std::istream& operator >> (std::istream& in, PumpingStation& ps);
};