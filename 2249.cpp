#include <iostream>//cout
#include <iomanip>
#include <cmath>//sqrt
#include<string>
#include <limits>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cctype>//isalpha,isdigit
using namespace std;
bool have7(int a){
	vector<int>digit(7);
	bool haves=0;
	for(int i=0;i<7;i++){
		int num=pow(10,i);
		digit[i]=(a/num)%10;
		//cout<<digit[i]<<" ";
		if(digit[i]==7) haves=1;
	}
	return haves;//统一为一个变量
}
int main()
{
	int a,b,c=0;
	cin>>a>>b;
	vector<int>lucky;
	for(int i=7;i<=b;i++){
		if(have7(i)) lucky.push_back(i);
	}
	int sum=lucky.size();
	vector<bool> isapprox(b,false);
	for(int j=0;j<sum;j++){
		for(int i=1;i<=b/lucky[j];i++){
			int c=lucky[j]*i;
			isapprox[c]=1;
		}
	}
	for(int i=a;i<=b;i++){

		if(!have7(i)&&!isapprox[i]) c++; 
	}
	cout<<c;
	return 0;
}

