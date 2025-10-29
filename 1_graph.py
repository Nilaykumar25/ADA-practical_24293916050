#1a linear search
import matplotlib.pyplot as plt
n = [1000, 5000, 10000, 50000, 100000, 200000]
time = [0.000001,0.000007,0.000016,0.000065,0.000119,0.000222]

plt.plot(n, time, marker='o')
plt.xlabel("Number of Elements (n)")
plt.ylabel("Time Taken (seconds)")
plt.title("Linear Search Time Complexity")
plt.grid(True)
plt.show()

#1b binary search
import matplotlib.pyplot as plt
n = [1000,5000,10000,50000,100000,200000]
time = [0.000047,0.000065,0.000070,0.000072,0.000068,0.000076]

plt.plot(n,time,marker='o')
plt.xlabel("Number of Elements(n)")
plt.ylabel("Time Taken(in Seconds)")
plt.title("Binary Search Time Complexity")
plt.grid(True)
plt.show()