#include "event_list.h"
#include <fstream>

void SaveEventToFile(const Event& e)
{
    std::ofstream file("events.txt", std::ios::app);
    if (file.is_open())
    {
        file << e.name << ";" << e.year << "\n";
        file.close();
    }
}