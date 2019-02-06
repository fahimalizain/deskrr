#ifndef SC_HANDLER__
#define SC_HANDLER__ 

class ScreenShotHandler {
    public:
        void * GetScreenShot();
        int SaveScreenShotToFile(void *);
};

#endif