import java.io.*;
class node
{
    int data;
    node prev,next;
    public node(int x)
    {
        data=x;
    next=null;
    }
}
class SLL
{
    node start=null;
    public void insertFirst(int x)
    {
    if (isEmpty())
    {
            node p=new node(x);
            start=p;
    }
    else
    {
            node p=new node(x);
            p.next=start;
            start=p;
    }
    }
    public void insertLast(int x)
    {
    if (isEmpty())
    {
            node p=new node(x);
            start=p;
    }
    else
    {
            node p=new node(x);
            node current=start;
            while(current.next!=null)
            current=current.next;
            current.next=p;
            p.next=null;
    }
    }
    public void insertAt(int x,int pos)
    {
    if (isEmpty())
    {
            node p=new node(x);
            start=p;
    }
    else
    {
            int i=1;
            node current=start;
            if (pos>0)
            {
                while (current!=null)
        {
                    if (i==pos-1)
                    {
            node p=new node(x);
            p.next=current.next;
            current.next=p;
                        return ;
                    }
                    else
                    {
            current=current.next;
            i++;
                    }
        }
            }
            else
                System.out.println("Wrong position!");
    }
    }
    public boolean isEmpty()
    {
    if(start==null)
            return true;
    else
            return false;
    }
    public int removeFirst()
    {
    if (isEmpty())
    {
            System.out.println("The list is empty");
            return 0;
    }
    else
    {
            int x=start.data;
            start=start.next;
            return x;
    }
    }
    public int removeLast()
    {
    if (isEmpty())
    {
            System.out.println("The list is empty");
            return 0;
    }
    else
    {
            node current=start;
            while (current.next.next!=null)
                current=current.next;
            int x=current.next.data;
            current.next=null;
            return x;
        }
    }
    public int removeAt(int pos)
    {
    if (isEmpty())
    {
            System.out.println("The list is empty");
            return 0;
    }
    else
    {
            int i=0;
            node current=start;
            if (pos>0)
            {
                while(current!=null)
                {
                    if(i==pos-2)
                    {
                        int d=current.next.data;
                        current.next=current.next.next;
                        return d;
                    }
                    else
                    {
                        current=current.next;
                        i++;
                    }
                }
            }
            else
            {
                System.out.println("Wrong position!");
        return 0;
            }
        }
        return 0;
    }
    public int search(int x)
    {
    if (isEmpty())
    {
            System.out.println("The list is empty");
            return -1;
    }
    else
    {
            node current=start;
            int c=1;
            while (current!=null)
            {
        if(current.data==x)
                    return c;
        else
                    current=current.next;
                c++;
            }
        }
        return -1;
    }
    public void display()
    {
    if (isEmpty())
            System.out.println("The list is empty");
    else
    {
            node current=start;
            while (current!=null)
            {
        System.out.print(current.data+" ");
        current=current.next;
            }
    }
    }
}
public class Sl
{
    public static void main(String[] args) throws IOException
    {
        InputStreamReader obj=new InputStreamReader(System.in);
    BufferedReader r=new BufferedReader(obj);
    int ch;
        SLL s=new SLL();
    do
    {
            System.out.println("Menu");
            System.out.println("1.Insert");
            System.out.println("2.Remove");
            System.out.println("3.Search");
            System.out.println("4.Display");
            System.out.println("5.Exit");
            System.out.println("Enter your choice:");
            ch=Integer.parseInt(r.readLine());
            switch (ch)
            {
                case 1:
                    System.out.println("1.Insert at position");
                    System.out.println("2.Insert at first");
                    System.out.println("3.Insert at last");
                    System.out.println("Enter your choice:");
                    int al=Integer.parseInt(r.readLine());
                    switch (al)
                    {
                        case 1:
                            System.out.println("Enter an element");
                            int x=Integer.parseInt(r.readLine());
                            System.out.println("Enter its position");
                            int pos=Integer.parseInt(r.readLine());
                            s.insertAt(x,pos);
                            break;
            case 2:
                            System.out.println("Enter an element");
                            int y=Integer.parseInt(r.readLine());
                            s.insertFirst(y);
                            break;
            case 3:
                            System.out.println("Enter an element");
                            int z=Integer.parseInt(r.readLine());
                            s.insertLast(z);
                            break;
                    }
                    break;
        case 2:
                    System.out.println("1.Remove first element");
                    System.out.println("2.Remove last element");
                    System.out.println("3.Remove element at position");
                    System.out.println("Enter your choice:");
                    int al1=Integer.parseInt(r.readLine());
                    switch (al1)
                    {
                        case 1:
                            System.out.println("The element removed is: "+s.removeFirst());
                            break;
            case 2:
                            System.out.println("The element removed is: "+s.removeLast());
                            break;
            case 3:
                            System.out.println("Enter the position of the element:");
                            int pos=Integer.parseInt(r.readLine());
                            System.out.println("The element removed is:"+s.removeAt(pos));
                            break;
                    }
                    break;
        case 3:
                    System.out.println("Enter element to be searched: ");
                    int search=Integer.parseInt(r.readLine());
                    System.out.println("Element present at "+s.search(search));
                    break;
        case 4:
                    s.display();
                    break;
        case 5:
                    break;
            }
    }while(ch!=5);
    }
}
