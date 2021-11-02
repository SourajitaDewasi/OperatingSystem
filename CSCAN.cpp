/* CSCAN algorithm : Go from the outside to inside servicing requests till 0 and then back to the outmost disk
to inside servicing requests. This algorithm is simple and easy to understand. CSCAN algorithm have
less starvation than SSTF. This algorithm considers the disk in circular form. */

#include <iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
int last=0;
int first=0;
int i, j, temp,seek, head_indice, least_indice, Cylinder;
int seek1=0;
int CSCAN(int arr[], int n, int head){
    int arr1[8];
    arr1[0]=0;
    arr1[7]=199; //If there are 200 tracks ranging from 0-199
    int distance=0;
    arr1[6]=head;
    for(i=0; i<n; i++){
        arr1[i+1]=arr[i];
    }
    sort(arr1,arr1+8);
    for(int i=0; i<8; i++){
        if(arr1[i]==head){
            head_indice=i;
        }
        if(arr[i]==0){
            least_indice=i;
        }
    }  
    //Going to the outermost track (right)
    for(i=head_indice; i<8; i++){
        distance=arr1[i]-head;
        seek=seek+distance;
        head=arr1[i];
        cout<<"\n Next address is "<<head;
        
    }
    head=arr[0]; //Going to the cylindrical by read-write head direction change. Lowest track present.
    
    //Again moving from lowest value to the right.
    for( i=0; i<head_indice; i++){
        distance=head-arr1[i];
        seek=seek+distance;
        head=arr1[i];
        cout<<"\n Next address is "<<head;
    }
    seek1=(arr1[7]-arr1[head_indice])+(arr1[7]-arr1[0])+(arr1[head_indice-1]-arr1[0]);
    return seek1;}
    
int main() {
	int Request[5]={23,89,132,42,187}; //Request Array
	Cylinder=CSCAN(Request, 5, 100); //Initially head is at 100
	cout<<"\n Total no of seeks "<<Cylinder;
	return 0;
}
