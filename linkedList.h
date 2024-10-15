#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <class Type>
struct nodeType {
    Type info;
    nodeType<Type>* link;
};

template <class Type>
class linkedListIterator {
public:
    linkedListIterator();
    linkedListIterator(nodeType<Type>* ptr);
    Type operator*();
    linkedListIterator<Type> operator++();
    bool operator==(const linkedListIterator<Type>&) const;
    bool operator!=(const linkedListIterator<Type>&) const;

private:
    nodeType<Type>* current;
};

template <class Type>
linkedListIterator<Type>::linkedListIterator() {
    current = nullptr;
}

template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type>* ptr) {
    current = ptr;
}

template <class Type>
Type linkedListIterator<Type>::operator*() {
    return current->info;
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++() {
    current = current->link;
    return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const {
    return (current == right.current);
}

template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const {
    return (current != right.current);
}

template <class Type>
class linkedListType {
public:
    const linkedListType<Type>& operator=(const linkedListType<Type>&);
    void initializeList();
    bool isEmptyList() const;
    void print() const;
    int length() const;
    void destroyList();
    Type front() const;
    Type back() const;
    virtual bool search(const Type& searchItem) const = 0;
    virtual void insertFirst(const Type& newItem) = 0;
    virtual void insertLast(const Type& newItem) = 0;
    virtual void deleteNode(const Type& deleteItem) = 0;
    linkedListIterator<Type> begin();
    linkedListIterator<Type> end();
    linkedListType();
    linkedListType(const linkedListType<Type>& otherList);
    ~linkedListType();

protected:
    int count;
    nodeType<Type>* first;
    nodeType<Type>* last;

private:
    void copyList(const linkedListType<Type>& otherList);
};

template <class Type>
linkedListType<Type>::linkedListType() {
    first = nullptr;
    last = nullptr;
    count = 0;
}

template <class Type>
void linkedListType<Type>::initializeList() {
    destroyList();
}

template <class Type>
bool linkedListType<Type>::isEmptyList() const {
    return (first == nullptr);
}

template <class Type>
int linkedListType<Type>::length() const {
    return count;
}

template <class Type>
Type linkedListType<Type>::front() const {
    return first->info;
}

template <class Type>
Type linkedListType<Type>::back() const {
    return last->info;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin() {
    return linkedListIterator<Type>(first);
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end() {
    return linkedListIterator<Type>(nullptr);
}

template <class Type>
void linkedListType<Type>::destroyList() {
    nodeType<Type>* temp;
    while (first != nullptr) {
        temp = first;
        first = first->link;
        delete temp;
    }
    last = nullptr;
    count = 0;
}

template <class Type>
linkedListType<Type>::~linkedListType() {
    destroyList();
}

#endif