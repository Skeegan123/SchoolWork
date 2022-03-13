/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package linkedlistsfall21;

/**
 *
 * @author Hunter
 */
public class LinkedList2 {
    
    private Node2 first;
    
    
    LinkedList2()
    {
        first = null;
    }
  
    public void deleteList()
    {
        first = null;
    }
    public void add(int x){
       
        Node2 temp  = new Node2(x);
        
            temp.setNext(first);
            if(first != null)
               first.setPrev(temp);
            first = temp;   
       
    }
    public void print()
    {
        Node2 temp = first;
        
        while(temp !=  null)    
        {
            System.out.println(temp.getData());
            temp = temp.getNext();
        }
            
     }
    
    public void search(int index)
    {
        Node2 temp = first;
        
        while(temp !=  null)    
        {
            if (temp.getData() == index)
            {
                System.out.println("Found " + index);
                return;
             }
            temp = temp.getNext();
        }
        
        System.out.println("Didn't find " + index);
            
     }
    public void deleteNode(int x){
        Node2 temp = first;
        
        if(temp == null)
            return;
        
        if (temp.getData() == x)
        {
            first.getNext().setPrev(null);
            first = temp.getNext();
            return;
        }
        else{
           //lagptr = first;
            temp = temp.getNext();
        }
        while(temp !=  null)    
        {
            if (temp.getData() == x)
            {
                temp.getPrev().setNext(temp.getNext());
                temp.getNext().setPrev(temp.getPrev());
                return;
             }
            //lagptr = temp;
            temp = temp.getNext();
        }
        
        System.out.println("Didn't find " + x);
    }
    
}
