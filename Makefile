FLAGS = -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

QuadEqu: main.o SolvEqu.o io.o test.o ComLinePars.o
	g++ obj/main.o obj/SolvEqu.o obj/io.o obj/test.o obj/ComLinePars.o -o QuadEqu -lasan -lubsan
	
main.o: src/main.cpp
	g++ $(FLAGS) src/main.cpp -c -o obj/main.o

SolvEqu.o: src/SolvEqu.cpp
	g++ $(FLAGS) src/SolvEqu.cpp -c -o obj/SolvEqu.o

io.o: src/io.cpp
	g++ $(FLAGS) src/io.cpp -c -o obj/io.o

test.o: src/test.cpp
	g++ $(FLAGS) src/test.cpp -c -o obj/test.o

ComLinePars.o: src/ComLinePars.cpp
	g++ $(FLAGS) src/ComLinePars.cpp -c -o obj/ComLinePars.o
	
clean:
	rm obj/* QuadEdu