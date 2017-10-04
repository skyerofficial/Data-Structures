#Class to create a node with key and next pointer
class Node:

#Constructor to initialize key & node    
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = None

#Class contains methods to perform operation on linklist
class LinkList:

#Constructor of the class to initialize head node
    def __init__(self):
        self.head = None

#Method to add node at the beginning of linllist
    def add_beg(self, data):
        node = Node(data)
        if self.head == None:
            self.head = node
        else:
            node.next = self.head
            self.head = node

#Method to add node at the end of linklist
    def add_end(self, data):
        node = Node(data)
        p = self.head
        if p != None:
            while p.next != None:
                p = p.next
            p.next = node

#Method to print nodes of linklist
    def print_list(self):
        node = self.head
        while node:
            print(node.data + " ")
            node = node.next

#Main method
def main():
    l = LinkList()
    val = input("enter the node value: \n")
    while val != -1:
        place = input("enter 0 for beg and 1 for insertion at end: \n")
        if place == 0:
            l.add_beg(val)
        else:
            l.add_end(val)
        val = input("enter the node value: \n")
    l.print_list()

main()
