//This code is contributed by Sourajita Dewasi
#include<iostream>
using namespace std;

int main()
{     cout<<"\n First In First Out Simulation";
      int reference_string[12]={5,1,2,3,5,1,4,5,1,2,3,4};
      int page_faults = 0;
      int m, n, s, pages=12, frames=4;

      int temp[frames];
      for(m = 0; m < frames; m++)
      {
            temp[m] = -1;
      }
      for(m = 0; m < pages; m++)
      {
            s = 0;
            for(n = 0; n < frames; n++)
            {
                  if(reference_string[m] == temp[n])
                  {
                        s++;
                        page_faults--;
                  }
            }     
            page_faults++;
            if((page_faults <= frames) && (s == 0))
            {  temp[m] = reference_string[m]; }   
            else if(s == 0)
            {
                  temp[(page_faults - 1) % frames] = reference_string[m];
            }
            cout<<"\n";
            for(n = 0; n < frames; n++)
            {     
                  cout<<"\t\t"<< temp[n];
            }
      } 
      cout<<"\n Total Number of Page Faults "<<page_faults;
      cout<<"\n Total number of Page Hits "<<pages-page_faults;
      return 0;
}
