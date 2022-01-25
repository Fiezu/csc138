#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cstring>
#include <fstream>

struct info{
	char name[30];
	char no[15];
	char payment;
	char address[70];
	char bun;
	int quantity;
};

using namespace std;

void types();
void getData(info[], ofstream&);


int main()
{
	char answer;
	ofstream buns;
	
	info data[100];
	int count=0;
	
	do
	{
		cout<<"Welcome to Funbun system"<<endl;
		types();
		
		buns.open("Personal Data.txt");
		getData(data, buns);
		
		//receipt(data);
		cout<<"Do you want to enter another customer? (Y/N): ";
		cin>>answer;
		cout<<endl;
		
		count++;
	}
	while(answer=='Y' || answer=='y');
	
	cout<<"Total customer: "<<count<<endl;
	cout<<"Total payment received : RM";
	cout<<"The average of income per customer is :RM";
	
	
	
	buns.close();
	return 0;
}
void getData(info data[], ofstream& buns)
{
	char Name[30];
	int durian=0, redBean=0;
	
	for(int i=0; i<100; i++)
	{
		cout<<"Enter customer name: ";
		cin>>ws;
		cin.getline(data[i].name,30);
		
		cout<<"Enter phone number: ";
		cin>>ws;
		cin.getline(data[i].no,15);
		
		do
		{
			cout<<"Enter payment method (A-Cash On Delivery / B-Delivery): ";
			cin>>ws;
			cin>>data[i].payment;
			cout<<endl;
		}
		while((data[i].payment!='A' && data[i].payment!='a') && (data[i].payment!='B' && data[i].payment!='b'));
		
		data[i].quantity=0;
		char answer;
		int total_order=0;
		do
		{
			
			cout<<"Please enter your flavour (D-Durian / R-Red Bean): ";
			cin>>data[i].bun;
		
			cout<<"Please enter quantity (6-Half dozen / 12-Dozen): ";
			cin>>total_order;
		
			cout<<"Do you want to order more (Y/N)?: ";
			cin>>answer;
			
			data[i].quantity+=total_order;
			cout<<endl;
			
			if(data[i].bun=='D' || data[i].bun=='d')
			{
				durian+=total_order;
			}
			else if(data[i].bun=='R' || data[i].bun=='r')
			{
				redBean+=total_order;
			}
		}
		while(answer=='Y' || answer=='y');
		
		cout<<"Total durian buns: "<<durian<<endl;
		cout<<"Total red bean buns: "<<redBean<<endl;
		cout<<"Your total buns: "<<data[i].quantity<<endl<<endl;
		
		cout<<"Do you want to purchase more? (Y/N): ";
		cin>>answer;
		
		if(answer=='N' || answer=='n')
		{
			buns<<data[i].name<<endl<<data[i].no<<endl;
			if(data[i].payment=='A' || data[i].payment=='a')
			{
				buns<<"Payment Method: Cash On Delivery"<<endl;
				buns<<"1 Shopping Complex, First Floor, Jalan Kolam Air, Kampung Gubah, 85000 Segamat District, Johor, Malaysia";
			}
			else
			{
				buns<<"Payment Method: Delivery"<<endl;
				buns<<"Owner bank name: "<<Name<<endl;
			}
			break;
		}
			
	}
			
}

void types()
{
	cout<<"---------------------------------------------------"<<endl;
	cout<<"|   Flavour    |    Quantity    |    Price (RM)   |"<<endl;
	cout<<"---------------------------------------------------"<<endl;
	cout<<"|   Red Bean   |       6        |       5.00      |"<<endl;
	cout<<"|      (A)     |       12       |      10.00      |"<<endl;
	cout<<"---------------------------------------------------"<<endl;
	cout<<"|    Durian    |       6        |       6.00      |"<<endl;
	cout<<"|      (B)     |       12       |      12.00      |"<<endl;
	cout<<"---------------------------------------------------"<<endl;
}

/*void paymentMethod(info& data)
{
	if(data.payment=='A' || data.payment=='a')
	{
		cout<<"Meet at Segamat"<<endl;
		cout<<"1 Shopping Complex, First Floor, Jalan Kolam Air, Kampung Gubah, 85000 Segamat District, Johor, Malaysia"<<endl;
		cout<<"From 9.00a.m.-11.00a.m"<<endl;
		cout<<"For further information please contact 012-281 3154(Aqil)"<<endl<<endl;
	}
	else if(data.payment=='B' || data.payment=='b')
	{
		cout<<"Please enter your shipping address: "<<endl;
		cin>>ws;
		cin.getline(data.address,70);
		cout<<endl;
				
		cout<<"Account Name: Fiezu"<<endl;
		cout<<"Please bank in at 12-256-10-045316-0(Bank Islam)"<<endl;
		cout<<"Please type in your account name: ";
		cin>>ws;
		cin.getline(Name,30);
		cout<<endl;
	}
	else
	{
		cout<<"Wrong data entered!!\nPlease enter correctly."<<endl<<endl;
	}
	while((!data.payment=='A' || !data.payment=='a') || (!data.payment=='B' || !data.payment=='b'));
}*/
