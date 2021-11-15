//This code is contributed by Sourajita Dewasi
#include <iostream>
using namespace std;

int main()
{
      int frames[12], temp[12];
      int total_pages=12, i, m,n, j, position, k, l; int total_frames=4;
      int a = 0, b = 0, page_fault = 0;
      for(i = 0; i < total_frames; i++)
      {
            frames[i] = -1;
      }
      
      int pages[12]={5,1,2,3,5,1,4,5,1,2,3,4};
    
      for(n = 0; n < total_pages; n++)
      {
            a = 0, b = 0;
            for(m = 0; m < total_frames; m++)
            {
                  if(frames[m] == pages[n])
                  {
                        a = 1;
                        b = 1;
                        break;
                  }
            }
            if(a == 0)
            {
                  for(m = 0; m < total_frames; m++)
                  {
                        if(frames[m] == -1)
                        {
                              frames[m] = pages[n];
                              b = 1;
                              break;
                        }
                  }
            }
            if(b == 0)
            {
                  for(m = 0; m < total_frames; m++)
                  {
                        temp[m] = 0;
                  }
                  for(k = n - 1, l = 1; l <= total_frames - 1; l++, k--)
                  {
                        for(m = 0; m < total_frames; m++)
                        {
                              if(frames[m] == pages[k])
                              {
                                    temp[m] = 1;
                              }
                        }
                  }
                  for(m = 0; m < total_frames; m++)
                  {
                        if(temp[m] == 0)
                        position = m;
                  }
                  frames[position] = pages[n];
                  page_fault++;
            }
            cout<<"\n ";
            for(m = 0; m < total_frames; m++)
            {
                 cout<<"\t"<<frames[m];
            }
      }
      cout<<"\n Total Number of Page Faults: "<<page_fault;
      cout<<"\n Total Number of Page Hits are: "<<total_pages-page_fault;
      return 0;
}
