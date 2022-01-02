all:
	g++ -Isrc/include -Lsrc/lib -o test test.cpp -lmingw32 -lSDL2main -lSDL2
	g++ -Isrc/include -Lsrc/lib -o cleanup ../cleanup.cpp -lmingw32 -lSDL2main -lSDL2
	g++ -Isrc/include -Lsrc/lib -o drawing_functions ../drawing_functions.cpp -lmingw32 -lSDL2main -lSDL2
	g++ -Isrc/include -Lsrc/lib -o res_path ../res_path.cpp -lmingw32 -lSDL2main -lSDL2
	g++ -Isrc/include -Lsrc/lib -o randomNumber ../randomNumber.cpp -lmingw32 -lSDL2main -lSDL2