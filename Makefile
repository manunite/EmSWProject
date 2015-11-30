DIR = DB Pages
.PHONY : all clean


all :
	@for d in $(DIR); do $(MAKE) -C $$d; done
	
clean :
	@for d in $(DIR); do $(MAKE) -C $$d clean; done
