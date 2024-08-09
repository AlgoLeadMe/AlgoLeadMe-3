import java.io.*;
import java.util.*;


public class 치킨배달 {

    static int N, M;
    static int[][] graph;
    static ArrayList<Point> person;
    static ArrayList<Point> chicken;
    static int answer;
    static boolean[] open;
    private static int CHICKEN = 2;
    private static int HOME = 1;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        graph = new int[N][N];
        person = new ArrayList<>();
        chicken = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                graph[i][j] = Integer.parseInt(st.nextToken());

                if (graph[i][j] == HOME) {
                    person.add(new Point(i, j));
                }
                if (graph[i][j] == CHICKEN) {
                    chicken.add(new Point(i, j));
                }
            }
        }

        answer = Integer.MAX_VALUE;
        open = new boolean[chicken.size()];

        DFS(0, 0);
    }

    public static void DFS(int start, int cnt) {
        if(cnt != M) {
            for (int i = start; i < chicken.size(); i++) {
                open[i] = true;
                DFS(i + 1, cnt + 1);
                open[i] = false;
            }
            return;
        }

        int res = 0;
        for (int i = 0; i < person.size(); i++) {
            int minimum = Integer.MAX_VALUE;

            for (int j = 0; j < chicken.size(); j++) {
                if (open[j]) {
                    int distance = getDistance(i, j);
                    minimum = Math.min(minimum, distance);
                }
            }

            res += minimum;
        }
        answer = Math.min(answer, res);
    }

    private static int getDistance(final int i, final int j) {
        return Math.abs(person.get(i).x - chicken.get(j).x)
                + Math.abs(person.get(i).y - chicken.get(j).y);
    }

    private static class Point {
        int x;
        int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}