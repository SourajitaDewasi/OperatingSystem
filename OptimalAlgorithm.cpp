//This code is contributed by Sourajita Dewasi
#include <iostream>
using namespace std;

int main()
{
    int noframes=3, nopages=12, frames[12], temp[12];
    int flag1, flag2, flag3, i, j, k, pos, max, page_faults = 0;
    cout<<"\n Optimal Page Replacement Algorithm";
    int pages[12]={5,1,2,3,5,1,4,5,1,2,3,4};
    for(i=0; i<noframes; ++i){
        frames[i] = -1;
    }
    
    for(i=0; i<nopages; ++i){
        flag1 = flag2 = 0;
        
        for(j=0; j<noframes; ++j){
            if(frames[j] == pages[i]){
                   flag1 = flag2 = 1;
                   break;
               }
        }
        if(flag1 == 0){
            for(j = 0; j<noframes; ++j){
                if(frames[j] == -1){
                    page_faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }    
        }
        if(flag2 == 0){
        	flag3 =0;
        	
            for(j = 0; j < noframes; ++j){
            	temp[j] = -1;
            	
            	for(k = i+1; k<nopages; ++k){
            		if(frames[j] == pages[k]){
            			temp[j] = k;
            			break;	}
            	}
            }
            
            for(j=0; j<noframes; ++j){
            	if(temp[j] == -1){
            		pos = j;
            		flag3 = 1;
            		break;
            	}
            }
            if(flag3 ==0){
            	max = temp[0];
            	pos = 0;
            	
            	for(j = 1; j < noframes; ++j){
            		if(temp[j] > max){
            			max = temp[j];
            			pos = j;
            		}
            	}            	
            }
			frames[pos] = pages[i];
			page_faults++;
        }
        
        cout<<"\n";
        for(j = 0; j < noframes; ++j){
            cout<<"\t\t"<<frames[j];
        }
    }
   cout<<"\n Total Number of Page Faults "<<page_faults;
   cout<<"\n Total number of Page Hits "<<nopages-page_faults;
   return 0;
}

