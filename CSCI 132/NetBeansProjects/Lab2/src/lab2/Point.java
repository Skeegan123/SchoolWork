/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab2;

/**
 *
 * @author Keegans Laptop
 */
public class Point {
    private int x;
    
    private int y;
    
    public Point(int oldX, int oldY){
        x = oldX;
        y = oldY;
    }
    
    public int[] reflect_x(){
        return new int[] {x, -y};
    }
    
    public int[] get_line_to(Point point2){
        int slope = (point2.y - y) / (point2.x - x);
        int b = (-slope * x) + y;
        return new int[] {slope, b};
    }
    
    public String getPoint() {
        return "(" + x + "," + y + ")";
    }
        
}
