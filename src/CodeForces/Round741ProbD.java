package CodeForces;

import java.util.Scanner;

public class Round741ProbD {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {

            int[] query = new int[2];
            query[0] = in.nextInt();
            query[1] = in.nextInt();

            String plugs = in.next();

            int[][] queries = new int[query[1]][2];
            for(int j = 0; j < query[1]; j++){
                queries[j][0] = in.nextInt();
                queries[j][1] = in.nextInt();
            }

            int[] values = new int[plugs.length()+1];
            for(int k = 1; k <= plugs.length(); k++){
                values[k] = values[k-1] + (plugs.charAt(k-1) == '+' ? 1 : -1) * (k % 2 == 0 ? -1 : 1);
            }

            for(int l = 0; l < queries.length; l++){
                System.out.println(values[queries[l][1]] - values[queries[l][0]]);
            }

        }
    }
}
