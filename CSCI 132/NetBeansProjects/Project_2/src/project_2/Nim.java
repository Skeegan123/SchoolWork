/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package project_2;

import java.util.Random;
import java.util.Scanner;
import java.lang.Math;

/**
 *
 * @author Keegans Laptop
 */
public class Nim {
    
    Random rand = new Random();
    Scanner scan = new Scanner(System.in);
    
    private int marbles = rand.nextInt(100 - 10) + 10;
    private int compType = rand.nextInt(2);
    private int whoFirst = rand.nextInt(2);
    private int j = 0;
    
    public int pMakeMove() {
        
        System.out.println("How many marbles would you like to remove from the pile?");
        System.out.println("(Between 1 and " + marbles/2 + ")");
        int move = scan.nextInt();
        
        if (move >= 1 && move <= marbles/2) {
            j = 0;
            return move;
        }else{
        System.out.println("Invalid number of marbles.");
        System.out.println("Please Try Again");
        
        
        if (j == 9) {
            System.out.println("Alright I'm gonna give you one last chance... Don't mess it up!");
        } else if (j == 10) {
            System.out.println("That's it! I give up!");
            System.exit(0);
        }
        return -1;
        }
        
    }
    
    public int dumbMove() {
        if (marbles > 3){
            int cMove = rand.nextInt((marbles/2) - 1) + 1;
            return cMove;
        } else {
            int cMove = 1;
            return cMove;
        }
    }
    
    public double smartMove() {
        
        int i = 1;
        double goal;
        
        do {
            goal = (Math.pow(2, i))-1;
            i++;
        } while (goal < marbles);
        
        i -= 2;
        
        double cMove = marbles - ((Math.pow(2, i))-1);
        
        if (cMove > marbles/2) {
            return dumbMove();
        }
        
        return cMove;
    }
    
    public void game() {
        
        System.out.println("WELCOME TO THE GAME OF NIM");
        System.out.println();
        System.out.println("There are " + marbles + " marbles");
        
        switch(whoFirst) {
        
            case (0):
                System.out.println("The Computer Will Go First...");
                switch(compType) {
                    case (0):
                        System.out.println("You will be playing Simon... He is really smart!");
                        System.out.println();
                        System.out.println("Let the game begin!");
                        do {
                            
                            System.out.println("There are " + marbles + " marbles left.");
                            System.out.println();
                            
                            int cMove = (int)smartMove();
                            
                            System.out.println("Simon pulled " + cMove + " marbles.");
                            System.out.println();
                            
                            marbles -= cMove;
                            if (marbles == 1) {
                                System.out.println("YOU WIN!!!");
                                System.out.println();
                                System.out.println("JK you are kinda bad... better luck next time?");
                                break;
                            } else if (marbles == 0) {
                                System.out.println("YOU WIN!!!");
                                System.out.println();
                                System.out.println("...");
                                System.out.println();
                                System.out.println("Wait... How did you do that?");
                                break;
                            }
                            
                            System.out.println("There are " + marbles + " marbles left.");
                            System.out.println("Your turn!");
                            
                            int move = pMakeMove();
                            if (move == -1) {
                                do {
                                    move = pMakeMove();
                                    j++;
                                } while (move == -1);
                            }
                            marbles -= move;
                            
                            
                            
                        } while (marbles != 0);
                        
                        break;
                        
                    case (1):
                        System.out.println("You will be playing Buford... He isn't very bright...");
                        System.out.println();
                        System.out.println("Let the game begin!");
                        do {
                            
                            System.out.println("There are " + marbles + " marbles left.");
                            System.out.println();
                            
                            int cMove = dumbMove();
                            
                            System.out.println("Buford pulled " + cMove + " marbles.");
                            System.out.println();
                            
                            marbles -= cMove;
                            if (marbles == 1) {
                                System.out.println("Wow... I did not know it was possible to be this bad...");
                                System.out.println();
                                System.out.println("Maybe go for a walk and think about your loss.");
                                break;
                            } else if (marbles == 0) {
                                System.out.println("YOU WIN!!!");
                                System.out.println();
                                System.out.println("Good thing too because that would've been really sad if you didn't");
                                break;
                            }
                            
                            System.out.println("There are " + marbles + " marbles left.");
                            System.out.println();
                            System.out.println("Your turn!");
                            
                            int move = pMakeMove();
                            if (move == -1) {
                                do {
                                    move = pMakeMove();
                                    j++;
                                } while (move == -1);
                            }
                            marbles -= move;
                            
                            
                        } while (marbles != 0);
                        
                        break;
                        
                }
                        
                    break;
                    
                
                        
            case (1):
                System.out.println("You Will Go First...");
                switch(compType) {
                    case (0):
                        System.out.println("You will be playing Simon... He is really smart!");
                        System.out.println();
                        System.out.println("Let the game begin!");
                        do {
                            
                            System.out.println("There are " + marbles + " marbles left.");
                            System.out.println();
                            System.out.println("Your turn!");
                            
                            int move = pMakeMove();
                            if (move == -1) {
                                do {
                                    move = pMakeMove();
                                    j++;
                                } while (move == -1);
                            }
                            marbles -= move;
                            
                            System.out.println("There are " + marbles + " marbles left.");
                            System.out.println();
                            
                            int cMove = (int)smartMove();
                            
                            System.out.println("Simon pulled " + cMove + " marbles.");
                            System.out.println();
                            
                            marbles -= cMove;
                            if (marbles == 0) {
                                System.out.println("YOU WIN!!!");
                                System.out.println();
                                System.out.println("Wow that was actually pretty good!");
                                break;
                            } else if (marbles == 1) {
                                System.out.println("You Lose...");
                                System.out.println();
                                System.out.println("Could've called that one.");
                                break;
                            }
                            
                        } while (marbles != 0);
                        break;
                        
                    case (1):
                        System.out.println("You will be playing Buford... He isn't very bright...");
                        System.out.println();
                        System.out.println("Let the game begin!");
                        do {
                            
                            System.out.println("There are " + marbles + " marbles left.");
                            System.out.println();
                            System.out.println("Your turn!");
                            
                            int move = pMakeMove();
                            if (move == -1) {
                                do {
                                    move = pMakeMove();
                                    j++;
                                } while (move == -1);
                            }
                            marbles -= move;
                            
                            System.out.println("There are " + marbles + " marbles left.");
                            System.out.println();
                            
                            int cMove = dumbMove();
                            
                            System.out.println("Buford pulled " + cMove + " marbles.");
                            System.out.println();
                            
                            marbles -= cMove;
                            if (marbles == 0) {
                                System.out.println("YOU WIN!!!");
                                System.out.println();
                                System.out.println("Thankfully...");
                                break;
                            } else if (marbles == 1) {
                                System.out.println("How?");
                                System.out.println();
                                System.out.println("L");
                                System.out.println("O");
                                System.out.println("O");
                                System.out.println("S");
                                System.out.println("E");
                                System.out.println("R");
                                break;
                            }
                            
                        } while (marbles != 0);
                        
                        break;
                        
                }
                        
                    break;
                    
                    
                }
        
        }

    }

