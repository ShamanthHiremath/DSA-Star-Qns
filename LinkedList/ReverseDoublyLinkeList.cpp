#include<iostream>
using namespace std;

// Definition of LinkedListNode class (assuming it's something like this)
template <typename T>
class LinkedListNode {
public:
    T data;
    LinkedListNode* next;
    LinkedListNode* prev;

    LinkedListNode(T value) : data(value), next(nullptr), prev(nullptr) {}
};

LinkedListNode<int>* reverseLinkedList(LinkedListNode<int>* &head, LinkedListNode<int>* &tail) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    LinkedListNode<int>* temp = head;
    LinkedListNode<int>* curr = head->next;

    while (curr != NULL) {
        temp->next = temp->prev;
        temp->prev = curr;
        curr->next = temp;
        curr->prev = curr->next;
        temp = temp->prev;
        curr = curr->prev;
    }
    temp = head;
    head = tail;
    tail = temp;
    return head;
}

void printLinkedList(LinkedListNode<int>* &head) {
    LinkedListNode<int>* temp = head;
    int len = 0;
    cout << "The Linked List is: ";
    while (temp != NULL) {
        len++;
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl << "Linked List Length = " << len << endl << endl;
}

int main() {
    // Create a sample doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
    LinkedListNode<int>* head = new LinkedListNode<int>(1);
    head->next = new LinkedListNode<int>(2);
    head->next->prev = head;
    head->next->next = new LinkedListNode<int>(3);
    head->next->next->prev = head->next;
    head->next->next->next = new LinkedListNode<int>(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new LinkedListNode<int>(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new LinkedListNode<int>(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    cout << "Original Doubly Linked List: ";
    printLinkedList(head);

    LinkedListNode<int>* tail = head->next->next->next->next->next ;
    head = reverseLinkedList(head, head->next->next->next->next->next );

    cout << "Reversed Doubly Linked List: ";
    printLinkedList(head);

    return 0;
}
