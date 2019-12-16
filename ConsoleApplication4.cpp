// ConsoleApplication4.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>

using namespace std;

class queue
{
	int f;
	int r;
	int size;
	int *a;
	int p;
public:
	queue(int sayi) :size(sayi + 1)
	{
		a = new int[size];
		f = 0;
		r = 0;
		p = 0;

	};
	int say();
	void ekle(int);
	void listele();
	void getir();
};


void queue::ekle(int sayi)
{


	if (f == (r + 1) % (size))
	{
		cout << "Bos yer yok" << endl;

	}
	else
	{
		a[r] = sayi;
		r = (r + 1) % (size); p++;
	}
}

void queue::listele()
{
	int i, x = 1;
	for (i = f; i < p; i++, x++)
		cout << x << ".eleman" << a[i%size] << endl;
}

void queue::getir()
{
	if (f == r)
	{
		cout << "Kuyruk bos" << endl;
	}
	else
	{
		cout << "ilk eleman : " << a[f] << endl;
		a[f] = 0;
		f = (f + 1) % (size);
	}

}
int queue::say()
{
	if ((r - f) < 0)
		return -(r - f);
	else
		return r - f;
}


int main()
{
	char y;
	int x, a;
	cout << "kuyrugun boyutunu giriniz: " << endl;
	cin >> x;
	queue anil(x);




	while (1) {
		cout << "Eklemek    --> E" << endl << "Saymak     --> S " << endl << "Getirmek   --> G" << endl << "Listelemek --> L" << endl << "cikmak     --> C" << endl;
		cin >> y;
		if (y == 'C')break;
		switch (y) {

		case 'E':
		{ cout << "eklemek istediginiz sayiyi giriniz:";
		cin >> a;
		anil.ekle(a); }break;

		case'S': cout << "kuyrugun boyu --> " << anil.say() << endl; break;

		case'G': anil.getir(); break;

		case'L': anil.listele(); break;


		default: cout << "yanlis bir harf girdiniz."; break;

		}

	}

	system("PAUSE");
	return 0;
}


