#include <iostream>
#include<vector>
#include<queue>
#include<list>
#include<math.h>
#include<algorithm>
using namespace std;
//node class
template<typename T>
//Quick sort is a stable algorithm and its a inplace algo means no extra space (const space need as temp) required 
class QuickSort
{
	private:
		
	public:
		
		QuickSort()
		{
			
		}
		~QuickSort()
		{
			
		}
	    void sortData(vector<T> &data,unsigned int _start,unsigned int _end)
	    {
	    	 //begin
		     unsigned int start=_start;
			 //end
			 unsigned int end=_end;
			 //until begin < end	 
		     if(start<end)
		     {
		     	unsigned int pIndex=getPivotIndex(data,start,end); 
		     	sortData(data,start,pIndex-1);
		     	sortData(data,pIndex+1,end);
			 }
			 
     	}
     	int getPivotIndex(vector<T> &data,unsigned int _start,unsigned int _end)
     	{
     		unsigned int start=_start;
     		unsigned int end=_end;
     		unsigned int pIndex=start;
     		T pivotValue=data.at(end);
     		//loop array and swap index value with pIndex only if index value is less than pivot value
     		for(unsigned int i=start;i<end;++i)
     		{
     			if(data.at(i)<=pivotValue)
     			{
     				swap(data.at(i),data.at(pIndex));
        			++pIndex;			
				 }
			}
			swap(data.at(pIndex),data.at(end));
			return pIndex;
		
	    }
};
int main()
{
	vector<unsigned int> data={11,12,1,1,1,90,10,20,1,1,1,1,89,90,2,199,100};
	QuickSort<unsigned int> *quicksort=new QuickSort<unsigned int>();
	quicksort->sortData(data,0,data.size()-1);
	for(auto d:data)
	{
		cout<<d<<endl;
	}
}
