#include "event_list.h"
#include <iostream>

//adds a new event sorted by year
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

//returns head
EventNode* GetAllEvents(EventNode* head)
{
    return head;
}

//deletes a node from the list
void DeleteEvent(EventNode*& head, EventNode* target)
{
    if (!head || !target) return;

    if (head == target)
    {
        EventNode* tmp = head;
        head = head->next;
        delete tmp;
        return;
    }

    EventNode* current = head;
    while (current->next && current->next != target)
        current = current->next;

    if (current->next == target)
    {
        EventNode* tmp = current->next;
        current->next = tmp->next;
        delete tmp;
    }
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

//free all nodes
void FreeList(EventNode*& head)
{
    while (head)
    {
        EventNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}