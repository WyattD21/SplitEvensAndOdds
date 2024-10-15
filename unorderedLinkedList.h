#ifndef UNORDEREDLINKEDLIST_H
#define UNORDEREDLINKEDLIST_H

#include "linkedList.h"

template <class Type>
class unorderedLinkedList : public linkedListType<Type> {
public:
    bool search(const Type& searchItem) const;
    void insertFirst(const Type& newItem);
    void insertLast(const Type& newItem);
    void deleteNode(const Type& deleteItem);
};

template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const {
    nodeType<Type>* current = this->first;
    while (current != nullptr) {
        if (current->info == searchItem)
            return true;
        current = current->link;
    }
    return false;
}

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem) {
    nodeType<Type>* newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = this->first;
    this->first = newNode;
    if (this->last == nullptr)
        this->last = newNode;
    this->count++;
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem) {
    nodeType<Type>* newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = nullptr;
    if (this->first == nullptr) {
        this->first = newNode;
        this->last = newNode;
    }
    else {
        this->last->link = newNode;
        this->last = newNode;
    }
    this->count++;
}

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem) {
    if (this->first == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    nodeType<Type>* current = this->first;
    nodeType<Type>* trailCurrent = nullptr;

    if (this->first->info == deleteItem) {
        current = this->first;
        this->first = this->first->link;
        if (this->first == nullptr)
            this->last = nullptr;
        delete current;
        this->count--;
    }
    else {
        while (current != nullptr && current->info != deleteItem) {
            trailCurrent = current;
            current = current->link;
        }

        if (current == nullptr)
            cout << "Item not found." << endl;
        else {
            trailCurrent->link = current->link;
            if (this->last == current)
                this->last = trailCurrent;
            delete current;
            this->count--;
        }
    }
}

#endif
