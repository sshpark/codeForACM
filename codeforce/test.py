#coding=utf-8
from pygame.locals import *
from sys import exit
import pygame

pygame.init()
SCREEN_SIZE = (800, 600)
# 设置游戏屏幕大小，以及颜色深度为32位
screen = pygame.display.set_mode(SCREEN_SIZE, 0, 32)

while True:
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            exit()
        print event
    pygame.display.update()