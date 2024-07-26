input = open(0).readline

def preorder(r):
    if r != '.':
        print(r, end="")
        preorder(tree[r][0])
        preorder(tree[r][1])

def inorder(r):
    if r != '.':
        inorder(tree[r][0])
        print(r, end="")
        inorder(tree[r][1])

def postorder(r):
    if r != '.':
        postorder(tree[r][0])
        postorder(tree[r][1])
        print(r, end="")

tree = {chr(i):['.', '.'] for i in range(65, 91)}

for j in range(int(input())):
    a = input().split()
    tree[a[0]][0], tree[a[0]][1] = a[1], a[2]

preorder("A")
print("")
inorder("A")
print("")
postorder("A")