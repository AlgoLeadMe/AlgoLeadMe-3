import java.util.*;
import java.lang.*;
import java.io.*;

class 원판돌리기 {
    static int N, M, T;
    static int[][] arr;
    static int zeroNum;
    static int total = 0, cnt = 0;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        arr = new int[N+1][M];

        for(int i=1; i<=N; ++i) {
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<M; ++j) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int remainCnt = N*M;
        for(int i=0; i<T; ++i) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            // 회전 시키기
            for(int r=x; r<=N; r+=x) {
                arr[r] = rotate(r, d, k);
            }

            // 수가 남아있는지 확인하기
            if(remainCnt > 0) {
                zeroNum = 0;
                total = 0;
                cnt = 0;
                boolean[][] zero = makeZero(arr);


                if(zeroNum == 0) {
                    double avg = (double)total / (double)cnt;

                    for(int r=1; r<=N; ++r) {
                        for(int c=0; c<M; ++c) {
                            if(arr[r][c] == 0) continue;
                            if((double)arr[r][c] < avg) arr[r][c]++;
                            else if((double)arr[r][c] > avg) arr[r][c]--;
                        }
                    }
                }
                else {
                    for(int r=1; r<=N; ++r) {
                        for (int c = 0; c < M; ++c) {
                            if(zero[r][c]) arr[r][c] = 0;
                        }
                    }

                }
            }
        }

        int ans = 0;
        for(int r=1; r<=N; ++r) {
            for(int c=0; c<M; ++c) {
                ans += arr[r][c];
            }
        }

        System.out.println(ans);
    }

    static int[] rotate(int r, int d, int k) {
        int[] newArr = new int[M];
        if(d == 0) { // 시계방향
            for(int i=0; i<M; ++i) {
                newArr[i] = arr[r][(i+M-k) % M];
            }
        } else {
            for(int i=0; i<M; ++i) {
                newArr[i] = arr[r][(i+k) % M];
            }
        }

        return newArr;
    }

    static boolean[][] makeZero(int[][] arr) {
        boolean[][] zero = new boolean[N+1][M];
        for(int i=1; i<=N; ++i) {
            for(int j=0; j<M; ++j) {
                if(arr[i][j] == 0) continue;

                cnt++;
                total += arr[i][j];

                if(arr[i][j] == arr[i][(j+1)%M]) {
                    zero[i][j] = zero[i][(j+1)%M] = true;
                    zeroNum++;
                }

                if(i<N && arr[i][j] == arr[i+1][j]) {
                    zero[i][j] = zero[i+1][j] = true;
                    zeroNum++;
                }
            }
        }

        return zero;
    }
}