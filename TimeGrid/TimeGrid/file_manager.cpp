#include "file_manager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

void SaveEventToFile(const Event& e)
{
    std::ofstream file("events.txt", std::ios::app);
    if (!file.is_open())
    {
        std::cout << "Failed to open events.txt for writing!\n";
        return;
    }

    file << e.name << "; "
        << e.year << "; "
        << e.theme << "; "
        << e.leader << "; "
        << e.participants << "; "
        << e.result << "\n";

    file.close();
}

void LoadEventsFromFile(EventNode*& head)
{
    std::ifstream file("events.txt");
    if (!file.is_open()) return;

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string token;
        Event e;

        if (!std::getline(ss, token, ';')) continue;
        e.name = token;

        if (!std::getline(ss, token, ';')) continue;
        e.year = std::stoi(token);

        if (!std::getline(ss, token, ';')) continue;
        e.theme = token;

        if (!std::getline(ss, token, ';')) continue;
        e.leader = token;

        if (!std::getline(ss, token, ';')) continue;
        e.participants = token;

        if (!std::getline(ss, token, ';')) continue;
        e.result = token;

        AddEvent(head, e);
    }

    file.close();
}