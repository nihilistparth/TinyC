assembly: tinyC libass2_grp61.a


	./tinyC 1 > ass6_grp61_quads1.out
	./tinyC 2 > ass6_grp61_quads2.out
	./tinyC 3 > ass6_grp61_quads3.out
	./tinyC 4 > ass6_grp61_quads4.out
	./tinyC 5 > ass6_grp61_quads5.out
	./tinyC 6 > ass6_grp61_quads6.out
	# ./tinyC 7 > ass6_grp61_quads7.out



	gcc -c ass6_grp61_1.s
	gcc -c ass6_grp61_2.s
	gcc -c ass6_grp61_3.s
	gcc -c ass6_grp61_4.s
	gcc -c ass6_grp61_5.s
	gcc -c ass6_grp61_6.s
	# gcc -c ass6_grp61_7.s

	@echo "\n-------------  All Files Generated and Compiled Successfully!!!!  ---------------\n"

	gcc ass6_grp61_1.o -o test1 -L. -lass2_grp61 -no-pie
	gcc ass6_grp61_2.o -o test2 -L. -lass2_grp61 -no-pie
	gcc ass6_grp61_3.o -o test3 -L. -lass2_grp61 -no-pie
	gcc ass6_grp61_4.o -o test4 -L. -lass2_grp61 -no-pie
	gcc ass6_grp61_5.o -o test5 -L. -lass2_grp61 -no-pie
	gcc ass6_grp61_6.o -o test6 -L. -lass2_grp61 -no-pie
	# gcc ass6_grp61_7.o -o test7 -L. -lass2_grp61 -no-pie

	@echo "\n###########  test files are sucessfully generated, for example use ./test1 for running test 1  ##########\n"

libass2_grp61.a:
	gcc -c ass2_grp61.c
	ar -rcs libass2_grp61.a ass2_grp61.o

tinyC: lex.yy.o ass6_grp61.tab.o ass6_grp61_translator.o ass6_grp61_target_translator.o
	g++ lex.yy.o ass6_grp61.tab.o ass6_grp61_translator.o \
	ass6_grp61_target_translator.o -lfl -o tinyC

ass6_grp61_target_translator.o: ass6_grp61_target_translator.cxx
	g++ -c ass6_grp61_target_translator.cxx

ass6_grp61_translator.o: ass6_grp61_translator.cxx ass6_grp61_translator.h
	g++ -c ass6_grp61_translator.h
	g++ -c ass6_grp61_translator.cxx

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

ass6_grp61.tab.o: ass6_grp61.tab.c
	g++ -c ass6_grp61.tab.c

lex.yy.c: ass6_grp61.l ass6_grp61.tab.h ass6_grp61_translator.h
	flex ass6_grp61.l

ass6_grp61.tab.c: ass6_grp61.y
	bison -dtv ass6_grp61.y -W

ass6_grp61.tab.h: ass6_grp61.y
	bison -dtv ass6_grp61.y -W


	
clean:
	rm lex.yy.c\
	   ass6_grp61.tab.c\
	   ass6_grp61.tab.h\
	   lex.yy.o\
	   ass6_grp61.tab.o\
	   ass6_grp61.output\
	   ass6_grp61_translator.o\
	   test1\
	   test2\
	   test3\
	   test4\
	   test5\
	   test6\
	   tinyC\
	   ass6_grp61_target_translator.o\
	   ass6_grp61_translator.h.gch\
	   ass6_grp61_quads1.out\
	   ass6_grp61_quads2.out\
	   ass6_grp61_quads3.out\
	   ass6_grp61_quads4.out\
	   ass6_grp61_quads5.out\
	   ass6_grp61_quads6.out\
	   libass2_grp61.a\
	   ass2_grp61.o\
	   ass6_grp61_1.o\
	   ass6_grp61_2.o\
	   ass6_grp61_3.o\
	   ass6_grp61_4.o\
	   ass6_grp61_5.o\
	   ass6_grp61_6.o\
	   ass6_grp61_1.s\
	   ass6_grp61_2.s\
	   ass6_grp61_3.s\
	   ass6_grp61_4.s\
	   ass6_grp61_5.s\
	   ass6_grp61_6.s\
	
