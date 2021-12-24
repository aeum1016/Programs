package ProjectEuler;

public class P9 {
    public static void main(String[] args){

        int a, sum = 1000;

        for(a = 1; a < sum; a++){
            if(isTriplePrime(a, sum)){
                System.out.println(a);
                break;
            }
        }

    }


    public static boolean isTriplePrime(int a, int sum){
        double b, c, d;

        b = (Math.pow(sum, 2) - (2*sum*a)) / ((-2 * a) + (2*sum));
        c = sum - a - b;
        System.out.println("a: " + a + " b: " + b + " c: " + c);
        if((int) b  == b & (int) c == c) return true;
        return false;
    }
}
