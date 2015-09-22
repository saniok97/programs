#include <iostream>
#include "__mobiletel.h"
using namespace std;



int main() 
{ 
	
	char x;
	filecon();
	local();
 	do
 	{
 		cout<<"1.Ввiд данних\n2.Показати всi данi\n3.Пошук працівників\n4.Очистка бази\n5.Редагувати данi\n";
 		x=getch();
 		switch(x)
 		{
		case '8': fclose(f); return 0;
 		case '1': cout<<endl;input();cout<<endl;break;
		case '2': cout<<endl;show(); cout<<endl;break;
      	case '3': cout<<endl;search();cout<<endl; break;
      	case '4': cout<<endl;clear(); cout<<endl;break;
		case '5': cout<<endl;redag();cout<<endl;break;
      	case '6': cout<<endl;filecon();cout<<endl; break;
 	 	}
 	 	
 	} while (1);	
}

