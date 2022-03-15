compiler=g++
standard=-std=c++2a
optimization=
errors=-pedantic-errors
build_path = build/

.PHONY : clean 


__ : $(build_path)main
	@echo
	@echo ./$(build_path)main
	@echo -----------------------
	@echo
	@./$(build_path)main $(ARGS) 
#   To pass the ARGS you have to run make ARGS={...}
#	valgrind --leak-check=yes ./main

$(build_path)my_v.o : my_v.cpp
	@mkdir -p build
	$(compiler) $(standard) $(debug) $(optimization) $(errors) -c -o $@ $^
$(build_path)main.o : main.cpp
	@mkdir -p build
	$(compiler) $(standard) $(debug) $(optimization) $(errors) -c -o $@ $^
$(build_path)main : $(build_path)main.o $(build_path)my_v.o
	@mkdir -p build
	$(compiler) $(standard) $(debug) $(optimization) $(errors) -o $@ $^


clean : 
	rm main $(build_path)executionHelpersFunc.o $(build_path)main.o 
