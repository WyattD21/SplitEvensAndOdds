#include <iostream>
#include "intLinkedList.h"

using namespace std;

int main() {
    intLinkedList list, evensList, oddsList;
    int num;

    cout << "Enter integers ending with -999:" << endl;
    cin >> num;

    while (num != -999) {
        list.insertLast(num);
        cin >> num;
    }

    list.splitEvensOddsList(evensList, oddsList);

    cout << "Evens list: ";
    for (auto it = evensList.begin(); it != evensList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Odds list: ";
    for (auto it = oddsList.begin(); it != oddsList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
