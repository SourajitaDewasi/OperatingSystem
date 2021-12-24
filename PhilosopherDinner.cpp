//This code is contributed by Sourajita Dewasi
#include<iostream>
using namespace std;
#define n 4

int comp = 0,i;
 
struct Chopstick{
	int taken;
}C[n];
 
struct Philosopher{
	int left;
	int right;
}P[n];
 
void Dinner(int x){ 
	if(P[x].left==5 && P[x].right==5)
    {cout<<"Philosopher "<<x+1<<" done with dinner\n";}

	else if(P[x].left==1 && P[x].right==1){
       cout<<"Philosopher "<<x+1<<" just did dinner\n";
       P[x].left = P[x].right = 5;
       int OtherC = x-1;
       if(OtherC== -1)
       OtherC=(n-1);
       C[x].taken = C[OtherC].taken = 0;
       cout<<"Philosopher "<<x+1<<" released chopstick "<<x+1<<" and chopstick "<<OtherC+1<<"\n";
       comp++;
        }
        else if(P[x].left==1 && P[x].right==0){ 
                if(x==(n-1)){
                    if(C[x].taken==0){ 
                        C[x].taken = P[x].right = 1;
                        cout<<"Chopstick "<<x+1<<" is taken by philosopher "<<x+1<<"\n";
                    }else{
                        cout<<"Philosopher "<<x+1<<" is waiting for chopstick "<<x+1<<"\n";
                    }
                }else{ 
                    int dp = x;
                    x-=1;
 
                    if(x == -1)
                        x=(n-1);
 
                    if(C[x].taken == 0){
                        C[x].taken = P[dp].right = 1;
                        cout<<"Chopstick "<<x+1<<" is taken by Philosopher "<<dp+1<<"\n";
                    }else{
                        cout<<"Philosopher "<<dp+1<<" is waiting for Fork "<<x+1<<"\n";
                    }
                }
            }
            else if(P[x].left==0){ 
                    if(x==(n-1)){
                        if(C[x-1].taken==0){ 
                            C[x-1].taken = P[x].left = 1;
                            cout<<"Chopstick "<<x<<" is taken by philosopher "<<x+1<<"\n";
                        }else{
                            cout<<"Philosopher "<<x+1<<" is waiting for fork "<<x<<"\n";
                        }
                    }else{ 
                        if(C[x].taken == 0){
                            C[x].taken = P[x].left = 1;
                            cout<<"Chopstick "<<x+1<<" is taken by Philosopher "<<x+1<<"\n";
                        }else{
                            cout<<"Philosopher "<<x+1<<" is waiting for Fork "<<x+1<<"\n";
                        }
                    }
        }else{}
}
 
int main(){
	for(i=0;i<n;i++)
        C[i].taken=P[i].left=P[i].right=0;
 
	while(comp<n){
		for(i=0;i<n;i++){Dinner(i);
	}
	}
	
	if(comp==n){
	    cout<<"All dinners done";
	}
	return 0;
}
