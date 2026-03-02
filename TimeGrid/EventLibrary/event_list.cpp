#include "event_list.h"

void AddEvent(EventNode*& head, const Event& newEvent)
{
    EventNode* newNode = new EventNode{ newEvent, nullptr };

    if (!head || newEvent.year < head->data.year)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    EventNode* current = head;
    while (current->next && current->next->data.year < newEvent.year)
        current = current->next;

    newNode->next = current->next;
    current->next = newNode;
}

EventNode* GetAllEvents(EventNode* head)
{
    return head;
}

EventNode* SearchByYear(EventNode* head, int year)
{
    while (head)
    {
        if (head->data.year == year)
            return head;
        head = head->next;
    }
    return nullptr;
}

void FreeList(EventNode*& head)
{
    while (head)
    {
        EventNode* temp = head;
        head = head->next;
        delete temp;
    }
}