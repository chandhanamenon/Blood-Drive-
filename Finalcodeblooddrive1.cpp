#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
using namespace std;
class insertmenu                                                
{
    public:
    char name[ 25 ];
    int age;
    char address[30];
    char phno[20];
    insertmenu();
    char umtid[4];
    char bg[4];
    void insertdonor();
    void showdonor();
};
class hospital
{
	public:	
	void forhospital();
	void display();
};
class patients
{
	public:
	void showpatients()
		{
			cout<<"NAME"<<"\t"<<"DATE OF WITHDRAWAL"<<"\t"<<"BLOOD GROUP"<<"\t"<<"GENDER"<<"\n";
			cout<<"Kim"<<"\t"<<"01/12/18"<<"\t\t"<<"A+"<<"\t\t"<<"Male"<<"\n";
			cout<<"Tim"<<"\t"<<"02/12/18"<<"\t\t"<<"O+"<<"\t\t"<<"Female"<<"\n";
			cout<<"Rim"<<"\t"<<"03/12/18"<<"\t\t"<<"A+"<<"\t\t"<<"Male"<<"\n";
			cout<<"Bim"<<"\t"<<"04/12/18"<<"\t\t"<<"A-"<<"\t\t"<<"Female"<<"\n";
			cout<<"Wim"<<"\t"<<"05/12/18"<<"\t\t"<<"AB-"<<"\t\t"<<"Male"<<"\n";
			cout<<"Jim"<<"\t"<<"06/12/18"<<"\t\t"<<"A+"<<"\t\t"<<"Female"<<"\n";
			cout<<"Nim"<<"\t"<<"07/12/18"<<"\t\t"<<"O+"<<"\t\t"<<"Male"<<"\n";
		}
};
insertmenu :: insertmenu()
{
     strcpy (umtid ,"Nill");
     strcpy (name ,"Nill");
     strcpy (bg ,"Nill");
     strcpy (address ,"Nill");
     strcpy (phno ,"Nill");
}
void insertmenu :: insertdonor()
{
    
    cout<<"\n\n ___________________________________\n";
    cout<<"  Donor Directory: Insert Menu\n";
    cout<<" _____________________________________\n";
    cin.ignore();
    cout<<"\n Enter name: ";
    gets (name);
    fflush(stdin);
    cout<<"\n Enter ID : ";
    gets(umtid);
    fflush(stdin);
    cout<<"\n Enter your age: ";
    cin>>age;
    fflush(stdin);
    cout<<"\n Enter Blood Group :";
    gets(bg);
    fflush(stdin);

    fflush(stdin);
    cout<<"\n Enter your Locality :";
    gets( address);
    fflush(stdin);
    cout<<"\n Enter Phone number: ";
    gets( phno);
    fflush(stdin);
    cout<<"\n\n Record Save Successfully ";
}
void insertmenu ::  showdonor()
{

    cout<<"\n ID: "<<umtid;
    cout<<"\n Donor Name : "<<name;
    cout<<"\n Age : "<<age;
    cout<<"\n Blood group : "<< bg;
    cout<<"\n Locality : "<<address;
    cout<<"\n Phone Number : "<<phno<<endl<<endl;

}

/* Function Declaration For Handling File */
class donor:public insertmenu
{
public:
void write_donor();
void display_all();
void display_hospital();
void display_patients();
void search_record( char *);
void delete_record(char *);
void update_record(char *);
};
/* Blood Donor project */

int main()
{
int a,b;
    char ch[10];
    cout<<"________________________________________________________________________________________________________________________";
    cout<<" \t\t\t\t\t\t\t BLOOD DRIVE\t\n";
    cout<<"________________________________________________________________________________________________________________________";
    cout<<"\n\n\t\t\t\t\t*******WELCOME TO BLOOD DRIVE PORTAL*******\n\n";
    cout<<"1. New Blood Donor Entry"<<endl<<endl;
    cout<<"2. Hospital Records "<<endl<<endl;
    cout<<"3. Receivers Directory"<<endl<<endl;
    cout<<"Select your option (1-3): ";cin>>b;
    cout<<endl<<endl;
    donor dn;
    hospital h1;
    switch (b)
	    {
			case 1:
			while(1)
							{
				  cout<<"________________________________________________________________________________________________________________________";				
				  cout<<" \t\t\t\t\t\t\t BLOOD BANK DIRECTORY \t\n";
				  cout<<"________________________________________________________________________________________________________________________";
				  cout<<"\t\t\t MAIN MENU \n\n";
				  cout<<"1. Insert a New Donor   "<<endl<<endl;
				  cout<<"2. Update an existing donor"<<endl<<endl;
				  cout<<"3. Delete a Record of Donor (Using ID) "<<endl<<endl;
				  cout<<"4. Search a Donor (Using BLOOD GROUP) "<<endl<<endl;
				  cout<<"5. Display All  Existing Donor  "<<endl<<endl;
				  cout<<"6. Press 6 for Exit  "<<endl<<endl;
				  cout<<"Select your option (1-6): ";cin>>a;
				  cout<<endl<<endl;

				  switch (a)
				{
				   case 1:
				     dn.write_donor();
				     break;
				   case 2:
				    cout<< "Enter ID of Donor : ";cin>>ch;
				     dn.update_record( ch);
				     break;
				   case 3:
				     cout<< "Enter ID of Donor : ";cin>>ch;
				     dn.delete_record(ch);
				     break;
				   case 4:
				     cout<< " Enter the Blood group : ";cin>>ch;
				     dn.search_record(ch);
				     break;
				   case 5:
				     dn.display_all();
				     break;
				   case 6:
				     cout<<endl <<endl;
				   cout<<"\t\t<<<<Thank You For Using This BLOOD DRIVE >>>> \n\n\n"<<endl;
				     return 0;
				     default:
				   cout<<" Please Enter Value Form 1 to 5 "<<endl<<endl;
				}
			      cin.ignore();
			    }


 case 2:
 	   cout<<"________________________________________________________________________________________________________________________";
	   cout<< "\t\t\t\t\t\t\tHOSPITAL DIRECTORY\n";
	   cout<<"________________________________________________________________________________________________________________________";

	  h1.forhospital();
	     break;
     case 3:
     	
    cout<<"________________________________________________________________________________________________________________________";
	cout<<"\t\t\t\t\t\t\tRECEIVERS DIRECTORY\n";
	cout<<"________________________________________________________________________________________________________________________";

	dn.display_patients();

     case 6:
	 cout<<endl <<endl;
	 cout<<"\t\t<<<<Thank You For using BLOOD DRIVE >>>> \n\n\n"<<endl;
	return 0;
     default:
	cout<<" Please Enter Value Form 1 to 3"<<endl<<endl;
	//cin.ignore();

     }

	   return 0;
	    }




	// Function defination for Insert a New Donor

void donor::write_donor()
{
insertmenu ac;
ofstream fout;
fout.open("file1.txt",ios::binary | ios::app);
ac.insertdonor();
fout.write ((char*) (&ac), sizeof(insertmenu));
fout.close();
}


//Function defination for Display All Donors Accounts

void donor::display_all()
{
  insertmenu ac;
    ifstream fin;
    fin.open ("file1.txt", ios::in | ios :: binary);
    if (!fin)
{
    cout<<"File does not exist..\n";
  return;
  }
else{

   fin.read((char*) (&ac), sizeof(insertmenu));
   while (!fin.eof())
   {
   ac.showdonor();
   fin.read((char*) (&ac), sizeof(insertmenu));
   }

fin.close();

}
}

//  Function Defination for Search of Donor Record

void donor::search_record(char *t)
{
    {
	insertmenu ac;


    int counter=0;
    ifstream fin;
    fin.open("file1.txt", ios :: in | ios :: binary );
    if (!fin)
    {
	cout<<" File is not Found ";
    }
    else
    {
	fin.read((char*) (&ac) , sizeof (insertmenu) );

 while(!fin.eof() ){

	 if ( ! strcmp( t, ac.bg ) )
	    {
		ac.showdonor();
	       counter++;
	    }

	    fin.read((char*) (&ac) , sizeof (insertmenu));
	    }
    fin.close();

	    if (counter==0)
	    {
		cout<<"\n\nOpsss......Record is not Found."<<endl<<endl;
	    }

    }
}


}

// Function Defination For Delete a Donor Account

void donor::delete_record( char * t)
{
    insertmenu ac;
    ifstream fin;
    ofstream fout;
     fin.open("file1.txt", ios:: in | ios:: binary);
if (!fin)
{ cout<<"File doesnt find";}
else
{
   fout.open("temp.txt", ios:: out | ios:: binary);
   fin.read((char*) (&ac), sizeof(insertmenu));
while (! fin.eof())
    {
       if (strcmp(ac.umtid,t))
       {
	fout.write((char*)(&ac), sizeof(insertmenu));
       }
   fin.read((char*) (&ac), sizeof(insertmenu));
}
fin.close();
fout.close();
remove("file1.txt");
rename("temp.txt","file1.txt");
cout<<" \n\n\t\tSuccessfully Deleted\n\n";
}

}

// Function Defination For  Update A Donor

void donor::update_record( char * t)
{
    insertmenu ac;
    fstream obj;
    obj.open("file1.txt", ios :: ate | ios :: in | ios :: out | ios :: binary  );
    obj.seekg(0);
    obj.read((char *) (&ac), sizeof(insertmenu));
    while (! obj.eof())
    {
	if ( ! strcmp(t , ac.umtid))
	    {
		cout<<"\t\t\n\n <<Enter New Record>> \n\n ";
		ac.insertdonor();
	   obj.seekp(obj.tellp()-sizeof(insertmenu));
	   obj.write( (char*)(&ac),sizeof(insertmenu));
	    }
	    obj.read((char *) (&ac), sizeof(insertmenu));
    }
}
// Function Defination For displaying hospitals//
//void donor::display_hospital()
//{
//	hospital obj;
//	ifstream fp1;
//	fp1.open("hospital.txt",ios::binary);
//	while(fp1.read((char*)&obj,sizeof(obj)));
//	{
//		obj.showhospital();
//		fp1.close();
//	}
//	}

//function defination for displaying patients//
void donor::display_patients()
{
	patients obj;
	ifstream fp2;
	fp2.open("patients.txt",ios::binary);
	while(fp2.read((char*)&obj,sizeof(obj)));
	{
		obj.showpatients();
		fp2.close();
	}
}

void hospital::forhospital()
{
int n;
            
            cout<<endl;
            cout<<"NAME"<<"\t\t\t\t\t"<<"CONTACT NO."<<"\t\t\t"<<"EMAIL ID"<<"\n";
			cout<<"1.St. Joseph’s General Hospital"<<"\t\t"<<"9845323423"<<"\t\t\t"<<"stjh_gnt@yahoo.com"<<endl;
			cout<<"2.Apollo Hospital "<<"\t\t\t"<<"9534534537"<<"\t\t\t"<<"apollo.hyd@gnhyd.global.net.in"<<endl;
			cout<<"3.Yashoda Hospital "<<"\t\t\t"<<"9786786786"<<"\t\t\t"<<"sreebhushanraju@hotmail.com"<<endl;
			cout<<"4.Nimms Hospital "<<"\t\t\t\t"<<"9783242356"<<"\t\t\t"<<"somajiguda@yashodahospitals.com"<<endl;
			cout<<"5.Vijaya Health Care "<<"\t\t\t"<<"9782345456"<<"\t\t\t"<<"vhc@yahoo.com"<<endl;
			cout<<"6.Down Town Hospital "<<"\t\t\t"<<"9745677566"<<"\t\t\t"<<"downtown@gmail.com"<<endl;
			cout<<"7.Inscol Hospital  "<<"\t\t\t"<<"9786345666"<<"\t\t\t"<<"contact@inscol.com"<<endl;    
			cout<<endl;
			cout<<endl<<"enter the hospital that you want to approach:";
cin>>n;
hospital h1;
switch(n)
{
	case 1:
	cout<<"Welcome to our blood bank"<<endl;
	h1.display();
	break;
	case 2:
	cout<<"Welcome to our blood bank"<<endl;
	h1.display();
	break;
	case 3:
	cout<<"Welcome to our blood bank"<<endl;
	h1.display();
	break;
	case 4:
	cout<<"Welcome to our blood bank"<<endl;
	h1.display();
	break;
	case 5:
	cout<<"Welcome to our blood bank"<<endl;
	h1.display();
	break;
	case 6:
	cout<<"Welcome to our blood bank"<<endl;
	h1.display();
	break;
	case 7:
	cout<<"Welcome to our blood bank"<<endl;
	h1.display();
	break;	
}
}
void hospital::display()
{
	cout<<"NAME"<<"\t"<<"BLOOD GROUP"<<"\t"<<"GENDER"<<"\t"<<"CONTACT NO."<<"\n";
			cout<<"Kim"<<"\t"<<"A+"<<"\t\t"<<"Male"<<"\t"<<"1234512345"<<"\n";
			cout<<"Tim"<<"\t"<<"O+"<<"\t\t"<<"Female"<<"\t"<<"1234512345"<<"\n";
			cout<<"Rim"<<"\t"<<"A+"<<"\t\t"<<"Male"<<"\t"<<"1234512345"<<"\n";
			cout<<"Bim"<<"\t"<<"A-"<<"\t\t"<<"Female"<<"\t"<<"1234512345"<<"\n";
			cout<<"Wim"<<"\t"<<"AB-"<<"\t\t"<<"Male"<<"\t"<<"1234512345"<<"\n";
			cout<<"Jim"<<"\t"<<"A+"<<"\t\t"<<"Female"<<"\t"<<"1234512345"<<"\n";
			cout<<"Nim"<<"\t"<<"O+"<<"\t\t"<<"Male"<<"\t"<<"1234512345"<<"\n";

}




