package com.example.programs;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Template {
    private static Scanner s;
    static String FILE_NAME = "Input/Template.txt";

    private static void setup() {
        try {s = new Scanner(new File(FILE_NAME));}
        catch (FileNotFoundException e) {print("File not Found");}}
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
        //Write your code here
        print("Hello, " + s.next());
        s.close();
        System.exit(0);
    }
}
