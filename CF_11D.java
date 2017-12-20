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
    int n, m, a, b, count2, countI; //n定点数 m边数

    public void solve() throws Exception {
        n = nextInt();
        m = nextInt();
        l2 = new int[m];
        li = new int[400];
        for (int i = 0; i < m; i++) {
            a = nextInt();
            b = nextInt();
            l2[i] = l2[i] | 1 << (19-a) | 1 << (19-b);
            li[i] = li[i] | 1 << (19-a) | 1 << (19-b);
        }
        countI = count2 = m;
        int[] tmp;
        int t;
        for (int i = 3; i <= n; ++i, li = tmp, countI = t) {
            tmp = new int[200];
            t = 0;
            for (int pli = 0; pli < countI; pli++) {
                for (int pl2 = 0; pl2 < count2; ++pl2) {
//                    if(((l2[pl2]&(l2[pl2]-1)) | (li[pli]&~(li[pli]-1))) == (l2[pl2]&(l2[pl2]-1))){  //最低位1连上最高位1
//                        tmp[t++] = li[pli] | l2[pl2];
//                        writer.println(Integer.toBinaryString(0x10000 | tmp[t-1]).substring(1));
//                    }
                    if(((li[pli]&~(li[pli]-1)) & l2[pl2]) !=0 && (li[pli] | l2[pl2]) != l2[pli]){
                        tmp[t++] = li[pli] | l2[pl2];
                        writer.println(Integer.toBinaryString(0x10000000 | tmp[t-1]).substring(1));
                        writer.flush();
                    }
                }
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
