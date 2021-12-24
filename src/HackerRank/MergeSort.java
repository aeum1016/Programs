package HackerRank;

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Result3 {

    public static int binaryFirstHigherSearch(List<Integer> arr, int goal){
        int start = 0, end = arr.size()-1;
        int index = 1;
        while(start <= end){
            int mid = (start + end) / 2;
            // System.out.printf("Start: %d, End: %d, Mid: %d, Goal: %d\n", start, end, mid, goal);
            // System.out.printf("GetMid: %d\n", arr.get(mid));
            if(arr.get(mid) <= goal){
                start = mid + 1;
                index = start;
            }
            else{
                if(arr.get(mid) > goal){
                    index = mid;
                    end = mid - 1;
                }
            }
        }
        return index;
    }

    /*
     * Complete the 'countInversions' function below.
     *
     * The function is expected to return a LONG_INTEGER.
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    public static long countInversions(List<Integer> arr) {
        // Write your code here

        // O(n * logn)
        // for each object in arr O(n)
        // find sorted position in arr2 using binary search O(logn)
        // add num objects in arr2, greater than the current object
        // add that value to a counter
        long inversions = 0;
        List<Integer> arr2 = new ArrayList<>();
        for(int i = 0; i < arr.size(); i++){
            if(arr2.isEmpty()){
                arr2.add(arr.get(i));
            }
            else{
                int pos = binaryFirstHigherSearch(arr2, arr.get(i));
                inversions += arr2.size() - pos;
                // System.out.println(inversions);
                arr2.add(pos, arr.get(i));
            }
        }

        System.out.println(inversions);
        return inversions;
    }

}

public class MergeSort {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
//        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = Integer.parseInt(bufferedReader.readLine().trim());

        for (int tItr = 0; tItr < t; tItr++) {
            int n = Integer.parseInt(bufferedReader.readLine().trim());

            String[] arrTemp = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

            List<Integer> arr = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                int arrItem = Integer.parseInt(arrTemp[i]);
                arr.add(arrItem);
            }

            long result = Result3.countInversions(arr);

//            bufferedWriter.write(String.valueOf(result));
//            bufferedWriter.newLine();
        }

        bufferedReader.close();
//        bufferedWriter.close();
    }
}
