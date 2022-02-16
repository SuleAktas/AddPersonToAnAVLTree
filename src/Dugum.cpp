/**
* @file G181210056_ÞuleAktaþ_1A
* @description Veri Yapýlarý Final Ödevi
* @course 1A
* @assignment Ödev 2
* @date Kodu 25-08-2020
* @author Þule Aktaþ
*/
#include"Dugum.hpp"

Dugum::Dugum(const Kisi& vr, Dugum *sl, Dugum *sg) {
	kisi_oz = vr;
	sol = sl;
	sag = sg;
	yukseklik = 0;
	onceki_seviye = -1;

}

Dugum::Dugum(const Kisi& vr)
{
	sol = NULL;
	sag = NULL;
	kisi_oz = vr;
	yukseklik = 0;
	onceki_seviye = -1;
}