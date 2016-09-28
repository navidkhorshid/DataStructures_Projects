//<Upper Triangle Matrix><Project 1>
//Programmers :   Navid Shamsizadeh (870134089)
//Professor : Mrs. Roia Rad
//////////////////////////////////////////////
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
//****Global Variables & Functions**********
int menu();
void enter();
void edit();
void read();
void print();
void add();
void addo();
void equal();
int m;
//********Class Matrix**********************
class matrix{
 	private:
		int *p;
      bool *p2;
      int size;

   public:
      matrix() {
      	cout << "Enter The Size Of Your Matrix [M]*[M]" ;
			cout << "\nM: ";
			cin >> m;
         size = ((((m-1)*(m))/2)+m);
         p = new int[size];
         p2 = new bool[size];

         for (int k=0; k < size; k++){
         p[k]=0;
         p2[k]=false;              }
                          }
      matrix(int b) {
         size = ((((b-1)*(b))/2)+b);
         p = new int[size];
         p2 = new bool[size];

         for (int k=0; k < size; k++){
         p[k]=0;
         p2[k]=false;              }
                          }

      void eenter(int i, int j, int g)  {
			p[(((j*(j+1))/2) + i)] = g;
   		p2[(((j*(j+1))/2) + i)] = true;}
      int rread(int x, int y){return p[( ((y*(y+1))/2)+x )];}
      bool check(int a,int b){return p2[((((b-1)*(b))/2)+ (a-1))];}
      void aadd();
      bool eequal();
      };

      matrix mat;
      matrix b(m);

//******Main************************
int main()
{

int j;

for(;;) {
	clrscr();
	j = menu();
	switch (j) {
		case 1:
			enter();
			break;
		case 2:
         edit();
			break;
		case 3:
         read();
			break;
		case 4:
         print();
			break;
		case 5:
         add();
			break;
		case 6:
         equal();
			break;
		case 7:
         addo();
		   break;
		case 8:
      	cout << "\nProgrammers : Navid Shamsizadeh\n";
         cout << "              Mahmood Reza Rasayi\n";
         cout << "              Soroush Shahreza\n\n";
			cout << "*********************************************Press Any Key To Exit ...";
			getch();
			exit(0);
		default:
			cout << "Out Of Range";
			cout << "\nClose The Program ...";
			getch();
			break;
				  }
		  }
}




//*****Global-Functions-Define**************

int menu()
{
	int z;
	gotoxy(1,4);
	cout << "****************************<<*Matrix*>>****************************\n";
	cout << "*                                                                  *\n";
	cout << "*                                                                  *\n";
	cout << "*                                                                  *\n";
	cout << "*                                                                  *\n";
	cout << "*                                                                  *\n";
	cout << "*                                                                  *\n";
	cout << "*                                                                  *\n";
	cout << "*                                                                  *\n";
	cout << "********************************************************************";
	gotoxy(5, 5);
	cout << "1) Enter New Matrix.";
	gotoxy(7, 6);
	cout << "2) Edit Matrix.";
	gotoxy(9, 7);
	cout << "3) Read Matrix.";
	gotoxy(11, 8);
	cout << "4) Print Matrix.";
	gotoxy(13, 9);
	cout << "5) Add with.";
	gotoxy(15, 10);
	cout << "6) Check Equality.";
	gotoxy(17, 11);
	cout << "7) Sum Of Main Diameter's Elements.";
	gotoxy(19, 12);
	cout << "8) Exit !\n";

 do {
		gotoxy(5, 14);
		cout << "Please Enter Your Choice ... (1-8) : ";
		cin >> z;
	 } while (z < 1 && z > 8);

return z;
}


//+++++++++++++++++++++++++++++++++++++++++++
void enter(){
int get;

         clrscr();
          for (int z=1; z<=(2*m-1); z++)	{
      		gotoxy(1,z);
            cout << "|";
            gotoxy(((4*m)+1),z);
            cout << "|";

                                          }


         for(int y=0;y<m;y++)
         for(int x=0;x<m;x++){
            if(y>=x){
            gotoxy(2+(4*y),1+(2*x));
            cin >> get;
            mat.eenter(x,y,get);}
            else{ gotoxy(2+(4*y),1+(2*x));
            cout << "0";}
                             }

            }

//+++++++++++++++++++++++++++++++++++++++++++++++++++++
void edit(){
clrscr();
int x1,y1,g1;
cout << "Which Element Do You want to Edit ? ([1][1],...,[M][M]) : \n";
cout << "[  ],[  ]";
gotoxy(2,2);
cin >> x1;
gotoxy(7,2);
cin >> y1;
if (0<x1 && x1<=m && 0<y1 && y1<=m){
if(y1>=x1){
cout << "Enter Your New Quantity : ";
cin >> g1;
mat.eenter(x1-1,y1-1,g1);
}
else{
cout << "This Element is 0";}
												}else{
                                    cout << "Your Number is Out Of range.";
                                    	  }
getch();

}
//+++++++++++++++++++++++++++++++++++++++++++++++++++
void read() {
clrscr();
int x2,y2;
cout << "Which Element Do You want to Read ? ([1][1],...,[M][M]) : \n";
cout << "[  ],[  ]";
gotoxy(2,2);
cin >> x2;
gotoxy(7,2);
cin >> y2;
if (0<x2 && x2<=m && 0<y2 && y2<=m) {
if(mat.check(x2,y2) == true){
if(y2>=x2){
cout << "Element [" << x2 << " ][" << y2 << " ] = " << mat.rread(x2-1,y2-1);
          }else{
				cout << "Element [" << x2 << " ][" << y2 << " ] = " << "0";
               }
                            }else{
                            cout << "You Haven't Edit this element yet.";
											}	}else{
                                    cout << "Your Number is Out Of Range.";
                                         }
getch();
				}
//+++++++++++++++++++++++++++++++++++++++++++++++++++
void print(){
				clrscr();
          	for (int z=1; z<=(2*m-1); z++)	{
      		gotoxy(1,z);
            cout << "|";
            gotoxy(((4*m)+1),z);
            cout << "|";

                                          }
			for(int y=0;y<m;y++)
         	for(int x=0;x<m;x++){
            if(y>=x){
            gotoxy(2+(4*y),1+(2*x));
            cout << mat.rread(x,y);
                    }
            else{ gotoxy(2+(4*y),1+(2*x));
            cout << "0";}
                             }
getch();
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++
void addo(){
clrscr();
int sum;
for(int i=0;i<m;i++)
	for(int j=0;j<m;j++)
   	if(i==j)
      	sum = sum + mat.rread(i,j);
cout << "Sum Of Main Diameter = " << sum;
getch();
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++
void add(){
int get;

         	print();
            gotoxy((4*m+2),(m));
            cout << "+";
          for (int z=1; z<=(2*m-1); z++)	{
      		gotoxy((4*m+3),z);
            cout << "|";
            gotoxy((8*m+3),z);
            cout << "|";

                                          }
         for(int y=0;y<m;y++)
         for(int x=0;x<m;x++){
            if(y>=x){
            gotoxy((4*m+4)+(4*y),1+(2*x));
            cin >> get;
            b.eenter(x,y,get);}
            else{ gotoxy((4*m+4)+(4*y),1+(2*x));
            cout << "0";}
                             }
		mat.aadd();

            gotoxy((8*m+4),(m));
            cout << "=";
            for (int z=1; z<=(2*m-1); z++)	{
      			gotoxy((8*m+5),z);
            	cout << "|";
            	gotoxy((12*m+5),z);
            	cout << "|";

                                          }
			for(int y=0;y<m;y++)
         	for(int x=0;x<m;x++){
            if(y>=x){
            gotoxy((8*m+6)+(4*y),1+(2*x));
            cout << b.rread(x,y);
                    }
            else{ gotoxy((8*m+6)+(4*y),1+(2*x));
            cout << "0";}
                             }
getch();

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++
void equal(){
int get;

         clrscr();
          for (int z=1; z<=(2*m-1); z++)	{
      		gotoxy(1,z);
            cout << "|";
            gotoxy(((4*m)+1),z);
            cout << "|";

                                          }


         for(int y=0;y<m;y++)
         for(int x=0;x<m;x++){
            if(y>=x){
            gotoxy(2+(4*y),1+(2*x));
            cin >> get;
            b.eenter(x,y,get);}
            else{ gotoxy(2+(4*y),1+(2*x));
            cout << "0";}
                             }

			if(b.eequal()==true){
         cout << "\n\n     This Matrix Is Equal with the first one.";
                             }else{
         cout << "\n\n     This Matrix Is Not Equal with the first one.";
                                  }


getch();
}
//@@@@@@@@@@@@@@@Some-Class-Member-Functions@@@@@@@@@@@@@
void matrix::aadd(){
for(int i=0;i<size;i++){
if(b.p2[i]==p2[i]){
b.p[i]=p[i]+b.p[i];
b.p2[i]=p2[i];
						}else{b.p2[i]=false;}

                       }
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool matrix::eequal(){
	for(int z=0;z<size;z++){
   	if( (p2[z] != mat.p2[z]) || (p[z] != mat.p[z]) )
      	return false;
         					  }
return true;
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

