/**
* @file G181210056_ÞuleAktaþ_1A
* @description Veri Yapýlarý Final Ödevi
* @course 1A
* @assignment Ödev 2
* @date Kodu 25-08-2020
* @author Þule Aktaþ
*/
#include"Dosya.hpp"

Dosya::Dosya()
{
	satir_sayisi = dosya_satir_sayisi();
}

int Dosya:: dosya_satir_sayisi()
{
	ifstream dosyaOku;
	dosyaOku.open("kisiler.txt");
	int satir_sayisi = 0;
	string satir;
	if (dosyaOku.is_open()) {

		while (!dosyaOku.eof()) {
			getline(dosyaOku, satir, '\n');
			satir_sayisi++;
		}


	}
	dosyaOku.close();

	return satir_sayisi;
}
string* Dosya:: dosyayi_diziye_atma()
{
	string *satir = new string[satir_sayisi];
	ifstream dosyaOku;
	dosyaOku.open("kisiler.txt");
	int satir_sayisi = 0;

	if (dosyaOku.is_open())
	{
		int i = 0;
		while (!dosyaOku.eof())
		{
			getline(dosyaOku, satir[i], '\n');
			i++;
		}

	}
	dosyaOku.close();

	return satir;
}

Kisi* Dosya::DiziyiAyirma()
{
	Kisi *kisiler = new Kisi[satir_sayisi];
	string *satir = new string[satir_sayisi];
	satir = dosyayi_diziye_atma();

	int x = 0;
	int diyez_sayisi = 0;

	for (int i = 0;i < (satir + x)->length() + 1;i++)
	{

		if (satir[x][i] == '#')
		{
			if (diyez_sayisi == 0)
			{
				(kisiler + x)->isim = (satir + x)->substr(0, i);

				(satir + x)->erase(0, i + 1);//Diyezleri silmek için +1
				i = 0;
				diyez_sayisi++;
			}
			else if (diyez_sayisi == 1)
			{
				(kisiler + x)->dogum_yili = stoi((satir + x)->substr(0, i));
				(satir + x)->erase(0, i + 1);//Diyezleri silmek için +1
				i = 0;
				diyez_sayisi = 0;

			}
		}

		if (satir[x][i] == '\0')
		{
			(kisiler + x)->kilo = stoi((satir + x)->substr(0, i));
			(satir + x)->erase(0, i + 1);//Diyezleri silmek için +1
			i = 0;
			x++;
			if (x == dosya_satir_sayisi())
				break;

		}
	}

	for (int i = satir_sayisi - 1;i >= 0;i--)
	{
		delete (satir + i);
	}

	return kisiler;

}