/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pythontojava00;

/**
 *
 * @author Keegans Laptop
 */
public class Baby {
   private String name;
   
   private int weight;
    public Baby(String n){
        name = n;
        weight = 0;
    }
    
    public void cry(){
        System.out.println("Waaahhhh says " + name);
    }
    
    public void setWeight(int amt){
        weight += amt;
    }
    
    public int getWeight(){
        return weight;
    }
    
}
