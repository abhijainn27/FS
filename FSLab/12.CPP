#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream.h>
#include<string.h>
#include<fstream.h>
#include<iomanip.h>
class node
{
	public:char name[15];
		char usn[15];
		node * link;
};

node * first = NULL;

void writefile()
{
	node * p;
	char buffer[100];
	fstream out;
	out.open("student.txt",ios::app);
	if(!out)
	{
		cout<<"Unable to open the file in append mode";
		getch();
		exit(0);
	}
	p=first;
	while(p!=NULL)
	{
		strcpy(buffer,p->name);
		strcat(buffer,"|");
		strcat(buffer,p->usn);
		strcat(buffer,"\n");
		out<<buffer;
		p=p->link;
	}
}

void display()
{
node *p;
if(first==NULL)
{
	cout<<"List is empty";
	return;
}
p= first;
while(p!=NULL)
{
	cout<<"|"<<p->name<<" "<<p->usn<<"|"<<"->";
	p=p->link;
}
}

void insert()
{
char name[20];
char usn[15];
node *p;
node *q;
cout<<"\nEnter the name\n";
cin>>name;
cout<<"\nEnter the usn\n";
cin>>usn;
cout<<"\n\n";
p=new node;
strcpy(p->name,name);
strcpy(p->usn,usn);
p->link=NULL;
if(first==NULL)
{
	first=p;
	writefile();
	display();
	return;
}
for(q=first;q->link!=NULL;q=q->link)
{
	;
}
q->link=p;
writefile();
display();
}

void del()
{
	char usn[15];
	node * curr;
	node * prev;
	node * del;
	if(first==NULL)
	{
		printf("The list is empty..deletion not possible");
		return;
	}
	cout<<"Enter the USn to be deleted=";


