/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<float> BucketSort(vector<float> &Range)
{
    int size=Range.size();
    vector<vector<float>>  Buckets(size);
    //fill Buckets with right Index
    for(int i=0;i<size;i++)
    {
        int index=size*Range.at(i);
        Buckets.at(index).push_back(Range.at(i));
    }
    //Sort individual buckets
    for(int i=0;i<size;i++)
    {
        sort(Buckets.at(i).begin(),Buckets.at(i).end());
    }
    
    int index=0;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<Buckets.at(i).size();j++)
        {
            Range[index++]=Buckets.at(i).at(j);
        }
    }
    
   
    return Range;
    
    
};
int main()
{
    vector<float> Range={ 0.897,0.565, 0.656, 0.1234, 0.665, 0.3434};
  vector<float> result=BucketSort(Range);
    
    for( auto x:result)
    {
        cout<<x<<" ";
    }
    return 0;
}

