#include <iostream>

using namespace std;
int PC1=1, PC2=1;
int a=0;
int flag0=0, flag1=0;
 
 
int turn=0;
int PZero(int PC1, int b1){
    int x1=PC1;
    while(b1>=x1){
    switch(x1){
        case 1: flag0=1; x1++;
                break;  
                
        case 2: turn =1; x1++;
                break;
                
        case 3: while(turn==1 && flag1==1){cout<<"\n Waiting for P1 to come out of CS"; break;}
                x1++;
                break;
                
        case 4: a=5; x1++; cout<<"\n CS of P0";
                break;
                
        case 5: flag0=0;
                cout<<"\n Process 0 completed";
                x1++;
                break;
    }
    }
    if(x1==6){
        x1=0;
    }
    cout<<"\n a="<<a;
    return x1;
}

int POne(int PC2, int b2){
    int x2=PC2;
    while(b2>=x2){
    switch(x2){
        case 1: flag1=1; x2++;
                break;  
                
        case 2: turn =0; x2++;
                break;
                
        case 3: while(turn==0 && flag0==1){cout<<"\n Waiting for P0 to come out of CS"; break;}
               x2++;
                break;
                
        case 4: a=a-5; x2++;cout<<"\n CS of P1";
                break;
                
        case 5: flag1=0;
                cout<<"\n Process 1 completed";
                x2++;
                break;
    }
    }
    if(x2==6){
        x2=0;
    }cout<<"\n a="<<a;
    return x2;
}

int main() {
    int PC1=0;
    int PC2=0;
    cout<<"***General Test Run of Peterson's Algorithm. The value of 'a' after process is completed is final";
	PC1=PZero(1,5);
	PC2=POne(1,5);
	
	cout<<"\n ****** Case 1 of Mutual Exclusion if Process0 is preempted during Entry Condition";
	PC1=PZero(1,2);
	PC2=POne(1,2);
	PC1=PZero(PC1,4);
	PC2=POne(PC2,3);
	PC1=PZero(PC1,5);
	PC2=POne(PC2,5);
	
	cout<<"\n Case 2 of Mutual Exclusion if Process0 is preempted during Entry Condition";
	PC1=PZero(1,2);
	PC2=POne(1,3);
	PC1=PZero(PC1,5);
	PC2=POne(PC2,5);
	
	cout<<"\n\n ****** Case of Progress:";
	cout<<" Checking if Process1 will Busy Wait till Process0 has done CS if Process0 has already entered CS";
	PC1=PZero(1,4);
	PC2=POne(1,3);
	PC1=PZero(PC1,5);
	PC2=POne(PC2,5);
	
	cout<<"\n Case of Progress: ";
	cout<<"Checking if Process1 will enter into deadlock if";
	cout<<"\nProcess0 has completed entry condition but got preempted before it had enter CS";
	PC1=PZero(1,4);
	PC2=POne(1,3);
	PC1=PZero(PC1,5);
	PC2=POne(PC2,5);
	
	cout<<"\n *** Case of Bounded Waiting ";
	PC1=PZero(1,4);
	PC2=POne(1,3);
	PC1=PZero(PC1,5);
	PC1=PZero(1,3);
	PC2=POne(PC2,5);
	PC1=PZero(PC1,5);

	return 0;
}
