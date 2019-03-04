#include "win32/WinSocketHandler.h"
#include "win32/WinScreenShotHandler.h"
#include <iostream>
#include <windows.h>

int main(int argc, char **argv)
{
  std::cout << "Hello" << std::endl;
  MessageBox(0, "PRRR OK", "Hi", MB_SETFOREGROUND);
  WinScreenShotHandler ss;
  WinSocketHandler s(1000);
  s.startListening();
  HBITMAP m = (HBITMAP) ss.GetScreenShot();
  ss.SaveScreenShotToFile(m);
  return 0;
}