import java.util.*;
import java.lang.*;
import java.io.*;

class 낚시왕 {
    private static int ROW, COLUMN, SARK_COUNT;

    private static int UP = 1;
    private static int DOWN = 2;
    private static int RIGHT = 3;
    private static int LEFT = 4;
    private static int[] dx = {0, -1, 1, 0, 0};
    private static int[] dy = {0, 0, 0, 1, -1};

    private static List<Shark> sharks;
    private static int[][] map;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        ROW = Integer.parseInt(st.nextToken());
        COLUMN = Integer.parseInt(st.nextToken());
        SARK_COUNT = Integer.parseInt(st.nextToken());

        sharks = new ArrayList<>();
        map = new int[ROW+1][COLUMN+1];

        for(int i = 1; i <= SARK_COUNT; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int speed = Integer.parseInt(st.nextToken());
            int direction = Integer.parseInt(st.nextToken());
            int size = Integer.parseInt(st.nextToken());

            map[x][y] = i;
            sharks.add(new Shark(i, x, y, speed, direction, size));
        }

        int answer = 0;
        for(int i = 1; i <= COLUMN; i++) {
            answer += getShark(i);
            moveShark();
        }

        System.out.println(answer);
    }

    private static int getShark(int now) {
        for(int i = 1; i <= ROW; i++) {
            int sharkNumber = map[i][now];

            if(sharkNumber != 0) {
                Shark s = sharks.get(sharkNumber-1);
                s.alive = false;
                map[i][now] = 0;
                return s.size;
            }
        }
        return 0;
    }

    private static void moveShark() {
        int[][] copyMap = new int[ROW+1][COLUMN+1];

        for(Shark s : sharks) {
            if(!s.alive) continue;

            int speed = s.speed;
            while(speed-- > 0) {
                int nextX = s.x + dx[s.direction];
                int nextY = s.y + dy[s.direction];

                if(isOutRange(nextX, nextY)) {
                    s.changeDirection();
                    speed++;
                    continue;
                }

                s.x = nextX;
                s.y = nextY;
            }

            if(copyMap[s.x][s.y] != 0) {
                Shark op = sharks.get(copyMap[s.x][s.y] - 1);
                if(s.size < op.size) {
                    s.alive = false;
                    continue;
                } else {
                    op.alive = false;
                }
            }

            copyMap[s.x][s.y] = s.number;
        }

        for(int i = 1; i <= ROW; i++) {
            for(int j = 1; j <= COLUMN; j++) {
                map[i][j] = copyMap[i][j];
            }
        }
    }

    private static boolean isOutRange(int x, int y) {
        return x <= 0 || x > ROW || y <= 0 || y > COLUMN;
    }


    private static class Shark {
        int number;
        int x;
        int y;
        int speed;
        int direction;
        int size;
        boolean alive;

        public Shark(int number, int x, int y, int speed, int direction, int size) {
            this.number = number;
            this.x = x;
            this.y = y;
            this.speed = speed;
            this.direction = direction;
            this.size = size;
            alive = true;
        }

        public void changeDirection() {
            if(direction == UP) direction = DOWN;
            else if(direction == DOWN) direction = UP;
            else if(direction == LEFT) direction = RIGHT;
            else if(direction == RIGHT) direction = LEFT;
        }
    }
}
