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
	friend ostream& operator<<(ostream& os, const Invoice& invoice) {
        os << "Marker: " << invoice.marker.price << ", Quantity: " << invoice.qty;
        return os;
    }
};

class SaveInvoice{
	
public:
	Invoice invoice;

	virtual void save(Invoice invoice )=0;
};
class SaveToDb:public SaveInvoice{
public:
	SaveToDb(Invoice invoice){
		this->invoice=invoice;
	}
	void save(Invoice invoice) override{
		cout<<"Saved Invoice:"<<invoice<<"  into database"<<endl;
	}
};
class SaveToFile:public SaveInvoice{
public:
	void save(Invoice invoice) override{
		cout<<"Saved Invoice:  into Files"<<endl;
		
	}
};

/*class PrintInvoice{
	Invoice invoice;
public:
	PrintInvoice(Invoice invoice){
		this->invoice=invoice;
	}
	void print(){
		cout<<"Invoice Printed"<<endl;                 
	}
}; */
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	Marker camel("camel",2010,50);
	Invoice today(camel,10);
	SaveToDb saved(today);
	saved.save(today);
	return 0;
}