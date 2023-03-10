import sys
# Represent a stack list in Python3
class Node:
    # create nodes of stack
    # constructor using data
    def __init__(self, data):
        self.data = data
        self.next = None

    # returns a string representation of the data
    def __str__(self):
        return str(self.data)


class Storage:

    # default constructor
    # head is default NULL
    def __init__(self):
        self.head = None

    # adds data to the stack
    # adds data to the end of the stack
    def push(self, data):
        new_node = Node(data)

        if(not new_node):
            print("Stack overflow!!!")
            sys.exit(0);
        
        if self.head is None:
            self.head = new_node
        else:
            new_node.next = self.head
            self.head = new_node

    # Function to remove the first element/current head (start of the stack)
    def pop(self):
        if(self.head == None):
            return 'Stack is empty'
        else:
            # Removes the current head node
            # makes the new value the new head
            result = self.head.data
            self.head = self.head.next
            print(f"Popped value is: {result}")
            return result
    
    # Function that returns the top of element in a stack
    def peek(self):
        if (self.head == None):
            raise Exception("Peeking from an empty stack")
            return None
        else:
            new_node = self.head
            print(f"Top element is {new_node.data}")
            return new_node.data

    # Checks if stack is empty
    def isempty(self):
        if self.head is None:
            print("Stack is empty")
            return True
        else:
            print("Stack is not empty")
            return False
    
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
        if(i < 0 or i > count or j < 0 or j > count):
            return i, j
        
        p1 = self.head
        p2 = self.head

        # checks if storage is empty
        if(p1 and p2 is None):
            print("Swapping is not possible")

        # traverse to the nodes where given values to be swapped
        for i in range(1, i):
            p1 = p1.next
        for i in range(1, j):
            p2 = p2.next
        
        # swap the values of two nodes
        val = p1.data
        p1.data = p2.data
        p2.data = val

    # prints out the stack
    def __str__(self):
        node = self.head
        my_str = ""
        my_str += "None -> "

        while node is not None:
            my_str += f"{node.data} -> "
            node = node.next

        return my_str

# Driver code
if __name__ == '__main__':
    s = Storage()

    # Add new elements in the stack
    s.push(100)
    print(s)
    s.push(3)
    print(s)
    s.push(19)
    print(s)
    s.push(15)
    print(s)
    s.push(10)
    print(s)
    s.push(95)

    print(s)
    s.isempty()
    s.swap(1, 6)
    print(s)
    s.peek()
    s.pop()
    print(s)