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
public class LinkedList {
    private Node first;
    private Node last;
    private int i = 0;
    private int j = 0;
    
    public void print(){
        Node iter = first;
        while(i > j)
        {
            System.out.println(iter.getData());
            iter = iter.getNext();
            j++;
        }
        j = 0;
    }
    
    public void printBackwards(){
        Node iter = last;
        while(i+1 > j)
        {
            System.out.println(iter.getData());
            iter = iter.getPrev();
            j++;
        }
        j = 0;
    }
    
    public void add(int num){
        Node temp = new Node(num);
        if(first == null)
        {
            first = temp;
            last = temp;
            first.setNext(last);
            first.setPrev(last);
            i++;
       
        } 
        else{
            temp.setNext(first);
            temp.setPrev(last);
            first.setPrev(temp);
            first = temp;
            last.setNext(first);
            i++;
         }
        
        
    }
    public void search(int num){
        Node iter = first;
        while(i != j)
        {
            if(iter.getData() == num){
                 System.out.println("Found " +  iter.getData());
                 return;
            }
             iter = iter.getNext();
             j++;
        }
        j = 0;
        System.out.println("Didn't find " + num);
    }
    public boolean deleteNode(int num){
        Node iter = last;
        Node curr = first;
        i--;
        
        System.out.println("last " + last.getData());
        
        while(i > j)
        {
            
            if(iter.getData() == num)
            {
                if (iter == first) {
//                    System.out.println(last.getData());
                    first = first.getNext();
//                    System.out.println(last.getData());
                    first.setPrev(last);
                    last.setNext(first);
//                    i--;
//                    j++;
                    return true;
                } else if (iter == last) {
//                    System.out.println("last");
                    last = last.getPrev();
//                    System.out.println(last.getData());
                    last.setNext(first);
                    first.setPrev(last);
//                    i--;
//                    j--;

//                    curr = first;
//                    iter = last.getPrev();
//                    iter.setNext(curr);
//                    curr.setPrev(iter);
                    return true;
                } else {
//                    System.out.println(last.getData());
                    curr = iter.getNext();
                    iter = iter.getPrev();
                    iter.setNext(curr);
                    curr.setPrev(iter);
//                    System.out.println(last.getData());
//                    i--;
                    System.out.println("Deleted " + num);
//                    j++;
    //                printBackwards();
    //                print();
                    return true;
                }
                
            }
            iter = iter.getNext();
            j++;
        }
        j = 0;
        
    
        return false;
    }
    
//    public boolean deleteNode(int num){
//        Node iter = first;
////        i--;
//        
//        while(i < j)
//        {
////            System.out.println("check");
////            System.out.println(iter.getData());
//            
//            if (iter == first && iter.getData() == num) {
//                first = first.getNext();
//                first.setPrev(last);
//                return true;
//            }
//            else if (iter == last && iter.getData() == num) {
//                last = last.getPrev();
//                last.setNext(first);
//                return true;
//            }
//            else if (iter.getData() == num){
//                iter = iter.getNext();
//                iter.setPrev(iter.getPrev().getPrev());
//                i--;
//                System.out.println("Deleted " + num);
////                printBackwards();
////                print();
//                return true;
//            }
//            iter = iter.getNext();   
//            j++;
//        }
//        j = 0;
//        
//        
//        return false;
//    }
    
    
}
