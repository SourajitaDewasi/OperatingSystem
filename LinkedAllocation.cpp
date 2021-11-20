
#include <iostream>
using namespace std;
int MaximumSizeAvailable=12;

int j=0; int i=0;
void LinkedAllocate(int StartingPos, int Length, int Block[], int Size, int FileNumber, int BlockFile[], int BlockLink[]){
    int k=Length;  int Count;
    if (Block[StartingPos] == 0){
        for (j = StartingPos; j < StartingPos+k; j++){
            if (Block[j] == 0){
                Block[j] = 1; /*
                if(j == (StartingPos+Length-1)){
                    BlockLink[Count]=20; //Returning it to deadend. 20 is not in block
                }
                else{
                    BlockLink[Count]=j; //Keeping the address of current block in previous address place to link them.
                } */
                BlockFile[j]= FileNumber; Count=j;
                cout<<"\n Successful Allocation";
    	        cout<<"\n Block Starting From "<<StartingPos<<" with Length "<<Length;
    	        cout<<" allocated to File Number"<<FileNumber<<" at "<<j; 
            }
            else {
                cout <<"\n The Block "<< j << " is already allocated";
                k++;
            }
        }
    }
}

void Display(int Block[], int MaximumSizeAvailable, int BlockFile[]){
    cout<<"Display of Free and Allocated Blocks \n";
    for(i=0; i<MaximumSizeAvailable; i++){
        if(Block[i]==1){
            cout<<i<<": Block Already allocated to FileNumber"<<BlockFile[i]<<" \n";
        }
        else{
            cout<<i<<": Block Not Allocated \n";
        }
    }
}

void Delete(int Block[], int FileNumber, int MaximumSizeAvailable, int BlockFile[], int BlockLink[]){
    for(i=0; i<MaximumSizeAvailable; i++){
        if(BlockFile[i]==FileNumber){
            BlockFile[i]=0;
            Block[i]=0;
        }
        else{
        }
    }Display(Block, MaximumSizeAvailable, BlockFile);
}

int main() {
	int Block[MaximumSizeAvailable]; int Choice=1; int Start; int Length; int Menu;
    int x=0; int FileNumber=1; int File; int p; int a; int BlockLink[MaximumSizeAvailable];
    int BlockFile[MaximumSizeAvailable];
    for(i=0; i<MaximumSizeAvailable; i++)
    {
        Block[i] = 0;
        BlockFile[i]=0;
    }
    cout << "Enter the number of blocks already allocated: ";
    cin >> p;
    cout << "Enter the blocks already allocated: ";
    for (i = 0; i < p; i++){
        cin >> a;
        Block[a] = 1;
    }
    
    while(Choice)
    {   cout<<"\n Simulation of Linked Allocation"<<"\n 1. Allocate"<<"\n 2. Display"<<"\n 3. Delete \n 4. Exit \n";
        cout<<"Enter the Value ";
    	cin>>Menu;
    	switch(Menu){
    	    case 1: cout<<"\n Enter the starting block address: "; cin>>Start;
    	            cout<<"\n Enter units of block required "; cin>>Length;
    	            LinkedAllocate(Start, Length, Block, MaximumSizeAvailable, FileNumber, BlockFile, BlockLink);
    	            break;
    	   case 2:  Display(Block, MaximumSizeAvailable, BlockFile); break;
    	   case 3:  cout<<"\n Which FileNumber Do You Want To Delete? "; 
    	            cin>>File; Delete(Block, File,  MaximumSizeAvailable, BlockFile, BlockLink); 
    	            break;
    	   case 4:  return 0;
    	   
    	}
    	cout<<"\n Do you want to continue "; cin>>Menu; FileNumber++;
    }return 0;
}
