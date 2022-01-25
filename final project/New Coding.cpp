#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cstring>
#include <fstream>

struct info{
	char name[30];
	char no[15];
	char payment;
	char address[70];;
	int durian;
	int redBean;
	int total;
};

using namespace std;

void types();
void getData(info[], ofstream&, int&, int, int&);


int main()
{
	char answer;
	ofstream buns;
	
	info data[]={ };
	int count=0, durian, redBean, total=0, j, i=0, finalTotal=0;
	
	do
	{
		cout<<"Welcome to Funbun system"<<endl;
		types();
		
		buns.open("Personal Data.txt");
		getData(data, buns, j, i, total);
		//price(data, total, j);
		
		cout<<"Final price: RM"<<total<<endl;
		cout<<"Do you want to enter another customer? (Y/N): ";
		cin>>answer;
		count++;
		if(answer=='Y' || answer=='y')
			i++;
			
		finalTotal+=total;
	}
	while(answer=='Y' || answer=='y');
	
	cout<<"Total customer: "<<count<<endl;
	cout<<"Total payment received : RM"<<finalTotal<<endl;
	cout<<"The average of income per customer is :RM"<<finalTotal/count<<endl;
	
	
	
	buns.close();
	return 0;
}
void getData(info data[], ofstream& buns, int& j, int i, int& total)
{
	int quantity, durian, redBean;
	char ans;
	
		int tDurian=0, tRedBean=0;
		data[i].durian=0;
		data[i].redBean=0;
		
		
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
		
		do
		{
			cout<<"Please enter quantity Durian bun (6-Half dozen / 12-Dozen): ";
			cin>>durian;
			
			if(durian==6)
			{
				data[i].durian=data[i].durian+6;
			}
			else if(durian==12)
			{
				data[i].durian=data[i].durian+12;
			}
			else
			{
				data[i].durian=data[i].durian+0;
			}
			
			cout<<"Please enter quantity Red Bean bun (6-Half dozen / 12-Dozen): ";
			cin>>redBean;
			
			if(redBean==6)
			{
				data[i].redBean=data[i].redBean+5;
			}
			else if(redBean==12)
			{
				data[i].redBean=data[i].redBean+10;
			}
			else
			{
				data[i].redBean=data[i].redBean+0;
			}
			
			tDurian+=durian;
			tRedBean+=redBean;
	
			quantity=tDurian+tRedBean;
			cout<<"Total durian buns: "<<tDurian<<endl;
			cout<<"Total red bean buns: "<<tRedBean<<endl;
			cout<<"Your total buns: "<<quantity<<endl<<endl;
			
			cout<<"Do you want to order more (Y/N): ";
			cin>>ans;
			cout<<endl;
		}
		while(ans=='Y' || ans=='y');
		
		total=data[i].redBean+data[i].durian;
		cout<<"--------------------------------------------------"<<endl;
		cout<<"Name : "<<data[i].name<<endl;
		cout<<"Phone no. :"<<data[i].no<<endl;
		cout<<"Quantity Durian bun: "<<tDurian<<endl;
		cout<<"Quatity Red Bean bun: "<<tRedBean<<endl;
		cout<<"Payment Method: "<<data[i].payment<<endl;
		cout<<"Price: RM"<<total<<endl;
		cout<<"--------------------------------------------------"<<endl<<endl;
		
		j=i;
	
	/*for(int i=0; i<=j; i++)
	{
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
		}
	}*/		
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

/*void price(info data[], int j)
{
	for(int i=0; i<=j; i++)
	{
		if(data[i].durian==6)
		{
			priceD=data[i].durian*6;
		}
		else
		{
			priceD=data[i].durian*12;
		}
		if(data[i].redBean==6)
		{
			priceR=data[i].redBean*5;
		}
		else
		{
			priceR=data[i].redBean*10;
		}
		data[i].total=priceD+priceR;
	}
}



void paymentMethod(info& data)
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
