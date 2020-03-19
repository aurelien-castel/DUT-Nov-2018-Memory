# Memory : fichier Makefile

# CHAPITRE 1 : BUT FINAL

but : memory

# CHAPITRE 2 : VARIABLES

OFILES =difficulty_tableau.o \
		graphismes.o \
		chrono_triche.o \
		main.o

CC = gcc

CFLAGS = -lgraph

# CHAPITRE 3 : DEPENDANCES (REGLES IMPLICITES)

difficulty_tableau.o : difficulty_tableau.h

graphismes.o : graphismes.h chrono_triche.h

chrono_triche.o : chrono_triche.h graphismes.h

main.o : difficulty_tableau.h graphismes.h chrono_triche.h

#CHAPITRE 4 : DEPENDANCES AVEC COMMANDES

memory : $(OFILES)
	$(CC) $(CFLAGS) -o memory $(OFILES) $(CFLAGS)

#CHAPITRE 5 : NETTOYAGE DES FICHIERS GENERES

clean :
	-rm -f $(OFILES) memory

#CHAPITRE 6 : BUTS FACTICES

.PHONY : but clean run

#CHAPITRE 7 : MAKE RUN

run: but
	./memory
