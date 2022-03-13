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
public class CommissionBase extends Commissioned{
    int base;
    int id;
    
    CommissionBase() {}
    
    CommissionBase(String firstName, String lastName, double cr, int sales, int base) {
        super(firstName, lastName, cr, sales);
        this.base = base;
        
        this.id = counter;
    }
    
     public String toString() {
         return "Employee ID: " + id + ", First: " + first + ", Last: " + last + ", Commission Rate: " + cr + ", Sales: " + sales + ", Base: " + base;
     }
}
