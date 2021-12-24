package HackerRank;

import java.util.*;
public class Dequeue {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Deque<Integer> deque = new ArrayDeque<>();
        HashSet<Integer> set = new HashSet<>();
        int n = in.nextInt();
        int m = in.nextInt();
        int max = 0;

        for (int i = 0; i < n; i++) {
            int num = in.nextInt();

            deque.addLast(num);
            set.add(num);
            if(i >= m){
                int temp = deque.getFirst();
                if(!deque.contains(deque.removeFirst())){
                    set.remove(temp);
                }
            }
            if(set.size() > max) max = set.size();
        }
        System.out.print(max);
    }
}



