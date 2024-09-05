import java.util.*;

class 양과늑대 {

    int[][] edges;
    int[] info;
    int maxSheepCnt = 0;

    public int solution(int[] Info, int[][] Edges) {
        info = Info;
        edges = Edges;
        dfs(0, 0, 0, new HashSet<Integer>());
        return maxSheepCnt;
    }

    private void dfs(int now, int sheepCnt, int wolfCnt, Set<Integer> nexts) {
        if (info[now] == 0) sheepCnt++;
        else wolfCnt++;

        if (wolfCnt >= sheepCnt) return;
        maxSheepCnt = Math.max(sheepCnt, maxSheepCnt);

        // 다음 탐색 위치 복사
        Set<Integer> copySet = new HashSet<>(nexts);

        // 다음 탐색 목록중 현재 위치제외
        copySet.remove(now);

        for(int[] edge : edges) {
            int start = edge[0];
            int end = edge[1];
            if(start == now) copySet.add(end);
        }

        for (int next : copySet) {
            dfs(next, sheepCnt, wolfCnt, copySet);
        }
    }
}
