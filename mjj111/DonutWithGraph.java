// 3시 13분 시작 3시 54분 완료  약 40분 소요
// 정점 도넛 막대 8자 그래프 반환
// 정점 개수 100만개
import java.util.*;
class DonutWithGraph {
    public int[] solution(int[][] edges) {
        Map<Integer, Node> nodes = new HashMap<>();

        for(int[] edge : edges) {
            int start = edge[0];
            int end = edge[1];

            Node startNode;
            if(!nodes.containsKey(start)) {
                nodes.put(start, new Node(0,0));
            }
            startNode = nodes.get(start);

            Node endNode;
            if(!nodes.containsKey(end)) {
                nodes.put(end, new Node(0,0));
            }
            endNode = nodes.get(end);

            endNode.indegree++;
            startNode.next++;
            startNode.nexts.add(end);
        }

        int middleNodeIndex = 0;
        int total = 0;
        int eight = 0;
        int line = 0;
        int donut = 0;
        int wannaRemove = 0;
        for(Integer nodeIndex : nodes.keySet()) {
            Node now = nodes.get(nodeIndex);
            if(now.indegree == 0 && now.next >= 2) {
                middleNodeIndex = nodeIndex;
                total = now.next;

                wannaRemove = nodeIndex;

                for(int next : now.nexts) {
                    nodes.get(next).indegree--;
                }
            }
        }
        nodes.remove(wannaRemove);

        for(int nodeIndex : nodes.keySet()) {
            Node now = nodes.get(nodeIndex);
            if(now.indegree == 0) {
                line++;
            }
            if(now.indegree == 2 && now.next == 2) {
                eight++;
            }
        }

        donut = total - eight - line;
        // 정점 도넛 막대 8자 그래프 반환
        int[] answer = new int[]{middleNodeIndex,donut, line, eight};
        return answer;
    }

    class Node {
        int indegree;
        int next;
        ArrayList<Integer> nexts = new ArrayList<>();

        Node(int indegree, int next) {
            this.indegree = indegree;
            this.next = next;
        }
    }
}

