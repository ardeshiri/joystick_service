CC = g++
TARGET = joystick_ctrl_service
CFLAGS  = -Wall -O2 -std=c++20 
INCLUDES = -I./include
LFLAGS = -pthread -lstdc++fs -lssl -lcrypto -lpthread -lrabbitmq -lsfml-window
all : $(TARGET)

$(TARGET): main.o CPPAMQP.o JK_state.o Joystick_mediator.o Motor_med.o Servo_med.o 
	$(CC) -o ./bin/Release/$(TARGET) ./obj/Release/CPPAMQP.o ./obj/Release/main.o ./obj/Release/JK_state.o ./obj/Release/Joystick_mediator.o ./obj/Release/Motor_med.o  ./obj/Release/Servo_med.o $(LFLAGS)
	echo Done!

main.o: ./src/main.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c ./src/main.cpp -o ./obj/Release/main.o
	
JK_state.o: ./src/JK_state.cpp ./include/JK_state.h
	$(CC) $(CFLAGS) $(INCLUDES) -c ./src/JK_state.cpp -o ./obj/Release/JK_state.o
	
Joystick_mediator.o: ./src/Joystick_mediator.cpp ./include/Joystick_mediator.h
	$(CC) $(CFLAGS) $(INCLUDES) -c ./src/Joystick_mediator.cpp -o ./obj/Release/Joystick_mediator.o
	
Motor_med.o: ./src/Motor_med.cpp ./include/Motor_med.h
	$(CC) $(CFLAGS) $(INCLUDES) -c ./src/Motor_med.cpp -o ./obj/Release/Motor_med.o
	
Servo_med.o: ./src/Servo_med.cpp ./include/Servo_med.h
	$(CC) $(CFLAGS) $(INCLUDES) -c ./src/Servo_med.cpp -o ./obj/Release/Servo_med.o
	
CPPAMQP.o: ./src/CPPAMQP.cpp ./include/CPPAMQP.h
	$(CC) $(CFLAGS) $(INCLUDES) -c ./src/CPPAMQP.cpp -o ./obj/Release/CPPAMQP.o
		
.PHONY: clean

clean:
	rm -f ./obj/Release/*.o  ./bin/Release/$(TARGET)
