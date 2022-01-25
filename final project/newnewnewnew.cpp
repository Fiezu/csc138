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
	double price;
	int tDurian;
	int tRedBean;
	char method[20];
	int date;
};

using namespace std;
                                                    // All of these are function declaration
void types();
void Data(info[][2], ofstream&, int&, int, int);
void paymentMethod(info[][2], int, int);
void highestLowest(info[][2], int, int);
void sorting(info[][2], int, int);
void search(info[][2], int, int);
void average(info[][2], int, int);


int main()
{
	char answer;
	ofstream buns;
	
	info data[100][2]={ };
	int  count=0, j, i=0, z=0;
	double Total=0.00;
	
	buns.open("Personal Data.txt");
	do
	{
		cout<<"Welcome to Funbun system"<<endl;
		types();                                                               //to display the type of buns as well as its price
		
		data[i][z].tDurian=0;
		data[i][z].tRedBean=0;
		
		cout<<"Enter month (1-Jan, 2-Feb): ";
		cin>>data[i][z].date;
		
		if(data[i][z].date==1)
		{
			Data(data, buns, j, i, z);                                               //to get data from user
		
			cout<<"Final price: RM"<<data[i][z].price<<endl;
			paymentMethod(data, i, z);                                               //to inform the user about payment method
			count++;
		
			do
			{
				cout<<"Do you want to enter another customer? (Y/N): ";
				cin>>answer;
			}		
			while((answer!='Y' && answer!='y') && (answer!='N' && answer!='n'));
		
			if(answer=='Y' || answer=='y')
			{
				i++;
			}
			cout<<endl;
		
		}
		
		if(data[i][z].date==2)
		{
			Data(data, buns, j, i, z);                                               //to get data from user
		
			cout<<"Final price: RM"<<data[i][z].price<<endl;
			paymentMethod(data, i, z);                                               //to inform the user about payment method
			count++;
		
			do
			{
				cout<<"Do you want to enter another customer? (Y/N): ";
				cin>>answer;
			}		
			while((answer!='Y' && answer!='y') && (answer!='N' && answer!='n'));
		
			if(answer=='Y' || answer=='y')
			{
				z++;
			}
			cout<<endl;
		
		}
	}
	while((answer=='Y' || answer=='y'));
	
	for(int x=0; x<=j; x++)
	{
		for(int z=0; z<2; z++)
		{
			Total=Total+data[x][z].price;
		}
	}
	
	cout<<"For staff purposes"<<endl;
	cout<<"---------------------------------------------------"<<endl;
	cout<<"Total customer : "<<count<<endl;
	cout<<setprecision(2)<<fixed;                                          //setprecision(2)<<fixed is to manipulate the output into 2 decimal places
	cout<<"Total payment received : RM"<<Total<<endl;
	//cout<<"The average of income per customer is :RM"<<Total/count<<endl;
	highestLowest(data, j,z); 
	sorting(data, j,z);
	average(data, j,z);
	search(data,j,z);  
	
	buns.close();
	getch();
	return 0;
}

void Data(info data[][2], ofstream& buns, int& j, int i, int z)                       // Function definition must be used to call the calling module
{
	int durian, redBean, tDurian=0, tRedBean=0; 
	char ans, method[20];
		
		data[i][z].price=0;
		

		
		cout<<"Enter customer name: ";
		cin>>ws;
		cin.getline(data[i][z].name,30);
		
		cout<<"Enter phone number: ";
		cin>>ws;
		cin.getline(data[i][z].no,15);
		
		do
		{
			cout<<"Enter payment method (A-Cash On Delivery / B-Delivery): ";
			cin>>ws;
			cin>>data[i][z].payment;
			cout<<endl;
		}
		while((data[i][z].payment!='A' && data[i][z].payment!='a') && (data[i][z].payment!='B' && data[i][z].payment!='b'));
		
		cout<<"If you do not want to buy any buns, please enter 0 and you have to enter either 6 or 12 only"<<endl;
		do
		{

			cout<<"Please enter quantity Durian bun (6-Half dozen / 12-Dozen): ";
			cin>>durian;
			
			if(durian==6)
			{
				data[i][z].price=data[i][z].price+6;
			}
			else if(durian==12)
			{
				data[i][z].price=data[i][z].price+12;
			}
			else
			{
				durian=0;
				data[i][z].price=data[i][z].price+0;
			}
			
			cout<<"Please enter quantity Red Bean bun (6-Half dozen / 12-Dozen): ";
			cin>>redBean;
			
			if(redBean==6)
			{
				data[i][z].price=data[i][z].price+5;
			}
			else if(redBean==12)
			{
				data[i][z].price=data[i][z].price+10;
			}
			else
			{
				redBean=0;
				data[i][z].price=data[i][z].price+0;
			}
			
			data[i][z].tDurian+=durian;
			data[i][z].tRedBean+=redBean;
	
			cout<<"Total durian buns: "<<data[i][z].tDurian<<endl;
			cout<<"Total red bean buns: "<<data[i][z].tRedBean<<endl;
			cout<<"Your total buns: "<<data[i][z].tDurian+data[i][z].tRedBean<<endl<<endl;
			
			do
			{
				cout<<"Do you want to order more (Y/N): ";
				cin>>ans;
				cout<<endl;
			}
			while((ans!='Y' && ans!='y') && (ans!='N' && ans!='n'));
		}
		while(ans=='Y' || ans=='y');
		
		if(data[i][z].payment=='A' || data[i][z].payment=='a')
		{
			strcpy(data[i][z].method, "Cash on Delivery");
		}
		else
		{
			strcpy(data[i][z].method, "Delivery");
		}
		
		buns<<data[i][z].name<<"* "<<data[i][z].no<<"* "<<data[i][z].tDurian<<" "<<data[i][z].tRedBean<<" "<<data[i][z].method<<endl;
		cout<<"--------------------------------------------------"<<endl;
		//cout<<setw(23)<<left<<"Month: "<<endl;
		cout<<setw(23)<<left<<"Name"<<":"<<data[i][z].name<<endl;
		cout<<setw(23)<<left<<"Phone no. "<<":"<<data[i][z].no<<endl;
		cout<<setw(23)<<left<<"Quantity Durian bun "<<":"<<data[i][z].tDurian<<endl;
		cout<<setw(23)<<left<<"Quatity Red Bean bun "<<":"<<data[i][z].tRedBean<<endl;
		cout<<setw(23)<<left<<"Payment Method "<<":"<<data[i][z].method<<endl;
		cout<<setprecision(2)<<fixed;
		cout<<setw(23)<<left<<"Price "<<":RM"<<data[i][z].price<<endl;
		cout<<"--------------------------------------------------"<<endl<<endl;
		cout<<"\n\tTHANK YOU FOR USING OUR SYSTEM"<<endl;
		
		j=i;
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

void paymentMethod(info data[][2], int i, int z)
{
	char Name[30], information;
	
	if(data[i][z].payment=='A' || data[i][z].payment=='a')
	{
		cout<<"Meet at Segamat"<<endl;
		cout<<"1 Shopping Complex, First Floor, Jalan Kolam Air, Kampung Gubah, 85000 Segamat District, Johor, Malaysia"<<endl;
		cout<<"From 9.00a.m.-11.00a.m"<<endl;
		cout<<"For further information please contact 012-281 3154(Aqil)"<<endl<<endl;
	}
	else
	{
		cout<<"Please bank in at 12-256-10-045316-0 (Bank Islam) - Hafiezudin Rosdi"<<endl;
		cout<<"Please type in your bank account name: ";
		cin>>ws;
		cin.getline(Name,30);
		cout<<endl;
		
		do
		{
			cout<<"Please enter your shipping address: "<<endl;
			cin>>ws;
			cin.getline(data[i][z].address,70);
			cout<<endl;
			
			cout<<"************************************************"<<endl;
			cout<<"Your name: "<<Name<<endl;
			cout<<"Please check and confirm your address: "<<data[i][z].address<<endl;
			cout<<"************************************************"<<endl;
			cout<<"Your information is correct (Y/N): ";
			cin>>information;
			cout<<endl;
		}
		while(information!='Y' && information!='y');		
	}
}

void highestLowest(info data[][2], int j, int z)
{
	int highestOrder=data[0][0].tDurian+data[0][0].tRedBean, highestSales=data[0][0].price;
	int lowestOrder=data[0][0].tDurian+data[0][0].tRedBean, lowestSales=data[0][0].price;
	
	for(int i=0; i<=j; i++)
	{
		for(int z=0; z<2; z++)
		{
			if(highestOrder<(data[i][z].tDurian+data[i][z].tRedBean))
			{
				highestOrder=data[i][z].tDurian+data[i][z].tRedBean;
			}
			
			if(highestSales<data[i][z].price)
			{
				highestSales=data[i][z].price;
			}
			
			if(lowestOrder>(data[i][z].tDurian+data[i][z].tRedBean))
			{
				lowestOrder=data[i][z].tDurian+data[i][z].tRedBean;
			}
		
			if(lowestSales>data[i][z].price)
			{
				lowestSales=data[i][z].price;
			}
		}
	}
	cout<<"\nHighest order is: "<<highestOrder<<" buns"<<"\nHighest sales is: RM"<<highestSales<<endl;
	cout<<"Lowest order is: "<<lowestOrder<<" buns"<<"\nLowest sales is: RM"<<lowestSales<<endl;
}

void sorting(info data[][2], int j, int z)
{
	int highestTdurian=data[0][0].tDurian, temp;
	int highestTRedBean=data[0][0].tRedBean, Temp;
	
	for(int i=0; i<j+1; i++)
	{
		for(int iteration=0; iteration<j+1; x++)
		{
			for(int z=0; z<2-iteration; z++)
			{
				if(data[x][z].tDurian<data[x+1][z].tDurian)
				{
					temp=data[x][z].tDurian;
					data[x][z].tDurian=data[x+1][z].tDurian;
					data[x+1][z].tDurian=temp;
				}
			
				if(data[x][z].tRedBean<data[x+1][z].tRedBean)
				{
					Temp=data[x][z].tRedBean;
					data[x][z].tRedBean=data[x+1][z].tRedBean;
					data[x+1][z].tRedBean=Temp;
				}
			}
			
		}
	}
	cout<<"\nHighest order to lowest order for Durian buns: "<<endl;
	for(int i=0; i<=j; i++)
	{
		for(int z=0; z<2; z++)
		{
			cout<<data[i][z].tDurian<<" ";
		}
	}
	cout<<endl<<endl;
	
	cout<<"Highest order to lowest order for Red Bean buns: "<<endl;
	for(int i=0; i<=j; i++)
	{
		for(int z=0; z<2; z++)
		{
			cout<<data[i][z].tRedBean<<" ";
		}
	}
	cout<<endl;
}

void search(info data[][2], int j, int z)
{
	char input[30],code; 
	ofstream update;
	update.open("Data searched.txt");
	ifstream bun;
	bun.open("Personal Data.txt");
	ofstream personal;
	personal.open("List customer data.txt");
	
	int i=0;
	while(!bun.eof() && (i<=j))
	{
		bun.getline(data[i][z].name, 30, '*');
		bun>>ws;
		bun.getline(data[i][z].no, 15, '*');
		bun>>data[i][z].tDurian>>data[i][z].tRedBean;
		bun>>ws;
		bun.getline(data[i][z].method, 20);
		
		personal<<setw(23)<<left<<"Name "<<":"<<data[i][z].name<<endl;
		personal<<setw(23)<<left<<"Phone no. "<<":"<<data[i][z].no<<endl;
		personal<<setw(23)<<left<<"Durian buns "<<":"<<data[i][z].tDurian<<endl;
		personal<<setw(23)<<left<<"Red Bean buns "<<":"<<data[i][z].tRedBean<<endl;
		personal<<setw(23)<<left<<"Method "<<":"<<data[i][z].method<<endl<<endl;
		
		i++;
	}
	
	do
	{	
		bool found = false;
		cout<<"\nSearching name : ";
		cin>>ws;
		cin.getline(input,30);
		int i=0;
		for(int i=0; i<=j; i++)
		{
			if (strcmp(data[i][z].name,input)==0)
			{
				found = true;
				cout<<"Data found"<<endl;
				
				update<<setw(23)<<left<<"Date: "<<data[i][z].date<<endl;
				update<<setw(23)<<left<<"Name "<<":"<<data[i][z].name<<endl<<setw(23)<<left<<"Phone no. "<<":"<<data[i][z].no<<endl;
				update<<setw(23)<<left<<"Durian buns "<<":"<<data[i][z].tDurian<<endl;
				update<<setw(23)<<left<<"Red Bean buns "<<":"<<data[i][z].tRedBean<<endl;
				update<<setw(23)<<left<<"Method "<<":"<<data[i][z].method<<endl<<endl;
				
				/*if(data[i]date==1)
				{
					//update<<"\t      January"<<endl;
					
				}
				else
				{
					//update<<"\t     February"<<endl;
					update<<setw(23)<<left<<"Date: "<<data[i].date<<endl;
					update<<setw(23)<<left<<"Name "<<":"<<data[i].name<<endl<<setw(23)<<left<<"Phone no. "<<":"<<data[i].no<<endl;
					update<<setw(23)<<left<<"Durian buns "<<":"<<data[i].tDurian<<endl;
					update<<setw(23)<<left<<"Red Bean buns "<<":"<<data[i].tRedBean<<endl;
					update<<setw(23)<<left<<"Method "<<":"<<data[i].method<<endl<<endl;
				}*/
				
				
			}
		}
		if (!found)
		cout << "The data is not exist!"<< endl;
		do
		{		
			cout<<"\nDo you want to continue serching (Y/N) : ";
			cin>>ws;
			cin>>code;
		}
		while((code!='Y' && code!='y') && (code!='N' && code!='n'));
		
		i++;
	}
	while(code=='Y'||code=='y');
	
	
		
	update.close();
	bun.close();
	personal.close();
}

void average(info data[][2], int j, int z)
{
	double month,average[12],totalaverage=0,total=0;
	int i=0;
	
	cout<<"Enter month (1-Jan, 2-Feb): ";
	cin>>data[i][z].date;
	
	for(int i=0;i<=j;i++)
	{
		for(int x=0; x<2; x++)
		{
			total=total+data[i][x].price;
		}
	
		if (data[i][z].date=1)
		{
			month=31;
		}	
		else if (data[i][z].date=2)
		{
			month=28;
		}
		average[i]=total/month;
		totalaverage+=average[i];
	}
	
	for(int y=0; y<z; y++)
	{
		cout<<"Average for "<<y+1<<" month : "<<average[y]<<endl;
	}
	cout<<"Total average : "<<totalaverage<<endl;
	
}
