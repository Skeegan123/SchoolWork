/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package football.project;

/**
 *
 * @author Keegans Laptop
 */
public class FootballProject {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try{
            new FileOpenReadWrite(args[0]);
        }catch(Exception e)
        {
            System.out.println("Usage: Need file input name");
            System.err.println(e);
        }
    }
    
}
