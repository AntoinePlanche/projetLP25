CC=gcc
CFLAGS=-Wall -Werror
EXEC=Mastermind
SRC= playerInput.c createGameFile.c addLigneToFile.c combinaisonSecret.c main.c 
IDIR=include/
ODIR=src/
OBJ= $(addprefix $(ODIR),$(SRC:.c=.o))

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^
main.o: $(ODIR)main.c $(ODIR)playerInput.c  $(IDIR)define.h  $(IDIR)playerInput.h
	$(CC) -o $@ -c $(CFLAGS) $<
playerInput.o: $(ODIR)playerInput.c $(IDIR)playerInput.h $(IDIR)define.h
	$(CC) -o $@ -c $(CFLAGS) $<

.PHONEY: clean mrproper
clean:
	rm -rf $(ODIR)/*.o
mrproper: clean
	rm -rf $(EXEC)