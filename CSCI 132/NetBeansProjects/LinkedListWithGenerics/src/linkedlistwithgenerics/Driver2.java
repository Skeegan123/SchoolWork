import java.util.LinkedList;
import java.util.Iterator;

public class Driver2
{
    public static void main (String [] args)
    {
        Iterator pointer;
        
        LinkedList<Integer> myList = new LinkedList<Integer>();
        
        for (int i = 1; i <= 5; i++)
        {
            myList.add(i);
        }
        
        // inefficient print
        for (int i = 0; i < 5; i++)
        {
            System.out.println(myList.get(i));
        }
        
        // efficient print - uses an iterator
        pointer = myList.iterator();
        while (pointer.hasNext())
        {
            System.out.println(pointer.next());
        }
        
        // efficient print - uses an enhanced for loop that implicitly
        // uses an iterator
        for (int number: myList)
        {
            System.out.println(number);
        }
    }
}
