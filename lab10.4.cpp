#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void CreateTXT(char* fname) // створення файлу з введених рядків
{
	ofstream fout(fname); 
	char ch; 
	string s; 
	int k=0;
	do
	{
		cin.get(); 
		cin.sync(); 
		cout << "enter line: "; getline(cin, s); 
		fout << s << endl; 
		k++;
	} while (k < 0);
	cout << endl;
}
void CreateTXT2(char* fname,char* gname, int l) // створення файлу з введених рядків
{
	ofstream gout(gname);
	
	string s,in, z = "";;
	int k;
	do
	{
		k = 0;
		ifstream fin(fname);
		while (getline(fin, s)) 
		{
			if (s <= z) // якщо цей рядок вже записаний у файл g
				continue;
			in = s;
			k++;
		}
		z = in;
		if (k > 0) { // якщо були знайдені ще не записані
			
			if (l == 1)
				gout << z << "-" << "No Triangle" << endl;
			if (l == 2)
				gout << z << "-" << "Obtuse Triangle" << endl;
			if (l == 3)
				gout << z << "-" << "Acute Triangle" << endl;
			if (l == 4)
				gout << z << "-" << "Right Triangle" << endl;
		}
		fin.close();
		
	} while (k > 0);
	
}
void PrintTXT(char* fname) 
{
	ifstream fin(fname); 
	string s; 
	while (getline(fin, s)) 
	{
		cout << s << endl; 
	}
	cout << endl;
}
void PrintTXT2(char* fname, int l)
{
	ifstream fin(fname);
	string s;
	while (getline(fin, s))
	{
		if (l == 1)
			cout << s << "-"  << endl;
		if (l == 2)
			cout << s << "-" << endl;
		if (l == 3)
			cout << s << "-" << endl;
		if (l == 4)
			cout << s << "-" << endl;
	}
	cout << endl;
}

int ProcessTXT(char* fname) // обчислення кількості слів,
{ // відокремлених пробілами та знаками пунктуації
	ifstream fin(fname); // відкрили файл для зчитування
	char s[100]; // прочитаний рядок
	char* w; // виокремлене з рядка слово
	int k = 0; // кількість слів
	int l = 0;
	int h,a,b,c;
	while (fin.getline(s, sizeof(s))) // поки можна прочитати рядок
	{
		w = strtok(s, " .,:;!?-'"); // початок циклу виокремлення слів
	
		while (w != NULL) // поки можна виокремити слово
		{
			k++; // збільшуємо лічильник слів
			if (k == 1) {
				a = atoi(w);
				cout <<  "a: " << a << endl;
				w = strtok(NULL, " .,:;!?-'"); // виокремлюємо наступне слово
			}
			if(k == 2) {
				b = atoi(w);
				cout << "b: " << b << endl;
				w = strtok(NULL, " .,:;!?-'"); // виокремлюємо наступне слово
			}
			if (k == 3) {
				c = atoi(w);
				cout << "c: " << c << endl;
				w = strtok(NULL, " .,:;!?-'"); // виокремлюємо наступне слово
			}
		}
		h = b * b + c * c;
		if (a >= b + c) {
			l = l + 1;
			//cout << "No Triangle" << endl;
		}
		else if (h < a * a) {
			l = l + 2;
			//cout << "Obtuse Triangle" << endl;
		}
		else if (h > a * a) {
			l = l + 3;
			//cout << "Acute Triangle" << endl;
		}
		else {
			l = l + 4;
			//cout << "Right Triangle" << endl;
		}

		
	}
	return l;
}

int main()
{
	// text files
	char fname[100]; // ім'я першого файлу
	cout << "enter file name 1: "; cin >> fname;
	CreateTXT(fname); // ввели рядки файлу з клавіатури
	PrintTXT(fname); // вивели вміст першого файлу на екран
	ProcessTXT(fname) ;
	char gname[100]; // ім'я другого файлу
	cout << "enter file name 2: "; cin >> gname;
	int l;
	l = ProcessTXT(fname);
	CreateTXT2(fname, gname, l);
	PrintTXT2(gname, l); // вивели вміст другого файлу на екран
	return 0;
}