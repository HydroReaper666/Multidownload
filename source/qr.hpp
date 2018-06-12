#include <3ds.h>
#include <citro2d.h>
#include <citro3d.h>
#include <string>
extern "C"
{
    #include "quirc/quirc.h"
}
class qr
{
    public:
    Result qrInit(void);
    Result qrScan(void);
    std::string getDecodedURL(void)
    {
        return url;
    }
    private:
    struct quirc *context;
    u16 *cameraBuffer;
    std::string url;
    int TOPSCREEN_HEIGHT = 400;
    int TOPSCREEN_WIDTH = 240;
    C3D_Tex *tex;
    C2D_Image image;
    Handle events[2] = {0};
    Handle lock;
    Result res;
    s32 transferUnit;
};