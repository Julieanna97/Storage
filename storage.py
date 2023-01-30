# Represent a node of singly linked list in Python3
class Node:
    # create nodes of linked list
    # constructor using data
    def __init__(self, data):
        self.data = data
        self.next = None

    # return string representation of Node class
    def __str__(self):
        return self.data

class Storage:

    # default constructor
    # head is default NULL
    def __init__(self):
        self.head = None

    # adds data to the stack
    # adds data to the end of the stack
    def push(self, data):
        new_node = Node(data)
        
        if self.head is None:
            self.head = new_node
        else:
            temp = self.head
            while temp.next is not None:
                temp = temp.next
            temp.next = new_node

    # Function to remove the first element/current head (start of the stack)
    def pop(self):
        if self.head is None:
            print("List is empty")
            return None
        else:
            # Removes the current head node
            # makes the new value the new head
            temp = self.head
            self.head = self.head.next
            result = temp.data
            print(f"Popped value is: {result}")

        return result
    
    # Function that returns the top of element in a stack
    def peek(self):
        new_node = self.head
        if self.head is None:
            return False
        else:
            print(f"Top element is {new_node.data}")
            new_node = new_node.next
            return True

    # Checks if stack is empty
    def isempty(self):
        if self.head is None:
            print("List is empty")
            return True;
        else:
            print("List is not empty")
            return False;
    
    # Function to swap the given two nodes
    def swap(self, i, j):
        # if i and j are equal or null, the list will remain the same
        if(i == j):
            return
        
        # count the number of nodes in the list
        count = 0
        temp = self.head
        while(temp is not None):
            count += 1
            temp = temp.next
        
        # check if the swap positions are valid
        if(i < 1 or i > count or j < 1 or j > count):
            return i, j
        
        p1 = self.head
        p2 = self.head

        # checks if storage is empty
        if(p1 and p2 is None):
            print("Swapping is not possible")
            return False

        # traverse to the nodes where given values to be swapped
        for i in range(1, i):
            p1 = p1.next
        for i in range(1, j):
            p2 = p2.next
        
        # swap the values of two nodes
        val = p1.data
        p1.data = p2.data
        p2.data = val

        return True

    # prints out the stack
    def __str__(self):
        node = self.head
        my_str = ""

        while node is not None:
            my_str += f"{node.data} -> "
            node = node.next

        my_str += "None"
        return my_str

# Driver code
if __name__ == '__main__':
    s = Storage()

    # Add new elements in the stack
    s.push(100)
    s.push(3)
    s.push(19)
    s.push(15)

    # Display stack elements
    print(s)

    # Print top element of stack
    s.peek()

    # Delete top element of stack
    s.pop()

    print("Result after removing the first element: ")
    print(s)

    # Check if stack is empty or not
    s.isempty()
    s.peek()
    s.pop()
    print("Remaining storage values: ")
    print(s)
    
    # Swap nodes at index 1 and 2. 
    # Must contain 2 index position in the parameter.
    # Any value can be inserted as long as it exists.
    s.swap(1, 2)
    print("After swapping: ")
    print(s)
