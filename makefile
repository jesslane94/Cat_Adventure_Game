finalproject.o: inputValidation.o main.o rangeChecker.o menu.o space.o cat.o barn.o frontyard.o forest.o lake.o garden.o shed.o game.o
	g++ -g -std=c++11 rangeChecker.o inputValidation.o menu.o space.o cat.o frontyard.o barn.o forest.o lake.o garden.o shed.o game.o main.o -o main

inputValidation.o: inputValidation.hpp inputValidation.cpp
	g++ -g -std=c++11 -c inputValidation.cpp

rangeChecker.o: rangeChecker.cpp rangeChecker.hpp
	g++ -g -std=c++11 -c rangeChecker.cpp

menu.o: menu.cpp menu.hpp
	g++ -g -std=c++11 -c menu.cpp

space.o: space.hpp space.cpp
	g++ -g -std=c++11 -c space.cpp

cat.o: cat.hpp cat.cpp
	g++ -g -std=c++11 -c cat.cpp

frontyard.o: frontyard.hpp frontyard.cpp
	g++ -g -std=c++11 -c frontyard.cpp

barn.o: barn.hpp barn.cpp
	g++ -g -std=c++11 -c barn.cpp

forest.o: forest.hpp forest.cpp
	g++ -g -std=c++11 -c forest.cpp

lake.o: lake.hpp lake.cpp
	g++ -g -std=c++11 -c lake.cpp

garden.o: garden.hpp garden.cpp
	g++ -g -std=c++11 -c garden.cpp

shed.o: shed.hpp shed.cpp
	g++ -g -std=c++11 -c shed.cpp

game.o: game.hpp game.cpp
	g++ -g -std=c++11 -c game.cpp

main.o: main.cpp
	g++ -g -std=c++11 -c main.cpp

clean:
	rm *.o main
