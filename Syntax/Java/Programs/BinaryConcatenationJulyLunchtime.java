package com.example.programs;

import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.stream.*;

class Codechef {
    //Declare global variables here

    public static void main (String[] args) throws java.lang.Exception {
        for (int tc = intput(); tc-- > 0;) {
            int n = intput();
            int min = intput();
            int max = min;
            for (int i = 1; i < n; i++) {
                int x = intput();
                min = Math.min(min, x);
                max = Math.max(max, x);
            }
            String minBin = Integer.toBinaryString(min);
            String maxBin = Integer.toBinaryString(max);
            int xPlusY = Integer.parseInt(maxBin + minBin, 2);
            int yPlusX = Integer.parseInt(minBin + maxBin, 2);
            print(yPlusX-  xPlusY);
        }
    }

    //IO code
    private static final int MOD = 1000000007;
    private static int INF = Integer.MAX_VALUE;
    private static Scanner sc;
    static {
        try {
            sc = new Scanner(new File("Input/BinaryConcatenationCodechefJulyLunchtimeInput.txt"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
    private static int intput() {return sc.nextInt();}
    private static void print(Object msg) {System.out.println(msg);}
}