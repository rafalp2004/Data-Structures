#include <iostream>
#include "DobuleLinkedList.h"
#include <cassert>

#include "LinkedList.h"
using namespace std;
void runScenarioForDoubleLinkedList() {
  std::cout << "Testing DoubleLinkedList...\n";

    DoubleLinkedList<int> list;

    // Test 1: Add to empty list (addToFirst)
    std::cout << "Test 1: Add 10 to first\n";
    list.addToFirst(10);
    list.print();  // Expected: 10
    assert(list.head->data == 10 && list.tail->data == 10);

    // Test 2: Add to first
    std::cout << "Test 2: Add 20 to first\n";
    list.addToFirst(20);
    list.print();  // Expected: 20 10
    assert(list.head->data == 20 && list.tail->data == 10);

    // Test 3: Add to last
    std::cout << "Test 3: Add 30 to last\n";
    list.addToLast(30);
    list.print();  // Expected: 20 10 30
    assert(list.tail->data == 30);

    // Test 4: Add to index (middle)
    std::cout << "Test 4: Add 15 to index 1\n";
    list.addToIndex(15, 1);
    list.print();  // Expected: 20 15 10 30
    assert(list.head->next->data == 15);

    // Test 5: Add to invalid index (should add to last)
    std::cout << "Test 5: Add 40 to index 10\n";
    list.addToIndex(40, 10);
    list.print();  // Expected: 20 15 10 30 40
    assert(list.tail->data == 40);

    // Test 6: Remove from first
    std::cout << "Test 6: Remove from first\n";
    list.removeFromFirst();
    list.print();  // Expected: 15 10 30 40
    assert(list.head->data == 15);

    // Test 7: Remove from last
    std::cout << "Test 7: Remove from last\n";
    list.removeFromLast();
    list.print();  // Expected: 15 10 30
    assert(list.tail->data == 30);

    // Test 8: Remove from index (middle)
    std::cout << "Test 8: Remove from index 1\n";
    list.removeFromIndex(1);
    list.print();  // Expected: 15 30
    assert(list.head->next->data == 30);

    // Test 9: Find element
    std::cout << "Test 9: Find element 15\n";
    int index = list.findElement(15);
    std::cout << "Index of 15: " << index << "\n";  // Expected: 0
    assert(index == 0);

    // Test 10: Find non-existent element
    std::cout << "Test 10: Find element 100\n";
    index = list.findElement(100);
    std::cout << "Index of 100: " << index << "\n";  // Expected: -1
    assert(index == -1);

    std::cout << "DoubleLinkedList tests completed.\n\n";

}
void runScenarioLinkedList() {
    std::cout << "Testing LinkedList...\n";
    LinkedList<int> list;
  // Test 1: Add to empty list (addToFirst)
    std::cout << "Test 1: Add 10 to first\n";
    list.addToFirst(10);
    list.print();  // Expected: 10
    assert(list.head->data == 10 && list.tail->data == 10);

    // Test 2: Add to first
    std::cout << "Test 2: Add 20 to first\n";
    list.addToFirst(20);
    list.print();  // Expected: 20 10
    assert(list.head->data == 20 && list.tail->data == 10);

    // Test 3: Add to last
    std::cout << "Test 3: Add 30 to last\n";
    list.addToLast(30);
    list.print();  // Expected: 20 10 30
    assert(list.tail->data == 30);

    // Test 4: Add to index (middle)
    std::cout << "Test 4: Add 15 to index 1\n";
    list.addToIndex(15, 1);
    list.print();  // Expected: 20 15 10 30
    assert(list.head->next->data == 15);

    // Test 5: Add to invalid index (should add to last)
    std::cout << "Test 5: Add 40 to index 10\n";
    list.addToIndex(40, 10);
    list.print();  // Expected: 20 15 10 30 40
    assert(list.tail->data == 40);

    // Test 6: Remove from first
    std::cout << "Test 6: Remove from first\n";
    list.removeFromFirst();
    list.print();  // Expected: 15 10 30 40
    assert(list.head->data == 15);

    // Test 7: Remove from last
    std::cout << "Test 7: Remove from last\n";
    list.removeFromLast();
    list.print();  // Expected: 15 10 30
    assert(list.tail->data == 30);

    // Test 8: Remove from index (middle)
    std::cout << "Test 8: Remove from index 1\n";
    list.removeFromIndex(1);
    list.print();  // Expected: 15 30
    assert(list.head->next->data == 30);

    // Test 9: Find element
    std::cout << "Test 9: Find element 15\n";
    int index = list.findElement(15);
    std::cout << "Index of 15: " << index << "\n";  // Expected: 0
    assert(index == 0);

    // Test 10: Find non-existent element
    std::cout << "Test 10: Find element 100\n";
    index = list.findElement(100);
    std::cout << "Index of 100: " << index << "\n";  // Expected: -1
    assert(index == -1);

    std::cout << "LinkedList tests completed.\n\n";


}
int main() {
    runScenarioForDoubleLinkedList();
    runScenarioLinkedList();
    return 0;
}