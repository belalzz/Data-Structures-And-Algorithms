#include <iostream>
#include "ArrayList.h"
#include "ArrayList.cpp"
using namespace std;

int main() {
    cout << "=== Testing ArrayList ===" << endl;

    // 1. Test constructor + append
    ArrayList<int> list;
    cout << "Appending 1,2,3,4,5..." << endl;
    for (int i = 1; i <= 5; i++) list.append(i);
    cout << "Size after append: " << list.size() << endl;

    // 2. Test operator[] (read & write)
    cout << "Element at index 2: " << list[2] << endl;
    list[2] = 99;
    cout << "After modification, element at index 2: " << list[2] << endl;

    // 3. Test get/set
    cout << "list.get(1) = " << list.get(1) << endl;
    list.set(1, 77);
    cout << "After set, list.get(1) = " << list.get(1) << endl;

    // 4. Test insert
    cout << "Inserting 55 at index 2..." << endl;
    list.insert(2, 55);
    cout << "List after insertion: ";
    for (int i = 0; i < list.size(); i++) cout << list[i] << " ";
    cout << endl;

    // 5. Test remove
    cout << "Removing element at index 3..." << endl;
    list.remove(3);
    cout << "List after removal: ";
    for (int i = 0; i < list.size(); i++) cout << list[i] << " ";
    cout << endl;

    // 6. Test search
    cout << "Searching for 99... Found at index " << list.search(99) << endl;
    cout << "Searching for 123 (not in list)... Result = " << list.search(123) << endl;

    // 7. Test copy constructor
    cout << "Creating a copy of list (copy constructor)..." << endl;
    ArrayList<int> copyList(list);
    cout << "CopyList contents: ";
    for (int i = 0; i < copyList.size(); i++) cout << copyList[i] << " ";
    cout << endl;

    // 8. Test assignment operator
    cout << "Testing assignment operator..." << endl;
    ArrayList<int> assignList;
    assignList = list;
    cout << "AssignList contents: ";
    for (int i = 0; i < assignList.size(); i++) cout << assignList[i] << " ";
    cout << endl;

    // Modify assignList to ensure deep copy works
    assignList[0] = -100;
    cout << "After modifying assignList[0], original list[0] = " << list[0] << endl;

    // 9. Test clear
    cout << "Clearing the list..." << endl;
    list.clear();
    cout << "List size after clear: " << list.size() << endl;
    cout << "Appending new values to cleared list..." << endl;
    list.append(500);
    list.append(600);
    cout << "List contents after reusing: ";
    for (int i = 0; i < list.size(); i++) cout << list[i] << " ";
    cout << endl;

    cout << "=== All tests finished successfully ===" << endl;
    return 0;
}