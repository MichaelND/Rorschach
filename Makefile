CC=			gcc
CFLAGS=		-g -gdwarf-2 -Wall -std=gnu99
LD=			gcc
LDFLAGS=	-L.
TARGETS=	rorschach

all:		$(TARGETS)

test:
	@echo Testing ...
	@[ `valgrind --leak-check=full ./rorschach .` ]


rorschach: rorschach.o search.o examine.o rules.o
	@echo "Linking $@..."
	@$(LD) $(LDFLAGS) -o $@ $^

rorschach.o: rorschach.c
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $^

search: search.o
	@$(CC) $(CFLAGS) -o $@ $^

search.o: search.c
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $^

examine: examine.o
	@$(CC) $(CFLAGS) -o  $@ $^

examine.o: examine.c
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $^

rules: rules.o
	@$(CC) $(CFLAGS) -o $@ $^

rules.o: rules.c
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $^

clean:
	@echo "Cleaning..."
	@rm -f $(TARGETS) *.o
