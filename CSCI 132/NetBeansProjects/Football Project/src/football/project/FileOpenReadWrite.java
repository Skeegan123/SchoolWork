/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package football.project;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author Hunter
 */
public class FileOpenReadWrite {

    Scanner fin;
    FileOut fout;
    LinkedList ll = new LinkedList();
    int i = 0;
    int[] game = new int[3];
    
    FileOpenReadWrite(String fileName){
        try{
            fin = new Scanner(new File(fileName));
        }catch(IOException e)
        {
            System.err.println(e);
        }
        
        fout = new FileOut("output.txt");
        
        while(fin.hasNext()){
            do {
                int num = fin.nextInt();

                if (num !=0){

                    game[i] = num;
                    i++;

                }
                else{
                    System.exit(0);
                }
            } while (i < 3);
            
            ll.game(game);
            i = 0;
            }
        
    }
    
}
