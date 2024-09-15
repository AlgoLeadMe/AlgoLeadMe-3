import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class 이항계수2 {
    public static final int MOD = 10007;
    private static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        dp = new int[N + 1][K + 1];

        System.out.println(binomialCoefficient(N, K));
    }

    static private int binomialCoefficient(int n, int k) {

        if (dp[n][k] > 0) {
            return dp[n][k];
        }

        if (k == 0 || n == k) {
            return dp[n][k] = 1;
        }

        // nCk = (n-1)C(k-1) + (n-1)C(k)
        return dp[n][k] = (binomialCoefficient(n - 1, k - 1)
                + binomialCoefficient(n - 1, k)) % MOD;
    }
}