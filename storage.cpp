#include <iostream>
#include <cstring>

using namespace std;

// Represent a stack list in C++
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
    * @brief Prints a given stack
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
    // and sets the new value to given push() parameter
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        // next new node will be assigned as head like stack
        // last-in first-out (LIFO)
        // that head will point to new node
        newNode->next = head;
        head = newNode;
    }
}

// Function to remove a key from the beginning
bool Storage::pop(int &data)
{
    Node *newNode = head;

    if(newNode == NULL)
    {
        cout << "Stack is empty." << endl;
        return false;
    }
    else
    {
        cout << "The popped element is " << newNode->data << endl;
        head = newNode->next;
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
        cout << "Stack is empty" << endl;
        return true;
    }
    else
    {
        // if stack is filled
        cout << "Stack is not empty" << endl;
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
    for(int k = 0; k < i; k++)
    {
        p1 = p1->next;
    }
    for(int l = 0; l < j; l++)
    {
        p2 = p2->next;
    }

    // swap the values of two nodes
    int val = p1->data;
    p1->data = p2->data;
    p2->data = val;

    return true;

}
// Function to print the nodes in linked list
void Storage::printList()
{
    Node *temp = head;

    if(head == NULL)
    {
        cerr << "Stack is empty" << endl;
    }
    else
    {
        // Traverse the list
        cout << "Stack elements are: ";
        cout << "None -> ";
        while(temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
    }
    cout << endl;

}

// Main function for execution
int main()
{
    // create an instance (object) of a class
    Storage *s = new Storage();
    int pop = 0, peek = 0;

    // appends values to the stack
    s->push(1);
    // prints the stack
    s->printList();
    s->push(2);
    s->printList();
    s->push(3);
    s->printList();
    s->push(4);
    s->printList();
    s->push(5);
    s->printList();
    // checks if the storage is empty or not
    s->isEmpty();
    // removes the node from the top
    s->pop(pop);
    s->printList();
    s->pop(pop);
    s->printList();
    s->push(10);
    s->printList();
    // prints the top node in the stack
    s->peek(peek);
    s->push(19);
    s->printList();
    s->peek(peek);
    s->pop(pop);
    s->printList();
    cout << "\nBefore swapping: " << "\n";
    s->printList();
    // swapping nodes at index 0 & 2
    s->swap(0, 2);
    cout << "\nAfter swapping: " << endl;
    s->printList();

    return 0;
}
