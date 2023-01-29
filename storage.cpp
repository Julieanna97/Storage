#include <iostream>
#include <cstring>

using namespace std;

// Represent a node of singly linked list in C++
class Node
{
public:
    int data;
    Node *next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Constructor with data
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

};

class Storage
{
public:
    Node *head;

    /** Default constructor
     * 
    */
    Storage()
    {
        head = NULL;
    }
    
    /* Linked list functions */

    /** Create a Node to hold the data, then put it at the head of the list.
     * @param data The data for the new node
    */
    void push(int data);

    /** Remove the head Node and return its data.
     * 
     * @param [out] The data (only valid if return true)
     * @return True if there is a node to return
    */
    bool pop(int &data);

    /**
     * Return the data from the head Node, without removing it.
     * 
     * @param [out] The data (only valid if return true)
     * @return True if text has been returned successfully (there is a node)
    */    
    bool peek(int &data);

    /**
     * Return True if the list is empty, otherwise False  
     * 
     * @return True if the list is empty, otherwise False
    */
    bool isEmpty();

    /**
     * Swaps the nodes at position i and j.
     * 
     * @return Returns true if successful, otherwise false (e.g. outside range)
    */
    bool swap(int i, int j);
    

   /**
    * @brief Prints a given linked list
    * 
    */
   void printList();

};

// Function that will add a new node to the storage
void Storage::push(int data)
{
    // allocate space for new node in heap
    Node *newNode = new Node(data);

    // check if stack/heap is full.
    // Inserting an element would
    // lead to stack overflow
    if(!newNode)
    {
        cerr << "Log of negative number is: " << errno << "\n";
        cerr << "Cause of error: " << strerror(errno) << endl;
        exit(-1);
    }

    // checks if storage is empty
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        // new node will be added after head
        // that head will point to new node
        Node *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        // next node will become new node of the storage
        temp->next = newNode;
    }
}

// Function to remove a key from the beginning
bool Storage::pop(int &data) // remove node at the beginning
{
    if(head == NULL)
    {
        cout << "List is empty." << endl;
        return false;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        cout << "Popped value is: " << temp->data << endl;
        delete temp;
        return true;
    }
}

// Function that returns the top element in a stack
bool Storage::peek(int &data)
{
    Node *newNode = head;
    // if stack is empty
    if(head == NULL)
    {
        return false;
    }
    else
    {
        // if stack is not empty, return the top element
        cout << "Top element is " << newNode->data << endl;
        newNode = newNode->next;
        return true;
    }
}

// Function to check if the storage is empty or not
bool Storage::isEmpty()
{
    // If head is NULL it means that
    // there are no elements in the storage
    if(head == NULL)
    {
        cout << "List is empty" << endl;
        return true;
    }
    else
    {
        // if stack is filled
        cout << "List is not empty" << endl;
        return false;
    }

}

// Function to swap two node values
bool Storage::swap(int i, int j)
{
    // if i and j are equal, then the list will remain the same
    if(i == j)
    {
        return true;
    }

    // count how many nodes there are in the list
    int count = 0;
    Node *temp = head;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    Node *p1 = head;
    Node *p2 = head;

    // checks if storage is empty
    if(p1 && p2 == NULL)
    {
        cerr << "Swapping is not possible" << endl;
        return false;
    }

    // traverse to the nodes where given values to be swapped
    for(int k = 1; k < i; k++)
    {
        p1 = p1->next;
    }
    for(int l = 1; l < j; l++)
    {
        p2 = p2->next;
    }

    // swap the values of two nodes
    int val = p1->data;
    p1->data = p2->data;
    p2->data = val;

    return true;

}

void Storage::printList()
{
    Node *temp = head;

    // Check for empty list.
    if(head == NULL)
    {
        cerr << "List empty" << endl;
        return;
    }

    // Traverse the list
    while(temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
        if(temp != NULL)
        {
            cout << " -> ";
        }
    }

    cout << " -> None" << endl;
}

int main()
{
    // create an instance (object) of a class
    Storage *s = new Storage();
    // stores the specific index position of list in peek() function
    int peek;

    s->push(1);
    s->printList();
    s->push(2);
    s->printList();
    s->push(3);
    s->printList();
    s->push(4);
    s->printList();
    s->push(5);
    s->printList();

    s->isEmpty();
    s->peek(peek);
    int pop;
    s->pop(pop);
    cout << "Result after removing the first element: " << endl;
    s->printList();
    s->peek(peek);
    s->push(5);
    s->printList();
    s->swap(1, 5);
    cout << "After swapping between 2 nodes: " << endl;
    s->printList();

    return 0;
}