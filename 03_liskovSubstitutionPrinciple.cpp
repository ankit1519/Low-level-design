/*

Liskov substitution Principle:
-> Subclass should extent capability of parent class but should not narrow it down.
-> means if class B inherits A then All the property of A should be own by B. There should not be any exception.
->example: suppose we create class bird with property-> eat(),sleep(),fly() and we crete a class Dog which inherits bird then it should throw exception in fly()    ohh wait what? flyyyy -> nomb.
So, This should not happen is goal of LSP.

*/

#include<bits/stdc++.h>
using namespace std;
class Bird{
	int name;
public:
	virtual void eat()=0;
	virtual void sleep()=0;
	virtual void fly()=0;
};
class Dog:public Bird{
public:
	void eat() override{
		cout<<"Dog eating\n";
	}
	void sleep() override{
		cout<<"Dog sleeping\n";
	}
	//our program willl give exception -not good
	void fly() override{
		throw runtime_error("Dog can't fly\n");
	}

};
class Parrot:public Bird{
public:
	void eat() override{
		cout<<"Parrot eating\n";
	}
	void sleep() override{
		cout<<"Parrot sleeping\n";
	}
	//our program willl give exception -not good
	void fly() override{
		cout<<"Parrot flying\n";
	}

};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	//Dog myDog;
	//myDog.fly();
	Parrot mithhu;
	mithhu.fly();
	mithhu.eat();
	mithhu.sleep();
	return 0;
}