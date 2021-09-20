import java.util.*;
import java.lang.*;
import java.io.*;
public class Main {
//Classes here
//Global variables here
public static void main(String[] args) throws java.lang.Exception {
    for (int tc = intput(); tc-- > 0;) {
        
    }
}
//Functions here
//Template code
private static final double EPSILON = 0.00000001;
private static final int MOD = 1000000007;
private static int INF = Integer.MAX_VALUE;
private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
private static StringTokenizer st;
private static String strput() {while (st == null || !st.hasMoreElements()) {try{st = new StringTokenizer(br.readLine());} catch (IOException  e) {e.printStackTrace();}} return st.nextToken();}
private static int intput() {return Integer.parseInt(strput());}
private static long longput() {return Long.parseLong(strput());}
private static float floatput() {return Float.parseFloat(strput());}
private static String strputln() {String str = ""; try{str = br.readLine();} catch (IOException e) {e.printStackTrace();} return str;}
private static int[] arrput(int n) {int[] res = new int[n]; for (int i = 0; i < n; i++) {res[i] = Integer.parseInt(strput());} return res;}
private static long[] longArrput(int n) {long[] res = new long[n]; for (int i = 0; i < n; i++) {res[i] = Long.parseLong(strput());} return res;}
private static void print(Object msg) {System.out.println(msg);}
}