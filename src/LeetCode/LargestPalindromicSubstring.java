package LeetCode;

import java.util.Scanner;

class Solution {
    public String longestPalindrome(String s) {
        // two loops (unfortunately)
        // start from the largest, return if find any
        // start from substring of length s.size(), iterate downwards

        for(int i = s.length(); i > 0; i--){
            for(int j = 0; j <= s.length() - i; j++){

                if(checkPalindrome(s.substring(j, j+i))){
                    return s.substring(j, j+i);
                }
            }
        }
        return s.substring(0, 1);
    }

    public boolean checkPalindrome(String s){

        for(int i = 0; i < s.length() / 2; i++){
            System.out.println(s.charAt(i) + " " + s.charAt(s.length() - 1 - i));
            if(s.charAt(i) != s.charAt(s.length() - 1 - i)) return false;
        }
        return true;

    }
}

class LargestPalindromicSubstring {
    public static void main(String[] args){

        Scanner in = new Scanner(System.in);
        Solution sol = new Solution();

        System.out.println(sol.longestPalindrome(in.next()));
    }
}