#ifndef INTLINKEDLIST_H
#define INTLINKEDLIST_H

#include "unorderedLinkedList.h"

class intLinkedList : public unorderedLinkedList<int> {
public:
    void splitEvensOddsList(intLinkedList& evensList, intLinkedList& oddsList);
};

void intLinkedList::splitEvensOddsList(intLinkedList& evensList, intLinkedList& oddsList) {
    nodeType<int>* current = this->first;

    while (current != nullptr) {
        nodeType<int>* nextNode = current->link;
        if (current->info % 2 == 0) {
            evensList.insertLast(current->info);
        }
        else {
            oddsList.insertLast(current->info);
        }
        current = nextNode;
    }

    this->first = nullptr;
    this->last = nullptr;
    this->count = 0;
}

#endif
