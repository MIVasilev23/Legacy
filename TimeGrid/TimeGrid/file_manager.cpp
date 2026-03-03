#include "file_manager.h"
#include <fstream>
#include <string>
#include <limits>
#include <iostream>

void SaveEventToFile(const Event& e)
{
    std::ofstream file("events.txt", std::ios::app);
    if (file.is_open())
    {
        file << e.name << ";" << e.year << "\n";
        file.close();
    }
    else
    {
        std::cout << "Failed to open events.txt for writing!\n";
    }
}

void LoadEventsFromFile(EventNode*& head)
{
    std::ifstream file("events.txt");
    if(!file.is_open()) return;

    std::string name;
    int year;

    while(std::getline(file, name, ';') && file >> year)
    {
        Event e;
        e.name = name;
        e.year = year;
        AddEvent(head, e);

        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    file.close();

}