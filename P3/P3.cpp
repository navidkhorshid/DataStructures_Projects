//********************************
//Project#3:Library(Linked-Lists)*
//Programmer:Navid Shamsizadeh****
//Professor : Mrs. Roia Rad
//********************************
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//prototype///////////////////////
int menu();
void bookregister();
void memberregister();
void searchbook();
void printbookmember();
void borrow();
void giveback();
int bnum=7;
int mnum=6;
//////////////////////////////////
//Classes/////////////////////////
//////////////////////////////////
class date{
private:
	int year;
   int month;
   int day;
public:
	date(int mm=0,int dd=0,int yyyy=0){setdate(mm,dd,yyyy);}
   void setdate(int ,int , int);
   void printdate();
};
void date::setdate(int m,int d, int y){
   month = ( m >= 1 && m <= 12 ) ? m : 0;
   day = ( d >= 1 && d <= 31 ) ? d : 0;
   year = ( y >= 1 && y <= 3000 ) ? y : 0;}
void date::printdate(){cout << month <<"/"<<day<<"/"<<year;}
//////////////////////////////////
//prototype///////////////////////
class booklist;
//////////////////////////////////
class book{
friend class booklist;
private:
	int booknum;
 	char bookname[10];
 	char author[10];
 	char title[10];
 	date publishdate;
 	char publisher[10];
   date enterdate;
	int status;
	book *next;
public:
	book(int a, char b[10], char c[10], char d[10], date e, char f[10], date g, book *p=0){
   next = p;
   status = 0;
   booknum = a;
   strcpy(bookname,b);
   strcpy(author,c);
   strcpy(title,d);
   publishdate=e;
   strcpy(publisher,f);
   enterdate=g;
   }
};
//////////////////////////////////
class booklist{
private:
	book *first;
public:
	booklist(){first=0;}

	void insert(int a, char b[10], char c[10], char d[10], date e, char f[10], date g){
   	book *p=new book(a,b,c,d,e,f,g);
      if (first==NULL){first = p;}else{
      p->next = first;
      first = p;                      }
   }

   void print();
   void searchbyname(char []);
   void searchtoborrow(char []);
   void searchtogiveback(char []);
};
//////////////////////////////////
//prototype///////////////////////
class memberlist;
//////////////////////////////////
class member{
friend class memberlist;
private:
	int membernum;
 	char name[15];
 	char lastname[15];
 	date birth;
   date membership;
   int count;
	member *next;
public:
	member(int a,char b[15],char c[15],date d,date e,member *p=0){
   next=p;
   count = 0;
   membernum = a;
   strcpy(name,b);
   strcpy(lastname,c);
   birth=d;
   membership=e;
   }
};
//////////////////////////////////
class memberlist{
private:
	member *first;
public:
	memberlist(){first=0;}

   void insert(int a,char b[15],char c[15],date d,date e){
   	member *p=new member(a,b,c,d,e);
      if (first==NULL){first = p;}else{
      p->next = first;
      first = p;                      }
   }

   void print();
   int searchnum(int);
   void searchnumtogiveback(int);
};
//////////////////////////////////
///////Making Objects/////////////
//////////////////////////////////
booklist books;
memberlist members;
//////////////////////////////////
//////////////////////////////////
//Booklist::Public Functions//////
//////////////////////////////////
//////////////////////////////////
void booklist::print(){
   book *tmp=first;
clrscr();
char p=220;
char q=179;
char q1=222;
char r=221;
char p1=196;
int i=0;
cout <<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p
     <<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p;
cout <<r<< "No. " <<q<< "BOOK NAME "<<q<<"  AUTHOR  "<<q<<"BOOK TITLE"<<q<<"PUBLISH DATE"<<q<<"PUBLISHER "<<q<<" ENTER DATE "<<q<<"MNo"<<q1;
cout <<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1
     <<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1
     <<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1;
   while (tmp!=NULL) {
   gotoxy(1,4+i);cout <<r<< "    " <<q<< "          "<<q<<"          "<<q<<"          "<<q<<"            "<<q<<"          "<<q<<"            "<<q<<"   "<<q1;
	gotoxy(2,4+i);cout << tmp->booknum;
   gotoxy(7,4+i);cout << tmp->bookname;
   gotoxy(18,4+i);cout << tmp->author;
   gotoxy(29,4+i);cout << tmp->title;
	gotoxy(41,4+i);tmp->publishdate.printdate();
	gotoxy(53,4+i);cout << tmp->publisher;
	gotoxy(65,4+i);tmp->enterdate.printdate();
   gotoxy(77,4+i); if(tmp->status!=NULL){cout <<" "<< tmp->status << endl;}else{cout<<" - \n";}
   i++;
   tmp=tmp->next;		}//end while
cout <<r<< "    " <<q<< "          "<<q<<"          "<<q<<"          "<<q<<"            "<<q<<"          "<<q<<"            "<<q<<"   "<<q1<<"\n\n\n";
               }//end print
//////////////////////////////////
void booklist::searchbyname(char name[10]){
char p=220;
char q=179;
char q1=222;
char r=221;
char p1=196;
int i=1;
cout <<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p
     <<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p;
cout <<r<< "No. " <<q<< "BOOK NAME "<<q<<"  AUTHOR  "<<q<<"BOOK TITLE"<<q<<"PUBLISH DATE"<<q<<"PUBLISHER "<<q<<" ENTER DATE "<<q<<"MNo"<<q1;
cout <<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1
     <<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1
     <<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1;
   book *tmp=first;
   while(tmp!=NULL){
   	if(strcmp(name,tmp->bookname)==0){
   gotoxy(1,4+i);cout <<r<< "    " <<q<< "          "<<q<<"          "<<q<<"          "<<q<<"            "<<q<<"          "<<q<<"            "<<q<<"   "<<q1;
	gotoxy(2,4+i);cout << tmp->booknum;
   gotoxy(7,4+i);cout << tmp->bookname;
   gotoxy(18,4+i);cout << tmp->author;
   gotoxy(29,4+i);cout << tmp->title;
	gotoxy(41,4+i);tmp->publishdate.printdate();
	gotoxy(53,4+i);cout << tmp->publisher;
	gotoxy(65,4+i);tmp->enterdate.printdate();
   gotoxy(77,4+i); if(tmp->status!=NULL){cout << tmp->status << endl;}else{cout<<" - \n";}
   i++;
      }
   tmp=tmp->next;
                   }//end while
cout <<r<< "    " <<q<< "          "<<q<<"          "<<q<<"          "<<q<<"            "<<q<<"          "<<q<<"            "<<q<<"   "<<q1<<"\n\n\n";
if(i==1){cout << "There's no book called \"" << name << "\" , Try Something Else ...";}
}
//////////////////////////////////
void booklist::searchtoborrow(char name[10]){
char p=220;
char q=179;
char q1=222;
char r=221;
char p1=196;
int i=1;
cout <<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p
     <<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p;
cout <<r<< "No. " <<q<< "BOOK NAME "<<q<<"  AUTHOR  "<<q<<"BOOK TITLE"<<q<<"PUBLISH DATE"<<q<<"PUBLISHER "<<q<<" ENTER DATE "<<q<<"MNo"<<q1;
cout <<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1
     <<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1
     <<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1;
   book *tmp=first;
   while(tmp!=NULL){
   	if(strcmp(name,tmp->bookname)==0){
   gotoxy(1,4+i);cout <<r<< "    " <<q<< "          "<<q<<"          "<<q<<"          "<<q<<"            "<<q<<"          "<<q<<"            "<<q<<"   "<<q1;
	gotoxy(2,4+i);cout << tmp->booknum;
   gotoxy(7,4+i);cout << tmp->bookname;
   gotoxy(18,4+i);cout << tmp->author;
   gotoxy(29,4+i);cout << tmp->title;
	gotoxy(41,4+i);tmp->publishdate.printdate();
	gotoxy(53,4+i);cout << tmp->publisher;
	gotoxy(65,4+i);tmp->enterdate.printdate();
   gotoxy(77,4+i); if(tmp->status!=NULL){cout << tmp->status << endl;}else{cout<<" - \n";}
   i++;
   gotoxy(4,7+i);cout << "Do You want to borrow this book ? (Press \"Y\")";
   gotoxy(4,8+i);cout << "Press Any Key To Continue Searching ...   ";
   int yesno=getch();
   if(yesno == 121 || yesno == 89){
   	if(tmp->status!=NULL){cout << "\n\nThis Book Has Been Taken" << endl;}
      	else{
              cout << "\n\nPlease Enter A memeber's number to search : ";
              int num; cin >> num;
              num=members.searchnum(num);
              tmp->status=num;
      		 }

   return;}
   gotoxy(4,7+i);cout << "                                                   ";
   gotoxy(4,8+i);cout << "                                               \n";
      }
   tmp=tmp->next;
                   }//end while
gotoxy(1,4+i);cout <<r<< "    " <<q<< "          "<<q<<"          "<<q<<"          "<<q<<"            "<<q<<"          "<<q<<"            "<<q<<"   "<<q1<<"\n\n\n";
if(i==1){cout << "\nThere's no book called \"" << name << "\" , Try Something Else ...";}else{cout << "There Is No More Book Named \""<<name<<"\"";}
}
//////////////////////////////////
void booklist::searchtogiveback(char name[10]){
char p=220;
char q=179;
char q1=222;
char r=221;
char p1=196;
int i=1;
cout <<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p
     <<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p;
cout <<r<< "No. " <<q<< "BOOK NAME "<<q<<"  AUTHOR  "<<q<<"BOOK TITLE"<<q<<"PUBLISH DATE"<<q<<"PUBLISHER "<<q<<" ENTER DATE "<<q<<"MNo"<<q1;
cout <<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1
     <<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1
     <<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1;
   book *tmp=first;
   while(tmp!=NULL){
   	if(strcmp(name,tmp->bookname)==0){
   gotoxy(1,4+i);cout <<r<< "    " <<q<< "          "<<q<<"          "<<q<<"          "<<q<<"            "<<q<<"          "<<q<<"            "<<q<<"   "<<q1;
	gotoxy(2,4+i);cout << tmp->booknum;
   gotoxy(7,4+i);cout << tmp->bookname;
   gotoxy(18,4+i);cout << tmp->author;
   gotoxy(29,4+i);cout << tmp->title;
	gotoxy(41,4+i);tmp->publishdate.printdate();
	gotoxy(53,4+i);cout << tmp->publisher;
	gotoxy(65,4+i);tmp->enterdate.printdate();
   gotoxy(77,4+i); if(tmp->status!=NULL){cout << tmp->status << endl;}else{cout<<" - \n";}
   i++;
   gotoxy(4,7+i);cout << "Do You want to give this book back ? (Press \"Y\")";
   gotoxy(4,8+i);cout << "Press Any Key To Continue Searching ...   ";
   int yesno=getch();
   if(yesno == 121 || yesno == 89){
   	if(tmp->status==NULL){cout << "\n\nThis Book Hasn't Been Taken" << endl;}
      	else{
              members.searchnumtogiveback(tmp->status);
              cout << "\n\nMember number \""<<(tmp->status)<<"\" returned the book \"" <<name<<"\" ." ;
              tmp->status=0;
      		 }

   return;}
   gotoxy(4,7+i);cout << "                                                   ";
   gotoxy(4,8+i);cout << "                                               \n";
      }
   tmp=tmp->next;
                   }//end while
gotoxy(1,4+i);cout <<r<< "    " <<q<< "          "<<q<<"          "<<q<<"          "<<q<<"            "<<q<<"          "<<q<<"            "<<q<<"   "<<q1<<"\n\n\n";
if(i==1){cout << "\nThere's no book called \"" << name << "\" , Try Something Else ...";}else{cout << "There Is No More Book Named \""<<name<<"\"";}
}
//////////////////////////////////
//Memberlist::Public Functions////
//////////////////////////////////
//////////////////////////////////
void memberlist::print(){
   member *tmp=first;
clrscr();
char p=220;
char q=179;
char q1=222;
char r=221;
char p1=196;
int i=0;

cout <<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p
     <<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<endl;
cout <<r<< "MEMBER No." <<q<< "  MEMBER NAME  "<<q<<"MEMBER LASTNAME"<<q<<"  BIRTHDAY  "<<q<<"MEMBERSHIP DATE"<<q<<"COUNT"<<q1<<endl;
cout <<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1
     <<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1
     <<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<endl;

   while (tmp!=NULL) {
   cout <<r<< "          " <<q<< "               "<<q<<"               "<<q<<"            "<<q<<"               "<<q<<"     "<<q1<<endl;
   gotoxy(2,4+i);cout<<tmp->membernum;
   gotoxy(13,4+i);cout<<tmp->name;
   gotoxy(29,4+i);cout<<tmp->lastname;
	gotoxy(46,4+i);tmp->birth.printdate();
	gotoxy(60,4+i);tmp->membership.printdate();
   gotoxy(76,4+i);cout<<tmp->count<<endl;
   i++;
   tmp=tmp->next;		}//end while
cout <<r<< "          " <<q<< "               "<<q<<"               "<<q<<"            "<<q<<"               "<<q<<"     "<<q1<<"\n\n\n";
				            }//end print


//////////////////////////////////
int memberlist::searchnum(int num){
	member *tmp=first;
   while(tmp!=NULL){
   	if(tmp->membernum==num){
      	cout << "\nMember \"" << num <<"\" Exists ";
         if((tmp->count)<2){
            (tmp->count)++;
            cout << "and you have successfully borrowed the book.";
         	return (tmp->membernum);

         						}else{cout << ",But you can't borrow the book because you already have 2.";return 0;}
      }
   tmp=tmp->next;
                   }//end while
cout << "\n\nDidn't find Any member number \""<<num<<"\" in members list.";return 0;
                   }//end searchnum
//////////////////////////////////
void memberlist::searchnumtogiveback(int num){
	member *tmp=first;
   while(tmp!=NULL){
   	if(tmp->membernum==num){
            (tmp->count)--;
            return;
         						  }

   tmp=tmp->next;
                   }//end while
}
//////////////////////////////////
//GLOBAL FUNCTIONS////////////////
//////////////////////////////////
int main()
{
books.insert(1,"C#2008","Lee","Program",date(10,10,2009),"Wiley",date(1,1,2010));
books.insert(2,"C++","Deitel","Program",date(10,1,2008),"Prentice",date(1,3,2010));
books.insert(3,"UsingIT","Sawyer","IT",date(1,31,2009),"McGraw",date(1,5,2010));
books.insert(4,"A+","Meyers","Hardware",date(12,18,2005),"McGraw",date(1,6,2010));
books.insert(5,"English","Longman","DIC",date(6,5,2005),"Pearson",date(1,6,2010));
books.insert(6,"C++","Schildt","Program",date(9,27,1998),"Osborne",date(1,8,2010));
members.insert(1,"Navid","Shamsizadeh",date(3,3,1990),date(11,29,2009));
members.insert(2,"Mike","Shinoda",date(12,3,1989),date(12,8,2009));
members.insert(3,"Ross","Geller",date(7,3,1990),date(12,23,2009));
members.insert(4,"Johnny","Depp",date(8,16,1990),date(12,31,2009));
members.insert(5,"Serj","Tankian",date(3,6,1994),date(1,2,2010));
int j;
for(;;) {
	clrscr();
	j = menu();
	switch (j) {
		case 1:
         bookregister();
			break;
		case 2:
         memberregister();
			break;
		case 3:
         searchbook();
			break;
		case 4:
         printbookmember();
			break;
      case 5:
      	borrow();
         break;
		case 6:
      	giveback();
         break;
		case 7:
      clrscr();
      	cout << "\nProgrammer : Navid Shamsizadeh\n ";
			cout << "*********************************************Press Any Key To Exit ...";
			getch();
			exit(0);
         break;
		default:
			cout << "Out Of Range";
			getch();
			break;
				  }
		  }
}
//////////////////////////////////
int menu()
{
	int z;
   char m=220;
   char o=177;
   char p=223;
   gotoxy(4,1);
   cout <<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m;
   gotoxy(4,2);
	cout << o <<" 1) Register A New Book.              "<<o;
	gotoxy(4,3);
	cout << o <<" 2) Sign-Up A New Member.             "<<o;
	gotoxy(4,4);
	cout << o <<" 3) Search A Book By Name.            "<<o;
	gotoxy(4,5);
	cout << o <<" 4) Print Members & Books             "<<o;
	gotoxy(4,6);
	cout << o <<" 5) Borrow A Book.                    "<<o;
   gotoxy(4,7);
   cout << o <<" 6) Give A Book Back.   7)Exit.       "<<o;
   gotoxy(4,8);
   cout <<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p;
   gotoxy(6,1);cout << "<-*WELCOME TO OUR LIBRARY*->";
      gotoxy(7, 10);
		cout << "Please Enter Your Choice ...(1-7):   ";
		z=getch()-48;
return z;
}
//////////////////////////////////
void bookregister(){
clrscr();
char p=220;
char q=179;
char q1=222;
char r=221;
char p1=196;
int a;
char b[10];
char c[10];
char d[10];
date e;
int mm;
int dd;
int yyyy;
char f[10];
date g;
cout <<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p
     <<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<endl;
cout <<r<< "No. " <<q<< "BOOK NAME "<<q<<"  AUTHOR  "<<q<<"BOOK TITLE"<<q<<"PUBLISH DATE"<<q<<"PUBLISHER "<<q<<" ENTER DATE "<<q1<<endl;
cout <<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1
     <<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1
     <<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<endl;
cout <<r<< "    " <<q<< "          "<<q<<"          "<<q<<"          "<<q<<" MM/DD/YYYY "<<q<<"          "<<q<<"   /  /     "<<q1<<endl;
cout <<r<< "    " <<q<< "          "<<q<<"          "<<q<<"          "<<q<<"            "<<q<<"          "<<q<<"            "<<q1<<endl;
a=bnum++;

struct tm *Sys_T = NULL;
time_t Tval = 0;
Tval = time(NULL);
Sys_T = localtime(&Tval);
dd=Sys_T->tm_mday;
mm=Sys_T->tm_mon+1;
yyyy= 1900 + Sys_T->tm_year;
gotoxy(65,4);g.setdate(mm,dd,yyyy);g.printdate();//date g

gotoxy(2,4);cout<<a;gotoxy(7,4);cin>>b;gotoxy(18,4);cin>>c;gotoxy(29,4);cin>>d;
gotoxy(41,4);cin>>mm;gotoxy(44,4);cin>>dd;gotoxy(47,4);cin>>yyyy;e.setdate(mm,dd,yyyy);//date e
gotoxy(53,4);cin>>f;
books.insert(a,b,c,d,e,f,g);
}
//////////////////////////////////
void memberregister(){
clrscr();
char p=220;
char q=179;
char q1=222;
char r=221;
char p1=196;
int a;
char b[15];
char c[15];
date d;
date e;
int mm;
int dd;
int yyyy;
cout <<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p
     <<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<endl;
cout <<r<< "MEMBER No." <<q<< "  MEMBER NAME  "<<q<<"MEMBER LASTNAME"<<q<<"  BIRTHDAY  "<<q<<"MEMBERSHIP DATE"<<q1<<endl;
cout <<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1
     <<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1
     <<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<p1<<endl;
cout <<r<< "          " <<q<< "               "<<q<<"               "<<q<<" MM/DD/YYYY "<<q<<"    /  /       "<<q1<<endl;
cout <<r<< "          " <<q<< "               "<<q<<"               "<<q<<"            "<<q<<"               "<<q1<<endl;
a=mnum++;

struct tm *Sys_T = NULL;
time_t Tval = 0;
Tval = time(NULL);
Sys_T = localtime(&Tval);
dd=Sys_T->tm_mday;
mm=Sys_T->tm_mon+1;
yyyy= 1900 + Sys_T->tm_year;
gotoxy(60,4);e.setdate(mm,dd,yyyy);e.printdate();//date e

gotoxy(2,4);cout<<a;gotoxy(13,4);cin>>b;gotoxy(29,4);cin>>c;
gotoxy(46,4);cin>>mm;gotoxy(49,4);cin>>dd;gotoxy(52,4);cin>>yyyy;d.setdate(mm,dd,yyyy);//date d
members.insert(a,b,c,d,e);
   }
//////////////////////////////////
void searchbook(){
clrscr();
cout << "Type A Book Name To Search :  ";
char bn[10];
cin >> bn;
books.searchbyname(bn);
getch();

}
//////////////////////////////////
void printbookmember(){
	clrscr();
   books.print();
   cout << "Press Any Key To See Members List ...";
   getch();
   clrscr();
   members.print();
   cout << "Press Any Key To Return To Menu ...";
   getch();
}
//////////////////////////////////
void borrow(){
clrscr();
cout << "Search A Book Name To Borrow :  ";
char bn[10];
cin >> bn;
books.searchtoborrow(bn);
getch();
}
//////////////////////////////////
void giveback(){
clrscr();
cout << "Search A Book Name To Give Back :  ";
char bn[10];
cin >> bn;
books.searchtogiveback(bn);
getch();
}
//////////////////////////////////

