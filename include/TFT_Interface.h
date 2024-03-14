
#ifndef TFT_INTERFACE_H_
#define TFT_INTERFACE_H_

typedef enum {
	IMAGE='0',
	VIDEO,
	AUDIO,
	NOTHING_SENT=100
}IOT_Status_t;
void TFT_Init(void);
void TFT_Display(const u16*Image);


#endif /* TFT_INTERFACE_H_ */
