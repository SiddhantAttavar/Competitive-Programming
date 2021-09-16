package com.example.programs;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class DijkstrasAlgorithm {
    private static Scanner sc;
    static String FILE_NAME = "Input/DijkstrasAlgorithmInput.txt";
    private static final int INF = Integer.MAX_VALUE;
    private static final int MOD = 10000007;

    private static void setup() {
        try {sc = new Scanner(new File(FILE_NAME));}
        catch (FileNotFoundException e) {e.printStackTrace();}}
    private static int input() {return sc.nextInt();}
    private static int[] intput(int n) {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = sc.nextInt();
        }
        return res;
    }
    private static void print(Object msg) {System.out.println(msg);}

    public static void main(String[] args) {
        setup();
        //Write your code here
        int n = input(), m = input(), s = input();
        List<Integer[]>[] graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int u = input(), v = input(), w = input();
            graph[u].add(new Integer[] {v, w});
            graph[v].add(new Integer[] {u, w});
        }

        boolean[] visited = new boolean[n];
        int[] distance = new int[n + 1];
        for (int i = 0; i < n; i++) {
            visited[i] = false;
            distance[i] = INF;
        }
        distance[n] = INF;
        distance[s] = 0;
        for (int i = 0; i < n; i++) {
            int u = n;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && distance[j] < distance[u]) {
                    u = j;
                }
            }

            visited[u] = true;
            for (Integer[] x: graph[u]) {
                int v = x[0], w = x[1];
                if (!visited[v]) {
                    distance[v] = Math.min(distance[v], distance[u] + w);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            System.out.println(i + ": " + distance[i]);
        }

        sc.close();
    }
}
