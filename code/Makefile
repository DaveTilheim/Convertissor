CC=gcc
LD=gcc
CFLAGS=
GTKFLAGS=`pkg-config --cflags --libs gtk+-2.0`
OBJ=  util-gtk.o controleur.o vue.o modele.o 
HEAD=  util-gtk.h controleur.h vue.h modele.h 
CODE=  util-gtk.c controleur.c vue.c modele.c 
EXE=convertissor

all:$(EXE)

convertissor: main.o $(OBJ) 
	@$(LD) -o convertissor main.o $(OBJ) $(GTKFLAGS)
	@echo compilation success

main.o:main.c
	@$(CC) -c main.c -o main.o $(CFLAGS) $(GTKFLAGS)

:  
	@$(CC) -c  -o  $(CFLAGS) $(GTKFLAGS)

util-gtk.o: util-gtk.h util-gtk.c
	@$(CC) -c util-gtk.c -o util-gtk.o $(CFLAGS) $(GTKFLAGS)

controleur.o: controleur.h controleur.c
	@$(CC) -c controleur.c -o controleur.o $(CFLAGS) $(GTKFLAGS)

vue.o: vue.h vue.c
	@$(CC) -c vue.c -o vue.o $(CFLAGS) $(GTKFLAGS)

modele.o: modele.h modele.c
	@$(CC) -c modele.c -o modele.o $(CFLAGS) $(GTKFLAGS)

open:
	@open -a SublimeText $(HEAD) $(CODE) main.c 

tar:
	@tar -czf convertissor.tar.gz $(HEAD) $(CODE) main.c Makefile


clean:
	@rm -f *.o
	@rm -f convertissor
	@clear



### gtk version -> gtk+2
### to install gtk with Homebrew [https://brew.sh/index_fr]
### -> (brew install gtk+)
### made with auto-makefile mac edition
### autor Arthur Detrembleur (Appliaction company)
