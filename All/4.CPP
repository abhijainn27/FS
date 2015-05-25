#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<iomanip.h>

class student
{
public:
char name[15];
char usn[10];
char age[5];
char sem[5];
char branch[15];
char buffer[100];

};



void writerecord()
{
fstream file;
student s;
int k,n;
file.open("program4.txt",ios::app);
if(!file)
{
cout<<"cannot open the file in append mode";
getch();
exit(0);
}
printf("how many records\n");
scanf("%d",&n);
for(k=0;k<n;k++)
{
cout<<"\n enter the student name=";
cin>>s.name;
cout<<"\n enter the usn=";
cin>>s.usn;
cout<<"\nenter the age=";
cin>>s.age;
cout<<"\nenter the sem=";
cin>>s.sem;
cout<<"\nenter the branch=";
cin>>s.branch;
file<<k<<"|"<<s.name<<"|"<<s.usn<<"|"<<s.age<<"|"<<s.sem<<"|"<<s.branch<<"\n";}
file.close();

     }

void search()
{
char rrn[10],rrn1[10][15];
int i;
student std[100];
cout<<"\n enter the rrn to be searched";
cin>>rrn;
fstream file;
file.open("program4.txt",ios::in);
if(!file)
{
cout<<"\n cannot open the file in input mode";
getch();
exit(0);
}
i=0;
printf("\nrrn\nname\tusn\tage\tsem\tbranch\n");

while(!file.eof())
{
file.getline(rrn1[i],4,'|');
file.getline(std[i].name,15,'|');
file.getline(std[i].usn,15,'|');
file.getline(std[i].age,5,'|');
file.getline(std[i].sem,5,'|');
file.getline(std[i].branch,15,'\n');
i++;
}
for(int j=0;j<i-1;j++)
{
if(strcmp(rrn,rrn1[j])==0)
{
printf("\n%s\t%s\t%s\t%s\t%s\t%s\n",rrn,std[j].name,std[j].usn,std[j].age,std[j].sem,std[j].branch);
printf("record found\n");
file.close();
return;
}
}
cout<<"\n record not found";
file.close();
return;
}


void displayFile()
{
student s;
char rrn[10];
fstream file;
file.open("program4.txt",ios::in);
if(!file)
{
cout<<"\ncannot open the file in input mode";
getch();
exit(1);
}
cout<<"\n";
printf("rrn\tNAME\t\tUSN\t\tAGE\t\tSEM\t\tBRANCH\n");
printf("----\t\t----\t\t----\t\t----\t\t----\n");


while(!file.eof())
{
file.getline(rrn,4,'|');
file.getline(s.name,15,'|');
file.getline(s.usn,15,'|');
file.getline(s.age,5,'|');
file.getline(s.sem,5,'|');
file.getline(s.branch,15,'\n');

printf("\n%s\t %s\t\t%s\t\t%s\t\t%s\t\t%s",rrn,s.name,s.usn,s.age,s.sem,s.branch);

}
file.close();
getch();
}


void main()
{
int choice;
clrscr();
while(1)
{

cout<<"\n 0:exit";
cout<<"\n 1:insert";
cout<<"\n 2:search";
cout<<"\n 3:display";

cout<<"\nenter your  choice:";
cin>>choice;


switch(choice)
{


case 1:writerecord();
       break;
case 2:search();
	break;
case 3:displayFile();
       break;
case 0: exit(0);
default:cout<<"\n invalid option";
break;
}
}
}

