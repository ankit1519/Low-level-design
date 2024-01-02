/*

Interface segmented principle:
-> Interface should be such, that client should not implement unnecessary functions that they do not need.
-> We should segment abstract class into such small pieces so that client should not implement unnecessary functions.
-> class should be modular.
*/


#include<bits/stdc++.h>
using namespace std;
/*class RestroWork{
public:
	virtual void serveCustomer()=0;
	virtual void cookFood()=0;
	virtual void washDish()=0;
};
class Waiter:public RestroWork{
public:
	void serveCustomer() override{
		cout<<"OK, I'll serve\n";
	}
	void cookFood() override{
		cout<<"That's not my job\n";            // should'nt be include
	}
	void washDish(){
		cout<<"I can't do\n";
	}
};*/
class WaiterInterface{
public:
	virtual void serve()=0;
	virtual void takeOrder()=0;
};
class ChefInterface{
public:
	virtual void cookFood()=0;
	virtual void decideMenu()=0;
};
class Waiter: public WaiterInterface{
public:
	void serve(){
		cout<<"Food served"<<endl;
	}
	void takeOrder(){
		cout<<"Order taken"<<endl;
	}
};
class Chef: public ChefInterface{
public:
	void cookFood(){
		cout<<"Food cooked"<<endl;
	}
	void decideMenu(){
		cout<<"Menu decided"<<endl;
	}
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	Waiter Ramesh;
	Ramesh.serve();
	Ramesh.takeOrder();
	
	return 0;
}