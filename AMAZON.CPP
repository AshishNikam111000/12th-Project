/* HELLO THIS IS MY PROJECT IN WHICH I TRIED TO MAKE AN BACKHAND OPRETIONAL
   APPLICATION.  */
#include<stdlib.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>

class amazon
 {
   char name[25];
   char product[25];
 public:
   int pno;
   char add[25];
   void showdata();
   void input();
   void newinput();
 };

/* menu() function is used to provide menu to the user */
void menu()
{
int x,y;
textcolor(LIGHTRED);
 for(x=20,y=2;x<60;x++)
  {
   gotoxy(x,y);
   cprintf("#");
  }
textcolor(LIGHTRED);
 for(x=20,y=2;y<24;y++)
  {
   gotoxy(x,y);
   cprintf("#");
  }
textcolor(LIGHTRED);
 for(x=59,y=2;y<24;y++)
  {
   gotoxy(x,y);
   cprintf("#");
  }
textcolor(LIGHTRED);
  for(x=20,y=24;x<60;x++)
  {
   gotoxy(x,y);
   cprintf("#");
  }
textcolor(YELLOW);
 gotoxy(34,4);
 cprintf("A M A Z O N");

textcolor(LIGHTRED);
  for(x=20,y=6;x<60;x++)
  {
   gotoxy(x,y);
   cprintf("#");
  }
textcolor(LIGHTGREEN);
 gotoxy(22,7);
 cprintf("************* WELCOME **************");
  gotoxy(22,8);
  cprintf(" ************** MENU **************");
textcolor(LIGHTMAGENTA);
 gotoxy(22,9);
 cprintf("1.  Input");
 gotoxy(22,10);
 cprintf("2.  Output");
 gotoxy(22,11);
 cprintf("3.  Search");
 gotoxy(22,12);
 cprintf("4.  delete a order");
 gotoxy(22,13);
 cprintf("5.  Modification");
 gotoxy(22,14);
 cprintf("6.  Delete entire file");
 gotoxy(22,15);
 cprintf("7.  Exit");
textcolor(LIGHTRED);
 for(x=20,y=17;x<60;x++)
  {
   gotoxy(x,y);
   cprintf("#");
  }
textcolor(LIGHTGREEN);
 gotoxy(22,19);
 cprintf("Enter your choice here:") ;
}

/* newinput() is a class member function used to input new data
   which is to be modify */
void amazon::newinput()
{
 cout<<"\nEnter New Name:";
 gets(name);
 cout<<"\nEnter New address:";
 gets(add);
}

/* input() is also a class member function used to input data in file */
void amazon::input()
{
 cout<<"\nEnter Your Product Number:";
 cin>>pno;
 cout<<"\nEnter Your Product Name:";
 gets(product);
 cout<<"\nEnter Your Name:";
 gets(name);
 cout<<"\nEnter address:";
 gets(add);
}

/* showdata() is also a class member function used to display details */
void amazon::showdata()
{
 cout<<"\n"
    <<"Product Number:"<<pno<<"\t\t "
    <<"Product Name:"<<product<<"\t\t\t        "
    <<"Name:"<<name<<"\t\t\t "
    <<"Address:"<<add<<"\n";
}

/* Function search() is used to search a record in a file */
void search()
{
  ifstream ob("AMAZON.dat",ios::in);
  amazon S;
    int pno1;
    cout<<"\nEnter Product Number to search:";
    cin>>pno1;
      ob.seekg(0);
      int count=0;
	while(!ob.eof())
	{
	    ob.read((char*)&S,sizeof(S));
	      if(pno1==S.pno)
		{
		 cout<<"\n     !!!Record found!!!\n";
		 S.showdata();
		 count++;
		 break;
		}
	}

		 if(count==1)
		 {}
		 else
		 {
		  cout<<"\n!!!!Result not found!!!!\n"   ;
		 }
  ob.close();
}

/* Function delete_data() is used to delete records */
void delete_data()
{
   ifstream iff("AMAZON.dat",ios::in);
   ofstream off("GARBAGE.dat",ios::out|ios::app);
     amazon S;
     int count=0;
     int pno1;
     cout<<"\nEnter Product Number to delete his data:";
     cin>>pno1;
     iff.seekg(0);
      while(!iff.eof())
	{
	   iff.read((char*)&S,sizeof(S));
	      if(pno1!=S.pno)
		{
		 off.write((char*)&S,sizeof(S));
		}
	      else
		count++;
	}
   off.close();
   iff.close();
      remove("AMAZON.dat");
      rename("GARBAGE.dat","AMAZON.dat");
	if(count>0)
	 {
	  cout<<"\n????Data Deleted????\n";
	 }
	else
	 {
	  cout<<"\n????Data Not Found????\n";
	 }

}

/* Function edit() is used to modify the details entered */
void edit()
{
  fstream ob;
  ob.open("AMAZON.dat",ios::in|ios::out);
    amazon S;
    int roll;
    cout<<"Enter roll no to edit:";
    cin>>roll;
    ob.seekg(0);
    int pos=0,count=0;
    char edit[20];
      while(!ob.eof())
	{
	   pos=ob.tellg();
	   ob.read((char*)&S,sizeof(S));
	      if(roll==S.pno)
		{
		 cout<<"\n     !!!Record found!!! ";
		 cout<<"\nEnter the new values:\n  ";
		 S.newinput();;
		 ob.seekp(pos);
		 ob.write((char*)&S,sizeof(S)) ;
		 cout<<endl;
		 S.showdata();
		 count++;
		 break;
		}
	}
	      if(count==1)
		{}
	      else
		{
		 cout<<"\n!!!!Result not found!!!!\n"   ;
		}
}

/* MAIN FUNCTION */
void main()
{
 clrscr();
   amazon S;
   fstream m;
      char v;
      int choice;
      do{
	 menu();
	 cin>>choice;
	 clrscr();
	   switch(choice)
	    {
	      case 1:
		 do{
		    S.input();
		    m.open("AMAZON.dat",ios::out|ios::app);
		    m.write((char*)&S,sizeof(S));
		    cout<<"\nDo you want to continue:(y/n):" ;
		    cin>>v;
		    clrscr();
		    m.close();
		   }while(v=='y'||v=='Y');
	      break;

	      case 2:
		  clrscr();
		  ifstream out("AMAZON.dat");
		    if(out)
		     {
		       m.open("AMAZON.dat",ios::in);
		       m.seekg(0);
			 while(!m.eof())
			     {
				m.read((char*)&S,sizeof(S));
				S.showdata();
			      }
		       m.close();
		       getch();
		       clrscr();
		     }
		    else
		     {
		      textcolor(LIGHTGRAY);
		      gotoxy(30,21);
		      cprintf("File doesn't exist!!!!");
		     }
	      break;

	      case 3:
		  ifstream searchf("AMAZON.dat");
		  if(searchf)
		    {
		     do{
			 search();
			 cout<<"\nDo you want to continue:(y/n):" ;
			 cin>>v;
			 clrscr();
		       }while(v=='y'||v=='Y');
		    }
		  else
		    {
		     textcolor(LIGHTGRAY);
		     gotoxy(30,21);
		     cprintf("File doesn't exist!!!!");
		    }
	      break;

	      case 4:
		  ifstream del("AMAZON.dat");
		  if(del)
		    {
		     do{
			delete_data();
			cout<<"\nDo you want to continue:(y/n):" ;
			cin>>v;
			clrscr();
		       }while(v=='y'||v=='Y');
		    }
		  else
		    {
		     textcolor(LIGHTGRAY);
		     gotoxy(30,21);
		     cprintf("File doesn't exist!!!!");
		    }
	      break;

	      case 5:
		  ifstream editf("AMAZON.dat");
		  if(editf)
		    {
		     do{
			edit();
			cout<<"\nDo you want to continue:(y/n):" ;
			cin>>v;
			clrscr();
		       }while(v=='y'||v=='Y');
		    }
		  else
		    {
		     textcolor(LIGHTGRAY);
		     gotoxy(30,21);
		     cprintf("File doesn't exist!!!!");
		    }
	      break;

	      case 6:
		  remove("AMAZON.dat");
		  textcolor(LIGHTGRAY);
		  gotoxy(34,21);
		  cprintf("File deleted!!!");
	      break;

	      case 7:exit(0);break;

	      default:
		  textcolor(LIGHTGRAY);
		  gotoxy(34,21);
		  cout<<"\nEnter right choice:" ;break;
	    } //switch ends
	}while(choice!=7); //do while loop ends
 getch();
} //main ends