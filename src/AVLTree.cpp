/**
* @file G181210056_ÞuleAktaþ_1A
* @description Veri Yapýlarý Final Ödevi
* @course 1A
* @assignment Ödev 2
* @date Kodu 25-08-2020
* @author Þule Aktaþ
*/
#include "AVLTree.hpp"

Dugum * AVLTree:: AraveEkle(Dugum *alt_Dugum, Kisi& yeni) {

	if (alt_Dugum == NULL)
	{
		alt_Dugum = new Dugum(yeni);

		if (Bosmu())
		{
			alt_Dugum->onceki_seviye = -1;

		}


	}
	else if (yeni.Yas() <= alt_Dugum->kisi_oz.Yas())
	{

		alt_Dugum->sol = AraveEkle(alt_Dugum->sol, yeni);

		if (Yukseklik(alt_Dugum->sol) - Yukseklik(alt_Dugum->sag) == 2)
		{

			// Sol Sol Durumu 

			if (yeni.Yas() <= alt_Dugum->sol->kisi_oz.Yas())
			{

				alt_Dugum = SolCocukIleDegistir(alt_Dugum);

			}

			else
			{ //Sað Sol Durumu

				alt_Dugum->sol = SagCocukIleDegistir(alt_Dugum->sol);
				alt_Dugum = SolCocukIleDegistir(alt_Dugum);

			}

		}

	}
	else if (yeni.Yas() > alt_Dugum->kisi_oz.Yas())
	{

		alt_Dugum->sag = AraveEkle(alt_Dugum->sag, yeni);

		if (Yukseklik(alt_Dugum->sag) - Yukseklik(alt_Dugum->sol) == 2) {
			// Sað Sað Durumu

			if (yeni.Yas() > alt_Dugum->sag->kisi_oz.Yas())
			{
				alt_Dugum = SagCocukIleDegistir(alt_Dugum);

			}


			else {// Sol Sað Durumu 

				alt_Dugum->sag = SolCocukIleDegistir(alt_Dugum->sag);
				alt_Dugum = SagCocukIleDegistir(alt_Dugum);



			}
		}
	}


	//Yüksekliði güncelle
	alt_Dugum->yukseklik = Yukseklik(alt_Dugum);

	return alt_Dugum;
}

Dugum * AVLTree:: SolCocukIleDegistir(Dugum * alt_Dugum)
{
	Dugum *tmp = alt_Dugum->sol;
	alt_Dugum->sol = tmp->sag;
	tmp->sag = alt_Dugum;

	// Yükseklikleri Güncelle 

	alt_Dugum->yukseklik = Yukseklik(alt_Dugum);
	tmp->yukseklik = max(Yukseklik(tmp->sol), alt_Dugum->yukseklik) + 1;
	return tmp;
}

Dugum * AVLTree:: SagCocukIleDegistir(Dugum *alt_Dugum)
{

	Dugum *tmp = alt_Dugum->sag;
	alt_Dugum->sag = tmp->sol;
	tmp->sol = alt_Dugum;

	// Yükseklikleri Güncelle
	alt_Dugum->yukseklik = Yukseklik(alt_Dugum);
	tmp->yukseklik = max(Yukseklik(tmp->sag), alt_Dugum->yukseklik) + 1;
	return tmp;
}

void AVLTree::Inorder(Dugum *alt_Dugum) const 
{
	if (alt_Dugum != NULL) {
		Inorder(alt_Dugum->sol);
		cout << alt_Dugum->kisi_oz.Yas() << " ";
		Inorder(alt_Dugum->sag);
	}
}

void AVLTree:: Preorder(Dugum *alt_Dugum) const 
{
	if (alt_Dugum != NULL) {
		cout << alt_Dugum->kisi_oz.Yas() << " ";
		Preorder(alt_Dugum->sol);
		Preorder(alt_Dugum->sag);
	}
}

void AVLTree::Tum_Elemanlari_Kontrol_Et(Dugum* alt_Dugum)
{
	if (alt_Dugum != NULL)
	{
		if (alt_Dugum->onceki_seviye == -1)
		{
			alt_Dugum->yigit.push('O');
		}
		else
		{
			Yigita_Eleman_Ekleme(alt_Dugum->onceki_seviye, Seviye_Bul(root, alt_Dugum), alt_Dugum);
		}
		Tum_Elemanlari_Kontrol_Et(alt_Dugum->sol);
		Tum_Elemanlari_Kontrol_Et(alt_Dugum->sag);
	}

}

void AVLTree:: Postorder(Dugum *alt_Dugum) const 
{
	if (alt_Dugum != NULL) 
	{

		Postorder(alt_Dugum->sol);

		Postorder(alt_Dugum->sag);

		cout << alt_Dugum->kisi_oz.isim << "," << alt_Dugum->kisi_oz.dogum_yili << "," << alt_Dugum->kisi_oz.kilo << "         ";

		alt_Dugum->yigit.Pop_Elemanlari_Goster();

		cout << endl;

	}
}

void AVLTree:: SeviyeyiYazdir(Dugum *alt_Dugum, int seviye)const 
{
	if (alt_Dugum == NULL) 
		return;

	if (seviye == 0) 
		cout << alt_Dugum->kisi_oz.Yas() << " ";

	else 
	{
		SeviyeyiYazdir(alt_Dugum->sol, seviye - 1);
		SeviyeyiYazdir(alt_Dugum->sag, seviye - 1);
	}
}

void AVLTree::Onceki_Guncelleme(Dugum* alt_Dugum) 
{
	if (alt_Dugum != NULL)
	{
		alt_Dugum->onceki_seviye = Seviye_Bul(root, alt_Dugum);
		Onceki_Guncelleme(alt_Dugum->sol);
		Onceki_Guncelleme(alt_Dugum->sag);
	}

}

int AVLTree::Seviye_Bul(Dugum* root, Dugum* alt_Dugum)
{

	int seviye = 0;
	if (root == NULL)
		return -1;
	if (root == alt_Dugum)
		return seviye;
	
	if (root->sol == NULL && root->sag == NULL)
		return -1;
	
	int sol_seviye = Seviye_Bul2(root->sol, alt_Dugum, seviye + 1);
	int sag_seviye = Seviye_Bul2(root->sag, alt_Dugum, seviye + 1);
	if (sol_seviye == -1)
		return sag_seviye;
	else
		return sol_seviye;
}

int AVLTree::Seviye_Bul2(Dugum*root, Dugum*alt_Dugum, int seviye)
{
	if (root == NULL)
		return -1;

	if (root == alt_Dugum)
		return seviye;
	
	if (root->sol == NULL && root->sag == NULL)
		return -1;
	
	int sol_seviye = Seviye_Bul2(root->sol, alt_Dugum, seviye + 1);
	int sag_seviye = Seviye_Bul2(root->sag, alt_Dugum, seviye + 1);
	if (sol_seviye == -1)
		return sag_seviye;
	else
		return sol_seviye;
}

void AVLTree:: Yigita_Eleman_Ekleme(int onceki, int guncel, Dugum*alt_Dugum)
{
	if (onceki > guncel)
	{
		alt_Dugum->yigit.push('Y');
	}
	else if (onceki < guncel)
	{
		alt_Dugum->yigit.push('A');
	}
	else
	{
		alt_Dugum->yigit.push('D');
	}
}

int AVLTree:: Yukseklik(Dugum *alt_Dugum)const {
	if (alt_Dugum == NULL)
		return -1; 
	return 1 + max(Yukseklik(alt_Dugum->sol), Yukseklik(alt_Dugum->sag));
}

bool AVLTree:: DugumSil(Dugum *&alt_Dugum)
{
	Dugum *silinecekDugum = alt_Dugum;

	if (alt_Dugum->sag == NULL) alt_Dugum = alt_Dugum->sol;
	else if (alt_Dugum->sol == NULL)alt_Dugum = alt_Dugum->sag;
	else {
		silinecekDugum = alt_Dugum->sol;
		Dugum *ebeveynDugum = alt_Dugum;
		while (silinecekDugum->sag != NULL) {
			ebeveynDugum = silinecekDugum;
			silinecekDugum = silinecekDugum->sag;
		}
		alt_Dugum->kisi_oz = silinecekDugum->kisi_oz;
		if (ebeveynDugum == alt_Dugum) alt_Dugum->sol = silinecekDugum->sol;
		else ebeveynDugum->sag = silinecekDugum->sol;
	}
	delete silinecekDugum;
	return true;
}

bool AVLTree:: Ara(Dugum *alt_Dugum, Kisi &aranan) {
	if (alt_Dugum == NULL) return false;
	if (alt_Dugum->kisi_oz.Yas() == aranan.Yas())
		return true;
	if (aranan.Yas() < alt_Dugum->kisi_oz.Yas())
		return Ara(alt_Dugum->sol, aranan);
	if (aranan.Yas() > alt_Dugum->kisi_oz.Yas())
		return Ara(alt_Dugum->sag, aranan);
}

AVLTree::AVLTree()
{
	root = NULL;
}

bool AVLTree:: Bosmu() const
{
	return root == NULL;
}

void AVLTree::Ekle(Kisi &yeni)
{
	root = AraveEkle(root, yeni);
	Tum_Elemanlari_Kontrol_Et(root);
	Onceki_Guncelleme(root);
	
}

void AVLTree:: Inorder() const
{
	Inorder(root);
}

void AVLTree:: Preorder() const
{
	Preorder(root);
}

void AVLTree:: Postorder() const
{
	Postorder(root);
}

void AVLTree:: Levelorder()const
{
	int h = Yukseklik();
	for (int level = 0;level <= h;level++)
		SeviyeyiYazdir(root, level);
}

bool AVLTree:: Arama(Kisi &aranan)
{
	return Ara(root, aranan);
}

void AVLTree:: Temizle()
{
	while (!Bosmu()) DugumSil(root);
}

int AVLTree:: Yukseklik()const
{
	return Yukseklik(root);
}

AVLTree:: ~AVLTree()
{
	Temizle();
}