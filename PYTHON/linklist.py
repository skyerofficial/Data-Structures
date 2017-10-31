#Class to create a node with key and next pointer
#------------------------------------------------
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

    def insertNode(self):
        val = input("enter the node value: \n")
        while val != -1:
            place = input("enter 0 for beg and 1 for insertion at end: \n")
            if place == 0:
                self.add_beg(val)
            else:
                self.add_end(val)
            val = input("enter the node value: \n")

    #Deleting an item based on data(or key)
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

    #Method to print nodes of link list.            
    def print_list(self):
        node = self.head
        while node:
            print node.data
            node = node.next

#Main method
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
