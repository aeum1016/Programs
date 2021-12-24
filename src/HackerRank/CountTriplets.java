package HackerRank;

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

public class CountTriplets {

    // Complete the countTriplets function below.
    static long countTriplets(List<Long> arr, long r) {

        long totTriplets = 0L;

        HashMap<Long, Long> single = new HashMap<>();
        HashMap<Long, Long> pairs = new HashMap<>();

        for(int i = 0; i < arr.size(); i++){

            long curValue = arr.get(i);
            if(curValue % r == 0) {
                if (pairs.containsKey(curValue / r)) {
                    totTriplets += pairs.get(curValue / r);
                }
                if (single.containsKey(curValue / r)) {
                    if (pairs.get(curValue) != null) {
                        pairs.put(curValue, pairs.get(curValue) + single.get(curValue / r));
                    } else pairs.put(curValue, single.get(curValue / r));
                }
            }
            if(single.get(curValue) != null){
                single.put(curValue, single.get(curValue) + 1);
            }
            else single.put(curValue, 1L);
        }

        System.out.println(totTriplets);
        return totTriplets;

    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
//        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nr = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n = Integer.parseInt(nr[0]);

        long r = Long.parseLong(nr[1]);

        List<Long> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                .map(Long::parseLong)
                .collect(toList());

        long ans = countTriplets(arr, r);

//        bufferedWriter.write(String.valueOf(ans));
//        bufferedWriter.newLine();

        bufferedReader.close();
//        bufferedWriter.close();
    }
}
