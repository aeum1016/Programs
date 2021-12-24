package Kattis;

import java.util.ArrayList;
import java.util.Scanner;

public class BooksExchange {
    public static void main(String[] args){

        Scanner in = new Scanner(System.in);

        int q = in.nextInt();

        for(int i = 0; i < q; i++){

            int n = in.nextInt();
            int[] vals = new int[n];
            int[] rep = new int[n];
            int[] size = new int[n];

            for(int j = 0; j < n; j++){
                vals[j] = in.nextInt() - 1;
                rep[j] = j;
                size[j] = 1;
            }
            for(int j = 0; j < n; j++){
                union(j, vals[j], rep, size);
            }
            for(int j = 0; j < n; j++){
                System.out.print(size[rep[j]] + " ");
            }
            System.out.println();
        }

    }

    public static int find(int i, int[] rep){
        if(i != rep[i]){
            rep[i] = find(rep[i], rep);
            return rep[i];
        }
        else
            return i;
    }

    public static void union(int p, int q, int[] rep, int[] size){
        int i = find(p, rep);
        int j = find(q, rep);
        if(i == j)
            return;
        else{
            if(size[i] < size[j]){
                rep[i] = j;
                size[j] += size[i];
            }
            else{
                rep[j] = i;
                size[i] += size[j];
            }
        }

    }
}
