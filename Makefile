CC=			g++
CFLAGS=		-g -gdwarf-2 -Wall -std=gnu++11
LD=			g++
LDFLAGS=	-L.
TARGETS=	rorschach

all:		$(TARGETS)

test:
	@echo Testing ...
	@[ `valgrind --leak-check=full ./rorschach .` ]


rorschach: rorschach.o search.o examine.o rules.o
	@echo "Linking $@..."
	@$(LD) $(LDFLAGS) -o $@ $^

rorschach.o: rorschach.cpp
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $^

search: search.o
	@$(CC) $(CFLAGS) -o $@ $^

search.o: search.cpp
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $^

examine: examine.o
	@$(CC) $(CFLAGS) -o  $@ $^

examine.o: examine.cpp
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $^

rules: rules.o
	@$(CC) $(CFLAGS) -o $@ $^

rules.o: rules.cpp
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $^

clean:
	@echo "Cleaning..."
	@rm -f $(TARGETS) *.o
