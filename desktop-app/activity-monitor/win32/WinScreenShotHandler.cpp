#include <Windows.h>
#include "WinScreenShotHandler.h"

void * WinScreenShotHandler::GetScreenShot() {
    // code from https://stackoverflow.com/a/3291411/2041598

    // get the device context of the screen
    HDC hScreenDC = GetDC(NULL);
    // and a device context to put it in
    HDC hMemoryDC = CreateCompatibleDC(hScreenDC);

    int width = GetDeviceCaps(hScreenDC, HORZRES);
    int height = GetDeviceCaps(hScreenDC, VERTRES);

    // maybe worth checking these are positive values
    HBITMAP hBitmap = CreateCompatibleBitmap(hScreenDC, width, height);
    // get a new bitmap
    HBITMAP hOldBitmap = (HBITMAP) SelectObject(hMemoryDC, hBitmap);

    BitBlt(hMemoryDC, 0, 0, width, height, hScreenDC, 0, 0, SRCCOPY);
    hBitmap = (HBITMAP) SelectObject(hMemoryDC, hOldBitmap);
    
    // save hBitmap to file
    // have to convert this HBITMAP to DIB (Device Independent Bitmap - normal bitmaps)

    // clean up
    DeleteDC(hMemoryDC);
    DeleteDC(hScreenDC);
    return hBitmap;
}