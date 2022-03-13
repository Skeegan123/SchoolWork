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
public class Hourly extends Employee{
    double wage;
    int hours;
    int id;
    
    Hourly() {}
    
    Hourly(String firstName, String lastName, double wage, int hours) {
        first = firstName;
        last = lastName;
        this.wage = wage;
        this.hours = hours;
        counter++;
        this.id = counter;
        
    }
    
     public String toString() {
         return "Employee ID: " + id + ", First: " + first + ", Last: " + last + ", Wage: " + wage + ", Hours: " + hours;
     }
}
