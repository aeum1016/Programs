package ProjectEuler;

public class P2 {
    public static void main(String[] args){
        System.out.println(fibonnaciSumToValue(4000000));

    }


    public static int fibonnaciSumToValue(int maxValue){
        int sum = 2;
        int curValue1 = 1;
        int curValue2 = 2;
        int tempValue;
        while(fibonnaci(curValue1, curValue2) < maxValue){
            tempValue = fibonnaci(curValue1,curValue2);
            System.out.println(tempValue);
            if(tempValue % 2 == 0) {
                System.out.println(tempValue);
                sum += tempValue;
            }
            curValue1 = curValue2;
            curValue2 = tempValue;
        }
        return sum;
    }

    public static int fibonnaci(int prevValue1, int prevValue2){
        int curValue = prevValue1 + prevValue2;
        return curValue;
    }
}
