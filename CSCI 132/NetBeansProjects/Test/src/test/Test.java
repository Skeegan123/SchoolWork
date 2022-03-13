/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test;

/**
 *
 * @author Keegans Laptop
 */
public class Test {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        TQ spoon = new TQ();
        TQ fork = new TQ("A");
        fork = spoon.test(new TQ("C"), spoon);
        
        System.out.println(spoon.getName());
        System.out.println(fork.getName());
        System.out.println(fork.getNum());
}
}
