windows-monitor: main.o WinScreenShotHandler.o WinSocketHandler.o
	g++ -o windows-monitor.exe \
		main.o WinScreenShotHandler.o WinSocketHandler.o

WinScreenShotHandler.o: SocketHandler.o
	g++ -c WinScreenShotHandler