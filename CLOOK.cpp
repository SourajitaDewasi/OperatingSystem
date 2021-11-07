//This code is contributed by Sourajita Dewasi

/* CLOOK algorithm : Go from the outside to inside servicing requests till the least service request
value and then back to the outmost disk to inside servicing requests. This algorithm is simple and 
easy to understand. CLOOK algorithm have less starvation than SSTF and CSCAN.
This algorithm considers the disk in circular form. */

#include <iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
int seek1,count, i, j, temp,seek, head_indice, Cylinder;

int CLOOK(int arr[], int n, int head){
    int arr1[6];
    int distance=0;
   
    for(i=0; i<n; i++){
        arr1[i]=arr[i];
    }
     arr1[5]=head;
    sort(arr1,arr1+6);
    for(int i=0; i<6; i++){
        if(arr1[i]==head){
            head_indice=i;
        }
    }  
    
        //Going inside the track
    for( i=head_indice-1; i>=0; i--){
        distance=head-arr1[i];
        seek=seek+distance;
        head=arr1[i];
        cout<<"\n Next address is "<<head;
    }
    
        //Going outside the track
    for(i=5; i>head_indice;i--){
        distance=arr1[i]-head;
        seek=seek+distance;
        head=arr1[i];
        cout<<"\n Next address is "<<head;
    }
    seek1=(arr1[5]-arr1[head_indice])+(arr1[5]-arr1[0])+(arr1[head_indice-1]-arr1[0]);
    return seek1;
    }
    

int main() {
	int Request[5]={23,89,132,42,187}; //Request Array
	Cylinder=CLOOK(Request, 5, 100); //Initially head is at 100
	cout<<"\n Total no of seeks "<<Cylinder;
	return 0;
}
