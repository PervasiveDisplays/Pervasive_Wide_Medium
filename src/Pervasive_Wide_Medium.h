///
/// @file Pervasive_Wide_Medium.h
/// @brief Driver for medium screens with wide temperature and embedded fast update
///
/// @details Project Pervasive Displays Library Suite
/// @n Based on highView technology
///
/// @author Rei Vilo
/// @date 21 Jan 2025
/// @version 902
///
/// @copyright (c) Pervasive Displays, 2010-2025
/// @copyright All rights reserved
/// @copyright For exclusive use with Pervasive Displays screens
///
/// * Basic edition: for hobbyists and for basic usage
/// @n Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)
/// @see https://creativecommons.org/licenses/by-sa/4.0/
///
/// @n Consider the Evaluation or Commercial editions for professionals or organisations and for commercial usage
///
/// * Evaluation edition: for professionals or organisations, evaluation only, no commercial usage
/// @n All rights reserved
///
/// * Commercial edition: for professionals or organisations, commercial usage
/// @n All rights reserved
///
/// * Viewer edition: for professionals or organisations
/// @n All rights reserved
///
/// * Documentation
/// @n All rights reserved
///
/// @see Application notes
/// * ApplicationNote_EPD3.40_WildTemp(E2340KS0G1)_20241015
/// * ApplicationNote_DualChip_wideTemperature_EPD_v01_20230804
/// * ApplicationNote_SingleChip_wideTemperature_EPD_v01_20230720
///

// SDK and configuration
#include "PDLS_Common.h"

#if (PDLS_COMMON_RELEASE < 902)
#error Required PDLS_COMMON_RELEASE 902
#endif // PDLS_COMMON_RELEASE

// Driver
#include "Driver_EPD_Virtual.h"

#ifndef DRIVER_WIDE_MEDIUM_RELEASE
///
/// @brief Library release number
///
#define DRIVER_WIDE_MEDIUM_RELEASE 902

///
/// @name List of supported screens
/// @details Wide temperature and embedded fast update
///
/// @note Normal and fast update
/// @see https://www.pervasivedisplays.com/products-e-ink-display/?_sft_etc_itc=pu%20itc&_sft_temperature_range=m15c-to-p60c
/// @{
///
#define eScreen_EPD_340_KS_0G SCREEN(SIZE_340, FILM_K, DRIVER_G) ///< reference 150-KS-0J
#define eScreen_EPD_581_KS_06 SCREEN(SIZE_581, FILM_K, DRIVER_6) ///< reference 150-KS-0J
#define eScreen_EPD_741_KS_06 SCREEN(SIZE_741, FILM_K, DRIVER_6) ///< reference 152-KS-0J
/// @}

///
/// @name List of features
/// @{
///
#define WITH_MONOCHROME ///< With B&W only
#define WITH_FAST ///< With fast update capability
/// @}

///
/// @brief Driver variant
///
#define DRIVER_EPD_RELEASE DRIVER_WIDE_MEDIUM_RELEASE
#define DRIVER_EPD_VARIANT "Wide medium"

///
/// @brief Wide medium screens class
///
class Pervasive_Wide_Medium : public Driver_EPD_Virtual
{
  public:

    ///
    /// @brief Constructor
    /// @param eScreen_EPD_EXT3 size and model of the e-screen
    /// @param board board configuration
    ///
    Pervasive_Wide_Medium(eScreen_EPD_t eScreen_EPD, pins_t board);

    /// @name General
    /// @{

    ///
    /// @brief Initialisation
    /// @details Initialise the board and read OTP
    ///
    void begin();

    ///
    /// @brief Driver reference
    ///
    /// @return STRING_CONST_TYPE scope and release number
    /// @note Example `Wide medium v9.0.0`
    ///
    STRING_CONST_TYPE reference();

    ///
    /// @brief Normal update
    ///
    /// @param frame next image
    /// @param sizeFrame size of the frame
    ///
    void updateNormal(FRAMEBUFFER_CONST_TYPE frame, uint32_t sizeFrame);

    ///
    /// @brief Fast update
    ///
    /// @param frame next image
    /// @param frame2 previous image
    /// @param sizeFrame size of the frame
    ///
    void updateFast(FRAMEBUFFER_CONST_TYPE frame, FRAMEBUFFER_CONST_TYPE frame2, uint32_t sizeFrame);

    /// @}

protected:

private:

    // Variables and functions specific to the screen
    uint8_t COG_data[128]; // OTP

    void COG_reset();
    void COG_getDataOTP();
    void COG_initial();
    void COG_sendImageDataNormal(FRAMEBUFFER_CONST_TYPE nextFrame, uint32_t sizeFrame);
    void COG_sendImageDataFast(FRAMEBUFFER_CONST_TYPE previousFrame, FRAMEBUFFER_CONST_TYPE nextFrame, uint32_t sizeFrame);
    void COG_update(uint8_t updateMode);
    void COG_stopDCDC();
};

#endif // DRIVER_WIDE_MEDIUM_RELEASE
