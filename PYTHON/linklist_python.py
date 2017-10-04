class Node:
     # Each node has its data and a pointer that points to next node in the Linked List
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = None

class LinkList:
    # Defining the head of the linked list
    def __init__(self):
        self.head = None

# inserting the node at the beginning
    def add_beg(self, data):
        node = Node(data)
        if self.head == None:
            self.head = node
        else:
            node.next = self.head
            self.head = node

 # inserting at the end of linked list
    def add_end(self, data):
        node = Node(data)
        p = self.head
        if p != None:
            while p.next != None:
                p = p.next
            p.next = node

    def insertNode(self):
        val = input("enter the node value: \n")
        while val != -1:
            place = input("enter 0 for beg and 1 for insertion at end: \n")
            if place == 0:
                self.add_beg(val)
            else:
                self.add_end(val)
            val = input("enter the node value: \n")

# deleting an item based on data(or key)
    def del_node(self, data):
        p = self.head
        if p != None:
            # if data/key is found in head node itself
            if(p.data == data):
                self.head = p.next
                del p
                return
            else:
                while p.next != None:
                    if (p.data == data):
                        break
                    sav = p
                    p = p.next

                #node not found
                if(p.data != data):
                    print("Node not found")
                    return

                sav.next = p.next
                return

    def print_list(self):
        node = self.head
        while node:
            print node.data
            node = node.next


def main():
    l = LinkList()
    case = input("Enter your choice - \n1:InsertNode,\n2:DeleteNode\n")
    while case != -1:
        if(case == 1):
            l.insertNode()
            l.print_list()
        if(case == 2):
            val = input("\nEnter the node value to be deleted:\n")
            l.del_node(val)
            l.print_list()
        case = input("Enter your choice\n1:InsertNode,\n2:DeleteNode\n")
        if(case == -1):
            raise SystemExit

main()
