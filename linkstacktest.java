class Node
{
    protected int data;
    protected Node link;
    public Node()
    {
        link=null;
        data=0;
    }
    public Node(int d,Node n)
    {
        data=d;
        link=n;
    }
    public void setlink(Node n)
    {
        link=n;
    }
    public void setdata(int d)
    {
        data=d;
    }
    public Node getlink()
    {
        return link;
    }
    public int getdata()
    {
        return data;
    }
}
class linkedstack
{
    protected Node top;
    protected int number;
    public linkedstack()
    {
      top=null;
        number=0;
    }
    public boolean isempty()
    {
        return top==null;
    }
    public int size()
    {
        return number;
    }
    public void push(int obj)
    {
        top=new Node(obj,top);
        number++;
    }
    public int pop()
    {
        if(isempty())
        
            return 0;
        Node tmp=top;
        top=tmp.getlink();
        number--;
        return tmp.getdata();
    }
    public int peep()
    {
        if(isempty())
        return 0;
        return top.getdata();
    }
}
public class linkstacktest
{
    protected static linkedstack s;
    public static void main(String args[])
    {
        int i;
        s=new linkedstack();
        for(int a=0;a<5;a++)
        {
            i=(int)(Math.random()*100);
            s.push(i);
            System.out.println("Pushed :"+i);
        }
        int pp=s.peep();
        System.out.println("At top "+ pp);
        System.out.println();
        while(!s.isempty())
        {
            System.out.println("Popped :"+s.pop());
        }
    }
}