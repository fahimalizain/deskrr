g++ = C:/MinGW/bin/g++

windows-monitor: main.o SocketHandler.o WinScreenShotHandler.o WinSocketHandler.o
	del a.exe
	g++ -v -Wall main.o \
		abstracts/SocketHandler.o 		win32/WinSocketHandler.o \
		abstracts/ScreenShotHandler.o win32/WinScreenShotHandler.o \
		-lgdi32
	del main.o WinSocketHandler.o SocketHandler.o ScreenShotHandler.o WinScreenShotHandler.o

main.o:
	g++ -c main.cpp

WinSocketHandler.o: SocketHandler.o
	g++ -c win32/WinSocketHandler.cpp -o win32/WinSocketHandler.o

SocketHandler.o:
	g++ -c abstracts/SocketHandler.cpp -o abstracts/SocketHandler.o

WinScreenShotHandler.o: ScreenShotHandler.o
	g++ -c win32/WinScreenShotHandler.cpp -o win32/WinScreenShotHandler.o

ScreenShotHandler.o:
	g++ -c abstracts/ScreenShotHandler.cpp -o abstracts/ScreenShotHandler.o

# Clean doesnt work
clean:
	rm main.o
	rm ScreenShotHandler.o
	rm SocketHandler.o
	rm WinScreenShotHandler.o
	rm WinSocketHandler.o