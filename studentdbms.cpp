#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;
int main()
{
    FILE *fp,*ft;
    char another ,choice;
    struct student
    {
        char first_name[50],last_name[50];
        char course[100];
        int section;
    };
    struct student e;
    char xfirst_name[50],xlast_name[50];
    long int recsize;
    fp=fopen("users.txt","rb+");
    if(fp==NULL)
    {
       fp=fopen("usesr.txt","wb+");
       if(fp==NULL)
       {
           puts("cannot open file");
           return 0;
       }
    }
    recsize=sizeof(e);
    while(1)
    {
        system("cls");
        cout<<"\t\t======STUDENT DATABASE MANAGEMENT SYSTEM======";
        cout<<"\n\n";
        cout<<"\n\n";
        cout<<"\n\t\t\t 1.Add records";
        cout<<"\n\t\t\t 2.list records";
        cout<<"\n\t\t\t 3.modify records";
        cout<<"\n\t\t\t 4.delete records";
        cout<<"\n\t\t\t 5.exit records";
        cout<<"\n\n";
        cout<<"\t\t\t select your choice:-> ";
        fflush(stdin);
        choice=getch();
        switch(choice)
        {
            case '1':
            fseek(fp,0,SEEK_END);
            another='Y';
            while(another=='Y'||another=='Y')
            {
                system("cls");
                cout<<"Enter the first name:";
                cin>>e.first_name;
                cout<<"Enter the last name: ";
                cin>>e.last_name;
                cout<<"Enter the course: ";
                cin>>e.course;
                cout<<"Enter the section: ";
                cin>>e.section;
                fwrite(&e,recsize,1,fp);
                cout<<"\n Add another  record(Y/N) ";
                fflush(stdin);
                another=getchar();
            }
            break;
            case '2':
            system("cls");
            rewind(fp);
            cout<<"===view the records in the database ===";
            cout<<"\n";
            while(fread(&e,recsize,1,fp)==1)
            {
                cout<<"\n";
                cout<<"\n"<<e.first_name<<setw(10)<<e.last_name;
                cout<<"\n";
                cout<<"\n"<<e.course<<setw(8)<<e.section;
            }
            cout<<"\n\n";
            system("pause");
            break;
            case '3':
            system("cls");
            another='Y';
            while (another=='Y'||another=='y')
            {
                cout<<"\nEnter the last name of the student :";
                cin>>xlast_name;
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)
                {
                    if(strcmp(e.last_name,xlast_name)==0)
                    {
                        cout<<"Enter the new first name :";
                        cin>>e.first_name;
                        cout<<"Enter the new last name :";
                        cin>>e.last_name;
                        cout<<"Enter the new course: ";
                        cin>>e.course;
                        cout<<"Enter the new section :";
                        cin>>e.section;
                        fseek(fp,-recsize,SEEK_CUR);
                        fwrite(&e,recsize,1,fp);
                        break;
                    }
                    else
                    cout<<"Record not found";
                }
                cout<<"\nmodify another record(Y/N)";
                fflush(stdin);
                another=getchar();
            }
            break;
            case '4':
            system("cls")
            another='Y';
            while(another=='Y'||another=='y')
            {
                cout<<"\nEnter last name of student to delete :";
                cin>>xlast_name;
                ft=fopen("temp.dat","wb");
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)
                if(strcmp(e.last_name,xlast_name)!=0)
                {
                    fwrite(&e,recsize,1,ft);
                }
                fclose(fp);
                fclose(ft);
                remove("users.txt");
                rename("temp.dat","users.txt");
                fp=fopen("users.txt","rb+");
                cout<<"\n delete another record(Y/N)";
                fflush(stdin);
                another=getchar();
            }
            break;
            case '5':
            fclose(fp);
            cout<<"\n\n";
            cout"\t\t THANKYOU FOR USING THIS SOFTWARE";
            cout<<"\n\n";
            exit(0);
        }
    }
    system("pause");
    return 0;
}
