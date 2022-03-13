/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package football.project;

/**
 *
 * @author Keegans Laptop
 */
public class LinkedList {
    
    FileOut fout = new FileOut("output.txt");
    
    private Node first;
    private Node last;
    private int i = 0;
    private int j = 0;
    public int y = 0;
    public int z = 0;
    
    Node cow;
    Node stun;
    int cowNum = 0;
    int stunNum = 0;
    
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
    
    public boolean deleteNode(int num){
        Node iter = first;
        Node curr = first;
        i--;
        
        while(i*100 != j)
        {
            if (iter == null) {
                return false;
            }
            else if(iter.getData() == num)
            {
                if (iter == iter.getNext()) {
                
                first = null;
                last = null;
                return true;
                } else if (iter == first) {
                    first = first.getNext();
                    first.setPrev(last);
                    last.setNext(first);
                    return true;
                } else if (iter == last) {
                    last = last.getPrev();
                    last.setNext(first);
                    first.setPrev(last);
                    return true;
                } else {
                    curr = iter.getNext();
                    iter = iter.getPrev();
                    iter.setNext(curr);
                    curr.setPrev(iter);
                    return true;
                }
                
            }
            
            iter = iter.getNext();
            j++;
        }
        j = 0;
        if (iter == null) {
            return false;
        }
    
        return false;
    }
    
    public void createList(int num) {
        for (int N = 0; N < num; N++) {
            add(N+1);
        }
        cow = last;
        stun = first;
    }
    
    
    public int stun(int num) {
        for (int k = 0; k < num; k++) {
            stun = stun.getPrev();
        }
        return stun.getData();
    }
    
    public void stunNext() {
        stun = stun.getPrev();
    }
    
    public int cow(int num) {
        for (int m = 0; m < num; m++) {
            cow = cow.getNext();
        }
        return cow.getData();
    }
    
    public void cowNext() {
        cow = cow.getNext();
    }
    
    public void decide(int cowInput, int stunInput) {
               
        cowNum = cowInput;
        stunNum = stunInput;
                
        if (!deleteNode(stunNum)) {
            fout.writer("");
            fout.writer("End of Program " + y);
            System.exit(0);
        } 
        else if (cowInput == stunInput) {
            fout.writer(cow.getData());
            int k = cowInput;
            cowNext();
            stunNext();
            deleteNode(k);
        } else {
            fout.write(stun.getData() + " ");
            fout.write(cow.getData() + "\n");
            int s = stun.getData();
            int c = cow.getData();
            if (cow.getNext().getData() == stun.getData()) {
                cowNext();
            } else if (stun.getPrev().getData() == cow.getData()) {
                stunNext();
            }
           
            deleteNode(s);
            deleteNode(c);
        }
    }
    
    public void game(int[] par) {
        
        y++;
        
        fout.writer("Program " + y);
        fout.writer("---------");
        fout.writer("");
        fout.write("N = ");
        fout.write(par[0]);
        fout.write(", k = ");
        fout.write(par[1]);
        fout.write(", m = ");
        fout.write(par[2]);
        fout.writer("");
        fout.writer("");
        fout.writer("Output");
        fout.writer("------");

        
        createList(par[0]);
        
        int cowPar = par[2];
        int stunPar = par[1];
        
        do {

            decide(cow(cowPar), stun(stunPar));

        } while (first != null);
        
        fout.writer("");
        fout.writer("End of Program " + y);
        fout.writer("");

    }
}
