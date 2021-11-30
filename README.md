# **Banker’s Algorithm for Deadlock Avoidance**
## By, Jason Abounader

**Determining if system is in a safe state through banker's algorithm**

Considering a system with five processes P0 through P4 and three resources of type A, B, C. Resource type A has 10 instances, B has 5 instances and type C has 7 instances. Suppose at time t0 following snapshot of the system has been taken:

![Screenshot from 2021-11-29 21-58-34](https://user-images.githubusercontent.com/86804265/143980910-e27d7ca6-a408-44e0-a59c-f0b97df6486d.png)

Implement the Banker’s algorithm to answer the following question：Is the system in a safe state? If Yes, then what is the safe sequence?

C++ code was written that reads a .csv file in the format shown above and determines if the system is in a safe state. If it is in a safe state the program will then print out the safe sequence using Banker's Algorithm. See bankers.cpp for reference.

**Compiled and executed using G++ Compiler with the following commands:**

g++ bankers.cpp -std=c++11 -o safestatecheck

./safestatecheck input.csv

**Output:**

![Screenshot from 2021-11-29 22-00-09](https://user-images.githubusercontent.com/86804265/143982008-adfa2fb4-cff3-4a5d-96f2-371033f4cddb.png)

As shown above, the system is in a safe state and the safe sequence in order is P1, P3, P4, P0, and P2.

**Counter Example:**

To show a system that is in an unsafe state see the following table:

![Screenshot from 2021-11-29 21-57-51](https://user-images.githubusercontent.com/86804265/143983002-a2f0b40b-ee65-4633-ae4f-fa2d62e64ffd.png)

The data is executed with the following command:

./safestatecheck badinput.csv

To receive this output: 

![Screenshot from 2021-11-29 22-00-28](https://user-images.githubusercontent.com/86804265/143983080-1b4ba13b-e441-476c-9605-0fa5b555fd37.png)


