CXX = g++
CXXFLAGS = -Wall -g

aitran: main.o Transcript.o Scenario.o Spell.o
	$(CXX) $(CXXFLAGS) -o aitran main.o Transcript.o Scenario.o Spell.o
	
main.o: main.cpp Transcript.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Transcript.o: Transcript.hpp Scenario.hpp

Scenario.o: Scenario.hpp Spell.hpp

Spell: Spell.hpp

clean:
	rm aitran *.o