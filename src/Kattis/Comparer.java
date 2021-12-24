package Kattis;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Comparer {

    public static void main(String[] args){
        File realFile = new File("C:\\Users\\aeum1\\Documents\\Programming\\src\\Kattis\\RealPrimes.txt");
        File myFile = new File("C:\\Users\\aeum1\\Documents\\Programming\\src\\Kattis\\MyPrimes.txt");
        try {
            Scanner real = new Scanner(realFile);
            Scanner mine = new Scanner(myFile);

            while(real.hasNext()){
                int realVal = real.nextInt();
                int myVal = mine.nextInt();
                if(realVal != myVal) System.out.println(myVal);
            }
        }
        catch(FileNotFoundException e){
            System.out.println(e);
        }

    }
}
