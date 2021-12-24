package Kattis;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

class PrimeSieve {

    public static void main(String[] args){

        Scanner in = new Scanner(System.in);

        int t = in.nextInt();

        for(int j = 0; j < t; j++)
        {
            int lowerBound = in.nextInt();
            int upperBound = in.nextInt();
            if(upperBound == 0){
                System.out.println(0);
                int n = in.nextInt();
                for(int i = 0; i < n; i++){
                    System.out.println(0);
                }
            }
            else {
                ArrayList<Integer> primeList = new ArrayList<>();
                boolean[] sqrtSieve = sieveOfEratosthenes((int) Math.sqrt(upperBound));

                for (int i = 0; i < sqrtSieve.length; i++) {
                    if (!sqrtSieve[i]) primeList.add(i);
                }

                for (int lower = (int) Math.sqrt(upperBound); lower < upperBound; lower += (int) Math.sqrt(upperBound)) {
                    int upper = Math.min((int) (lower + Math.sqrt(upperBound)), upperBound);
                    primeList = doSegment(sqrtSieve, lower, upper, primeList);
                }

                HashMap<Integer, Integer> diffCounts = new HashMap<>();

                int prevPrime = 0;
                int maxDiffCount = 0;
                int maxDiff = 0;
                boolean oneTrue = false;

                for(int prime : primeList)
                {
                    if(prime >= lowerBound){
                        if(prevPrime != 0)
                        {
                            if(diffCounts.getOrDefault(prime - prevPrime, 0) + 1 > maxDiffCount)
                            {
                                maxDiffCount = diffCounts.getOrDefault(prime - prevPrime, 0) + 1;
                                maxDiff = prime - prevPrime;
                                oneTrue = true;
                            }
                            else if(diffCounts.getOrDefault(prime - prevPrime, 0) + 1 == maxDiffCount)
                            {
                                oneTrue = false;
                            }
                            diffCounts.put(prime - prevPrime, diffCounts.getOrDefault(prime - prevPrime, 0) + 1);
                        }
                        prevPrime = prime;
                    }
                }
                if(oneTrue)
                    System.out.println(maxDiff);
                else
                    System.out.println("nah");
            }
        }
    }

    static ArrayList<Integer> doSegment(
            boolean[] smallPrimes,
            int lower,
            int upper,
            ArrayList<Integer> primes)
    {

        int range = upper - lower;
        boolean[] isNotPrime = new boolean[range+1];

        for(int i = 2; i < smallPrimes.length; i++) {
            if (!smallPrimes[i]) {
                int m = (lower * (i-1)) % (i);
                for (int j = m; j <= range; j += i) {
                    isNotPrime[j] = true;
                }
            }
        }

        for(int j = 0; j <= range; j++){
            if(!isNotPrime[j]){
                primes.add(j+lower);
            }
        }
        return primes;
    }

    static boolean[] sieveOfEratosthenes(int val){

        boolean[] isNotPrime = new boolean[val+1];
        isNotPrime[0] = true;
        isNotPrime[1] = true;

        for(int i = 2; i < Math.sqrt(val); i++){
            if(!isNotPrime[i]) {
                for (int j = i * i; j <= val; j += i) {
                    isNotPrime[j] = true;
                }
            }
        }
        return isNotPrime;
    }
}
