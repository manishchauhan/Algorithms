/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
/*
 interSection of two array and return a new vector
*/ 
vector<int> interSection(vector<int> &vectorA,vector<int> &vectorB)
{
     int i=0;
     int j=0;
     vector<int> result;
     while(i<vectorA.size() && j<vectorB.size())
     {
         if(vectorA.at(i)==vectorB.at(j))
         {
             result.push_back(vectorA.at(i));
              i++;
              j++;
         }else if(vectorA.at(i)<vectorB.at(j))
         {
              i++;
         }else if(vectorA.at(i)>vectorB.at(j))
         {
             j++;
         }
        
     }
     return result;
};
/*
    union of two Array and remove the duplicated from both vector and return a new vector
*/
vector<int> unionTwo(vector<int> &vectorA,vector<int> &vectorB)
{
     int i=0;
     int j=0;
     vector<int> result;
     while(i<vectorA.size() && j<vectorB.size())
     {
        if(vectorA.at(i)<vectorB.at(j))
         {
              result.push_back(vectorA.at(i));
              i++;
             
             
         }else if (vectorA.at(i)>vectorB.at(j))
         {
               result.push_back(vectorB.at(j));
             
             j++;
            
         } else
         {
                     result.push_back(vectorA.at(j));
             i++;
             j++;
      
         }
        
     }
     while(i<vectorA.size())
     {
         result.push_back(vectorA.at(i));
         i++;
     }
     while(j<vectorB.size())
     {
         result.push_back(vectorB.at(j));
         j++;
     }
    
    set<int> s(result.begin(), result.end()); 
    result.clear();
    result.assign(s.begin(),s.end());
     return result;
};
int main()
{
    vector<int> vectorA= {1,5,2,2};
    vector<int> vectorB= {2,4};
    vector<int> R=interSection(vectorA,vectorB);
    vector<int> R1=unionTwo(vectorA,vectorB);
    
    
    
    for(auto r1:R1)
    {
        std::cout << r1 ;
    }
    return 0;
}

