package Kattis;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class CobbledStreets {

    public static class UnionFind
    {
        private ArrayList<Integer> reference;
        private ArrayList<Integer> size;

        public UnionFind(int num){
            reference = new ArrayList<>(num);
            size = new ArrayList<>(num);
            for(int i = 0; i < num; i++){
                reference.add(i);
                size.add(1);
            }
        }

        public int find(int i)
        {
            if(i != reference.get(i))
            {
                reference.set(i, find(reference.get(i)));
                return reference.get(i);
            }
            else
            {
                return i;
            }
        }

        public void union(int p, int q)
        {
            int pRef = find(p);
            int qRef = find(q);

            if(pRef == qRef)
            {
                return;
            }
            else
            {
                if(size.get(pRef) < size.get(qRef))
                {
                    reference.set(pRef, qRef);
                    size.set(qRef, size.get(qRef) + size.get(pRef));
                }
                else if(size.get(pRef) >= size.get(qRef))
                {
                    reference.set(qRef, pRef);
                    size.set(pRef, size.get(qRef) + size.get(qRef));
                }
            }
        }
    }

    public static class Edge implements Comparable<Edge>{
        int start, end;
        int length;

        public Edge(int s, int e, int l){
            start = s;
            end = e;
            length = l;
        }

        @Override
        public int compareTo(Edge edge) {
            return Integer.compare(length, edge.length);
        }

        @Override
        public String toString(){
            return start + " " + end + " " + length;
        }

    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int t = in.nextInt();
        for (int j = 0; j < t; j++) {
            int p = in.nextInt();
            int n = in.nextInt();
            int m = in.nextInt();

            ArrayList<Edge> mst = new ArrayList<>();
            UnionFind uf = new UnionFind(n);
            Edge[] edges = new Edge[m];

            for (int i = 0; i < m; i++) {
                edges[i] = new Edge(in.nextInt(), in.nextInt(), in.nextInt());
            }
            Arrays.sort(edges);

            for (Edge edge : edges) {
                int a = edge.start;
                int b = edge.end;
                if (uf.find(a - 1) != uf.find(b - 1)) {
                    mst.add(edge);
                    uf.union(a - 1, b - 1);
                }
            }

            int sum = 0;
            for (Edge edge : mst) {
                sum += edge.length;
            }
            System.out.println(sum * p);
        }
    }
}

