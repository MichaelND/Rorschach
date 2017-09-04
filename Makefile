CC=			gcc
CFLAGS=		-g -gdwarf-2 -Wall -std=gnu99
LD=			gcc
LDFLAGS=	-L.
TARGETS=	rorschach

all:		$(TARGETS)

rorschach: rorschach.o search.o
	@echo "Linking $@..."
	@$(LD) $(LDFLAGS) -o $o $@ $^

rorschach.o: rorschach.c
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $^

search: search.o
	@echo "Linking $@..."
	@$(LD) $(LDFLAGS) -o $o $@ $^

search.o: search.c
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $^


clean:
	@echo Cleaning...
	@rm -f $(TARGETS) *.o

