# -*- coding: UTF-8 -*-
# animation.py

# 导入需要的模块
import pygame, sys
from pygame.locals import *

# 初始化pygame
pygame.init()

# 设置帧率（屏幕每秒刷新的次数）
FPS = 5

# import random
pre_route = list()  # 宽度搜索得到的节点
q = list()  # 队列结构控制循环次数
xx = [0, 1, 0, -1]  # 右移、下移、左移、上移
yy = [1, 0, -1, 0]
visited = list()  # 记录节点是否已遍历
father = list()  # 每一个pre_route节点的父节点
route = list()


def bfs(l, x, y, m, n):
    visited = [[0 for i in range(len(l[0]))] for j in range(len(l))]
    visited[x][y] = 1  # 入口节点设置为已遍历
    q.append([x, y])
    while q:  # 队列为空则结束循环
        now = q[0]
        q.pop(0)  # 移除队列头结点
        for i in range(4):
            point = [now[0] + xx[i], now[1] + yy[i]]  # 当前节点
            if point[0] < 0 or point[1] < 0 or point[0] >= len(l) or point[1] >= len(l[0]) or visited[point[0]][
                point[1]] == 1 or l[point[0]][point[1]] == '1':
                continue
            father.append(now)
            visited[point[0]][point[1]] = 1
            q.append(point)
            pre_route.append(point)
            if point[0] == m and point[1] == n:
                print("success")
                return 1
    print("false")
    return 0


def get_route(father, pre_route):  # 输出最短迷宫路径
    route = [pre_route[-1], father[-1]]
    for i in range(len(pre_route) - 1, -1, -1):
        if pre_route[i] == route[-1]:
            route.append(father[i])
    route.reverse()
    print("迷宫最短路径为：\n", route)
    print("步长：", len(route) - 1)
    return route


def prn_map(route, l, m, n):  # 打印包含路径的迷宫图
    for i in range(len(l)):
        l[i] = list(l[i])
    for i in range(len(route)):
        l[route[i][0]][route[i][1]] = '2'
    for i in range(len(l)):
        for j in range(len(l[0])):
            if l[i][j] == '1':
                print('  ', end='')
            elif l[i][j] == '0':
                print('██', end='')
            else:
                print('░░', end='')
            if i == m and j == n:
                print('☀', end='')
        print()


l = ['01010101001011001001010110010110100100001000101010',
     '00001000100000101010010000100000001001100110100101',
     '01111011010010001000001101001011100011000000010000',
     '01000000001010100011010000101000001010101011001011',
     '00011111000000101000010010100010100000101100000000',
     '11001000110101000010101100011010011010101011110111',
     '00011011010101001001001010000001000101001110000000',
     '10100000101000100110101010111110011000010000111010',
     '00111000001010100001100010000001000101001100001001',
     '11000110100001110010001001010101010101010001101000',
     '00010000100100000101001010101110100010101010000101',
     '11100100101001001000010000010101010100100100010100',
     '00000010000000101011001111010001100000101010100011',
     '10101010011100001000011000010110011110110100001000',
     '10101010100001101010100101000010100000111011101001',
     '10000000101100010000101100101101001011100000000100',
     '10101001000000010100100001000100000100011110101001',
     '00101001010101101001010100011010101101110000110101',
     '11001010000100001100000010100101000001000111000010',
     '00001000110000110101101000000100101001001000011101',
     '10100101000101000000001110110010110101101010100001',
     '00101000010000110101010000100010001001000100010101',
     '10100001000110010001000010101001010101011111010010',
     '00000100101000000110010100101001000001000000000010',
     '11010000001001110111001001000011101001011011101000',
     '00000110100010001000100000001000011101000000110011',
     '10101000101000100010001111100010101001010000001000',
     '10000010100101001010110000000100101010001011101000',
     '00111100001000010000000110111000000001000000001011',
     '10000001100111010111010001000110111010101101111000']
if bfs(l, 0, 0, 29, 49) == 1:
    route = get_route(father, pre_route)
for i in range(len(l)):
    l[i] = list(l[i])
for i in range(len(route)):
    l[route[i][0]][route[i][1]] = '2'

# 获得pygame的时钟
fpsClock = pygame.time.Clock()

# 设置窗口大小
screen = pygame.display.set_mode((500, 300), 0, 32)

# 设置标题
pygame.display.set_caption('迷宫')

# 定义颜色
WHITE = (255, 255, 255)
black = (0, 0, 0)
rect_color = (250, 50, 55)

it = 0
while True:
    screen.fill(WHITE)
    route2 = list()
    for i in route:
        route2.append([i[0] * 10, i[1] * 10])
    x = 0;
    y = 0
    for i in l:
        for j in i:
            if j == '1':
                pygame.draw.rect(screen, black, [x, y, 10, 10])
            x += 10
        x = 0
        y += 10
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            sys.exit()
    pygame.draw.rect(screen, rect_color, [route2[it][1], route2[it][0], 10, 10])
    if it < len(route2) - 1:
        it += 1
    pygame.display.update()
    fpsClock.tick(FPS)
