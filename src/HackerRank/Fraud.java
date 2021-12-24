package HackerRank;

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Result2 {

    public static int binarySearch(List<Integer> list, int low, int high, int key){
        int index = Integer.MAX_VALUE;

        while(low <= high){
            int mid = (low + high) / 2;

            if(list.get(mid) < key){
                low = mid + 1;
            }
            else if(list.get(mid) > key){
                high = mid - 1;
            }
            else{
                index = mid;
                break;
            }
        }

        return index;
    }

    public static int binarySearchFirstHigher(List<Integer> list, int low, int high, int key){
        int index = high + 1;

        while(low <= high){
            int mid = (low + high) / 2;
            if(mid == 0){
                index = 0;
                break;
            }
//            System.out.println(mid + " " + low + " " + high);

            if(list.get(mid) < key){
                low = mid + 1;
            }
            else if(list.get(mid) >= key && list.get(mid-1) < key){
                index = mid;
                break;
            }
            else{
                high = mid - 1;
            }
        }
        return index;
    }

    /*
     * Complete the 'activityNotifications' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER_ARRAY expenditure
     *  2. INTEGER d
     */

    public static int activityNotifications(List<Integer> expenditure, int d) {
        // Write your code here
        List<Integer> list = new ArrayList<>();
        Queue<Integer> queue = new ArrayBlockingQueue<Integer>(d);
        int notifications = 0;

        for(int i = 0; i < d; i++){
            list.add(expenditure.get(i));
            queue.add(expenditure.get(i));
        }
        Collections.sort(list);
        for(int j = d; j < expenditure.size() - 1; j++){
//            System.out.println(list);
            //determine whether send message
            //find median from sorted list
            //compare
            int doubleMedian;

            if(list.size() % 2 == 0){
                doubleMedian =  list.get(list.size()/2)
                        + list.get((list.size()/2) - 1);
            }
            else{
                doubleMedian = list.get(list.size() / 2);
            }

            if(expenditure.get(j) >= doubleMedian){
                notifications++;
            }

            //remove and replace indices
            //binary search for poll of queue, remove index
            //binary search for next expenditure + 1, add 1 index before
            System.out.println(notifications);

            list.remove(binarySearch(list, 0, list.size() - 1, queue.poll()));
            list.add(binarySearchFirstHigher(list, 0, list.size() - 1, expenditure.get(j)), expenditure.get(j));
            queue.add(expenditure.get(j));
        }

        return notifications;

    }

}

public class Fraud {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
//        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n = Integer.parseInt(firstMultipleInput[0]);

        int d = Integer.parseInt(firstMultipleInput[1]);

        String[] expenditureTemp = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        List<Integer> expenditure = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int expenditureItem = Integer.parseInt(expenditureTemp[i]);
            expenditure.add(expenditureItem);
        }

        int result = Result2.activityNotifications(expenditure, d);

//        bufferedWriter.write(String.valueOf(result));
//        bufferedWriter.newLine();

        bufferedReader.close();
//        bufferedWriter.close();
    }
}
