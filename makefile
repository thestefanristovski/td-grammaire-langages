TDGL: main.o Automate.o Etat.o Lexer.o Symbole.o E0.o E1.o E2.o E3.o E4.o E5.o E6.o E7.o E8.o E9.o
	g++ -o TDGL main.o Automate.o Etat.o Lexer.o Symbole.o E0.o E1.o E2.o E3.o E4.o E5.o E6.o E7.o E8.o E9.o

main.o: main.cpp
	g++ -c main.cpp

Automate.o: Automate.h Automate.cpp Symbole.h Lexer.h
	g++ -c Automate.cpp

Etat.o: Etat.cpp Etat.h Symbole.h Automate.h
	g++ -c Etat.cpp

Lexer.o: Lexer.cpp Lexer.h Symbole.h
	g++ -c Lexer.cpp

Symbole.o: Symbole.cpp Symbole.h
	g++ -c Symbole.cpp

E0.o: E0.cpp E0.h Etat.h
	g++ -c E0.cpp

E1.o: E1.cpp E1.h Etat.h
	g++ -c E1.cpp

E2.o: E2.cpp E2.h Etat.h
	g++ -c E2.cpp

E3.o: E3.cpp E3.h Etat.h
	g++ -c E3.cpp

E4.o: E4.cpp E4.h Etat.h
	g++ -c E4.cpp

E5.o: E5.cpp E5.h Etat.h
	g++ -c E5.cpp

E6.o: E6.cpp E6.h Etat.h
	g++ -c E6.cpp

E7.o: E7.cpp E7.h Etat.h
	g++ -c E7.cpp

E8.o: E8.cpp E8.h Etat.h
	g++ -c E8.cpp

E9.o: E9.cpp E9.h Etat.h
	g++ -c E9.cpp

run: TDGL
	./TDGL

clean:
	rm -f *.o TDGL *~
