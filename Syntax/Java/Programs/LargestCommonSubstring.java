package com.example.programs;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class LargestCommonSubstring {
    private static Scanner sc;
    private static void setup() {
        try {
            sc = new Scanner(new File("Programs/Input/LargestCommonSubstringAndSubsequence.txt"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
    private static void print(Object msg) {System.out.println(msg);}
    private static int input() {return sc.nextInt();}
    private static int[] intput(int n) {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = sc.nextInt();
        }
        return res;
    }

    public static void main(String[] args) {
        setup();
        int t = input();
        while (t-- > 0) {
            char[] s1 = sc.next().toCharArray();
            char[] s2 = sc.next().toCharArray();
            int m = s1.length, n = s2.length;
            int[][] dp = new int[n + 1][m + 1];

            int max = 0;
            for (int x = 0; x <= m; x++) {dp[0][x] = 0;}
            for (int y = 0; y <= n; y++) {dp[y][0] = 0;}
            for (int y = n - 1; y >= 0; y--) {
                for (int x = m - 1; x >= 0; x--) {
                    if (s1[x] == s2[y]) {
                        dp[y][x] = 1 + dp[y + 1][x + 1];
                        max = Math.max(max, dp[y][x]);
                    }
                    else {
                        dp[y][x] = 0;
                    }
                }
            }
            print(max);
        }
    }
}
