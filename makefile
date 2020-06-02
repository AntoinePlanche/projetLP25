CC=gcc
CFLAGS=-Wall -Werror
EXEC=Mastermind
SRC= checkLineContent.c playerInput.c main.c
IDIR=include/
ODIR=src/
OBJ= $(addprefix $(ODIR),$(SRC:.c=.o))

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^
main.o: $(ODIR)main.c $(ODIR)playerInput.c $(IDIR)playerInput.h $(IDIR)main.h 
	$(CC) -o $@ -c $(CFLAGS) $<
playerInput.o: $(ODIR)playerInput.c $(ODIR)checkLineContent.c $(IDIR)playerInput.h $(IDIR)define.h
	$(CC) -o $@ -c $(CFLAGS) $<
checkLineContant.o: $(ODIR)checkLineContent.c $(IDIR)define.h
	$(CC) -o $@ -c $(CFLAGS) $<

.PHONEY: clean mrproper
clean:
	rm -rf $(ODIR)/*.o
mrproper: clean
	rm -rf $(EXEC)