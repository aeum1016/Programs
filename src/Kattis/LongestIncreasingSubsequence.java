package Kattis;

import java.util.ArrayList;
import java.util.Scanner;

public class LongestIncreasingSubsequence {
    public static void main(String[] args){

        ArrayList<Integer> ans = new ArrayList<>();
        Scanner in = new Scanner(System.in);
        ans.add(Integer.MIN_VALUE);

        int q = in.nextInt();

        for(int i = 0; i < q; i++){

            int cur = in.nextInt();

            int low = 0, high = ans.size()-1;
            while(low <= high){
                int mid = low + (high-low)/2;

                if(ans.get(mid) < cur){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            if(low == ans.size()) ans.add(cur);
            else ans.set(low, cur);
        }
        System.out.println(ans.size()-1);


    }
}
