/*FCFS Scheduling: Simplest Disk Scheduling Algorithm. 
Performs operations according to order of the request. No ordering of work queue. 
No starvation. Every request is serviced. */

/*We are assuming static order of requests. */

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int seek=0; int i=0; int Cylinder=0;

int FCFS(int request[], int n, int head){
    int distance=0; int current_track;
    
    for(i=0; i<n; i++){
        current_track=request[i]; //Setting current track to the request to be serviced
        if(current_track-head >0){
            distance=current_track-head; //Current difference between head and current request
        }
        else{
            distance=head-current_track;
        }
        seek=seek+distance; //Summing the distance covered by read-write head
        head=current_track; //Accessed track = New head
        }
        
    //Seek records will be in the same order as given request
    cout<<"\nSeek sequence";
    for(i=0; i<n; i++){
        cout<<" "<<request[i]<<" ";
    }
    
    return seek;
}

int main() {
	int Request[5]={23,89,132,42,187}; //Request Array
	Cylinder=FCFS(Request, 5, 100); //Initially head is at 100
	cout<<"\n Total no of seeks "<<Cylinder;
	return 0;
}
