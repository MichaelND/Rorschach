CC=			gcc
CFLAGS=		-g -gdwarf-2 -Wall -std=gnu99
LD=			gcc
LDFLAGS=	-L.
TARGETS=	rorschach

all:		$(TARGETS)

rorschach: rorschac.o
	@echo "Linking $@..."
	@$(LD) $(LDFLAGS) -o $o $@ $^

rorschach.o: rorschac.c
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS -c -o $@ $^)

clean:
	@echo Cleaning...
	@rm -f $(TARGETS) *.o

