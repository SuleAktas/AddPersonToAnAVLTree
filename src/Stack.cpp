/**
* @file G181210056_�uleAkta�_1A
* @description Veri Yap�lar� Final �devi
* @course 1A
* @assignment �dev 2
* @date Kodu 25-08-2020
* @author �ule Akta�
*/
#include"Stack.hpp"

bool Stack:: dolumu() {
	return elemanSayisi == kapasite;
}
void Stack:: yerAc(int boyut)
{
	char *tmp = new char[boyut];
	for (int j = 0;j<elemanSayisi;j++) tmp[j] = elemanlar[j];
	if (elemanlar != NULL)
		delete[] elemanlar;
	elemanlar = tmp;
	kapasite = boyut;
}
Stack::Stack() {
	elemanlar = NULL;
	stackBasi = -1;
	elemanSayisi = 0;
	kapasite = 0;
}
bool Stack:: isEmpty() const {
	return stackBasi == -1;
}
void Stack:: push(const char &eleman) {
	if (dolumu()) {
		yerAc(max(1, 2 * kapasite));
	}
	stackBasi++;
	elemanlar[stackBasi] = eleman;
	elemanSayisi++;
}
void Stack:: pop() throw(ElemanYok) {
	if (isEmpty()) throw ElemanYok("Eleman yok"); // Stack bo�ken pop metodu �a�r�lamaz
	cout << " " << elemanlar[stackBasi] << " ";
	stackBasi--;
	elemanSayisi--;
}
void Stack::Pop_Elemanlari_Goster()
{
	if (isEmpty())
		throw ElemanYok("Eleman yok");
	else
	{
		int sayi;
		sayi = elemanSayisi;
		for (int i = 0; i <sayi; i++)
		{
			pop();
		}
	}
}
const char & Stack::top()const throw(ElemanYok) {
	if (isEmpty()) throw ElemanYok("Eleman yok"); // Stack bo�ken top metodu �a�r�lamaz
	return elemanlar[stackBasi];
}
void Stack:: makeEmpty() { // stack'i ilk haline �evirir
	stackBasi = -1;
	elemanSayisi = 0;
}
Stack::~Stack() {
	if (elemanlar != NULL) delete[] elemanlar;
	elemanlar = NULL;
}