package CodeForces;

import java.util.Scanner;

public class Round741ProbA {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        int[][] queries = new int[t][2];
        for (int i = 0; i < t; i++) {

            queries[i][0] = in.nextInt();
            queries[i][1] = in.nextInt();

        }

        for(int i = 0; i < t; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            if(l > (double) r/2) System.out.println(r % l);
            else{
                System.out.println(r % ((r / 2) + 1));
            }
        }
    }
}
