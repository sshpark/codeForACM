#coding=utf-8
from matplotlib import pyplot as plt
movies = ["Annie Hall", "Ben-Hur", "Casablanca", "Gandhi", "West Side Story"]
num_oscars = [5, 11, 3, 8, 10]
xs = [i+0.1 for i, _ in enumerate(movies)]

plt.bar(xs, num_oscars)
plt.ylabel("所获奥斯卡金像奖数量")
plt.title("我最喜爱的电影")
plt.xticks([i + 0.5 for i, _ in enumerate(movies)], movies)
plt.show()