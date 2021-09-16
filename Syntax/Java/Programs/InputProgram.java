package com.example.programs;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class InputProgram {
    private static Scanner s;
    static String FILE_NAME = "D:\\Java\\Programs\\Input\\InputProgram.txt";

    private static void setup() {
        try {s = new Scanner(new File(FILE_NAME));}
        catch (FileNotFoundException e) {print("File not found");}}
    private static int input() {return s.nextInt();}
    private static int[] intput(int n) {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = input();
        }
        return res;
    }
    private static void print(Object msg) {System.out.println(msg);}

    public static void main(String[] args) {
        setup();
        int i = input();
        int[] x = intput(4);
        print(i);
        for (int k: x) {
            print(k);
        }
    }
}
