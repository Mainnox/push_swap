## PushSwap

<img src="http://www.hugobally.me/host/img/pushswap1.png" width="30%"></img> <img src="http://www.hugobally.me/host/img/pushswap2.png" width="30%"></img> <img src="http://www.hugobally.me/host/img/pushswap.png" width="30%"></img> 

The goal of this project was to sort a queue A using only an additional queue B and the following set of instructions :

* pop from one queue and push to the other
* rotate/reverse rotate the queue
* swap the top two elements of the queue

The tricky part is finding an efficient sorting algorithm to minimize the number of instructions needed. A mix of quicksort and insertion sort was used.

The 'push_swap' binary takes a list of integers as input and outputs a list of instructions.

The 'checker' binary takes a list of integers as input, reads instructions from stdin and outputs 'OK'|'KO' if applying the instructions to the list sorts|doesn't sort the list correctly. \[add -v for visualizer\] 

A visualizer is included to see the sorting in progress.
