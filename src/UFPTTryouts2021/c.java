package UFPTTryouts2021;

import java.util.Scanner;
import java.util.Arrays;
import java.util.HashMap;

public class c {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        
        while(t > 0)
        {
            t--;
            int caves = in.nextInt();
            HashMap<Long, Integer> mapping = new HashMap<>(); 
            long[] mins = new long[caves];
            while(caves > 0)
            {
                int monsters = in.nextInt();
                int monsterCount = monsters;
                long min = Long.MIN_VALUE;
                for(int i = 0; i < monsters; i++)
                {
                    int monster = in.nextInt();
                    min = Math.max(monster-i+1, min);
                }
                mapping.put(min, monsterCount);
                mins[caves-1] = min; 
                caves--;
            }
            Arrays.sort(mins);

            long totalMin = mins[0];
            long totalMonsters = mapping.get(mins[0]);

            for(int i = 1; i < mins.length; i++)
            {
                long diff = mins[i] - (totalMin + totalMonsters);
                if(diff > 0)
                {
                    totalMin += diff;
                }
                totalMonsters += mapping.get(mins[i]);
            }

            System.out.println(totalMin);
        }
    }
}
