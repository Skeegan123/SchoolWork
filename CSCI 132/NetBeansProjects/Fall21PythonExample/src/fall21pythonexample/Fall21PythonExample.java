/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fall21pythonexample;

/*m
 *
 * @author Keegans Laptop
 */
public class Fall21PythonExample {
    
    private static int javaMethod(int a) {
        a = 77;
        System.out.println("Something " + a);
        return a;
    }

    /*
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int a = 99;
        a = javaMethod(a);
        System.out.println("Main " + a);
    }
    
}
