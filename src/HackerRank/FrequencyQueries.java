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

public class FrequencyQueries {

    // Complete the freqQuery function below.
    static List<Integer> freqQuery(List<List<Integer>> queries) {

        ArrayList<Integer> ans = new ArrayList<>();
        HashMap<Integer, Integer> map = new HashMap<>();
        HashMap<Integer, Integer> freqMap = new HashMap<>();
        for(int i = 0; i < queries.size(); i++){
            int queryType = queries.get(i).get(0);
            int queryValue = queries.get(i).get(1);
            int freq = 0;

            switch(queryType){
                case 1:
                    if(map.containsKey(queryValue)){
                        freq = map.get(queryValue) + 1;
                        map.put(queryValue, freq);
                        if(freqMap.containsKey(freq)){
                            freqMap.put(freq, freqMap.get(freq) + 1);
                            freqMap.put(freq - 1, freqMap.get(freq - 1) - 1);
                            freqMap.remove(freq - 1, 0);
                        }
                        else{
                            freqMap.put(freq, 1);
                            freqMap.put(freq - 1, freqMap.get(freq - 1) - 1);
                            freqMap.remove(freq - 1, 0);
                        }
                    }
                    else{
                        freq = 1;
                        map.put(queryValue, freq);
                        if(freqMap.containsKey(freq)){
                            freqMap.put(freq, freqMap.get(freq) + 1);
                            // freqMap.put(freq - 1, freqMap.get(freq - 1) - 1);
                            // freqMap.remove(freq - 1, 0);
                        }
                        else freqMap.put(freq, 1);
                    }
                    break;

                case 2:
                    if(map.containsKey(queryValue)){
                        freq = map.get(queryValue) - 1;
                        map.put(queryValue, freq);
                        map.remove(queryValue, 0);

                        if(freqMap.containsKey(freq)){
                            freqMap.put(freq, freqMap.get(freq) + 1);
                            freqMap.put(freq + 1, freqMap.get(freq + 1) - 1);
                            freqMap.remove(freq + 1, 0);
                        }
                        else{
                            freqMap.put(freq, 1);
                            freqMap.put(freq + 1, freqMap.get(freq + 1) - 1);
                            freqMap.remove(freq + 1, 0);
                        }
                    }
                    break;

                case 3:
                    if(freqMap.containsKey(queryValue)) ans.add(1);
                    else ans.add(0);
                    break;
            }
            System.out.println(freqMap);
//            System.out.println(map);
        }

        return ans;

    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
//        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = Integer.parseInt(bufferedReader.readLine().trim());

        List<List<Integer>> queries = new ArrayList<>();

        IntStream.range(0, q).forEach(i -> {
            try {
                queries.add(
                        Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                                .map(Integer::parseInt)
                                .collect(toList())
                );
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        List<Integer> ans = freqQuery(queries);

//        bufferedWriter.write(
//                ans.stream()
//                        .map(Object::toString)
//                        .collect(joining("\n"))
//                        + "\n"
//        );
//
        bufferedReader.close();
//        bufferedWriter.close();
    }
}
