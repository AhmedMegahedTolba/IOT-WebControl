/*
 * TFT_Private.h
 *
 *  Created on: Feb 5, 2024
 *      Author: HIFINE
 */

#ifndef TFT_PRIVATE_H_
#define TFT_PRIVATE_H_


#define TFT_DATA_RGB_444             0x03
#define TFT_DATA_RGB_565             0x05
#define TFT_DATA_RGB_666             0x06


#define TFT_CMD_SLEEP_OUT_MODE                  0x11
#define TFT_CMD_COLOR_MODE                      0x3A
#define TFT_CMD_DISPLAY_MODE                    0x29
#define TFT_CMD_SET_X_POSITION_MODE             0x2A
#define TFT_CMD_SET_Y_POSITION_MODE             0x2B
#define TFT_CMD_WRITEON_RAM_MODE                0x2C


static void TFT_WriteData(u8 data);
static void TFT_WriteCommand(u8 data);
static void TFT_RESET(void);






#endif /* TFT_PRIVATE_H_ */
