#ifndef _SCREENSHOT_HANDLER
#define _SCREENSHOT_HANDLER

#include <Windows.h>
#include "../abstracts/ScreenShotHandler.h"

class WinScreenShotHandler: public ScreenShotHandler {
    public:
        void * GetScreenShot();
        int SaveScreenShotToFile(HBITMAP);
};

#endif