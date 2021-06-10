#include <iostream>
#include<vector>
#include<queue>
#include<list>
#include<math.h>
#include<algorithm>
using namespace std;
//node class
template<typename T>
//BubbleSort 

class BubbleSort
{
	
	public:
		BubbleSort(){
		}
		~BubbleSort()
		{
			
		}
		 void sortData(vector<T> &data)  
		{
			
			for(int i=0;i<data.size();i++)
			{
				for(int j=0;j<data.size()-1;j++)
				{
					if(data.at(j)>data.at(j+1))
					swap(data.at(j),data.at(j+1));
					
				}
			}

		}
};
int main()
{
	vector<int> data={11,21,3,4,5,18,20};
	 BubbleSort<int> *bubbleSort=new BubbleSort<int>();
	 bubbleSort->sortData(data);
	 for(auto d: data)
	 {
	 	cout<<d<<endl;
	 }
	
}
