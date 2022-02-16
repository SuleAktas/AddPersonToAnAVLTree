#ifndef DUGUM_HPP
#define DUGUM_HPP
#include"Kisi.hpp"
#include"Stack.hpp"
struct Dugum {
	Kisi kisi_oz;

	Stack yigit;

	Dugum *sol;

	Dugum *sag;

	int onceki_seviye;

	int yukseklik;

	Dugum(const Kisi& vr, Dugum *sl, Dugum *sg);

	Dugum(const Kisi& vr);
	
	
};
#endif