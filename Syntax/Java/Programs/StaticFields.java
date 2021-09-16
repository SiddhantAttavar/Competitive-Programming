package com.example.programs;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class StaticFields {
    private static Scanner s;
    static String FILE_NAME = "D:\\Java\\Programs\\Input\\InputProgram.txt";

    private static void setup() {
        try {s = new Scanner(new File(FILE_NAME));}
        catch (FileNotFoundException e) {e.printStackTrace();}}
    private static int input() {return s.nextInt();}
    private static int[] intput(int n) {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = input();
        }
        return res;
    }
    private static void print(Object msg) {System.out.println(msg);}

    static class Person {
        public static int instanceCount;
        public int localCount;
        public Person(){
            instanceCount++;
            localCount++;
        }
    }

    public static void main(String[] args) {
        setup();
        //Write your code here
        Person person1 = new Person();
        Person person2 = new Person();
        Person person3 = new Person();
        Person person4 = new Person();
        print("(" + person4.localCount + "," + Person.instanceCount + ")");

        s.close();
    }
}
