#ifndef DOSYA_HPP
#define DOSYA_HPP
#include<iostream>
#include<fstream>
#include<string>
#include"Kisi.hpp"
using namespace std;

class Dosya
{

public:
	int satir_sayisi;

	Dosya();

	int dosya_satir_sayisi();
	
	string* dosyayi_diziye_atma();
	
	Kisi* DiziyiAyirma();
	
};
#endif