<<<<<<< HEAD
package com.example.programs;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class FencingFields {
    static boolean[][] farm, visitedfields;
    static int r, c, k;
    static int[][] moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    public static void main (String[] args) throws Exception {
        setup();
        r = input(); c = input(); k = input();
        farm = new boolean[r + 2][c + 2];
        visitedfields = new boolean[r + 2][c + 2];
        for (int y = 0; y < r + 2; y++) {for (int x = 0; x < c + 2; x++) {
            farm[y][x] = false;
            visitedfields[y][x] = false;
        }}
        for (int i = 0; i < k; i++) {
            int x = input(), y = input();
            farm[y][x] = true;
        }
        int max = 0;
        for (int y = 1; y < r; y++) {
            for (int x = 1; x < c; x++) {
                if (farm[y][x]) {
                    max = Math.max(max, fill(x, y));
                }
            }
        }
        println(max);
    }

    private static int fill(int x, int y) {
        Queue<Integer[]> queue = new LinkedList<Integer[]>();
        int res = 0;
        Integer[] pos = {x, y};
        queue.add(pos);
        while (!queue.isEmpty()) {
            pos = queue.remove();
            if (visitedfields[pos[1]][pos[0]]) continue;
            res += 4;
            farm[pos[1]][pos[0]] = false;
            visitedfields[pos[1]][pos[0]] = true;
            for (int[] move: moves) {
                Integer[] currpos = {move[0] + pos[0], move[1] + pos[1]};
                if (farm[currpos[1]][currpos[0]]) {
                    res--;
                    queue.add(currpos);
                }
                else if (visitedfields[currpos[1]][currpos[0]]) {
                    res --;
                }
            }
        }
        return res;
    }
    static Scanner sc;
    private static void setup() { try { sc = new Scanner(new File("Programs/Input/FencingFieldsInput.txt")); } catch (FileNotFoundException e) {e.printStackTrace();} }
    private static int mod = 1000000007;
    private static int inf = Integer.MAX_VALUE;
    private static void println(Object msg) {System.out.println(msg);}
    private static void print(Object msg) {System.out.print(msg);}
    private static int input() {return sc.nextInt();}
    private static String str_input() {return sc.next();}
    private static int[] intput(int n) {int[] res = new int[n]; for (int i = 0; i < n; i++) {res[i] = sc.nextInt();} return res;}
=======
package com.example.programs;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class FencingFields {
    static boolean[][] farm, visitedfields;
    static int r, c, k;
    static int[][] moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    public static void main (String[] args) throws Exception {
        setup();
        r = input(); c = input(); k = input();
        farm = new boolean[r + 2][c + 2];
        visitedfields = new boolean[r + 2][c + 2];
        for (int y = 0; y < r + 2; y++) {for (int x = 0; x < c + 2; x++) {
            farm[y][x] = false;
            visitedfields[y][x] = false;
        }}
        for (int i = 0; i < k; i++) {
            int x = input(), y = input();
            farm[y][x] = true;
        }
        int max = 0;
        for (int y = 1; y < r; y++) {
            for (int x = 1; x < c; x++) {
                if (farm[y][x]) {
                    max = Math.max(max, fill(x, y));
                }
            }
        }
        println(max);
    }

    private static int fill(int x, int y) {
        Queue<Integer[]> queue = new LinkedList<Integer[]>();
        int res = 0;
        Integer[] pos = {x, y};
        queue.add(pos);
        while (!queue.isEmpty()) {
            pos = queue.remove();
            if (visitedfields[pos[1]][pos[0]]) continue;
            res += 4;
            farm[pos[1]][pos[0]] = false;
            visitedfields[pos[1]][pos[0]] = true;
            for (int[] move: moves) {
                Integer[] currpos = {move[0] + pos[0], move[1] + pos[1]};
                if (farm[currpos[1]][currpos[0]]) {
                    res--;
                    queue.add(currpos);
                }
                else if (visitedfields[currpos[1]][currpos[0]]) {
                    res --;
                }
            }
        }
        return res;
    }
    static Scanner sc;
    private static void setup() { try { sc = new Scanner(new File("Programs/Input/FencingFieldsInput.txt")); } catch (FileNotFoundException e) {e.printStackTrace();} }
    private static int mod = 1000000007;
    private static int inf = Integer.MAX_VALUE;
    private static void println(Object msg) {System.out.println(msg);}
    private static void print(Object msg) {System.out.print(msg);}
    private static int input() {return sc.nextInt();}
    private static String str_input() {return sc.next();}
    private static int[] intput(int n) {int[] res = new int[n]; for (int i = 0; i < n; i++) {res[i] = sc.nextInt();} return res;}
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}