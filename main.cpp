///////////////////////////Hospital management system////////////////
////////////////////Header files///////////////////

///////////////////////// Made By Weranga Rathnayaka /////////////////////////
#include <iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>


///////////////////////////////////////////// Function declaration//////////
void menu();
void pascode();
void cpascode();
/////////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

/////////////////////////////////// class one//////////////////////////

class one
{
public:
    virtual void get()=0;
    virtual void show()=0;

};

/////////////////////// class info/////////////////

class info:public one
{
public:
    char name[50],time[50];
    int num,age;
    void get()
    {
       system("cls");
       cin.sync();
       cout<<"\n Enter the patient name = " ;
       cin.getline(name,50);
       cout<<"\n Enter the Appoinment Time =" ;
       cin.getline(time,50);
       cout<<"\n Enter Age = " ;
       cin>>age;
       cout<<"\n Enter Appoinment No = " ;
       cin>>num;


    }
    void show()
    {
        cout<<"\n Name = " <<name;
        cout<<"\n Age = " <<age;
        cout<<"\n No = " <<num;
        cout<<"\n Time = " <<time;
    }
};

/////////////////////////////////////class kasun////////////////////

class kasun:public info
{
public:
    info a1;
    void get()
    {
        system ("cls");
        ofstream out("kasun.txt",ios:: app|ios::binary);
        a1.get();
        out.write((char*)&a1,sizeof(info));
        out.close();
        cout<<"Your Entry Has Saved" ;
        getch();
        menu();
    }
    void show()
    {

       ifstream in ("kasun.txt");
      if(!in)
       {
           cout<<"\n\n No Data in the file " ;
           cout<<"\n\n\t\t Press Any key To Continue : " ;
           getch();
           menu();
       }
       else

       {


           while(!in.eof())
           {
               in.read((char*)&a1,sizeof(a1));
               a1.show();
           }
           in.close();
           getch();
           menu();
       }
    }
};

////////////////////////// class Dr nimal///////////////

class nimal:public info
{
   public:
    info a1;
    void get()
    {
        system ("cls");
        ofstream out("nimal.txt",ios:: app|ios::binary);
        a1.get();
        out.write((char*)&a1,sizeof(info));
        out.close();
        cout<<"Your Entry Has Saved" ;
        getch();
        menu();
    }
    void show()
    {
       ifstream in ("nimal.txt");
       if(!in)
       {
           cout<<"\n\n No Data in the file " ;
           cout<<"\n\n\t\t Press Any key To Continue : " ;
           getch();
           menu();
       }
       else
       {
           while(!in.eof())
           {
               in.read((char*)&a1,sizeof(a1));
               a1.show();
           }
           in.close();
           getch();
           menu();
       }
    }



};

////////////////////// class Dr sunil/////////////

class sunil:public info
{
   public:
    info a1;
    void get()
    {
        system ("cls");
        ofstream out("sunil.txt",ios:: app|ios::binary);
        a1.get();
        out.write((char*)&a1,sizeof(info));
        out.close();
        cout<<"Your Entry Has Saved" ;
        getch();
        menu();
    }
    void show()
    {
       ifstream in ("sunil.txt");
      if(!in)
       {
           cout<<"\n\n No Data in the file " ;
           cout<<"\n\n\t\t Press Any key To Continue : " ;
           getch();
           menu();
       }
       else
       {
           while(!in.eof())
           {
               in.read((char*)&a1,sizeof(a1));
               a1.show();
           }
           in.close();
           getch();
           menu();
       }
    }
};



class staff:public one
{

public:
    char all[999];
    char name[50],age[20],sal[30],pos[20];
    void get()
    {
        ofstream out("staff.txt",ios::app);
        {    system("cls");
             cin.sync();
             cout<<"\nEnter Name =" ;
             cin.getline(name,50);
             cout<<"\nEnter Age =" ;
             cin.getline(age,20);
             cout<<"\nEnter Sallary =" ;
             cin.getline(sal,30);
             cout<<"\nEnter Working Position =" ;
             cin.getline(pos,20);


          }

    out<<"\nName= "<<name<<"\nAge= "<<age<<"\nSallary="<<sal<<"\nWorking Position="<<pos ;
    out.close();
    cout<<"\n\n Your information has been saved  :\n\t\t\t press any key to Continue : ";
    getch();
    menu();

    }
    void show()
    {
        ifstream in ("staff.txt");
        if(!in)
        {
            cout<<"File Open error" ;
        }
        while(!(in.eof()))
        {
            in.getline(all,999);
            cout<<all<<endl;
        }
        in.close();
        cout<<"\n\n\t\t\t Press any key to continue : " ;
        getch();
        menu();
    }



};

////////////////class information/////////////////////

class information
{
   public:
       void drinfo()
       {
           system("cls");
           system("color F3");
           cout<<"\n=====================================================\n";
           cout<<"\n\n\t\t(Three Dcotors Available) \n\n\t\t [Information and Timing Are Given Below]\n";
           cout<<"--------------------------------------------------------\n";


           cout<<"\t\t Dr.Kasun (skin specialist)\n\n";
           cout<<"\t\t\t [[Timing]] :\n\n";
           cout<<"\t Monday to friday\t 9AM to 5PM\n";
           cout<<"\t saterday \t\t 9AM to 1PM\n";
           cout<<"\t sunday \t\t off \n";
           cout<<"\n-------------------------------------------------------\n";

           cout<<"\t\t Dr.Nimal (child specialist)\n\n";
           cout<<"\t\t\t [[Timing]] :\n\n";
           cout<<"\t Monday to friday\t 2AM to 10PM\n";
           cout<<"\t saterday \t\t 8AM to 1PM\n";
           cout<<"\t sunday \t\t 12PM to 9PM \n";
           cout<<"\n-------------------------------------------------------\n";

           cout<<"\t\t Dr.Sunil (Dental specialist)\n\n";
           cout<<"\t\t\t [[Timing]] :\n\n";
           cout<<"\t Monday to friday\t 8AM to 5PM\n";
           cout<<"\t saterday \t\t 10AM to 1PM\n";
           cout<<"\t sunday \t\t off \n";
           cout<<"\n-------------------------------------------------------\n";

           cout<<"\n press any key for continue : ";
           getch();
           menu();
       }






};

void call_dr()
{
    system("cls");
    int choice;
    cout<<"\n\n\n\t\t press 1 for Dr Kasun \n\n\t\t press 2 for Dr Nimal \n\n\t\t press 3 for Dr Sunil\n";
    cin>>choice;

    one *ptr;
    kasun s3;
    nimal s4;
    sunil s5;
    if(choice==1)
    {
        ptr=&s3;
        ptr->get();
    }
    if(choice==2)
    {
        ptr=&s4;
        ptr->get();
    }
    if(choice==3)
    {
        ptr=&s5;
        ptr->get();
    }
    else
    {
        cout<<"sorry invalid choice : ";

    }
}

void pinfoshow()
{
    system("cls");
    int choice;
    cout<<"\n\n\n\t\t press 1 for Dr Kasun \n\n\t\t press 2 for Dr Nimal \n\n\t\t press 3 for Dr Sunil";
    cin>>choice;

    one *ptr;
    kasun s3;
    nimal s4;
    sunil s5;
    if(choice==1)
    {
        ptr=&s3;
        ptr->show();
    }
    if(choice==2)
    {
        ptr=&s4;
        ptr->show();
    }
    if(choice==3)
    {
        ptr=&s5;
        ptr->show();
    }
    else
    {
        cout<<"sorry invalid choice : ";
        getch();
        menu();


    }
}

void menu ()
{
    system("cls");
    system ("color FC");

    cout<<"\n";
    cout<<"\n";

    cout<<"\t\t    |   ***********  MAIN MENU  ************   |   \n";
    cout<<"\t\t    |        Hospital Management System        |   \n";
    cout<<"\t\t    |   ==================================     |   \n";

    cout<<"\n-------------------------------------------------------------------------\n";
    cout<<"\t\t       please select any option            \n  " ;

    cout<<"\n\n\t1-\t\t press 1 for Available Doctor information\n\n";
    cout<<"\t2-\t\t press 2 for Doctor Appoinment\n\n" ;
    cout<<"\t3-\t\t press 3 for Saving staff information\n\n" ;
    cout<<"\t4-\t\t press 4 for checking patient appoinment menu\n\n" ;
    cout<<"\t5-\t\t press 5 for checking staff information menu \n\n" ;
    cout<<"\t6-\t\t press 6 for change or create password \n\n" ;
    cout<<"\t7-\t\t [press 7 for Logout]\n\n" ;

    cout<<"\n================================================================================\n";
    cout<<"\n\n\t\t please enter your choice : " ;
    information a1;
    one *ptr;
    staff a2;
    int a;
    cin>>a;
    if(a==1)
    {
        a1.drinfo();
    }
    else if (a==2)
    {
        call_dr();
    }
    else if (a==3)
    {
        ptr=&a2;
        ptr->get();
    }
    else if (a==4)
    {
        pinfoshow();
    }
    else if (a==5)
    {
        ptr=&a2;
        ptr->show();
    }
    else if (a==6)
    {
        cpascode();
    }
    else if (a==7)
    {
        pascode();
    }
    else
    {
        cout<<"sorry invalid choice : " ;
    }


}

void pascode()
{
    system ("cls");
    char p1[50],p2[50],p3[50];

    system("color Fc");
    ifstream in("password.txt");
    {
        cin.sync();

        cout<<"\n\n\n\n\n\n\t\t\t Enter the password : " ;
        cin.getline(p1,50);
        in.getline(p2,50);
        if(strcmp(p1,p2)==0)
        {
            menu();
        }
        else
        {
            cout<<"\n\n\t\t\t Incorrect passcode please try again \n";
            Sleep(999);
            pascode();
        }
    }
    in.close();
}

void cpascode()
{
    char n[50];
    system("cls");
    ofstream out("password.txt");
    {
        cin.sync();
        cout<<"\n\n\n\n\t\t\t Enter The New passowrd";
        cin.getline(n,50);
        out<<n;
    }
    out.close();
    cout<<"\n\n Your Password has been saved : " ;
    getch();
    menu();
}

int main ()
{
    pascode();
    system("pause");
}
