package Algorithms;

import java.util.ArrayList;

public class UnionFind
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
