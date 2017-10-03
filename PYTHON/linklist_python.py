class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = None

class LinkList:
    def __init__(self):
        self.head = None

    def add_beg(self, data):
        node = Node(data)
        if self.head == None:
            self.head = node
        else:
            node.next = self.head
            self.head = node

    def add_end(self, data):
        node = Node(data)
        p = self.head
        if p != None:
            while p.next != None:
                p = p.next
            p.next = node

    def print_list(self):
        node = self.head
        while node:
            print(node.data + " ")
            node = node.next

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
