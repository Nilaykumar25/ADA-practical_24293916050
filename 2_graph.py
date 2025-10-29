#2a merge sort
import matplotlib.pyplot as plt
n = [100,500,1000,3000,5000,6000,7000,8000]
time = [0.039000,0.177000,0.345000,0.928000,1.758000,2.171000,2.569000,2.875000]

plt.plot(n,time,marker='o')
plt.xlabel("Number of Elements(n)")
plt.ylabel("Time Taken(in Seconds)")
plt.title("Merge Sort Time Complexity")
plt.grid(True)
plt.show()

#2b quick sort
import matplotlib.pyplot as plt
n = [100,500,1000,3000,5000,6000,7000,8000]
time=[0.000005,0.000030,0.000070,0.000387,0.000706,0.000846, 0.000975,
0.001310]
plt.plot(n,time,marker='o')
plt.xlabel("Number of Elements(n)")
plt.ylabel("Time Taken(in Seconds)")
plt.title("Quick Sort Time Complexity")
plt.grid(True)
plt.show()

#2c insertion sort
import matplotlib.pyplot as plt
n = [100,500,1000,3000,5000,6000,7000,8000]
time=[0.00000,0.004000,0.007000,0.019000,0.032000,0.039000,0.050000,0.05
9000]
plt.plot(n,time,marker='o')
plt.xlabel("Number of Elements(n)")
plt.ylabel("Time Taken(in Seconds)")
plt.title("Insertion Sort Time Complexity")
plt.grid(True)
plt.show()

#2d selection sort
import matplotlib.pyplot as plt
n = [100,500,1000,3000,5000,6000,7000,8000]
time=[0.010000,0.196000,0.9140000,7.992000,22.042000,31.129000,44.98800
00,57.381000]
plt.plot(n,time,marker='o')
plt.xlabel("Number of Elements(n)")
plt.ylabel("Time Taken(in Seconds)")
plt.title("Selection Sort Time Complexity")
plt.grid(True)
plt.show()

#2e bubble sort 
import matplotlib.pyplot as plt

n = [100,500,1000,3000,5000,6000,7000,8000]
time=[0.009000,0.157000,0.820000,8.438000,21.572000,32.645000,39.519000,
55.371000]
plt.plot(n,time,marker='o')
plt.xlabel("Number of Elements(n)")
plt.ylabel("Time Taken(in Seconds)")
plt.title("Bubble Sort Time Complexity")
plt.grid(True)
plt.show()

