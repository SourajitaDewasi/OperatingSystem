#include <iostream>
using namespace std;
int MaximumSizeAvailable=12;
 
int BlockFiles[12];
int BlockIndex[12];
int IndexBlock, n;int i;int j; int k; int Choice=0;
void Allotment();
void IndexedAllocation(){
    cout << "\n Enter the index block number: ";
    cin >> IndexBlock;
    if (BlockFiles[IndexBlock] != 1){
        cout << "\n Enter the number of blocks needed for the index " << IndexBlock << " on the disk: ";
        cin >> n;
    }
    else{
        cout << IndexBlock << " is already allocated \n" << endl;
        IndexedAllocation();
    }
    Allotment();
}
void Allotment(){
    int occupied = 0;
    cout<<"\n Allotment of Files on the Index - File ";
    for (i=0; i<n; i++){
        cin >> BlockIndex[i];
        if (BlockFiles[BlockIndex[i]] == 0)
            occupied++;
    }
    if (occupied == n){ //All the files are alloted and indexed
        for (j=0; j<n; j++){
            BlockFiles[BlockIndex[j]] = 1;
        }
        cout << "\n Allocated and File Indexed";
        cout<<"\n File Number  \t\t Length \t\t Index Block Allocated";
        for (k=0; k<n; k++){
            cout <<"\n"<< IndexBlock << " \t\t\t\t " << BlockIndex[k] << " \t\t\t\t " << BlockFiles[BlockIndex[k]];
        }
    }
    else{
        cout << "\n File in the index is already allocated";
        cout << "\n Enter another file to index";
       Allotment();
    }
    cout << "\n Do you want to enter more files?";
    cin >> Choice;
    if (Choice == 1)
        IndexedAllocation();
    else
        exit(0);
    return;
}

int main()
{   cout<<"\n Simulation of Indexed Allocation";
    for(int i=0;i<MaximumSizeAvailable;i++){
        BlockFiles[i]=0;
        BlockIndex[i]=0;
    }
    IndexedAllocation();
    return 0;
}
