/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab2;

import java.util.*;

/**
 *
 * @author Keegans Laptop
 */
public class Lab2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Point first = new Point(3, -5);
        Point second = new Point(first.reflect_x()[0], first.reflect_x()[1]);
        System.out.println("First " + first.getPoint() + "," + " Second " + second.getPoint());
        Point third = new Point(4, 11);
        Point fourth = new Point(third.get_line_to(new Point(6, 15))[0], third.get_line_to(new Point(6, 15))[1]);
        System.out.println(fourth.getPoint());
    }
    
}
