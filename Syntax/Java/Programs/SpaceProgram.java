package com.example.programs;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class SpaceProgram {
    private static void print(Object msg) {System.out.println(msg);}

    static class Item {
        String name;
        int weight;
        Item(String name, int weight) {
            this.name = name;
            this.weight = weight;
        }
    }

    static class Rocket {
        int cost;
        int weight;
        int maxWeight;
        int cargo;
        float explosion;
        float crash;

        Rocket(int cost, int weight, int maxWeight) {
            this.cost = cost;
            this.weight = weight;
            this.maxWeight = maxWeight;

        }

        public boolean launch() {
            return false;
        }
        public boolean land() {
            return false;
        }

        public boolean canCarry(Item item) {
            return weight + item.weight <= maxWeight;
        }
        public void carry(Item item) {
            weight += item.weight;
        }
    }

    static class U1 extends Rocket {
        U1() {
            super(100, 10, 18);
        }

        @Override
        public boolean launch() {
            float chance = (float) (0.05 * (weight - 10 / maxWeight - 10));
            return Math.random() <= chance;
        }

        @Override
        public boolean land() {
            float chance = (float) (0.01 * (weight - 10 / maxWeight - 10));
            return Math.random() <= chance;
        }
    }

    static class U2 extends Rocket {
        U2() {
            super(120, 18, 29);
        }

        @Override
        public boolean launch() {
            float chance = (float) (0.04 * (weight - 10 / maxWeight - 10));
            return Math.random() <= chance;
        }

        @Override
        public boolean land() {
            float chance = (float) (0.08 * (weight - 10 / maxWeight - 10));
            return Math.random() <= chance;
        }
    }

    static class Simulation {
        public Queue<Item> loadItems(String FIlE_NAME) {
            Queue<Item> res = new LinkedList<>();
            Scanner s = null;
            try {
                s = new Scanner(new File(FIlE_NAME));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
            while (s.hasNextLine()) {
                String string = s.nextLine();
                String[] strarr = string.split("=");
                res.add(new Item(strarr[0], Integer.parseInt(strarr[1]) / 1000));
            }
            return res;
        }

        public Queue<Rocket> loadU1(Queue<Item> items) {
            Queue<Rocket> rockets = new LinkedList<>();
            while (!items.isEmpty()) {
                U1 u1 = new U1();
                while (!items.isEmpty() && u1.canCarry(items.peek())) {
                    u1.carry(items.remove());
                }
                rockets.add(u1);
            }
            return rockets;
        }

        public Queue<Rocket> loadU2(Queue<Item> items) {
            Queue<Rocket> rockets = new LinkedList<>();
            while (!items.isEmpty()) {
                U2 u2 = new U2();
                while (!items.isEmpty() && u2.canCarry(items.peek())) {
                    u2.carry(items.remove());
                }
                rockets.add(u2);
            }
            return rockets;
        }

        public int runSimulation(Queue<Rocket> rockets) {
            int cost = 0;
            while (!rockets.isEmpty()) {
                Rocket rocket = rockets.remove();
                do {
                    cost += rocket.cost;
                } while (rocket.launch() && rocket.land());
            }
            return cost;
        }
    }

    public static void main(String[] args) {
        //Write your code here
        Simulation simulation = new Simulation();
        Queue<Item> items1 = simulation.loadItems("D:\\Java\\Programs\\Input\\SpaceProgramPhase1.txt");
        Queue<Item> items2 = simulation.loadItems("D:\\Java\\Programs\\Input\\SpaceProgramPhase2.txt");

        Queue<Rocket> fleet1U1 = simulation.loadU1(new LinkedList<Item>(items1));
        Queue<Rocket> fleet2U1 = simulation.loadU1(new LinkedList<Item>(items2));
        int budgetU1 = simulation.runSimulation(fleet1U1);
        budgetU1 += simulation.runSimulation(fleet2U1);
        print(budgetU1);

        Queue<Rocket> fleet1U2 = simulation.loadU1(items1);
        Queue<Rocket> fleet2U2 = simulation.loadU1(items2);
        int budgetU2 = simulation.runSimulation(fleet1U2);
        budgetU2 += simulation.runSimulation(fleet2U2);
        print(budgetU2);

        if (budgetU1 > budgetU2) {
            print("U2 is a better option");
        }
        else if (budgetU2 > budgetU1) {
            print("U1 is a better option");
        }
        else {
            print("Either is fine");
        }
    }
}
