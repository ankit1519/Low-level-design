/*
 Single Responsibility Principle:- 
-> A class should have only one reason to change.
-> If a class has multiple responsibilities, and one of those responsibilities changes, 
it may affect the other responsibilities and introduce unexpected result.
-> The goal is to keep classes focused and modular, making them easier to understand, modify, and maintain. 
*/

#include<bits/stdc++.h>
using namespace std;
class Marker{
	string name;
	int year;
	
public:
	int price;
	Marker(string name, int year, int price){
		this->name=name;
		this->year=year;
		this->price=price;
	}
	Marker(){

	}

};

class Invoice{
	Marker marker;
	int qty;
public:
	Invoice(Marker marker, int qty){
		this->marker=marker;
		this->qty=qty;
	}
	Invoice(){}
	int totalCalc(){
		return qty*marker.price;      // reason to change -> we can change calculation algorithm
	}
	/*
	void printInvoice(){
		cout<<"Invoice Printed"<<endl;         //reason to change -> we can update print criteria
	}
	void saveToDB(){
		cout<<"Saved to DB"<<endl;                 //reason to change -> we can save to file
	}*/
};

class Save{
	Invoice invoice;
public:
	Save(Invoice invoice){
		this->invoice=invoice;
	}
	void saveToDB(){
		cout<<"Saved to DB"<<endl;                 
	}
};
class PrintInvoice{
	Invoice invoice;
public:
	PrintInvoice(Invoice invoice){
		this->invoice=invoice;
	}
	void print(){
		cout<<"Invoice Printed"<<endl;                 
	}
}; 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	Marker camel("camel",2010,50);
	Invoice today(camel,10);
	cout<<today.totalCalc()<<endl;
	Save saveI(today);
	saveI.saveToDB();

	PrintInvoice printI(today);
	printI.print();
	return 0;
}