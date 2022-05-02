FLAGS = -g

all: test_cost test_assignment test_node test_matrix test_container main

main: main.cpp Node.o Cost.o Assignment.o Matrix.o Container.o
	g++ Node.o Cost.o Assignment.o Matrix.o Container.o -o main main.cpp

test_cost: test_Cost_1.cpp Cost.o
	g++ $(FLAGS) test_Cost_1.cpp Cost.o -o test_cost

test_assignment: test_Assignment_1.cpp Assignment.o Cost.o Node.o Container.o Matrix.o
	g++ $(FLAGS) test_Assignment_1.cpp Assignment.o Cost.o Matrix.o Node.o Container.o -o test_assignment

test_node: test_Node_1.cpp Node.o
	g++ $(FLAGS) test_Node_1.cpp Node.o -o test_node

test_matrix: test_Matrix_1.cpp Matrix.o
	g++ $(FLAGS) test_Matrix_1.cpp Matrix.o -o test_matrix

test_container: test_Container_1.cpp Container.o Node.o
	g++ $(FLAGS) test_Container_1.cpp Container.o Node.o -o test_container

Container.o: Container.cpp Container.h
	g++ $(FLAGS) -c Container.cpp

Node.o: Node.cpp Node.h
	g++ $(FLAGS) -c Node.cpp

Assignment.o: Assignment.cpp Assignment.h
	g++ $(FLAGS) -c Assignment.cpp

Cost.o: Cost.h Cost.cpp
	g++ $(FLAGS) -c Cost.cpp

Matrix.o: Matrix.h Matrix.cpp
	g++ $(FLAGS) -c Matrix.cpp

clean:
	rm -f *.o test_cost test_assignment test_node test_matrix test_container main