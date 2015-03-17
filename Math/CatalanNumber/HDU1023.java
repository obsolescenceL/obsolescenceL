import java.math.*;
import java.util.*;

class Main {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner in = new Scanner(System.in);
        int n, a;
        BigInteger t;
        BigInteger[] h = new BigInteger[101];
        for (int i = 0; i < 101; i++)
            h[i] = BigInteger.ZERO;
        h[0] = h[1] = BigInteger.valueOf(1);
        for (int i = 2; i < 101; i++)
            for (int j = 0; j < i; j++) {
                a = i - j - 1;
                t = h[j].multiply(h[a]);
                h[i] = h[i].add(t);
            }
        while (in.hasNextInt()) {
            n = in.nextInt();
            System.out.println(h[n]);
        }
        in.close();

    }
}
