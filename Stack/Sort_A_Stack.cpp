#include <bits/stdc++.h> 
using namespace std;

void insertInSort(stack<int> &s,int element){
	if(s.empty()|| (!s.empty()&&s.top()<element)){
		s.push(element);
		return;
	}
	//element ko bahar rakhna
	int num=s.top();
	s.pop();
	//recursive call;
	insertInSort(s, element);
	//bahar jo elemnet nikale hai usko andar daalna wapas
	s.push(num);
}

void sortStack(stack<int> &stack){
	//base case
	if(stack.empty()){
		return;
	}
   
//element ko bahar nikal ke rakh diye hai
int num=stack.top();
stack.pop();

//recursive call
sortStack(stack);

//insert the bahar rakha element in sorted fashion
 insertInSort(stack,num);
}