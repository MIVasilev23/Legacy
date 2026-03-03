#pragma once
#include "event.h"

struct EventNode
{
    Event data;
    EventNode* next;
};

void AddEvent(EventNode*& head, const Event& newEvent);
EventNode* GetAllEvents(EventNode* head);
void DeleteEvent(EventNode*& head, EventNode* target);
EventNode* SearchByYear(EventNode* head, int year);
void FreeList(EventNode*& head);
