#3a iterative matrix
import matplotlib.pyplot as plt
n = [2,4,8,16,32]
time = [0.000000,0.002000,0.002000,0.026000,0.200000]

plt.plot(n,time,marker='o')
plt.xlabel("nxn Matrix size")
plt.ylabel("Time Taken(in Seconds)")
plt.title("Iterative Matrix Multiplication Time Complexity")
plt.grid(True)
plt.show()

#3b recursive matrix
import matplotlib.pyplot as plt
n = [2,4,8,16,32]
time = [0.001000,0.002000,0.010000,0.102000,0.676000]

plt.plot(n,time,marker='o')
plt.xlabel("nxn Matrix size")
plt.ylabel("Time Taken(in Seconds)")
plt.title("Recursion Matrix Multiplication Time Complexity")
plt.grid(True)
plt.show()

#3c strassen matrix
import matplotlib.pyplot as plt
n = [2,4,8,16,32]
time=[0.001000,0.005000,0.033000 ,0.113000,1.006000]
plt.plot(n,time,marker='o')
plt.xlabel("nxn Matrix size")
plt.ylabel("Time Taken(in Seconds)")
plt.title("Strassen Matrix Multiplication Time Complexity")
plt.grid(True)
plt.show()
