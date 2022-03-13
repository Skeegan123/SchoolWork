
public class Node<E>
{
    private E data;
    private Node<E> next;
    private Node<E> previous;
    
    public Node (E data)
    {
        this.data = data;
        this.next = null;
        this.previous = null;
    }
    
    public void setNext(Node<E> what)
    {
        this.next = what;
    }
    
    public void setPrevious(Node<E> what)
    {
        this.previous = what;
    }
    
    public E getData()
    {
        return data;
    }
    
    public Node<E> getNext()
    {
        return next;
    }
    
    public Node<E> getPrevious()
    {
        return previous;
    }
    
  

}
