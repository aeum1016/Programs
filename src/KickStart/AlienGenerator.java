package KickStart;

import java.util.Scanner;

public class AlienGenerator {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            long g = in.nextLong();
            int total = 1;
            for(long k = g/2; k >= 1; k--){
                for(long j = 1; j <= g; j++){
                    if(k*j + fib(j-1) == g){
                        total++;
                        break;
                    }
                    if(k*j + fib(j-1) > g) break;
                }
            }

            System.out.printf("Case #%d: %d\n", i + 1, total);
        }
    }

    static long fib(long i){
        if(i <= 0) return 0;
        else return i + fib(i-1);
    }

}
