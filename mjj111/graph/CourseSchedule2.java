import java.util.*;

class Solution {
    public int[] findOrder(int n, int[][] prerequisites) {
        List<Integer>[] vertex = new List[n];
        for (int i = 0; i < n; i++) {
            vertex[i] = new ArrayList<>();
        }

        int[] indegree = new int[n];
        for (int[] prerequisite : prerequisites) {
            int now = prerequisite[0];
            int pre = prerequisite[1];
            indegree[now] += 1;
            vertex[pre].add(now);
        }

        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                queue.offer(i);
            }
        }

        List<Integer> answerList = new ArrayList<>();
        while (!queue.isEmpty()) {
            int now = queue.poll();
            answerList.add(now);

            for (int next : vertex[now]) {
                indegree[next] -= 1;
                if (indegree[next] == 0) queue.offer(next);
            }
        }

        // 모든 노드를 방문할 수 없는 경우 (사이클이 존재하는 경우)
        if (answerList.size() != n) return new int[0];

        int[] answer = new int[n];
        for (int i = 0; i < n; i++) {
            answer[i] = answerList.get(i);
        }
        return answer;
    }
}