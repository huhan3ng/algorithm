import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * Created by huhansan on 2017/12/19.
 * http://codeforces.com/problemset/problem/11/D
 * int bitmask 存储点与点连接关系， dp计算长度从3-n的连线，并筛选出可以成环的，顶点最多19个, O(m^2)
 * ArrayList要是可以存 int 就好了
 */

public class CF_11D {
    int[] l2;    //长度为2的连线
    int[] li;    //长度为i的连线
    int n, m, a, b, count;

    public void solve() throws Exception{
        n = nextInt();
        m = nextInt();
        l2 = new int[200];
        li = new int[200];
        for(int i=0;i<m;i++){
            a = nextInt();
            b = nextInt();
            l2[i] = l2[i] | 1<<a | 1<<b;
        }
        count = m;
        for(int i=0;i<n;i++){
            for(int j=0;j<count;j++){
                li[j] = 
            }
        }
    }

    public static void main(String[] args) {
        new CF_11D().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;


    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}
