package ProjectEuler;

public class P6 {
    public static void main(String[] args){
        long sumSquared = 0;
        long sum = 0;
        for(int i = 0; i <=100; i++){
            sumSquared += Math.pow(i,2);
            sum += i;
        }

        sumSquared = (long) (sumSquared - Math.pow(sum,2));
        System.out.print(sumSquared);

    }
}
