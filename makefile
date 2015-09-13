CXX        := g++-4.8
CXXFLAGS   := -pedantic -std=c++11 -Wall -g
LDFLAGS    := -lgtest -lgtest_main -pthread
GCOV       := gcov-4.8
GCOVFLAGS  := -fprofile-arcs -ftest-coverage
GPROF      := gprof
GPROFFLAGS := -pg
VALGRIND   := valgrind

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f RunGift
	rm -f RunGift.tmp
	rm -f TestGift
	rm -f TestGift.tmp

config:
	git config -l

scrub:
	make  clean
	rm -f  Gift.log
	rm -rf gift-tests
	rm -rf html
	rm -rf latex

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

test: RunGift.tmp TestGift.tmp

solution: solution.cpp
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) solution.cpp -o solution

RunGift: Gift.h Gift.c++ RunGift.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) Gift.c++ RunGift.c++ -o RunGift

RunGift.tmp: RunGift 
	./RunGift < RunGift.in > RunGift.tmp
	diff RunGift.tmp RunGift.out

TestGift: Gift.h Gift.c++ TestGift.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) Gift.c++ TestGift.c++ -o TestGift $(LDFLAGS)

TestGift.tmp: TestGift
	$(VALGRIND) ./TestGift                                       >  TestGift.tmp 2>&1
	$(GCOV) -b Gift.c++     | grep -A 5 "File 'Gift.c++'"     >> TestGift.tmp
	$(GCOV) -b TestGift.c++ | grep -A 5 "File 'TestGift.c++'" >> TestGift.tmp
	cat TestGift.tmp
