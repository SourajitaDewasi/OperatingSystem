# OperatingSystem
Algorithms Studied During Operating Sytem Course

## Page Replacement Algorithm
1. *First In First Out (FIFO) Algorithm:* This is the basic page replacement method. The operating system uses this algorithm to maintain track of all pages in memory in a queue, with the oldest page at the top. When a page has to be replaced, the first page in the queue is chosen for replacement. 

2. *Least Recently Used (LRU) Algorithm:* The Least Recently Used (LRU) algorithm is a greedy method in which the page to be replaced is the one that has been used the least recently. The concept is based on the fact that the most recently used page is unlikely to be the most recently utilised page. 

3. *Most Recently Used (MRU) Algorithm:* The Most Recently Used (LRU) algorithm is a greedy method in which the page to be replaced is the one that has been used the least recently. The concept is based on the fact that the most recently used page is unlikely to be the most recently utilised page. 
4. *Optimal Algorithm:*

## File Allocation Algorithm
1. *Indexed Allocation:* Indexed allocation scheme stores all the disk pointers in one of the blocks called as indexed block. Indexed block doesn't hold the file data, but it holds the pointers to all the disk blocks allocated to that particular file. Directory entry will only contain the index block address.

2. *Linked Allocation:* Linked Allocation is a non-contiguous memory allocation method. We just keep a link of the next 
address in the previous block to not search throught memory for faster allocation or deallocation.

3. *Sequential Allocation:* Also known as Contigous Allocation, each file occupies a contiguous set of blocks on the disk.  This means that given the starting block address and the length of the file (in terms of blocks required), one can determine the blocks occupied by the file. The directory entry for a file with contiguous allocation contains:

    1. Address of starting block
 
    2. Length of the allocated portion.

## Disc Scheduling Algorithm
1. *FCFS Scheduling:* It is the Simplest Disk Scheduling Algorithm. It erforms operations according to order of the request. No ordering of work queue. 
No starvation. Every request is serviced. In the code, I assumed static order of requests.

2. *SSTF Scheduling:* Select the disk service request that requires the least movement of the disk head from the current position regardless of the direction. Starvation possible. Switching head direction slows down the system. Every request is serviced.

3. *LOOK Algorithm:* Same as SCAN but will go to the least request track and not till 0 and then back from inside to outside servicing requests. This algorithm is simple and easy to understand. LOOK algorithm have no starvation. This algorithm is better than FCFS and SCAN Scheduling algorithm.

4. *SCAN algorithm:* Go from the outside to inside servicing requests till 0 and then back from inside to outside servicing requests. This algorithm is simple and easy to understand. CAN algorithm have no starvation. This algorithm is better than FCFS Scheduling algorithm.

5. *CLOOK Algorithm:* Go from the outside to inside servicing requests till the least service request value and then back to the outmost disk to inside servicing requests. This algorithm is simple and easy to understand. CLOOK algorithm have less starvation than SSTF and CSCAN. This algorithm considers the disk in circular form.

6. *CSCAN Algorithm:* Go from the outside to inside servicing requests till 0 and then back to the outmost diskto inside servicing requests. This algorithm is simple and easy to understand. CSCAN algorithm haveless starvation than SSTF. This algorithm considers the disk in circular form.

## CLASSICAL PROBLEMS IN OPERATING SYSTEM

1. *The Dining Philosopher's Problem* : The dining philosopher's problem is a variation on the traditional synchronisation problem, in which five philosophers sit around a circular table and alternate between thinking and eating. A bowl of noodles, as well as five chopsticks for each of the philosophers, is placed in the centre of the table.
A philosopher must use both their right and left chopsticks to eat. A philosopher can only eat if both of his or her immediate left and right chopsticks are available.
If the philosopher's immediate left and right chopsticks are not available, the philosopher places their (either left or right) chopstick on the table and resumes thinking.

2. *Producer Consumer Semaphore Problem* : Producer consumer problem is a classical synchronization problem. There is a fixed-size buffer. A producer can make a product and store it in the buffer. A consumer has the ability to select and consume objects. We must ensure that when a producer places an item in the buffer, the consumer does not consume any of the items. The buffer portion is crucial in this problem. 
