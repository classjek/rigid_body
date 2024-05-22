# Define the compiler
CC=g++

# Define any compile-time flags
CFLAGS=-Wall -g -std=c++11


# Define any directories containing header files other than /usr/include
INCLUDES=-I../eigen-3.4.0

# Define library paths in addition to /usr/lib
LFLAGS=

# Define any libraries to link into executable:
LIBS=

# Define the C++ source files
SRCS=main.cpp Physics.cpp

# Define the object files
OBJS=$(SRCS:.cpp=.o)

# Define the executable file 
MAIN=main

.PHONY: depend clean

all:    $(MAIN)
	@echo  Simple compiler named $(MAIN) has been compiled

$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

# This is a suffix replacement rule for building .o's from .cpp's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .cpp file) and $@: the name of the target of the rule (a .o file)
# (see the gnu make manual section about automatic variables)
.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
