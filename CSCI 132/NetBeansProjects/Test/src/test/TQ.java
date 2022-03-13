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
public class TQ {
    private String name;
    private static int num = 0;
    TQ() {
        name = "G";
        num++;
    }
    TQ(String n) {
        name = n;
        num++;
    }
    
    public static int getNum() {
        return num;
    }
    
    public String getName() {
        return name;
    }
    
    public void changeName(String temp) {
        name = temp;
    }
    
    public TQ test(TQ plate, TQ glass) {
        
        TQ bowl = plate;
        bowl = new TQ("F");
        glass = plate;
        glass.changeName("Q");
        
        System.out.println(glass.getName());
        System.out.println(bowl.getName());
        System.out.println(plate.getName());
        
        return this;
    }
   
}
