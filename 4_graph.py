#4a fibonacci recursive
import matplotlib.pyplot as plt

n_values = [5, 10, 15, 20, 25, 30]
execution_times = [0.0, 0.0, 0.001, 0.002, 0.004, 0.015]
plt.plot(n_values, execution_times, marker='o', linestyle='-', color='r', label="Recursive Fibonacci")
plt.xlabel("Number of Terms (n)")
plt.ylabel("Execution Time (seconds)")
plt.title("Execution Time of Recursive Fibonacci")
plt.grid(True)
plt.legend()
plt.show()

#4b fibonacci iterative
import matplotlib.pyplot as plt
n_values = [5, 10, 15, 20, 25, 30]
execution_times = [0.002000, 0.001000, 0.003000, 0.001000, 0.006000, 0.006000]
plt.figure(figsize=(8, 5))
plt.plot(n_values, execution_times, marker='o', linestyle='-', color='b', label="Iterative Fibonacci")
plt.xlabel("Number of Terms (n)")
plt.ylabel("Execution Time (seconds)")

plt.title("Execution Time vs Input Size for Iterative Fibonacci")
plt.legend()
plt.grid(True)
plt.show()

#4c fibonacci topDown
import matplotlib.pyplot as plt
n_values = [5, 10, 15, 20, 25, 30]
execution_times = [0.005000, 0.004000, 0.002000, 0.007000, 0.009000, 0.009000]
plt.figure(figsize=(8,6))
plt.plot(n_values, execution_times, marker='o', color='green', linestyle='-', label="Top-Down DP (Memoization)")
plt.xlabel("Number of Terms (n)")
plt.ylabel("Execution Time (seconds)")
plt.title("Execution Time vs Input Size for Fibonacci (Top-Down DP)")
plt.legend()
plt.grid(True)
plt.show()

#4d fibonacci bottomUp
import matplotlib.pyplot as plt
n_values = [5, 10, 15, 20, 25, 30]
bottom_up_times = [0.000000, 0.002000, 0.003000, 0.002000, 0.003000, 0.004000]
plt.figure(figsize=(8,5))
plt.plot(n_values, bottom_up_times, marker='o', color='b', label="Bottom-Up DP (O(n))")
plt.xlabel("Number of Terms (n)")
plt.ylabel("Execution Time (seconds)")
plt.title("Fibonacci Execution Time (Bottom-Up DP)")
plt.legend()
plt.grid(True)
plt.show()