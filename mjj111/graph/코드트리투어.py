

import heapq
from collections import defaultdict
import itertools

INF = float('inf')

class TravelManager:
    def __init__(self, n):
        self.n = n  # 도시의 수
        self.graph = defaultdict(list)  # 도시 간 간선 정보
        self.distances = [INF] * n  # 0번 도시부터의 최단 거리
        self.products = {}  # 여행 상품 정보 (고유식별자 -> (매출, 도착지))
        self.unavailable = set()  # 판매되지 않는 상품의 고유식별자
        self.heap = []  # 최적의 상품 판매를 위한 힙

    def add_road(self, u, v, cost):
        self.graph[u].append((v, cost))
        self.graph[v].append((u, cost))  # 양방향 간선 추가

    def dijkstra(self, start):
        self.distances = [INF] * self.n
        self.distances[start] = 0
        pq = [(0, start)]

        while pq:
            current_dist, current_node = heapq.heappop(pq)
            if current_dist > self.distances[current_node]:
                continue

            for neighbor, weight in self.graph[current_node]:
                distance = current_dist + weight

                if distance < self.distances[neighbor]:
                    self.distances[neighbor] = distance
                    heapq.heappush(pq, (distance, neighbor))

    def add_product(self, product_id, revenue, destination):
        self.products[product_id] = (revenue, destination)
        cost = self.distances[destination]
        heapq.heappush(self.heap, (-(revenue - cost), product_id))  # 최대 힙 구현

    def cancel_product(self, product_id):
        if product_id in self.products:
            self.unavailable.add(product_id)

    def sell_best_product(self):
        while self.heap:
            profit, product_id = heapq.heappop(self.heap)

            if product_id in self.unavailable:
                continue  # 판매하지 않는 상품은 무시

            revenue, destination = self.products[product_id]
            cost = self.distances[destination]
            if cost == INF or cost > revenue:
                print(-1)
                return

            print(product_id)
            del self.products[product_id]
            return
        print(-1)

    def change_departure(self, new_start):
        self.dijkstra(new_start)
        self.heap = []
        for product_id, (revenue, destination) in self.products.items():
            if product_id not in self.unavailable:
                cost = self.distances[destination]
                heapq.heappush(self.heap, (-(revenue - cost), product_id))


def main():
    q = int(input())
    input_line = list(map(int, input().split()))

    n, m = input_line[1], input_line[2]
    manager = TravelManager(n)
    creations = input_line[3:]

    for i in range(0,len(creations),3):
        creation = creations[i:i+3]
        a = creation[0]
        b = creation[1]
        cost = creation[2]
        manager.add_road(a, b, cost)
    manager.dijkstra(0)

    for _ in range(q-1):
        input_line = list(map(int, input().split()))
        commend = input_line[0]

        if commend == 200:
            product_id, revenue, destination = input_line[1], input_line[2], input_line[3]
            manager.add_product(product_id, revenue, destination)

        elif commend == 300:
            product_id = input_line[1]
            manager.cancel_product(product_id)

        elif commend == 400:
            manager.sell_best_product()

        elif commend== 500:
            new_start = input_line[1]
            manager.change_departure(new_start)

if __name__ == "__main__":
    main()
