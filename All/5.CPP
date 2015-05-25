#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<fstream.h>
#include<iomanip.h>

class record{
	public: char age[5];
		char usn[20];
		char name[20];
		char sem[2];
		char branch[5];
	    }rec[20];
char st_no[5];
int no;
void retrieve_details()
{
	fstream file2;
	 char age[5];
	 char usn[20];
	 char name[20];
	 char sem[2];
	 char branch[5];
	 char ind[5];
 file2.open("record.txt",ios::in);
 for(int i=0;i<no;i++)
 {
	file2.getline(ind,5,'|');
	file2.getline(usn,20,'|');
	file2.getline(name,20,'|');
	file2.getline(age,5,'|');
	file2.getline(sem,5,'|');
	file2.getline(branch,5,'|');
	if(strcmp(ind,st_no)==0)
	{
		cout<<"\n\t"<<"Student Details\n";
		cout<<"\nUSN\tNAME\tAGE\tSEM\tBRANCH\n";
		cout<<"\t\n"<<usn<<"\t"<<name<<"\t"<<age<<"\t"<<sem<<"\t"<<branch<<"\n";
	}
 }
 file2.close();
 }
 void delete_record(char usno[])
 {
	int i;
	fstream file1,file2;
	 char age[5];
	 char usn[20];
	 char name[20];
	 char sem[2];
	 char branch[5];
	 char ind[5];

	  file2.open("record.txt",ios::in);
 for(i=0;i<no;i++)
 {
	file2.getline(ind,5,'|');
	file2.getline(usn,20,'|');
	file2.getline(name,20,'|');
	file2.getline(age,5,'|');
	file2.getline(sem,5,'|');
	file2.getline(branch,5,'|');

	strcpy(rec[i].usn,usn);
	strcpy(rec[i].name,name);
	strcpy(rec[i].age,age);
	strcpy(rec[i].sem,sem);
	strcpy(rec[i].branch,branch);
 }
 int flag=-1;
 for(i=0;i<no;i++){
	if(strcmp(rec[i].usn,usno)==0)
	 { flag=i;}
 }
 if(flag==-1)
 {
	cout<<"Error";
	return;
 }
 if(flag==(no-1))
 {
	no--;
	cout<<"Record Deleted";
	return;
 }
 for(i=flag;i<no;i++)
 {
	rec[i]=rec[i+1];
 }
 no--;
 cout<<"Record deleted";
 file2.close();
 file1.open("index.txt",ios::out);
 file2.open("record.txt",ios::out);
 for(i=0;i<no;i++)
 {
	file1<<rec[i].usn<<"|"<<i<<"\n";
	file2<<i<<"|"<<rec[i].usn<<"|"<<rec[i].name<<"|"<<rec[i].age<<"|"<<rec[i].sem<<"|"<<rec[i].branch<<"\n";
 }
 file1.close();
 file2.close();
 return;
 }
 int main()
 {
 int choice;
 char rt_usn[20];
 char st_usn[20];
 fstream file1,file2;
 char age[5];
 char usn[20];
 char name[20];
 char sem[2];
 char branch[5];
 char ind[5];
 int i,flag,flag1;
 clrscr();
 file1.open("index.txt",ios::out);
 file2.open("record.txt",ios::out);
 if(!file1 || !file2)
 {
	cout<<"file creation error";
	exit(0);
 }
 for(;;)
 {
	cout<<"\nEnter the choice:\n\n";
	cout<<"1: Add Record\n";
	cout<<"2: Search record\n";
	cout<<"3: Delete record\n";
	cout<<"4: Displat record";
	cout<<"5: exit\n";
	cin>>choice;
	switch(choice)
	{

	 case 1: cout<<"Enter the number of student:";
		 cin>>no;
		 cout<<"Enter the details\n";
		 for(i=0;i<no;i++)
		 {
			cout<<"\n Name:";
			cin>>rec[i].name;
			cout<<"\n USN:";
			cin>>rec[i].usn;
			cout<<"\n Age:";
			cin>>rec[i].age;
			cout<<"\n SEM:";
			cin>>rec[i].sem;
			cout<<"\n Branch:";
			cin>>rec[i].branch;
		       file1<<rec[i].usn<<"|"<<i<<"\n";
		       file2<<i<<"|"<<rec[i].usn<<"|"<<rec[i].name<<"|"<<rec[i].age<<"|"<<rec[i].sem<<"|"<<rec[i].branch<<"\n";
		 }
		 file1.close();
		 file2.close();
		 break;
	  case 2: cout<<"\n Enter the usn of student record to be searched";
		  cin>>st_usn;
		  file1.open("index.txt",ios::in);
		  if(!file1)
		  {
			cout<<"Error";
			exit(0);
		  }
		  flag1=0;
		  for(i=0;i<no;i++)
		  {
			file1.getline(rt_usn,20,'|');
			file1.getline(st_usn,4,'\n');
			if(strcmp(st_usn,rt_usn)==0)
			{
			  retrieve_details();
			  flag1=1;
			}
		  }
		  if(!flag1)
		  {
			cout<<"\nrecord search failed\n";
		  }
		  file1.close();
		  break;
	   case  3: cout<<"\n Enter the usn of student record to be deleted\n";
		    cin>>st_usn;
		    file1.open("index.txt",ios::in);
		    if(!file1)
		    {
			cout<<"error!";
			exit(0);
		    }
		    flag=0;
		    for(i=0;i<no;i++)
			 {
			file1.getline(rt_usn,20,'|');
			file1.getline(st_usn,4,'\n');
			if(strcmp(st_usn,rt_usn)==0)
			{
			  delete_record(rt_usn);
			  flag=1;
			}
		  }
		  if(!flag)
		  {
			cout<<"\ndeletion failed\n";

		  }
		  file1.close();
		  break;
	    case 4: cout<<"\n\tUSN\tNAME\tAGE\tSEM\tBRANCH\t\n";
		    for(i=0;i<no;i++)
		    {
			cout<<"\n\t"<<rec[i].usn;
			cout<<"\n\t"<<rec[i].name;
			cout<<"\n\t"<<rec[i].age;
			cout<<"\n\t"<<rec[i].sem;
			cout<<"\n\t"<<rec[i].branch<<"\n";
		    }
		    break;
	       case 5: exit(0);
	    default: cout<<"invalid";
		     break;
		 }
	       }
	     }