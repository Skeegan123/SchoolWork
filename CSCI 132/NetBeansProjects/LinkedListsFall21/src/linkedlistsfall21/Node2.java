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
public class Node2 {
    private int data;
    private Node2 next;
    private Node2 prev;
    
    public Node2(int d){ data = d;}
    public Node2 getNext(){return next;}
    public void setNext(Node2 temp) {next = temp;}
    public Node2 getPrev(){return prev;}
    public void setPrev(Node2 temp) { prev = temp;}
    public int getData(){return data;}
}
