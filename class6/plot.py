import matplotlib.pyplot as plt

list_x = []
for i in range(200):
    list_x.append(i * 0.1 - 10)

list_y = []
for x in list_x:
    list_y.append(x ** 3)

plt.plot(list_x, list_y)
plt.xlabel('my test x label')
plt.ylabel('whatever')
plt.title('my function plot')

plt.show()
