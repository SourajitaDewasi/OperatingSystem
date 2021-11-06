/*SSTF Scheduling: Select the disk service request that requires the least movement of the disk head
from the current position regardless of the direction. Starvation possible. 
Switching head direction slows down the system. Every request is serviced. */

/*We are assuming static order of requests. */

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct request{
    int value;
    int access;
}R[5];

int main()
{
int i,j,seek=0,min,loc,x,y;
int head=100;
int n=5;
int A[5], ar[5];

cout<<"\n Enter request queue";
    for(i=0;i<n;i++)
    {
        cin>>R[i].value;
        R[i].access=0;
    }
    
    for(i=0;i<n;i++)
    { x=0; min=0;loc=0; 
        if(i!=0){
            cout<<"\n Next address is "<<head;
        }
    for(j=0;j<n;j++)
    {
        if(R[j].access==0)
        {
            if(x==0)
            {
                ar[j]=head-R[j].value;
                if(ar[j]<0)
                    { ar[j]=R[j].value-head;}
                    min=ar[j];
                    loc=j;
                    x++; }
                else{
                    ar[j]=head-R[j].value;
                if(ar[j]<0)
                    { ar[j]=R[j].value-head;}
            }
            if(min>ar[j])
            { min=ar[j]; loc=j;}
        }
    }
    R[loc].access=1;
    
    A[i]=R[loc].value-head;
    if(A[i]<0)
        {A[i]=head-R[loc].value;}
    head=R[loc].value;
     if((i)==4){
        cout<<"\n Next address is "<<head;
    }
    }
    
    for(i=0;i<n;i++)
    {
    seek=seek+A[i];
    }
   
    cout<<"\n Total no of seeks "<<seek;
    return 0;
    
}