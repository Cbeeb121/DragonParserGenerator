build: main.o
	g++ -std=c++11 -g -Wall -Wno-c++11-extensions main.o -o dragonparse
main.o: main.cpp 
	g++ -std=c++11 -g -Wall -Wno-c++11-extensions -c main.cpp
run: 
	./dragonparse input.grammar
	g++ -std=c++11 -g -Wall -Wno-c++11-extensions parser.cpp -o parser

test: 
	./parser test.tokens

clean:
	rm *.o *.dot *.png parser.cpp parser dragonparse
dot:
	dot -Tpng -o parser.png parser.dot