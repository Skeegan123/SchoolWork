/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package employeedriver;

/**
 *
 * @author mcfee
 */
public class Commissioned extends Employee{
    double cr;
    int sales;
    int id;
    
    Commissioned() {}
    
    Commissioned(String firstName, String lastName, double cr, int sales) {
        first = firstName;
        last = lastName;
        this.cr = cr;
        this.sales = sales;
        counter++;
        this.id = counter;
    }
    
     public String toString() {
         return "Employee ID: " + id + ", First: " + first + ", Last: " + last + ", Percent: " + cr * 100 + ", Sales: " + sales;
     }
}
