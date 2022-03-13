/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package python_to_java;

/**
 *
 * @author Keegans Laptop
 */
public class Python_To_Java {
    
    public static void while_statement(){
        int i = 0;
        int x = 0;
        while (i < 10){
            x += i;
            i++;
            System.out.println(x);
        }
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        while_statement();
        // TODO code application logic here
    }
    
}
