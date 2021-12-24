package ProjectEuler;

public class P4 {
    public static void main(String[] args){
        for(int i = 998001; i >= 10000; i--){
            if(checkPalindrome(i)){
                if(checkTripleMultiple(i)) {
                    System.out.println(i);
                    break;
                }
            }
        }
    }

    public static boolean checkPalindrome(int value){
        int reverse = 0;
        int n = value;
        do{
            reverse = (reverse * 10) + (n % 10);
            n = n/10;
        }
        while (n != 0);
        System.out.println(value + "+" + reverse);
        if(reverse == value) return true;
        else return false;
    }

    public static boolean checkTripleMultiple(int value){
        for(int i = 999; i >= Math.sqrt(value); i--){
            if(value % i == 0) return true;
        }
        return false;
    }
}
