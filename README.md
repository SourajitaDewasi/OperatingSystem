# OperatingSystem
Algorithms Studied During Operating Sytem Course
1. First In First Out (FIFO) Algorithm:
2. Least Recently Used (LRU) Algorithm:
3. Most Recently Used (MRU) Algorithm:
4. Optimal Algorithm:

## File Allocation Algorithm
1. Indexed Allocation: Indexed allocation scheme stores all the disk pointers in one of the blocks called as indexed block. Indexed block doesn't hold the file data, but it holds the pointers to all the disk blocks allocated to that particular file. Directory entry will only contain the index block address.

2. Linked Allocation: Linked Allocation is a non-contiguous memory allocation method. We just keep a link of the next 
address in the previous block to not search throught memory for faster allocation or deallocation.

3. Sequential Allocation: Also known as Contigous Allocation, each file occupies a contiguous set of blocks on the disk.  This means that given the starting block address and the length of the file (in terms of blocks required), one can determine the blocks occupied by the file. The directory entry for a file with contiguous allocation contains
    3.1. Address of starting block
    3.2. Length of the allocated portion.

## Disc Scheduling Algorithm
1. CLOOK Algorithm: Go from the outside to inside servicing requests till the least service request
value and then back to the outmost disk to inside servicing requests. This algorithm is simple and 
easy to understand. CLOOK algorithm have less starvation than SSTF and CSCAN.
This algorithm considers the disk in circular form.

2. CSCAN Algorithm: Go from the outside to inside servicing requests till 0 and then back to the outmost disk
to inside servicing requests. This algorithm is simple and easy to understand. CSCAN algorithm have
less starvation than SSTF. This algorithm considers the disk in circular form.

3. LOOK Algorithm : Same as SCAN but will go to the least request track and not till 0 
and then back from inside to outside servicing requests. This algorithm is simple and easy to 
understand. LOOK algorithm have no starvation. This algorithm is better than FCFS and SCAN 
Scheduling algorithm .

4. SCAN algorithm : Go from the outside to inside servicing requests till 0 and then back from inside
to outside servicing requests. This algorithm is simple and easy to understand. CAN algorithm have
no starvation. This algorithm is better than FCFS Scheduling algorithm.
