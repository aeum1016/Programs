package CodeForces;

import java.math.BigInteger;
import java.util.HashMap;
import java.util.Scanner;

public class Round741ProbB {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        String[][] queries = new String[t][2];
        for (int i = 0; i < t; i++) {

            queries[i][0] = in.next();
            queries[i][1] = in.next();

        }

        for(int i = 0; i < t; i++){
            boolean singleCompositeDigit = false;
            boolean doubleAnyDigit = false;
            char[] numChars = queries[i][1].toCharArray();
            for(char num : numChars){
                if((num % 2 == 0 && !(num == '2')) || num == '1' || num == '9'){
                    System.out.println(1);
                    System.out.println(num);
                    singleCompositeDigit = true;
                    doubleAnyDigit = true;
                    break;
                }
            }
            if(!singleCompositeDigit) {
                HashMap<Character, Integer> mapping = new HashMap<>();
                for (int j = 0; j < queries[i][1].length(); j++) {
                    int curValue = mapping.getOrDefault(queries[i][1].charAt(j), 0);
                    if(curValue == 1){
                        System.out.println(2);
                        System.out.println(queries[i][1].charAt(j) + queries[i][1].charAt(j));
                        doubleAnyDigit = true;
                        break;
                    }
                    mapping.put(queries[i][1].charAt(j), curValue);
                }
            }
            if(!doubleAnyDigit){
                for(Integer j = 12; j < 9532; j++){
                    char[] digits = j.toString().toCharArray();
                    int point1 = 0, point2 = 0;
                    BigInteger num = new BigInteger(j.toString());
                    if(!num.isProbablePrime(1)) {
                        while (point1 < numChars.length && point2 < digits.length) {
                            if (numChars[point1] == digits[point2]) {
                                point1++;
                                point2++;
                            } else {
                                point1++;
                            }
                        }
                        if (point2 == digits.length) {
                            System.out.println(digits.length);
                            System.out.println(digits);
                            break;
                        }
                    }
                }
            }
        }
    }
}
