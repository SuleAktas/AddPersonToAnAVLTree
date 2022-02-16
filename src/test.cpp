/**
* @file G181210056_ÞuleAktaþ_1A
* @description Veri Yapýlarý Final Ödevi
* @course 1A
* @assignment Ödev 2
* @date Kodu 25-08-2020
* @author Þule Aktaþ
*/
#include"AVLTree.hpp"
#include"Dosya.hpp"
#include<iostream>
using namespace std;



int main(){

	
	Dosya *dosya = new Dosya();

	Kisi *kisiler = new Kisi[dosya->satir_sayisi];

	kisiler = dosya->DiziyiAyirma();

	AVLTree *agac = new AVLTree();
	
	for (int i = 0;i < dosya->satir_sayisi;i++)
	{
		agac->Ekle(*(kisiler+i));
	}
	
	
	
	cout<<endl<<"Postorder "<<endl;
	agac->Postorder();
	cout<<endl<<endl;	


	
	
	delete agac;
	for(int i=dosya->satir_sayisi-1;i>=0;i--)
		delete (kisiler+i);
	delete dosya;
	return 0;
}