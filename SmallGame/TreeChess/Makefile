SRC_PATH=./src/
OBJ_PATH=./obj/
INC_PATH=./include/
ALL:ThreeChess
ThreeChess:$(OBJ_PATH)main.o $(OBJ_PATH)GameControl.o $(OBJ_PATH)BoardAction.o
	gcc -o $@ $^
$(OBJ_PATH)main.o:$(SRC_PATH)main.c $(INC_PATH)GameControl.h
	gcc -o $@ -c $< -Wall -I $(INC_PATH)
$(OBJ_PATH)GameControl.o:$(SRC_PATH)GameControl.c $(INC_PATH)GameControl.h $(INC_PATH)BoardAction.h
	gcc -o $@ -c $< -Wall -I $(INC_PATH)
$(OBJ_PATH)BoardAction.o:$(SRC_PATH)BoardAction.c $(INC_PATH)BoardAction.h
	gcc -o $@ -c $< -Wall -I $(INC_PATH)
.PHONY:clean ALL
clean:
	-rm -f ThreeChess $(OBJ_PATH)*.o