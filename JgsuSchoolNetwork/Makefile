SRC_PATH=./src/
OBJ_PATH=./obj/
INC_PATH=./include/
ALL:login
login:$(OBJ_PATH)login.o $(OBJ_PATH)mysocket.o
	cc -o $@ $^
login.o:$(SRC_PATH)login.c $(INC_PATH)mysocket.h
	cc -o $(OBJ_PATH)$@ -c $< -Wall -I $(INC_PATH)
mysocket.o:$(SRC_PATH)mysocket.c $(INC_PATH)mysocket.h
	cc -o $(OBJ_PATH)$@ -c $< -Wall -I $(INC_PATH)
.PHONY:clean ALL
clean:
	-rm -f login $(OBJ_PATH)*.o