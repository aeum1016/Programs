package Kattis;

import java.util.HashMap;
import java.util.Scanner;

public class MinimumDistances {

    public static void main(String[] args){

        HashMap<Integer, Integer> lastPos = new HashMap<>();
        Scanner in = new Scanner(System.in);

        int minDistance = Integer.MAX_VALUE;

        int n = in.nextInt();

        for(int i = 0; i < n; i++){
            int cur = in.nextInt();
            try{
                minDistance = Math.min(minDistance, i+1 - lastPos.get(cur));
            }
            catch(Exception e){}
            lastPos.put(cur, i+1);
        }
        System.out.println(minDistance == Integer.MAX_VALUE ? -1 : minDistance);
    }
}
