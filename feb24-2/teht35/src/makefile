PROJECT = stackdemo

CC=gcc

SHARED_LIB_DIR = /etc/ld.so.conf.d/$(PROJECT)

IDIR = ../include
LDIR = ../lib
ODIR = ../obj
SRC = $(wildcard *.c)
LIBS = -l$(PROJECT)
INCLUDES = -I$(IDIR)
DEPS=$(IDIR)/$(PROJECT).h
OBJS = $(SRC:%.c=$(ODIR)/%.o)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -Wall -fPIC -o $@ $< $(INCLUDES)

all: $(OBJS)
	$(CC) $(ODIR)/$(PROJECT).o -L$(LDIR) $(LIBS) $(INCLUDES) -o $(PROJECT)

static: $(OBJS)
	$(CC) --static -o $(PROJECT) $(ODIR)/$(PROJECT).o -L$(LDIR) $(LIBS) $(INCLUDES) 

# libs depends on all obj-files except main obj-file
libs: $(filter-out $(ODIR)/$(PROJECT).o, $(OBJS)) 
	ar -r $(LDIR)/lib$(PROJECT).a $^
	@echo Shared library
	gcc $^ -shared -o $(LDIR)/lib$(PROJECT).so
	@echo 'Creating entry for ld.so...'
	@echo '$(CURDIR)/$(LDIR)' | sudo tee $(SHARED_LIB_DIR).conf
	sudo ldconfig

.PHONY: clean

clean:
	rm -f $(PROJECT) $(OBJS)
	#sudo rm $(SHARED_LIB_DIR).conf

