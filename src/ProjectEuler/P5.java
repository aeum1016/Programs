package ProjectEuler;

import java.util.ArrayList;

public class P5 {

    public static void main(String[] args){
        ArrayList<Integer> primes = divisibleBy(20);
        System.out.println(primes);
        int product = 1;
        for(Integer value : primes){
            product *= value;
        }
        System.out.println(product);
    }

    public static ArrayList<Integer> divisibleBy(int value){
        ArrayList<Integer> cumulativePrimes = new ArrayList<>();

        for(int i = value; i > 1; i--){
             ArrayList<Integer> curPrimes = findPrimes(i);
             cumulativePrimes = removeMultiples(cumulativePrimes, curPrimes);
        }

        return cumulativePrimes;
    }

    public static ArrayList<Integer> findPrimes(int value){
        ArrayList<Integer> primes = new ArrayList<>();

        while(value % 2 == 0){
            primes.add(2);
            value = value / 2;
        }

        for(int i = 3; i <= value; i = i + 2){
            while(value % i == 0){
                primes.add(i);
                value = value / i;
            }
        }
        return primes;
    }

    public static ArrayList<Integer> removeMultiples(ArrayList<Integer> a, ArrayList<Integer> b){
        ArrayList<Integer> cumulative = new ArrayList<>();

        for(Integer value : a){
            cumulative.add(value);
            for(int i = 0; i < b.size(); i++){
                if(value == b.get(i)){
                    b.remove(i);
                    break;
                }
            }
        }
        if(b.size() != 0){
            cumulative.addAll(b);
        }

        return cumulative;
    }
}
