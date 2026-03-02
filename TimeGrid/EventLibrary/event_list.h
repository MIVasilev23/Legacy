#pragma once
#include "event.h"

struct EventNode
{
    Event data;
    EventNode* next;
};

void AddEvent(EventNode*& head, const Event& newEvent);
EventNode* GetAllEvents(EventNode* head);
EventNode* SearchByYear(EventNode* head, int year);
void FreeList(EventNode*& head);