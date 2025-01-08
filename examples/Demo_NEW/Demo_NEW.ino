#include "Pervasive_Wide_Medium.h"

#define SCRN 581
#include "globalupdate_src/demoImageData.h"
#include "fastupdate_src/Fast_Data.h"

Pervasive_Wide_Medium myDriver(eScreen_EPD_581_KS_06, boardRaspberryPiPico_RP2040);

void setup()
{
    hV_HAL_begin();

    myDriver.begin();

    myDriver.updateNormal(BW_monoBuffer, frameSize);

    myDriver.updateFast(FastPic_2, FastPic_1, frameSize);
    myDriver.updateFast(FastPic_1, FastPic_2, frameSize);
    myDriver.updateFast(FastPic_2, FastPic_1, frameSize);
    myDriver.updateFast(FastPic_1, FastPic_2, frameSize);
    myDriver.updateFast(FastPic_b, FastPic_1, frameSize);
    myDriver.updateFast(FastPic_w, FastPic_b, frameSize);

    hV_HAL_exit();
}

void loop()
{
    hV_HAL_delayMilliseconds(1000);
}
