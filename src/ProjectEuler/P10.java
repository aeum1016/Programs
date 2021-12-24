package ProjectEuler;

import java.util.ArrayList;

public class P10 {
    public static void main(String[] args){

        ArrayList<Integer> prevPrimes = new ArrayList<>();
        prevPrimes.add(3);
        int lastPrime = prevPrimes.get(prevPrimes.size()-1);
        long sum  = 0;

        for(int i = 0; i < 2000000; i++){
            prevPrimes.add(findNextPrime(prevPrimes));
            i = prevPrimes.get(prevPrimes.size()-1);
        }
        for(int prevPrime : prevPrimes){
            sum += prevPrime;
        }
        System.out.println(sum - prevPrimes.get(prevPrimes.size()-1));
//        System.out.println(prevPrimes);
    }


    public static int findNextPrime(ArrayList<Integer> prevPrimes){
        int newPrime = 0;
        boolean notPrime = false;
        int i = prevPrimes.get(prevPrimes.size()-1);
        for(i = i; i > 0; i+=2){
            notPrime = false;
            for(int prevPrime : prevPrimes){
                if(i % prevPrime == 0){
                    notPrime = true;
                    break;
                }
            }

            if(!notPrime){
                newPrime = i;
                break;
            }
        }
        return newPrime;
    }
}
