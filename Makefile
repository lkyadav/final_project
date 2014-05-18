all: nlp
nlp: main.o avyaya.o verb.o noun.o
	g++ -o nlp main.o avyaya.o verb.o noun.o -fno-stack-protector
main.o: main.cpp functions.h
	g++ -c main.cpp -fno-stack-protector
avyaya.o: avyaya.cpp functions.h
	g++ -c avyaya.cpp -fno-stack-protector
verb.o:verb.cpp functions.h
	g++ -c verb.cpp -fno-stack-protector
noun.o:noun.cpp functions.h
	g++ -c noun.cpp -fno-stack-protector
clean:
	rm -f *.o nlp
