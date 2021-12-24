package ProjectEuler;

public class P3 {
    public static void main(String[] args){
        findPrimes(removeTwos(600851475143L));
    }

    public static long removeTwos(long value){
        while(value % 2 == 0){
            value = value / 2;
        }
        return value;
    }

    public static void findPrimes(long value){
        for(long i = 3; i <= value; i = i + 2){
            while(value % i == 0){
                System.out.println(i);
                value = value / i;
            }
        }
    }
}


