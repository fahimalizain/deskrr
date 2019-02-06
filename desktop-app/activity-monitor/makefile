g++ = C:/MinGW/bin/g++

windows-monitor: main.o WinScreenShotHandler.o WinSocketHandler.o
	g++ -Wall main.o WinSocketHandler.o SocketHandler.o WinScreenShotHandler.o ScreenShotHandler.o

main.o:
	g++ -c main.cpp

WinScreenShotHandler.o: ScreenShotHandler.o
	g++ -c win32/WinScreenShotHandler.cpp

WinSocketHandler.o: SocketHandler.o
	g++ -c win32/WinSocketHandler.cpp

SocketHandler.o:
	g++ -c abstracts/SocketHandler.cpp

ScreenShotHandler.o:
	g++ -c abstracts/ScreenShotHandler.cpp