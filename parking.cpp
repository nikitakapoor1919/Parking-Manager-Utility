#include "vehicle.h"
#include<iostream>
using namespace std;
#include<conio.h>
#include<string>
#include<process.h>
#include<fstream>
#include <iomanip>
#include<ctime>


vehicle a;
int n;
char x;


void vehicle:: entry_time()
{
	time_t e = time(0);
	entry = ctime(&e);
	cout<<"\n\n\n\t\tThe entry time of the vehicle is: "<<entry;
}

void vehicle:: exit_time()
{
	time_t e = time(0);
	exit = ctime(&e);
	cout<<"\n\n\n\t\tThe exit time of the vehicle is: "<<exit;
}

void line()
    {
            for(int i=1;i<41;i++)
          cout<<"--";

     cout<<"\n";
   }
int vehicle:: input()
	{
	
		system("CLS");
		cout<<"\n\n\tEnter the type of vehicle (2_wheeler,4_wheeler_light,4_wheeler_heavy) : \n";
		cout<<"\t\t";
		cin>>type;
		string s1=a.type;
		if((s1.compare("2_wheeler"))==0||(s1.compare("4_wheeler_light"))==0||(s1.compare("4_wheeler_heavy"))==0)
		{
		cout<<"\n\n\tEnter the name of driver : ";
		cin>>dname;
		cout<<"\n\n\tEnter the vehicle no : ";
		cin>>vno;
		cout<<"\n\n\tEnter the no of hours of stay : ";
		cin>>count;
		cout<<"\n\n\tDo You Want to Park in CCTV location? Charges are double.(y/n) : ";
		cin>>cctv_location;
		if(count<=8)
   			{
   				cout<<"\n\n\tParking Available! You can park your vehicle. ";
   				cout<<"\n\n\t\tvehicle got parked!!";
   				return 1;
   			}
   			else
   				cout<<"\n\n\tSORRY!Too many hours of stay(more than 8 hours)!Parking not possible!!";
   		return 0;
	}
	else{
		cout<<"\n\n\t\t\tIncorrect type of the vehicle!";
		return 0;
	}
	}
	void two_wheeler:: cal_two()
	{
		if(a.cctv_location=='y')
		{
			cout<<"\n\n\n\t\tThe total expenses during parking  ";
	     	cout<<(a.count)<<" * "<<2*p<<" = "<<2*(a.count)*p<<" rupees";
		}
		else
		{
		  cout<<"\n\n\n\t\tThe total expenses during parking  ";
		  cout<<(a.count)<<" * "<<p<<" = "<<(a.count)*p<<" rupees";	
		}
	}

	void four_wheeler_light:: cal_fourL()
	{
		if(a.cctv_location=='y')
		{
			cout<<"\n\n\n\t\tThe total expenses during parking  ";
	     	cout<<(a.count)<<" * "<<2*price<<" = "<<2*(a.count)*price<<" rupees";
		}
		else
		{
		  cout<<"\n\n\n\t\tThe total expenses during parking  ";
		  cout<<(a.count)<<" * "<<price<<" = "<<(a.count)*price<<" rupees";	
		}
		
	}
	
	void four_wheeler_heavy:: cal_fourH()
	{
		if(a.cctv_location=='y')
		{
			cout<<"\n\n\n\t\tThe total expenses during parking  ";
	     	cout<<(a.count)<<" * "<<2*cost<<" = "<<2*(a.count)*cost<<" rupees";
		}
		else
		{
		  cout<<"\n\n\n\t\tThe total expenses during parking  ";
		  cout<<(a.count)<<" * "<<cost<<" = "<<(a.count)*cost<<" rupees";	
		}
		
	}	
	void vehicle:: output()
	{
		cout<<"\n\n\t\tThe Vehicle Name : "<<type<<endl;
		cout<<"\n\n\t\tThe Driver Name : "<<dname<<endl;
		cout<<"\n\n\t\tThe Vehicle No : "<<vno<<endl;
		cout<<"\n\n\t\tThe Hours Of Stay : " <<count;
		
	}
	
	void vehicle:: bill()
	{
		cout<<"\n";
		cout<<"\n\t\t\t\t\tBILL\n";
		line();
		a.output();
		cout<<"\n";
		line();
	}


void delete_record()
{
	int n;
	system("CLS");
	cout<<"\n\n\t\tEnter the Vehicle number you want to get depart : ";
	cin>>n;
	ifstream inFile;
    inFile.open("parking3.dat", ios::binary);
	ofstream outFile;
    outFile.open("temp.dat", ios::out | ios::binary);
    while(inFile.read((char*)&a, sizeof(a)))
    {
        if(a.vno!= n)
        {	
            outFile.write((char*)&a, sizeof(a));
            cout<<"\n\n\tNo Record Found\n";
            return;
        }
        else
        {
        	a.exit_time();
            cout<<"\n\n\t\t Parking Record Deleted";
		}
        
    }
    cout<<"\n\n\tNo Record Found\n";
    inFile.close();
    outFile.close();
    
    remove("parking3.dat");
    rename("temp.dat", "parking3.dat");
}

int main()
{   
	two_wheeler two_w;
	four_wheeler_light four_wl;
	four_wheeler_heavy four_wh;
	int login();
    login();
	int choice,vno1,d;
	while(1) {
	system("CLS");

     cout << "\n\n\t\t ====== PARKING MANAGER UTILITY ======";
     cout <<"\n\n                                          ";
     cout<<" \n\t\t\t======================";
     cout << "\n\n\t\t\t  1. Arrival of a Vehicle";
     cout << "\n\n\t\t\t  2. Total no of Vehicles Arrived";
     cout << "\n\n\t\t\t  3. Total parking charges of the Vehicle";
     cout << "\n\n\t\t\t  4. Departure of the Vehicle";
     cout << "\n\n\t\t\t  5. View Price Chart";
     cout << "\n\n\t\t\t  6. Exit Program";
     cout<<" \n\t\t\t======================";
     cout << "\n\n";
     cout << "\t\t\t Select Your Choice ::";
     cin>>choice;
     switch(choice)
     {
      case 1 :
        {		
        		char f;
        		cout<<"\n\n\t\t\t==Do You Want to continue==y/n";
        		cin>>f;
        		if(f=='y')
        		{
        		
				 ofstream f1("parking3.dat",ios::binary|ios::out|ios::app);
                int ch=a.input();
                if(ch!=0)
                {
                	a.entry_time();
                	f1.write((char*)&a,sizeof(a));
				}
                
        }
            	break;
        }
       case 2 :
           {
           	system("CLS");
  		   cout << "\n\n\t\t=== NO VEHICLE PARKED ===";
           cout << "\n";
           ifstream infile("parking3.dat",ios::binary|ios::in);
           int d=1;
           while (infile.read((char *)&a,sizeof (a)))
		   {
		system("CLS");
           cout << "\n";
           cout<<"\n\n\tThe Vehicle position in parking lot : "<<d;
           d++;
           a.output();
           cout<<"\n";
           cout<<"\n\n\n";
           system("PAUSE");
           cout<<endl;
       	   }
       
           break;
       	   }
       	case 4:	
		   {
		   
		   delete_record();
		   break;
	}
    	case 3:
		{
			int n;
			system("CLS");
	        cout<<"\n\n\t\tEnter the vehicle no for which you want to see the bill : ";
	        cin>>n;
	        
	        system("CLS");
		   
		   ifstream infile("parking3.dat",ios::binary|ios::in);
		   
		   
		   	
           while (infile.read((char *)&a,sizeof (a)))
		   {
		   	 
		   	 if(a.vno==n)
		   	 {			
		   	 
		   	 string s1=a.type;
             cout << "\n";
             if((s1.compare("2_wheeler"))==0)
             {
				a.bill();
			 	two_w.cal_two();
			 }
			 else if((s1.compare("4_wheeler_light"))==0)
			 {
			 	a.bill();
			 	four_wl.cal_fourL();
			 }
			 else if((s1.compare("4_wheeler_heavy"))==0)
			 {
			 	a.bill();
			    four_wh.cal_fourH();
			 }
			 else
			 cout<<"\n\n\t\t\tIncorrect type of the vehicle!";
			 cout<<"\n";
			 cout<<endl;
			 }
			 else
			 	cout<<"\n\n\t\t\tWrong vehicle no!";
			 }
       		break;
       	    
       	
       	    
   }
   	case 5:
	   {
	   	   system("CLS");
	   	   cout<<"\n\n\n";
           cout<<setw(50)<<"PRICE CHART\n\n";
           line();
           cout<<setw(30)<<"Vehicle Type"<<setw(21)<<"CCTV LOCATION"<<setw(23)<<"PRICE\n";
           line();
           cout<<setw(30)<<"2 Wheeler"<<setw(20)<<"Yes"<<setw(22)<<2*two_w.p<<"Rs\n";
           cout<<setw(30)<<"2 Wheeler"<<setw(20)<<"No"<<setw(22)<<two_w.p<<"Rs\n";
           cout<<setw(30)<<"4 Wheeler Light"<<setw(20)<<"Yes"<<setw(22)<<2*four_wl.price<<"Rs\n";
           cout<<setw(30)<<"4 Wheeler Light"<<setw(20)<<"No"<<setw(22)<<four_wl.price<<"Rs\n";
           cout<<setw(30)<<"4 Wheeler Heavy"<<setw(20)<<"Yes"<<setw(22)<<2*four_wh.cost<<"Rs\n";  
           cout<<setw(30)<<"4 Wheeler Heavy"<<setw(20)<<"No"<<setw(22)<<four_wh.cost<<"Rs\n";
           line();
           break;
	   }	
   		case 6: 
		   {
		   	system("CLS");
		   	cout<<"\n\n\n\t\t\tTHANK YOU\n";
		   exit(0);
   			break;
   		}
   		default : 
		   {
		   cout<<"\n\n\t\t Invalid input";
			cout<<"\n\n\t\tPress Enter to continue";
			 
   	
   	}
   }
   
getch();
}}

int login(){
   string pass ="";
   char ch;
   cout <<"\n\n\n\n\n\n\n\t\t\tParking Manager Utility Login";
   cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";
   ch = _getch();
   while(ch != 13){
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "pass"){
      cout << "\n\n\n\n\t\t\t Access Granted! Welcome To Our System \n\n\n";
      system("PAUSE");
      
   }else{
      cout << "\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
      system("PAUSE");
      system("CLS");
      login();
   }
}
