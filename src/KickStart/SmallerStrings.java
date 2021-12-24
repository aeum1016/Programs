package KickStart;

import java.util.Scanner;

public class SmallerStrings {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
//        System.out.println(in.next());
        int t = in.nextInt();

        for(int i = 0; i < t; i++) {
            int n = in.nextInt();
            int half = n - (n/2);
            int k = in.nextInt();
            String s = in.next();
            long total = 0;
            boolean lastCase = false;
            long mod = (long) 1E9+7;

            for (int j = 0; j < half; j++) {
                int value = s.charAt(j) - 96;
                int value2 = s.charAt(s.length() - 1 - j) - 96;
                if (value < value2) lastCase = true;
                if (value > value2) lastCase = false;
//                if(j == half - 1 && !lastCase){
//                    if (s.charAt(0) == s.charAt(s.length()-1)) lastCase = false;
//                }

                long add = (long) ((value - 1) * Math.pow(k, half - j - 1)) % mod;
                add = (add + ((j == half - 1 && lastCase) ? 1 : 0)) % mod;
                total = total + add;
            }
            System.out.printf("Case #%d: %d\n", i+1, total);
        }
    }
}
