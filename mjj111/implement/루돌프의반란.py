import collections, math

def print_board(board):
    for i in board:
        print(i)

def is_out(x, y) :
    return x < 0 or x >= n or y < 0 or y >= n

def get_distance(a,b,c,d):
    return abs(a - c) ** 2 + abs(b - d) ** 2

class Santas:
    def __init__(self, power):
        self.santa_list = []
        self.santa_dict = {}
        self.power = power
        self.dx = [-1,0,1,0]
        self.dy = [0,1,0,-1] # 상우하좌

    def print_points(self):
        for santa in self.santa_list:
            print(santa.point, end = " ")

    def sort(self):
        self.santa_list.sort(key=lambda x: x.number)

    def append(self, santa):
        self.santa_list.append(santa)
        self.santa_dict[santa.number] = santa

    def has_living(self):
        for santa in self.santa_list:
            if not santa.is_out:
                return True
        return False

    def alive_plus(self):
        for santa in self.santa_list:
            if not santa.is_out:
                santa.point += 1

    def get_clost(self, x, y):
        colsts = []
        min_distance = float('inf')
        for santa in self.santa_list:
            if santa.is_out : continue
            min_distance = min(min_distance, get_distance(santa.x, santa.y, x, y))

        for santa in self.santa_list:
            if santa.is_out : continue
            if min_distance == get_distance(santa.x, santa.y, x, y):
                colsts.append(santa)
        colsts.sort(key=lambda s: (-s.x, -s.y))

        return colsts[0]

    def check(self, santa, board, move_x, move_y) :
        if board[santa.x][santa.y] == 0:
            board[santa.x][santa.y] = santa.number
            return

        located_santa = self.santa_dict[board[santa.x][santa.y]]
        board[santa.x][santa.y] = santa.number

        located_santa.x += move_x
        located_santa.y += move_y

        if is_out(located_santa.x, located_santa.y):
            located_santa.is_out = True
            return

        self.check(located_santa, board, move_x, move_y)

    def move(self, rudolph, board, turn):
        for santa in self.santa_list:
            if santa.is_out or santa.is_sturned >= turn:
                continue

            now_distance = get_distance(santa.x, santa.y, rudolph.x, rudolph.y)
            best_distance = now_distance
            best_move = None

            for i in range(4):
                next_x = santa.x + self.dx[i]
                next_y = santa.y + self.dy[i]

                if is_out(next_x, next_y) or board[next_x][next_y] >= 1:
                    continue

                next_distance = get_distance(next_x, next_y, rudolph.x, rudolph.y)
                if next_distance < best_distance:
                    best_distance = next_distance
                    best_move = (next_x, next_y, i)

            if best_move:
                next_x, next_y, direction = best_move
                board[santa.x][santa.y] = 0
                santa.x, santa.y = next_x, next_y

                if board[next_x][next_y] == 0:
                    board[santa.x][santa.y] = santa.number

                elif board[next_x][next_y] == -1:
                    santa.point += self.power
                    santa.is_sturned = turn + 1

                    direction = (direction + 2) % 4
                    move_x, move_y = self.dx[direction], self.dy[direction]

                    next_x = santa.x + move_x * self.power
                    next_y = santa.y + move_y * self.power

                    if is_out(next_x, next_y) :
                        santa.is_out = True
                        continue

                    santa.x, santa.y = next_x, next_y
                    self.check(santa, board, move_x, move_y)

class Santa:
    def __init__(self, number, x, y):
        self.point = 0
        self.number = number
        self.x = x - 1
        self.y = y - 1
        self.is_out = False
        self.is_sturned = 0

class Rudolph:
    def __init__(self, x, y, power):
        self.x = x - 1
        self.y = y - 1
        self.power = power
        self.dx = [-1,-1,-1,0,0,1,1,1]
        self.dy = [-1,0,1,-1,1,-1,0,1]

    def move(self, santas, board, turn):
        santa = santas.get_clost(self.x, self.y)

        min_distance = float('inf')
        direction = -1

        for i in range(8):
            next_x = self.x + self.dx[i]
            next_y = self.y + self.dy[i]

            if is_out(next_x, next_y):
                continue

            distance = get_distance(next_x, next_y, santa.x, santa.y)
            if distance <= min_distance:
                direction = i
                min_distance = distance

        next_x = self.x + self.dx[direction]
        next_y = self.y + self.dy[direction]

        if santa.x == next_x and santa.y == next_y :
            board[self.x][self.y] = 0
            self.x, self.y = next_x, next_y
            board[self.x][self.y] = -1

            santa.point += self.power
            santa.is_sturned = turn + 1

            santa.x += self.dx[direction] * self.power
            santa.y += self.dy[direction] * self.power

            if is_out(santa.x, santa.y):
                santa.is_out = True
            else:
                santas.check(santa, board, self.dx[direction], self.dy[direction])

        else :
            board[self.x][self.y] = 0
            self.x, self.y = next_x, next_y
            board[self.x][self.y] = -1



n, m, santa_count, rudolph_power, santa_power = map(int, input().split())
x, y = map(int, input().split())
rudolph = Rudolph(x, y, rudolph_power)
board = [[0] * n for _ in range(n)]
RUDOLPH = -1
board[rudolph.x][rudolph.y] = RUDOLPH

santas = Santas(santa_power)
for _ in range(santa_count):
    number, x, y = map(int, input().split())
    santa = Santa(number, x, y)
    santas.append(santa)
    board[santa.x][santa.y] = santa.number

santas.sort()
score = 0
turn = 0

while santas.has_living() and turn < m:
    turn += 1
    rudolph.move(santas, board, turn)
    santas.move(rudolph, board, turn)
    santas.alive_plus()
santas.print_points()