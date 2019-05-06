CC = g++
INCLUDE = .
CFLAGS = -g -Wall -ansi
run: BridgeAndTorch.exe
	@./BridgeAndTorch.exe
BridgeAndTorch.exe: BridgeTorch.cpp
	$(CC) $(CFLAGS) -o BridgeAndTorch.exe BridgeTorch.cpp
clean:
	@rm *.exe
