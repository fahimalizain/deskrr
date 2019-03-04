#include <Windows.h>
#include "WinScreenShotHandler.h"
#include <iostream>

using namespace std;

void * WinScreenShotHandler::GetScreenShot() {
    // code from https://stackoverflow.com/a/3291411/2041598
    cout << "Getting Screenshot" << endl;
    // get the device context of the screen
    HDC hScreenDC = GetDC(NULL);
    // and a device context to put it in
    HDC hMemoryDC = CreateCompatibleDC(hScreenDC);

    int width = GetDeviceCaps(hScreenDC, HORZRES);
    int height = GetDeviceCaps(hScreenDC, VERTRES);
    cout << "W:" << width << " H:" << height << endl;

    // The following for Getting all displays -- STARTS HERE
    int x1, y1, x2, y2;
    // get screen dimensions
    x1  = GetSystemMetrics(SM_XVIRTUALSCREEN);
    y1  = GetSystemMetrics(SM_YVIRTUALSCREEN);
    x2  = GetSystemMetrics(SM_CXVIRTUALSCREEN);
    y2  = GetSystemMetrics(SM_CYVIRTUALSCREEN);
    width  = x2;
    height = y2;
    cout << "X1: " << x1 << " Y1:" << y1 << " X2:" << x2 << " Y2:" << y2 << endl;
    cout << "W:" << width << " H:" << height << endl;
    // ------- ENDS HERE ------------

    // maybe worth checking these are positive values
    HBITMAP hBitmap = CreateCompatibleBitmap(hScreenDC, width, height);
    // get a new bitmap
    HBITMAP hOldBitmap = (HBITMAP) SelectObject(hMemoryDC, hBitmap);

    // FAZ: 7th & 8th param was 0, 0 -- changed to x1, y1 for all monitor screenshot
    /* Observations:
    width is 3x single screen (expected 2x)
    height is ok

    changing the parameter brought the screen into view
    */
    BitBlt(hMemoryDC, 0, 0, width, height, hScreenDC, x1, y1, SRCCOPY);
    hBitmap = (HBITMAP) SelectObject(hMemoryDC, hOldBitmap);
    
    // save hBitmap to file
    // have to convert this HBITMAP to DIB (Device Independent Bitmap - normal bitmaps)

    // save bitmap to clipboard
    OpenClipboard(NULL);
    EmptyClipboard();
    SetClipboardData(CF_BITMAP, hBitmap);
    CloseClipboard();
    cout << "Copied to Clipboard! Paste in Paint" << endl;

    // clean up
    DeleteDC(hMemoryDC);
    DeleteDC(hScreenDC);
    return hBitmap;
}

int WinScreenShotHandler::SaveScreenShotToFile(HBITMAP hBitmap) {
    return 0;
}