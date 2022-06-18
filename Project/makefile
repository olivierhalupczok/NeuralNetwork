compiler=g++
standard=-std=c++20
optimization=
errors=-pedantic-errors
build_path = build/

.PHONY : clean 


__ : $(build_path)main
	@mkdir -p logs
	@cd ..
	@echo
	@echo ./$(build_path)main
	@echo -----------------------
	@echo
	@./$(build_path)main $(ARGS) 
#   To pass the ARGS you have to run make ARGS={...}
#	valgrind --leak-check=yes ./main

$(build_path)mathFuncs.o : mathFuncs.cpp
	@mkdir -p build
	$(compiler) $(standard) $(debug) $(optimization) $(errors) -c -o $@ $^
$(build_path)networkResult.o : networkResult.cpp
	@mkdir -p build
	$(compiler) $(standard) $(debug) $(optimization) $(errors) -c -o $@ $^
$(build_path)neuron.o : neuron.cpp
	@mkdir -p build
	$(compiler) $(standard) $(debug) $(optimization) $(errors) -c -o $@ $^
$(build_path)neuralNetwork.o : neuralNetwork.cpp
	@mkdir -p build
	$(compiler) $(standard) $(debug) $(optimization) $(errors) -c -o $@ $^
$(build_path)logger.o : logger.cpp
	@mkdir -p build
	$(compiler) $(standard) $(debug) $(optimization) $(errors) -c -o $@ $^
$(build_path)main.o : main.cpp
	@mkdir -p build
	$(compiler) $(standard) $(debug) $(optimization) $(errors) -c -o $@ $^
$(build_path)main : $(build_path)main.o $(build_path)mathFuncs.o $(build_path)neuron.o $(build_path)neuralNetwork.o $(build_path)networkResult.o $(build_path)logger.o
	@mkdir -p build
	$(compiler) $(standard) $(debug) $(optimization) $(errors) -o $@ $^


clean : 
	rm main $(build_path)mathFuncs.o $(build_path)main.o 
