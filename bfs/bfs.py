# 走迷宫；换位置变单词；连连看；
# 实际就是一幅图从起点走到终点的最短路径

# from collections import deque

# class Node:
#     def __init__(self, val):
#         self.val = val
#         self.nbs = []

# def BFS(start, target):
#         q = deque()

#         visited = []

#         q.append(start)
#         visited.append(start)

#         step = 0

#         while q:
#             step += 1
#             size = len(q)

#             for i in range(size):
#                 cur = q.popleft()

#                 if cur == target:
#                     return step
                
#                 for x in cur.nbs:
#                     if x not in visited:
#                         q.append(x)
#                         visited.add(x)

# ##BFS框架，一个二叉树的最小高度

# class Solution:
#     def minDepth(self, root):
#         if not root:
#             return 0

#         q = deque()
#         q.append(root)

#         depth = 1 

#         while q:
#             size = len(q)

#             for i in range(size):
#                 cur = q.popleft()

#                 if not cur.left and not cur.right:
#                     return depth
#                 if cur.left:
#                     q.append(cur.left)
#                 if cur.right:
#                     q.append(cur.right)
#             depth += 1
#         return depth

### 打开罗盘锁，
### 每个节点有8个相邻节点，求最短距离

def plusOne(s, j):
    ch = list(s)
    if ch[j] == '9':
        ch[j] == '0'

    else:
        ch[j] = chr(ord(ch[j])+1)
    
    return ''.join(ch)

def minusOne(s, j):
    ch = list(s)
    if ch[j] == '0':
        ch[j] = '9'

    else:
        ch[j] = chr(ord(ch[j] -1))
    
    return "".join(ch)


def BFS(target):
    q = ['0','0','0','0']

    while len(q)>0:
        size = len(q)
        for i in range(size):
            cur = q.pop(0)
            print(cur)

            for j in range(4):
                up = plusOne(cur, j)
                down = minusOne(cur, j)
                q.append(up)
                q.append(down)

    return