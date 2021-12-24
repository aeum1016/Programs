package School;

public class COT3100HW6 {

    public static void main(String[] args)
    {
        int total = 0;
        for(int i = 1; i < 1000; i++)
        {
            if(i % 7 != 0 && i % 11 != 0)
            {
                total++;
            }
        }
        System.out.println(total);
    }
}
