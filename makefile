hepsi: nesneler derle calistir

nesneler:
	g++ -I ./include/ -o ./lib/Hata.o -c ./src/Hata.cpp
	g++ -I ./include/ -o ./lib/Kisi.o -c ./src/Kisi.cpp
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/AVLTree.o -c ./src/AVLTree.cpp
	g++ -I ./include/ -o ./lib/Dosya.o -c ./src/Dosya.cpp

derle:
	g++ -I ./include/ -o ./bin/Test ./lib/Hata.o ./lib/Kisi.o ./lib/Stack.o ./lib/Dugum.o ./lib/AVLTree.o ./lib/Dosya.o ./src/test.cpp
	
calistir:
	./bin/Test