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
public class LinkedListsFall21 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       LinkedList ll = new LinkedList();
//       ll.print();
       System.out.println("adding");
       ll.add(5);
       ll.add(7);
       ll.add(4);
       ll.add(3);
       ll.add(2);
       ll.add(9);
       ll.add(10);
       ll.print();
       ll.search(7);
       ll.search(99);
       ll.deleteNode(10);
       ll.printBackwards();
       ll.print();
       
       
       
//        ll.add(4);
//        ll.add(6);
//        ll.add(16);
//        ll.print();
//        ll.search(4);
//        ll.search(78);
//        ll.deleteNode(6);
//        ll.print();
//        ll.printBackwards();

//        ll.print();
        
    } 
}
