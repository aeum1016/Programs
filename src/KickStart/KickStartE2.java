package KickStart;

import java.util.Scanner;

public class KickStartE2 {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int t = in.nextInt();

        for(int i = 0; i < t; i++){
            System.out.print("Case #" + (i+1) + ": ");
            boolean impossible = false;
            String inputString = in.next();
            char[] inputArr = inputString.toCharArray();

            int minGap = Integer.MAX_VALUE;

            for(int j = 0; j < 26; j++) {
                int charWidth = 0, charGap = inputArr.length;
                int curWidth = 0, curGap = 0;
                int a = 0, b = 0;
                while (inputArr[a] == (char) j + 97) {
                    a++;
                    if (a == inputArr.length) break;
                }
                if(a == 0){
                    while(inputArr[b] != (char) j + 97) {
                        b++;
                        if(b == inputArr.length) break;
                    }
                }
                if (a != inputArr.length && b != inputArr.length) {
                    for (int k = 0; k < inputString.length(); k++) {
                        if (inputArr[(k + a) % inputArr.length] == (char) j + 97) {
                            curWidth++;
                            if(k == inputArr.length - 1) charWidth = Math.max(curWidth, charWidth);
                        } else {
                            charWidth = Math.max(curWidth, charWidth);
                            curWidth = 0;
                        }
                    }
                    for (int k = 0; k < inputString.length(); k++) {
                        if (inputArr[(k + b) % inputArr.length] == (char) j + 97) {
                            if(k+b != b) {
                                if (inputArr[(k + b - 1) % inputArr.length] != (char) j + 97) {
                                    charGap = Math.min(curGap, charGap);
                                    curGap = 0;
                                }
                            }
                        } else {
                            curGap++;
                            if(k == inputArr.length - 1) charGap = Math.min(curGap, charGap);
                        }
                    }
                    if (charGap < charWidth) {
                        impossible = true;
                        break;
                    } else {
                        minGap = Math.min(charGap, minGap);
                    }

                    if (j == 25) {
                    }
                }
                else{
                    if(a == inputArr.length) {
                        impossible = true;
                        break;
                    }
                }
            }
            if(impossible){
                System.out.println("IMPOSSIBLE");
            }
            else {
                StringBuilder sb = new StringBuilder();
                for (int k = 0; k < inputArr.length; k++) {
                    sb.append(inputArr[(k + minGap) % inputArr.length]);
                }
                System.out.println(sb.toString());
            }
        }
    }
}
