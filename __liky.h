#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

struct pracivnyk	
{ 	
	char name[30];
	char posada;
};

FILE * f;
char name_of_file[30];

void local()
{
	setlocale(LC_ALL,"");
}	

void filecon()
{
	local();	
	cout<<"Введiть назву файлу для пiдключення\nФайл повинен бути в кореневiй папцi\nЯкщо такого файлу нема буде створено новий\nНазва файлу для пiдключення:";
	cin>>name_of_file;
	if ((f=fopen(name_of_file,"rb+"))==NULL)
 	{
 	if ((f=fopen(name_of_file,"wb+"))==NULL)
 	{
 		cout<<"Пiд час пiдключення сталася помилка"<<endl;
	}
		cout<<"Оскiльки такого файлу не було, створено новий"<<endl;
 	}
}

void input()
{
	local();
	fseek(f,0,SEEK_END);
	struct pracivnyk a;	
	cout<<"ПІБ:";
	cin>>a.imya;getchar();
	cout<<"Посада:"; 
	gets(a.posada);
	fwrite(&a,sizeof(a),1,f);
	cout<<endl;
}


void print(struct liky a)
{
	local();
	cout<<"ПІБ:"<<a.imya<<endl;
	cout<<"Посада:"<<a.posada<<endl;

	cout<<endl;
}

void show()
{
	local();
 struct pracivnyk a;
 int k,r;
 	k=0;
	fseek(f,0,0);
	while (!feof(f))
	{
		
		r=fread(&a,sizeof(a),1,f);
		if (r<1) break;
		print(a);
		k++;
	}
	cout<<endl<<"Знайдено "<<k<<" працівників"<<endl<<endl;
}
 void search()
{
	local();
	char vyr[30];
	struct liky a;
	int k,r;
 	k=0;
	cout<<"Виробник препарату :"; 
	gets(vyr);
	fseek(f,0,0);
	while (!feof(f))
	{
		r=fread(&a,sizeof(a),1,f);
		if (r<1) break;
		if (a.vyrobnyk==vyr)
		{
			print(a);
			k++;
		}
	}
	if (k==0) cout<<"Не знайдено препаратiв"<<endl;
	else cout<<endl<<"Знайдено "<<k<<" препаратiв"<<endl<<endl;
}

void search_vag()
{
	local();
	char vyr[30];
	int vag;
	liky a;
	int k,r;
 	k=0;
	cout<<"Виробник :";
	cin>>vyr;
	cout<<"Вага     :";
	cin>>vag;
	cout<<endl;
	fseek(f,0,0);
	while (!feof(f))
	{
		r=fread(&a,sizeof(a),1,f);
		if (r<1) break;
		if (vyr==a.vyrobnyk)
		if (vag==a.vaga)
		{
			print(a);
			k++;
		}
	}
	if (k==0) cout<<"Не знайдено препаратiв"<<endl;
	else cout<<endl<<"Знайдено "<<k<<" препаратiв"<<endl<<endl;
}
 
void clear()
{
	local();
	fclose(f);
	if ((f=fopen(name_of_file,"wb+"))==NULL)
 	{
 		cout<<"Пiд час очистки сталася помилка"<<endl;
	}
}

void redag()
{
	liky a;
	int x,z,vag;
	char naz[30], vyr[30],name_buf[30];
		show();
	cout << "Введiть назву препарата для редагування : ";
	gets(name_buf);
	fseek(f,0,SEEK_SET);
	while (!feof(f))
	{
		if (strcmp(a.name,name_buf)==0)
		        {
			    lab1:	
			    cout << "Що потрiбно замiнити?\n\n1 - Кiлькiсть препарату\n2 - Назву препарату\n3 - Виробника препарату\n4 - Вагу препарату\n5 - Знищити записанi данi\n6 - Вихiд\n";
				cin >> z;
				switch (z){
				case 1: cout << "Кiлькiсть препарату :"; cin>>x; a.kilkist=x; break;
				case 2: cout << "Назва препарату     :"; cin>>naz; strcpy(a.name, naz);break;				
				case 3: cout << "Виробник препарату  :"; cin>>vyr; strcpy(a.vyrobnyk, vyr); break;
				case 4: cout << "Вага препарату      :"; cin>>vag; a.vaga=vag; break;
				case 5: cout << "Данi знищено"; strcpy(a.name,"........");strcpy(a.vyrobnyk,"........");a.kilkist=0;a.vaga=0; break;
				case 6: goto lab2;
				}
                goto lab1;
                lab2:z = ftell(f);
                fseek(f, z - sizeof(liky), 0);
                fwrite(&a, sizeof(liky), 1, f);
                fseek(f, sizeof(liky), SEEK_CUR);
		        }	
		fread(&a, sizeof(liky), 1, f);
	}
	}
	

