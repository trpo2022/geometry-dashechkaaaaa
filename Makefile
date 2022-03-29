CFLAGS = -Wall -Wextra -Werror

all: bin/geometry

bin/geometry: obj/src/geometry/geometry.o obj/src/libgeo/libgeo.a
	gcc $(CFLAGS) -o $@ $^ -lm

obj/src/geometry/geometry.o: src/geometry/geometry.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm

obj/src/libgeo/libgeo.a: obj/src/libgeo/skipTriangle.o obj/src/libgeo/skipCircle.o obj/src/libgeo/skipSign.o obj/src/libgeo/skipDigit.o obj/src/libgeo/checkEndStr.o obj/src/libgeo/perimeterCircle.o obj/src/libgeo/areaCircle.o obj/src/libgeo/sidesTriangle.o obj/src/libgeo/correctTriangle.o obj/src/libgeo/perimeterTriangle.o obj/src/libgeo/areaTriangle.o obj/src/libgeo/errorsFunctions.o
	ar rcs $@ $^


obj/src/libgeo/skipTriangle.o: src/libgeo/skipTriangle.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm

obj/src/libgeo/skipCircle.o: src/libgeo/skipCircle.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm

obj/src/libgeo/skipSign.o: src/libgeo/skipSign.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm	
	
obj/src/libgeo/skipDigit.o: src/libgeo/skipDigit.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm

obj/src/libgeo/checkEndStr.o: src/libgeo/checkEndStr.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm

obj/src/libgeo/perimeterCircle.o: src/libgeo/perimeterCircle.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm	

obj/src/libgeo/areaCircle.o: src/libgeo/areaCircle.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm	

obj/src/libgeo/sidesTriangle.o: src/libgeo/sidesTriangle.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm		
	
obj/src/libgeo/correctTriangle.o: src/libgeo/correctTriangle.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm	
	
obj/src/libgeo/perimeterTriangle.o: src/libgeo/perimeterTriangle.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm		
	
obj/src/libgeo/areaTriangle.o: src/libgeo/areaTriangle.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm	
	
obj/src/libgeo/errorsFunctions.o: src/libgeo/errorsFunctions.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm	

.PHONY: clean

clean:
	rm obj/src/libgeo/*.a obj/src/libgeo/*.o obj/src/geometry/*.o bin/geometry
