/* SCAN algorithm : Go from the outside to inside servicing requests till 0 and then back from inside
to outside servicing requests. This algorithm is simple and easy to understand. CAN algorithm have
no starvation. This algorithm is better than FCFS Scheduling algorithm . */

//This code is implemented by Sourajita Dewasi
#include <iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
int last=0;
int first=0;
int loc,count, i, j, temp,seek, head_indice, least_indice, Cylinder;
int seek1=0;

int SCAN(int arr[], int n, int head){
    int arr1[8];
    arr1[0]=0;
    int distance=0;
    arr1[6]=head;
    arr1[7]=199;
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
    //Going outside the track
    for(i=head_indice+1; i<8; i++){
        distance=arr1[i]-head;
        seek=seek+distance;
        head=arr1[i];
        cout<<"\n Next address is "<<head;
    }
    
        //Going inside the track
    for( i=head_indice-1; i>0; i--){
        distance=head-arr1[i];
        seek=seek+distance;
        head=arr1[i];
        cout<<"\n Next address is "<<head;
    }
        
   
    /*Calculating the distance by measuring the distance between last track present 
    and head, last track present and minimum request present. 
    Summing them up to find the final distance. */
    
    seek1=(arr1[7]-arr1[1])+(arr1[7]-arr1[head_indice]);
    return seek1;
    }
    

int main() {
	int Request[5]={23,89,132,42,187}; //Request Array
	Cylinder=SCAN(Request, 5, 100); //Initially head is at 100
	cout<<"\n Total no of seeks "<<Cylinder;
	return 0;
}
