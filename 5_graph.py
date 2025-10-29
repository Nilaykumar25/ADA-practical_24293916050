#5a fractional Knapsack Time and space complexity
import matplotlib.pyplot as plt
elements = [10, 100, 500, 750, 1000]
time_taken = [0.000000, 0.002000, 0.018000, 0.024000, 0.035000]
space_used = [480, 1200, 4400, 6400, 8400]

#Time Complexity
plt.figure(figsize=(8,5))
plt.plot(elements, time_taken, marker='o', linewidth=2)
plt.title("Fractional Knapsack: Time vs Number of Elements")
plt.xlabel("Number of Elements (n)")
plt.ylabel("Time Taken (seconds)")
plt.grid(True)
plt.show()

#Space complexity
plt.figure(figsize=(8,5))
plt.plot(elements, space_used, marker='s', color='orange', linewidth=2)
plt.title("Fractional Knapsack: Space vs Number of Elements")
plt.xlabel("Number of Elements (n)")
plt.ylabel("Space Used (bytes)")
plt.grid(True)
plt.show()


#5b 0/1 Knapsack Time and space complexity
import matplotlib.pyplot as plt
sizes = [10, 100, 500, 750, 1000]
time_taken = [0.001000, 0.018000, 0.125000, 0.154000, 0.207000]
space_used = [564, 5244, 26044, 39044, 52044]

#Time
plt.figure(figsize=(8, 5))
plt.plot(sizes, time_taken, marker='o', linestyle='-', color='b', label='Execution Time')
plt.title('Time taken to maximise profit vs Number of elements')
plt.xlabel('Number of Elements (n)')
plt.ylabel('Time (seconds)')
plt.grid(True)
plt.legend()
plt.show()

#Space
plt.figure(figsize=(8, 5))
plt.plot(sizes, space_used, marker='s', linestyle='--', color='g', label='Memory Usage')
plt.title('Estimated Space Used vs Number of elements')
plt.xlabel('Number of Elements (n)')
plt.ylabel('Space (bytes)')
plt.grid(True)
plt.legend()
plt.show()