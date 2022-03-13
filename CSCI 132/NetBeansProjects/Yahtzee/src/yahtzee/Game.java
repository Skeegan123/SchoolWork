/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package yahtzee;

/**
 *
 * @author Keegans Laptop
 */

import java.util.Random;
import java.util.Arrays;

public class Game {
    int[] dice = new int[5];
    int[] counter = new int[5];
    int[] sortedDice = new int[5];
    int[] ex1 = new int[]{1,2,3,4,5};
    int[] ex2 = new int[]{2,3,4,5,6};

    int yahtzee = 0;
    int fullHouse = 0;
    int straight = 0;
    int fourOAK = 0;
    int threeOAK = 0;
    int temp;
    int tempCount = 0;
    int loss = 0;
    
    
    Random rand = new Random();
    
    public void roll() {
        for (int i = 0; i < 5; i++) {
            dice[i] = rand.nextInt(5) + 1;
        }
    }
    
    public void count() {
        for (int x = 0; x < 5; x++) {
            temp = dice[x];
            for (int y = 0; y < 5; y++) {
                if (dice[y] == temp) {
                    tempCount++;
                }
                
            }
            counter[x] = tempCount;
            tempCount = 0;
        }
        
        Arrays.sort(counter);
        Arrays.sort(dice);
        
        
        if (counter[4] == 5) {
            yahtzee++;
        } else if (counter[4] == 4) {
            fourOAK++;
        } else if (counter[4] == 3 && counter[0] == 2) {
            fullHouse++;
        } else if (counter[4] == 3) {
            threeOAK++;
        }else if (Arrays.equals(dice, ex1) || Arrays.equals(dice, ex2)) {
            straight++;
        } else {
            loss++;
            
        }
    }
    
    public void start(int rolls) {
        for (int i = 0; i < rolls; i++) {
            roll();
            count();
//            System.out.println(Arrays.toString(dice));
//            System.out.println(Arrays.toString(counter));
//            System.out.println();
        }
        System.out.println("Number of Rolls: " + rolls);
        System.out.println("---------------------");
        System.out.println("Number of Yahtzees: " + yahtzee);
        System.out.println("Yahtzee Percent: " + (((double) yahtzee)/((double) rolls) * 100) + "%");
        System.out.println("Number of Full Houses: " + fullHouse);
        System.out.println("Full House Percent: " + (((double) fullHouse)/((double) rolls) * 100) + "%");
        System.out.println("Number of Large Straights: " + straight);
        System.out.println("Large Straight Percent: " + (((double) straight)/((double) rolls) * 100) + "%");
        System.out.println("Number of Four of a Kinds: " + fourOAK);
        System.out.println("Four of a Kind Percent: " + (((double) fourOAK)/((double) rolls) * 100) + "%");
        System.out.println("Number of Three of a Kinds: " + threeOAK);
        System.out.println("Three of a Kind Percent: " + (((double) threeOAK)/((double) rolls) * 100) + "%");
        System.out.println("Number of Loosers: " + loss);
        System.out.println("Looser Percent: " + (((double) loss)/((double) rolls) * 100) + "%");
        
    }
}
