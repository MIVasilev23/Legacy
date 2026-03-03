#pragma once
#include "event_list.h"

void SaveEventToFile(const Event& e);
void LoadEventsFromFile(EventNode*& head);
void SaveAllEvents(EventNode* head);