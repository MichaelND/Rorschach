CC=			g++
CFLAGS=		-g -gdwarf-2 -Wall -std=gnu++11
LD=			g++
LDFLAGS=	-L.
TARGETS=	rorschach

all:		$(TARGETS)

test:
	@echo Testing ...
	@[ `valgrind --leak-check=full ./rorschach .` ]


rorschach: rorschach.o search.o examine.o execute.o rules.o node.o match.o
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

execute: execute.o
	@$(CC) $(CFLAGS) -o  $@ $^

execute.o: execute.cpp
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $^

match: match.o
	@$(CC) $(CFLAGS) -o $@ $^

match.o: match.cpp
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $^

rules: rules.o
	@$(CC) $(CFLAGS) -o $@ $^

rules.o: rules.cpp
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $^

node: node.o
	@$(CC) $(CFLAGS) -o $@ $^

node.o: node.cpp
	@echo "Compiling $@..."
	@$(CC) $(CFLAGS) -c -o $@ $^

clean:
	@echo "Cleaning..."
	@rm -f $(TARGETS) *.o
