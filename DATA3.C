#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct stud
{
	int id;
	char name[20];
	float marks;
};

void append();
void display();
void displayAll();
void modify();
void del();
void search();

char mygetch();

char fname[]={"mydb.dat"};

int main()
	{
	int ch;

while(1)
	{
	clrscr();

	printf("=================Student Management System=============\n\n");

	printf("1. insert\n\n");
	printf("2. Modify\n\n");
	printf("3. Delete\n\n");
	printf("4. Search\n\n");
	printf("5. Display\n\n");
	printf("6. Display All\n\n");
	printf("0. Exit\n\n");

	printf("========================================================\n\n");

	printf("\nPlease enter your Choice:");
	scanf("%d",&ch);

switch(ch)
{
case 1:
	 append();
	break;

case 2:
	modify();
	break;

case 3:
	del();
	break;

case 4: search();
	break;

case 5: display();
	break;

case 6: displayAll();
	break;

case 0: exit(0);
}

mygetch();
}

return 0;
}
void append()
	{
	FILE *fp;
	struct stud t1;

	fp=fopen(fname,"ab");

printf("\nEnter rollno:");
scanf("%d",&t1.id);
printf("\nEnter name:");
scanf("%s",t1.name);
printf("\nEnter marks:");
scanf("%f",&t1.marks);
fwrite(&t1,sizeof(t1),1,fp);

	fclose(fp);
}
void modify()
{
	FILE *fp,*fp1;
	struct stud t,t1;
	int id,found=0,count=0;

fp=fopen(fname,"rb");
fp1=fopen("temp.dat","wb");

printf("\nEnter the student rollno you want to Modify:");
scanf("%d",&id);

	while(1)
	{
	fread(&t,sizeof(t),1,fp);

	if(feof(fp))
		{
		break;
		}
if(t.id==id)
{
found=1;
printf("\nEnter Student Roll no");
scanf("%d",&t.id);

fflush(stdin);
printf("\nEnter Student Name:");
scanf("%s",t.name);
printf("\nEnter Student marks:");
scanf("%f",&t.marks);
fwrite(&t,sizeof(t),1,fp1);
}
else
{
fwrite(&t,sizeof(t),1,fp1);
}
}
fclose(fp);
fclose(fp1);

if(found==0)
{
printf("Sorry No Record Found\n\n");
}
else
{
fp=fopen(fname,"wb");
fp1=fopen("temp.dat","rb");

while(1)
{
fread(&t,sizeof(t),1,fp1);

if(feof(fp1))
{
break;
}
fwrite(&t,sizeof(t),1,fp);
}

}
fclose(fp);
fclose(fp1);
}

void del()
{
	FILE *fp,*fp1;
	struct stud t,t1;
	int id,found=0,count=0;

	fp=fopen(fname,"rb");
	fp1=fopen("temp.dat","wb");

	printf("\nEnter the Student roll no you want to Delete:");
	scanf("%d",&id);

while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
	{
	break;
	}
if(t.id==id)
	{
	found=1;
	}
else
{
fwrite(&t,sizeof(t),1,fp1);
}
}
fclose(fp);
fclose(fp1);

if(found==0)
{
printf("Sorry No Record Found\n\n");
}
else
{
fp=fopen(fname,"wb");
fp1=fopen("temp.dat","rb");

while(1)
{
	fread(&t,sizeof(t),1,fp1);

	if(feof(fp1))
	{
	break;
	}
fwrite(&t,sizeof(t),1,fp);
}
}
fclose(fp);
fclose(fp1);
}

void display()
{
FILE *fp;
struct stud t;
int id,found=0;

	fp=fopen(fname,"rb");

	printf("\nEnter the Student roll no:");
	scanf("%d",&id);

while(1)
	{
	fread(&t,sizeof(t),1,fp);

	if(feof(fp))
	{
		break;
	}
if(t.id==id)
{
found=1;
printf("\n========================================================\n\n");
printf("\t\t Student Details of %d\n\n",t.id);
printf("========================================================\n\n");

printf("Name\tmarks\n\n");

printf("%s\t",t.name);
printf("%f\t\n\n",t.marks);

printf("========================================================\n\n");
}
}
if(found==0)
{
printf("\nSorry No Record Found");
}
fclose(fp);
}

void search()
{
FILE *fp;
struct stud t;
int found=0;
char name[20];

fp=fopen(fname,"rb");

printf("\nEnter the Employee Name:");
scanf("%s",&name);

while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
if(strcmp(name,t.name)==0)
{
printf("\n========================================================\n\n");
printf("\t\t Student Details of %d\n\n",t.id);
printf("========================================================\n\n");

printf("Name\tmarks\n\n");

printf("%s\t",t.name);
printf("%f\t\n\n",t.marks);

printf("========================================================\n\n");

}
}
if(found==0)
{
printf("\nSorry No Record Found");
}
fclose(fp);
}
void displayAll()
{
FILE *fp;
struct stud t;

fp=fopen(fname,"rb");

printf("\n========================================================\n\n");
printf("\t\t All Student Details\n\n");
printf("========================================================\n\n");

printf("rollno\tName\tmarks\n\n");

while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
printf("%d\t",t.id);
printf("%s\t",t.name);
printf("%f\t\n\n",t.marks);

}
printf("========================================================\n\n");

fclose(fp);
}

char mygetch()
{
char val;
char rel;

scanf("%c",&val);
scanf("%c",&rel);
return (val);
}
