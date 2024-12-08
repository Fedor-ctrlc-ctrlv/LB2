#pragma once
#ifndef PIPE_H
#define PIPE_H

#include <string>
#include <iostream>

class Pipe {
private:
    static int id_counter; // Статический счетчик для уникальных ID
    int id;  // Уникальный идентификатор для каждой трубы
    std::string name;
    int length;
    int diameter;
    bool underRepair;

public:
    Pipe();
    Pipe(const std::string& name, int length, int diameter, bool underRepair);

    int getId() const;
    std::string getName() const;
    int getLength() const;
    int getDiameter() const;
    bool isUnderRepair() const;

    void setName(const std::string& name);
    void setLength(int length);
    void setDiameter(int diameter);
    void setUnderRepair(bool underRepair);

    static void resetIdCounter();

    void display() const;
    void toggleRepairStatus();
};

#endif