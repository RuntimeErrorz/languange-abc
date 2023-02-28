sources = main.cpp date_t.cpp employee.cpp \
	job_t.cpp staff.cpp
objects = main.o date_t.o employee.o \
	job_t.o staff.o 
target = demo

CXX = g++

$(target):$(objects)
	@echo .
	@$(CXX) $(objects) -o $(target)
	@rm -rf $(objects)
	@echo Compilation finish
	@echo Executable file is named "demo"

main.o:
	@echo -n Compiling.
	@$(CXX) -c main.cpp

date_t.o:
	@echo -n .
	@$(CXX) -c date_t.cpp

employee.o:
	@echo -n .
	@$(CXX) -c employee.cpp

job_t.o:
	@echo -n .
	@$(CXX) -c job_t.cpp

staff.o:
	@echo -n .
	@$(CXX) -c staff.cpp

.PHONY:clean
clean:
	@rm -rf $(target) $(objects)
