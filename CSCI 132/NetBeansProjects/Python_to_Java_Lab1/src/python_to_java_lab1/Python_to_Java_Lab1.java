/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package python_to_java_lab1;

/**
 *
 * @author Keegans Laptop
 */
public class Python_to_Java_Lab1 {
    public static void firstCall(int a){
        if (a == 4) {
            System.out.println("Four");
        } else if (a == 2) {
            System.out.println("Two");
        } else {
            System.out.println("Neither number");
        }
    }
    
    public static String secondCall(String b) {
        System.out.println(b);
        return "MSU";
    
    
    public static void thirdCall() {
        for (int i = 0; i < 3; i++) {
            System.out.println(i);
        }
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        firstCall(2);
        String answer = secondCall("Bobcats");
        firstCall(4);
        thirdCall();
        System.out.println("The last answer is: " + answer);
    }
    
}
