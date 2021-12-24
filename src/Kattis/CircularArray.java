package Kattis;

import java.util.Scanner;

public class CircularArray {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int r = in.nextInt();
        int q = in.nextInt();

        int[] arr = new int[n];

        for(int i = 0; i < n; i++){
            arr[i] = in.nextInt();
        }

        int rNormal = r % n;

        for(int i = 0; i < q; i++){
            System.out.println(arr[(n - (rNormal - in.nextInt())) % n]);
        }
    }
}
