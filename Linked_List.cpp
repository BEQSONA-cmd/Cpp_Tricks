#include <iostream>

// Linked List

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
    private:
        Node *head = NULL;
    public:
        void addNode(int data);
        void printList();
        void deleteList();
};

void LinkedList::addNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void LinkedList::printList()
{
    Node *current = head;
    while (current != NULL)
    {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}

void LinkedList::deleteList()
{
    Node *current = head;
    Node *next;
    while (current != NULL)
    {
        next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
}

// Doubly Linked List

struct DNode
{
    int data;
    DNode *next;
    DNode *prev;
};

class DoublyLinkedList
{
    private:
        DNode *head = NULL;
    public:
        void addNode(int data);
        void printList();
        void deleteList();
};

void DoublyLinkedList::addNode(int data)
{
    DNode *newNode = new DNode;
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

void DoublyLinkedList::printList()
{
    DNode *current = head;
    while (current != NULL)
    {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}

void DoublyLinkedList::deleteList()
{
    DNode *current = head;
    DNode *next;
    while (current != NULL)
    {
        next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
}

int main(void)
{
    // LinkedList list
    LinkedList list;
    
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);

    list.printList();

    list.deleteList();

    // Doubly Linked List
    DoublyLinkedList dlist;

    dlist.addNode(1);
    dlist.addNode(2);
    dlist.addNode(3);
    
    dlist.printList();

    dlist.deleteList();

    return 0;
}
