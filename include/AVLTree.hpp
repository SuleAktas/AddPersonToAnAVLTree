#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <cmath>
#include "ElemanYok.hpp"
#include"Dugum.hpp"

class AVLTree{

	private:

		Dugum *root;

		Dugum* AraveEkle(Dugum *alt_Dugum, Kisi& yeni);
		
		Dugum* SolCocukIleDegistir(Dugum *alt_Dugum);
		
		Dugum* SagCocukIleDegistir(Dugum *alt_Dugum);
		
		void Inorder(Dugum *alt_Dugum) const;

		void Preorder(Dugum *alt_Dugum) const;

		void Tum_Elemanlari_Kontrol_Et(Dugum* alt_Dugum);
		
		void Postorder(Dugum *alt_Dugum) const;

		void SeviyeyiYazdir(Dugum *alt_Dugum, int seviye)const;

		void Onceki_Guncelleme(Dugum* alt_Dugum);

		int Seviye_Bul(Dugum* root, Dugum* alt_Dugum);

		int Seviye_Bul2(Dugum* root, Dugum* alt_Dugum, int level);

		void Yigita_Eleman_Ekleme(int onceki, int guncel, Dugum*alt_Dugum);
		
		int Yukseklik(Dugum *alt_Dugum)const;

		bool DugumSil(Dugum *&alt_Dugum);
		
		bool Ara(Dugum *alt_Dugum, Kisi &aranan);


	public:

		AVLTree();

		bool Bosmu() const;

		void Ekle(Kisi &yeni);
			
		void Inorder() const;

		void Preorder() const;

		void Postorder() const;

		void Levelorder()const;

		bool Arama(Kisi &aranan);

		void Temizle();

		int Yukseklik()const;
		
		~AVLTree();
};

#endif