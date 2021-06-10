/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<vector> 
using namespace std;

//divide recursively array/vector into smaller parts until they are be reduced further
//merge recursively until you get the right result
//time complexity is O(nlogn)
//suitable for big range and if lots of item unsorted
//don't use for small range as merge sort required extra space which in liner O(n) its required two extra parts to hold the left and right part


void combine(vector<int> leftPart,vector<int> rightPart, vector<int> /*pass by reference because we want to manipulate same vector*/&myVector)
{
    //length of left part
    long L=leftPart.size();
    
    
    //length of right part
    long R=rightPart.size();
    
    
    //create three variables which would help us to fill the sorted items
    long LV=0;
    long RV=0;
    long FV=0;
    
    
    //check and fill the left and right part in sorted mannner
    while (LV<L && RV<R) {
        
        if(leftPart.at(LV)<=rightPart.at(RV))
        {
            myVector[FV]=leftPart.at(LV);
            LV+=1;
        }else
        {
            myVector[FV]=rightPart.at(RV);
            RV+=1;
        }
        FV+=1;
        
    }
    while (LV<L) {
        myVector[FV]=leftPart.at(LV);
        LV+=1;
        FV+=1;
    }
    while (RV<R) {
        myVector[FV]=rightPart.at(RV);
        RV+=1;
        FV+=1;
    }
}

void MergeSort(vector<int> &myVector)
{
    //get length of myVector if its less than 2 its can't sorted one element is always sorted.
    long myVectorLength=myVector.size();
    if(myVectorLength<2)
        return;
  
    //if length is greater than 1  we need divide vector into two parts
    //first part would be left part and second part would be right part
    
    //get middle of vector
    long mid=myVectorLength/2;
    
    //first part start from 0 to mid-1
    //and also we need a array which holds the first part
    vector<int> leftPart;
    //fill the left Part
    for(int i=0;i!=mid;i++)
    {
        leftPart.push_back(myVector[i]);
    }
    //deal with right part now
    //but it would start form mid
    vector<int> rightPart;
    
    for(long i=mid;i<myVector.size();i++)
    {
        rightPart.push_back(myVector[i]);
        
    }
    
    
    //recursively call this function until array is not broken to single item
    MergeSort(leftPart);
    MergeSort(rightPart);
    //combine array recursively
    combine(leftPart,rightPart,myVector);
    
};



int main()
{
    
    vector<int> elements={5,5,5,3,3,3,99,1,2,1001,11,12,4,51,1,3,6,2};
    cout<<"sorted array"<<endl;
    MergeSort(elements);
    for(auto v:elements)
    {
        std::cout << v <<endl;
    }
    cout<<endl;
    return 0;
}

