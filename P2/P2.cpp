// P2_Shamsizadeh                            #
// 	870134089(Navid Shamsizadeh)           #
//    	Professor: Mrs. Roia Rad#
//       	Parking Project                  #
//############################################
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
//******PROTOTYPES****************
int menu();
int addright();
int addleft();
int cancel();
int delcar();
void printparking();
void outq1();void outq2();
void printparkingtext();

//*******CLASS*********************

class queue{
  private:
	int rear;
   int front;
   bool *mark;
   int *queue;
   int maxsize;
  public:
  	queue(int maxqueuesize):maxsize(maxqueuesize){
   	queue=new int[maxsize];
      mark = new bool[maxsize];
      rear = front = -1;
   }
   bool isfull(){
   	if((rear-front)>= maxsize) return true;
      else return false;
	}

   bool isempty(){
   	if(front==rear) return true;
      else return false;
   }
   bool add(const int& x);
   int* delet(int&);
   void printqueue();
   int avail(){return (rear-front);}
   void canceling(int n){mark[(front+n)]=false;}
   bool checkcancel(){return mark[front+1];}
   void graphic1();
   void graphic2();
   void graphicdel1();
   void graphicdel2();
   void graphiccancel();

   void sg1();
   void sg2();


};

bool queue::add(const int& x){
	if (isfull()) return false;
   queue[++rear]=x;
   mark[rear]=true;
   return true;
}

int* queue::delet(int& x){
	if (isempty()) return 0;
   x=queue[++front];
   mark[front]=false;
   return &x;
}

void queue::printqueue(){
for(int i=front+1; i <= rear; i++){
cout << queue[i];
cout << endl;}
}
void queue::graphic1(){
char b=27;
char a=255;
for(int i=0;i<maxsize-(rear-front); i++){
gotoxy(58-i,24);
cout << b;
for (int j=0;j<199999999;j++);
gotoxy(58-i,24);
cout << a;
gotoxy(58-i-1,24);
cout << b <<"\a";
}
sg1();
}
void queue::graphic2(){
char b=26;
char a=255;
for(int i=0;i<maxsize-(rear-front); i++){
gotoxy(44+i,24);
cout << b;
for (int j=0;j<199999999;j++);
gotoxy(44+i,24);
cout << a;
gotoxy(44+i+1,24);
cout << b <<"\a";
}
sg2();
}
void queue::graphicdel1(){
char a=255;
char b=27;
gotoxy(52,24);
cout << b;
for (int j=0;j<199999999;j++);
gotoxy(52,24);
cout << a;
gotoxy(52-1,24);
cout << b <<"\a";
}
void queue::graphicdel2(){
char a=255;
char b=26;
gotoxy(50,24);
cout << b;
for (int j=0;j<199999999;j++);
gotoxy(50,24);
cout << a;
gotoxy(50+1,24);
cout << b <<"\a";
}
void queue::graphiccancel(){
char b=25;
char a=255;
for(int i=0;i<3; i++){
gotoxy(51,24+i);
cout << b;
for (int j=0;j<199999999;j++);
gotoxy(51,24+i);
cout << a;
gotoxy(51,24+i+1);
cout << b <<"\a";
}
}
void queue::sg1(){
char b=27;
for(int i=0; i<=(rear-front)-1; i++){gotoxy(52+i,24);
cout << b;}
}
void queue::sg2(){
char b=26;
for(int i=0;i>=(front-rear)+1; i--){gotoxy(50+i,24);
cout << b;}
}
//*******************************
class stack{
  private:
	int top;
   int *stack;
   int maxsize;
  public:
  	stack(int maxstacksize):maxsize(maxstacksize){
   	stack=new int[maxsize];
      top = -1;
   }
   bool isfull(){
   	if(top==maxsize-1) return true;
      else return false;
	}

   bool isempty(){
   	if(top==-1) return true;
      else return false;
   }
   bool add(const int& x);
   int* delet(int&);
   void printstack();
   void graphic1();
   void graphic2();
   void graphicdel1();
   void graphicdel2();
   void sg1();
   void sg2();

};


bool stack::add(const int& x){
	if (isfull()) return false;
   stack[++top]=x;
   return true;
}

int* stack::delet(int& x){
if(isempty()) return 0;
x=stack[top--];
return &x;
}

void stack::printstack(){
for(int i=top; i > -1; i--){
cout << stack[i];
cout << endl;
}

}

void stack::graphic1(){
char b=26;
char a=255;
for(int i=0;i<maxsize-top; i++){
gotoxy(51+i,13);
cout << b;
for (int j=0;j<199999999;j++);
gotoxy(51+i,13);
cout << a;
gotoxy(51+i+1,13);
cout << b <<"\a";
}
}

void stack::graphic2(){
char b=27;
char a=255;
for(int i=0;i<maxsize-top; i++){
gotoxy(51-i,13);
cout << b;
for (int j=0;j<199999999;j++);
gotoxy(51-i,13);
cout << a;
gotoxy(51-i-1,13);
cout << b <<"\a";
}
}

void stack::graphicdel1(){
char b=27;
char a=255;
for(int i=top+1;i<maxsize; i++){
gotoxy(56-i,13);
cout << b;
for (int j=0;j<199999999;j++);
gotoxy(56-i,13);
cout << a;
gotoxy(56-i-1,13);
cout << b <<"\a";
}
}
void stack::graphicdel2(){
char b=26;
char a=255;
for(int i=top+1;i<maxsize; i++){
gotoxy(46+i,13);
cout << b;
for (int j=0;j<199999999;j++);
gotoxy(46+i,13);
cout << a;
gotoxy(46+i+1,13);
cout << b <<"\a";
}
}

void stack::sg1(){
for(int i=0; i<=top; i++){gotoxy(56-i,13);
cout << "x";}
}

void stack::sg2(){
for(int i=0;i<=top; i++){gotoxy(46+i,13);
cout << "x";}
}

//************************************
class deque{
	private:
   	int front,rear;
      int *deque;
      int maxsize;

   public:
   	deque(int maxdequesize):maxsize(maxdequesize){
   		deque = new int[maxsize];
     	 	rear = front = maxsize;
   	}
      bool isfull(){
   	if(rear==0) return true;
      else return false;
	}

   bool isempty(){
   	if(front==rear) return true;
      else return false;
   }

      int avail(){return (front-rear);}
   	bool addl(const int& x);//queue
      bool addr(const int& x);//stack
   	int* delet(int&);
   	void printdeque();
      void graphic();
      void graphicaddr();
      void graphicdel();
      void graphicout();
      void graphicrearrange();
      void sg();

      void rearrange(){
      for(int i=(maxsize-1);i>rear;i--){
      deque[i]=deque[i-1];
      }
		rear++;
      front++;
      }


};

bool deque::addl(const int& x){
	if (isfull()) return false;
   deque[--rear]=x;
   return true;
}
bool deque::addr(const int& x){
   deque[front++]=x;
   return true;
}

int* deque::delet(int& x){
if(isempty()) return 0;
 x=deque[--front];
 return &x;
}

void deque::printdeque(){
for(int i=front-1; i >= rear; i--){
cout << deque[i];
cout << endl;
}
}

void deque::graphic(){
char b=24;
char a=255;
for(int i=0;i<maxsize-(front-rear)+1; i++){
gotoxy(51,24-i);
cout << b;
for (int j=0;j<199999999;j++);
gotoxy(51,24-i);
cout << a;
gotoxy(51,24-i-1);
cout << b <<"\a";
}
}

void deque::graphicdel(){
char b=24;
char a=255;
for(int i=23-front;i>13; i--){
gotoxy(51,i);
cout << b;
for (int j=0;j<199999999;j++);
gotoxy(51,i);
cout << a;
gotoxy(51,i-1);
cout << b <<"\a";
}

}

void deque::graphicout(){
char b=24;
char a=255;
for(int i=0;i<3; i++){
gotoxy(51,13-i);
cout << b;
for (int j=0;j<199999999;j++);
gotoxy(51,13-i);
cout << a;
gotoxy(51,13-i-1);
cout << b <<"\a";
}
}

void deque::graphicaddr(){
char b=25;
char a=255;
for(int i=0;i<(maxsize-front+1); i++){
gotoxy(51,13+i);
cout << b;
for (int j=0;j<199999999;j++);
gotoxy(51,13+i);
cout << a;
gotoxy(51,13+i+1);
cout << b <<"\a";
}
}

void deque::graphicrearrange(){
char b=24;
char a=255;
for(int i=0;i<(front-rear); i++){
for(int z=0;z<1;z++){
gotoxy(51,15-z+i);
cout << b;
for (int j=0;j<199999999;j++);
gotoxy(51,15-z+i);
cout << a;
gotoxy(51,15-z-1+i);
cout << b <<"\a";
}}
}

void deque::sg(){
for(int i=0;i<avail(); i++){gotoxy(51,14+i);
cout << "x";}
}


//************MAIN*********************
queue q1(7);queue q2(7);stack s1(5);stack s2(5);deque de(10);

int main()
{
int j;
for(;;) {
	clrscr();
	j = menu();
	switch (j) {
		case 1:
         addright();
			break;
		case 2:
         addleft();
			break;
		case 3:
         cancel();
			break;
		case 4:
         delcar();
			break;
		case 5:
      clrscr();
      	cout << "\nProgrammer : Navid Shamsizadeh\n ";
			cout << "*********************************************Press Any Key To Exit ...";
			getch();
			exit(0);
         break;
      case 6:
         printparkingtext();
         break;
		default:
			cout << "Out Of Range";
			getch();
			break;
				  }
		  }
}




//*****Global-Functions-Define**************

int menu()
{
	int z;

   char a=186;
   char b=187;
   char c=201;
   char d=188;
   char e=200;
   char f=205;
   char m=220;
   char o=177;
   char p=223;

   char j=255;

   gotoxy(40,1);
   cout <<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m<<m;
   gotoxy(40,2);
	cout << j <<"1) Add From Right(Queue 1).           "<<o;
	gotoxy(40,3);
	cout << j <<"2) Add From Left(Queue 2).            "<<o;
	gotoxy(40,4);
	cout << j <<"3) Cancel A Car From Queues.          "<<o;
	gotoxy(40,5);
	cout << j <<"4) Delete A Car From The Main Parking."<<o;
	gotoxy(40,6);
	cout << j <<"5) Quit Program.    6)Print Parking   "<<o;
   gotoxy(40,7);
   cout <<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p<<p;

gotoxy(38,10);cout << "            Exit             ";
gotoxy(38,11);cout << "                             ";
gotoxy(38,12);cout << "       "<<c<<f<<f<<f<<f<<d<<j<<e<<f<<f<<f<<f<<b<<"         ";
gotoxy(38,13);cout << "   S2  "<<a<<"           "<<a<<"    Street1";
gotoxy(38,14);cout << "       "<<e<<f<<f<<f<<f<<b<<j<<c<<f<<f<<f<<f<<d<<"         ";
gotoxy(38,15);cout << "            "<<a<<j<<a<<"              ";
gotoxy(38,16);cout << "            "<<a<<j<<a<<"              ";
gotoxy(38,17);cout << "            "<<a<<j<<a<<"              ";
gotoxy(38,18);cout << "            "<<a<<j<<a<<"  Main Parking";
gotoxy(38,19);cout << "            "<<a<<j<<a<<"              ";
gotoxy(38,20);cout << "            "<<a<<j<<a<<"              ";
gotoxy(38,21);cout << "            "<<a<<j<<a<<"              ";
gotoxy(38,22);cout << "            "<<a<<j<<a<<"              ";
gotoxy(38,23);cout << "      "<<f<<f<<f<<f<<f<<f<<d<<j<<e<<f<<f<<f<<f<<f<<f<<"        ";
gotoxy(38,24);cout << "  Q2                   Queue1";
gotoxy(38,25);cout << "      "<<f<<f<<f<<f<<f<<f<<b<<j<<c<<f<<f<<f<<f<<f<<f<<"        ";
gotoxy(38,26);cout << "                             ";
gotoxy(38,27);cout << "       Out(Canceling)        ";

      printparking();
      gotoxy(1, 1);
		cout << "Please Enter Your Choice ...(1-6): ";
		z=getch()-48;
      cout << endl;

return z;
}



//*************************************
int addright(){
int n,x;
cout << "Enter Car's Number : ";
cin >> n;
if (!q1.add(n)) {cout << "Queue 1 is Full.\n";}
if (!de.addl(n)){cout << "You Have To wait.\n";q1.graphic1();getch();}
else{q1.delet(x);q1.graphic1();de.graphic();getch();}
return 0;
}
//*************************************
int addleft(){
int n,x;
cout << "Enter Car's Number : ";
cin >> n;
if (!q2.add(n)) {cout << "Queue 2 is Full.\n";}
if (!de.addl(n)){cout << "You Have To wait.\n";q2.graphic2();getch();}
else{q2.delet(x);q2.graphic2();de.graphic();getch();}
return 0;
}
//***************************************************
int cancel(){
   if(q1.isempty()&&q2.isempty()){
   	cout << "There is Car To Cancel...";getch();return 0;}
   	cout << "From Which Queue do you want to\n cancel the car? (1 OR 2)? ";
      int sel;
      cin >> sel;
      if(sel==1){
			if(q1.isempty()){cout << "There is Car To Cancel...";getch();return 0;}
         cout << "Left one ( 1 ) to Right one ( " << q1.avail() << " ): ";
   		int n;cin >> n;
         q1.canceling(n);
         for(int i=1;i<=q1.avail();i++){outq1();}
      return 0;}
      if(sel==2){
         if(q2.isempty()){cout << "There is Car To Cancel...";getch();return 0;}
         cout << "Right one ( 1 ) to Left one ( " << q2.avail() << " ): ";
   		int n;cin >> n;
         q2.canceling(n);
         for(int i=1;i<=q2.avail();i++){outq2();}
      return 0;}
      cout << "You Have Entered A Wrong Choice ...";
      getch();
	return 0;
}
//********************************************
int delcar(){
int x;
   if (de.isempty()) {cout << "There is No Car to Delete...";getch();return 0;}
   else{
   cout << "Which Car Do You want to Delete\nFrom The Main Parking\n";
   cout << "Upper one ( 1 ) to Lower one ( " << de.avail() << " ): ";
   int n;cin >> n;
   if(n>=2&&n<=6&&n<=de.avail()){
   	for (int i=1;i<=n-1;i++){
      	s1.add(*de.delet(x));
         de.graphicdel();s1.graphic1();
         }//endfor
         de.delet(x);
         de.graphicdel();
         de.graphicout();

      for (int i=1;i<=n-1;i++){
      	de.addr(*s1.delet(x));
         s1.graphicdel1();
         de.graphicaddr();
      }//endfor
		de.rearrange();
      de.graphicrearrange();
         if(!q1.isempty()){if(de.isfull()){cout << "Error.\n";}else{de.addl(*q1.delet(x));q1.graphicdel1();de.graphic();printparking();}}
         if(!q2.isempty()){if(de.isfull()){cout << "Error.\n";}else{de.addl(*q2.delet(x));q2.graphicdel2();de.graphic();printparking();}}
         for(int i=1;i<=q1.avail();i++){outq1();}for(int i=1;i<=q2.avail();i++){outq2();}

      printparking();
      return 0;
                 }

   if(n>6&&n<=10&&n<=de.avail()){
   	for (int i=1;i<=5;i++){
      	s1.add(*de.delet(x));
         de.graphicdel();s1.graphic1();
         }//endfor

         for (int i=6;i<=n-1;i++){
      		s2.add(*de.delet(x));
            de.graphicdel();s2.graphic2();
            }//endfor

            de.delet(x);
            de.graphicdel();
            de.graphicout();

      for (int i=6;i<=n-1;i++){
      	de.addr(*s2.delet(x));
         s2.graphicdel2();
         de.graphicaddr();
      }//endfor

      for (int i=1;i<=5;i++){
      	de.addr(*s1.delet(x));
         s1.graphicdel1();
         de.graphicaddr();
      }//endfor

      de.rearrange();
      de.graphicrearrange();

      if(!q1.isempty()){if(de.isfull()){cout << "Error.\n";}else{de.addl(*q1.delet(x));q1.graphicdel1();de.graphic();printparking();}}
      if(!q2.isempty()){if(de.isfull()){cout << "Error.\n";}else{de.addl(*q2.delet(x));q2.graphicdel2();de.graphic();printparking();}}
      for(int i=1;i<=q1.avail();i++){outq1();}for(int i=1;i<=q2.avail();i++){outq2();}
      printparking();
   return 0;}

   if(n==1&&n<=de.avail()){
   		de.delet(x);
         de.graphicdel();
         de.graphicout();
         de.rearrange();
			de.graphicrearrange();
         if(!q1.isempty()){if(de.isfull()){cout << "Error.\n";}else{de.addl(*q1.delet(x));q1.graphicdel1();de.graphic();printparking();}}
         if(!q2.isempty()){if(de.isfull()){cout << "Error.\n";}else{de.addl(*q2.delet(x));q2.graphicdel2();de.graphic();printparking();}}
         for(int i=1;i<=q1.avail();i++){outq1();}for(int i=1;i<=q2.avail();i++){outq2();}

   		printparking();return 0;}
   cout << "You've Entered unexisted Car.";getch();
   	 }//endelse

	return 0;
}
//**************************************************
void printparkingtext(){
cout << "Queue 1:\n";
			q1.printqueue();
cout << "Queue 2:\n";
			q2.printqueue();
cout << "Main Parking:\n";
         de.printdeque();
cout << "Street 1:\n";
         s1.printstack();
cout << "Street 2:\n";
         s2.printstack();
         cout << endl;
         printparking();
         getch();}
//**************************************************
void printparking(){
			q1.sg1();
         q2.sg2();
         de.sg();
         s1.sg1();
         s2.sg2();
         }
//*****************************************************
void outq1(){
int x;
	if(q1.checkcancel()==false){q1.delet(x);q1.graphicdel1();q1.graphiccancel();}

}
void outq2(){
int x;
   if(q2.checkcancel()==false){q2.delet(x);q2.graphicdel2();q2.graphiccancel();}
}







