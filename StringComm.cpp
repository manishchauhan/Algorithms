#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	//some comman string operation
	//all http://www.cplusplus.com/reference/string/string/erase/
	
	//assign one string to other
	
	//copy string from one place to other
	{
		cout<<1<<endl;
		string userName="manish chauhan";
		//do copy now userName and userNameCopy contain same values
		string userNameCopy=userName;
		cout<<"original "<<userName<<endl;
		cout<<"copy "<<userNameCopy<<endl;
		
	}	
	//move string so first string would be empty and value move from one string to other
	{
		cout<<2<<endl;
		string userName="manish chauhan";
		//userName move
		string userNameCopy=std::move(userName);
		cout<<"original "<<userName<<endl;
		cout<<"copy "<<userNameCopy<<endl;
	}
	//substr trim string
	{
		cout<<3<<endl;
		string fullName="manish chauhan";
		string firstName=fullName.substr(7,fullName.length());
		cout<<firstName<<endl;
		
		//another one
		{
			cout<<endl;
			string firstName="manishxxx";
			string secondName="chauhanxxx";
			string fullName;
			auto it1=firstName.length()-3;//remove last 3 spaces
			auto it2=secondName.length()-3;//remove last 3 spaces
			fullName=firstName.substr(0,it1)+" "+secondName.substr(0,it2);
			cout<<fullName<<endl;
		}
	}
	
	//
	{
		//find a string in another string
		cout<<endl;
		string big="gaming is so easy its not true";
		string small="gaming";
		size_t findIndex=big.find(small);
		if(findIndex!=string::npos)
		{
			cout<<"string found at - "<<findIndex<<endl;
		}else
		{
			cout<<"string not found"<<endl;
		}
		
		
		
		//find all string in other string and store result in a vector (index);
		vector<int> resultVector;
		string sameName="manish is manish chauhan manish";
		string search="manish";
		//find first string
		size_t  endIndex=sameName.length();
		size_t startIndex=sameName.find(search);
		if(startIndex!=string::npos)
		{
		  	resultVector.push_back(startIndex);
			while(startIndex<endIndex)
			{
			
				startIndex+=1;
				startIndex=sameName.find(search,startIndex);
				if(startIndex!=string::npos)
				{
					resultVector.push_back(startIndex);
				}
			}
		}else
		{
			cout<<"opps"<<endl;
		}
		for(auto index:resultVector)
		{
			cout<<"index---"<<index<<endl;
		}
	}
	
	//replace a part of a string
	{
		string password="123456";
		string replace="***";
		password.replace(2,replace.length(),replace);
		cout<<"your password is-->"<<password<<endl;
		//replace all * with A in a string
		{
			string whatsup="man*man*man*";
			string code="*";
			size_t end=whatsup.length();
			size_t start=whatsup.find(code);
			string replaceString="X";
			if(start!=string::npos)
			{
				whatsup.replace(start,1,replaceString);
				while(start<end)
				{
						
					start=whatsup.find(code,++start);
					if(start!=string::npos)
					{
					whatsup.replace(start,1,replaceString);

					}
				}
			}else
			{
				cout<<"some silly error"<<endl;
			}
			cout<<"final string is-->"<<whatsup<<endl;
		}
		
		//reverse a string 
		{
			string stringA="mam";
			string stringB;
			for(auto it=stringA.rbegin();it!=stringA.rend();it++)
			{
				stringB+=*it;
			}
			if(stringA==stringB)
			{
				cout<<"palindrome"<<endl;
			}else
			{
				cout<<"no palindrome"<<endl;
			}
		}
		//this is very impartant check two string is equal or not
		{
			string str1="xyz";
			string str2="xyza";
			int count=str1.compare(str2);
			if(count==0)
			{
				cout<<"equal"<<endl;
			}else if(count<0)
			{
				cout<<"second string is bigger"<<endl;
			}else if(count>0)
			{
				cout<<"first is bigger"<<endl;
			}
			//you can also do like
			/*
			  if(str1==str2)
			   {
		       	//something
			   }
			*/
		}
		//swap string with each other
		{
			string swapA="chauhan";
			string swapB="manish";
			swapA.swap(swapB);
			string fullName=swapA.append(" ").append(swapB);
			cout<<"full name is--"<<fullName<<endl;
		}
		//very important erase 
		{
			//earse last name from a string and move that string to firstname
			string fullName="manish chauhan";
			fullName.erase(fullName.find(" "),fullName.length());
			string firstName=std::move(fullName);
			cout<<"first name is->"<<firstName;
		}
		
	}
	return 0;
}
