# OperatingSystem
Algorithms Studied During Operating Sytem Course
1. First In First Out (FIFO)
2. Least Recently Used (LRU)
3. Most Recently Used (MRU)
4. Optimal

## Allocation
1. Indexed Allocation
2. Linked Allocation: Linked Allocation is a non-contiguous memory allocation method. We just keep a link of the next 
address in the previous block to not search throught memory for faster allocation or deallocation
3. Sequential Allocation

## Disc Schedueling Algorithm
1. CLOOK: Go from the outside to inside servicing requests till the least service request
value and then back to the outmost disk to inside servicing requests. This algorithm is simple and 
easy to understand. CLOOK algorithm have less starvation than SSTF and CSCAN.
This algorithm considers the disk in circular form.
