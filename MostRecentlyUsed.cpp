/* Most Recently Used is based on the idea that the page if it has been recently used may not be 
required by the memory immediately and hence can be replaced by an incoming non- placed page. So 
in this algorithm the most recent page is replaced by a page which isn't present in the frame.*/

//This code is contributed by Sourajita Dewasi
#include <iostream>
using namespace std;

struct Frame{
    int PageNo;
    int MostRecentlyUsed;
}F[3];

int i,j; int miss=0; int hits=0; int alloted=0; int frame; int n=12; 


int main(){
    cout<<"MRU Simulation: ";
    int array[n] = {5,1,2,3,5,1,4,5,1,2,3,4};
    /*cout<<"\n The reference string is: ";
    for(i=0; i<12; i++){
        cout<<"\t "<<array[i];
    }*/
	//initialize the frames with first non-unique three pages. Those are all misses.
	for(i=0, j=0; i<3; i++, j++){
	    F[i].PageNo = array[j];
	    F[i].MostRecentlyUsed =0;
	    miss++; frame=j;
	    cout<<"\n For process "<<array[i]<<" Frame "<<i<<" is used";
	}F[2].MostRecentlyUsed=1;
	
    for(i=3; i<12; i++){
        alloted=0;
        for(j=0; j<3; j++){ //check if the page is already present in the memory
            if(F[j].PageNo == array[i]){
                F[j]. MostRecentlyUsed = 1;
                hits++; alloted=1; frame=j;
            }
       }
       if(alloted == 1){ //make mostrecentlyused of other frames 0 in case the page is already present
            for(j=0; j<3; j++){
                if(frame != j){
                     F[j].MostRecentlyUsed = 0;
                   }
        }
    }
    /*if the page isn't present, make mostrecentlyused as 1, and allot the page to a frame that was
    last most recently used.*/
        if(alloted != 1){ 
            for(j=0; j<3; j++){
                if(F[j].MostRecentlyUsed==1){
                    F[j].PageNo == array[i];
                    alloted=1; frame=j; miss++;
                }
            }
        } cout<<"\n For process "<<array[i]<<" Frame "<<frame<<" is used";
    }    
    cout<<"\n No of misses are: "<<miss;
    cout<<"\n No of hits are: "<<hits;
	return 0;
}
