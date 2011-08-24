/*************************************************************
 * This file was automatically generated on 2011-08-23.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_lcd_20x4.h"

#include <string.h>

#define TYPE_WRITE_LINE 1
#define TYPE_CLEAR_DISPLAY 2
#define TYPE_BACKLIGHT_ON 3
#define TYPE_BACKLIGHT_OFF 4
#define TYPE_IS_BACKLIGHT_ON 5
#define TYPE_SET_CONFIG 6
#define TYPE_GET_CONFIG 7
#define TYPE_IS_BUTTON_PRESSED 8
#define TYPE_BUTTON_PRESSED 9
#define TYPE_BUTTON_RELEASED 10

typedef void (*button_pressed_func_t)(uint8_t);
typedef void (*button_released_func_t)(uint8_t);

#ifdef _MSC_VER
	#pragma pack(push)
	#pragma pack(1)

	#define PACKED
#else
	#define PACKED __attribute__((packed))
#endif

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t line;
	uint8_t position;
	char text[20];
} PACKED WriteLine;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED ClearDisplay;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED BacklightOn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED BacklightOff;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED IsBacklightOn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	bool backlight;
} PACKED IsBacklightOnReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	bool cursor;
	bool blinking;
} PACKED SetConfig;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetConfig;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	bool cursor;
	bool blinking;
} PACKED GetConfigReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t button;
} PACKED IsButtonPressed;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	bool pressed;
} PACKED IsButtonPressedReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t button;
} PACKED ButtonPressedCallback;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t button;
} PACKED ButtonReleasedCallback;

#ifdef _MSC_VER
	#pragma pack(pop)
#endif

int lcd_20x4_write_line(LCD20x4 *lcd_20x4, uint8_t line, uint8_t position, char text[20]) {
	if(lcd_20x4->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(lcd_20x4);

	WriteLine wl;
	wl.stack_id = lcd_20x4->stack_id;
	wl.type = TYPE_WRITE_LINE;
	wl.length = sizeof(WriteLine);
	wl.line = line;
	wl.position = position;
	strcpy(wl.text, text);


	ipcon_device_write(lcd_20x4, (char *)&wl, sizeof(WriteLine));

	ipcon_sem_post_write(lcd_20x4);

	return E_OK;
}

int lcd_20x4_clear_display(LCD20x4 *lcd_20x4) {
	if(lcd_20x4->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(lcd_20x4);

	ClearDisplay cd;
	cd.stack_id = lcd_20x4->stack_id;
	cd.type = TYPE_CLEAR_DISPLAY;
	cd.length = sizeof(ClearDisplay);

	ipcon_device_write(lcd_20x4, (char *)&cd, sizeof(ClearDisplay));

	ipcon_sem_post_write(lcd_20x4);

	return E_OK;
}

int lcd_20x4_backlight_on(LCD20x4 *lcd_20x4) {
	if(lcd_20x4->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(lcd_20x4);

	BacklightOn bo;
	bo.stack_id = lcd_20x4->stack_id;
	bo.type = TYPE_BACKLIGHT_ON;
	bo.length = sizeof(BacklightOn);

	ipcon_device_write(lcd_20x4, (char *)&bo, sizeof(BacklightOn));

	ipcon_sem_post_write(lcd_20x4);

	return E_OK;
}

int lcd_20x4_backlight_off(LCD20x4 *lcd_20x4) {
	if(lcd_20x4->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(lcd_20x4);

	BacklightOff bo;
	bo.stack_id = lcd_20x4->stack_id;
	bo.type = TYPE_BACKLIGHT_OFF;
	bo.length = sizeof(BacklightOff);

	ipcon_device_write(lcd_20x4, (char *)&bo, sizeof(BacklightOff));

	ipcon_sem_post_write(lcd_20x4);

	return E_OK;
}

int lcd_20x4_is_backlight_on(LCD20x4 *lcd_20x4, bool *ret_backlight) {
	if(lcd_20x4->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(lcd_20x4);

	lcd_20x4->answer.type = TYPE_IS_BACKLIGHT_ON;
	lcd_20x4->answer.length = sizeof(IsBacklightOnReturn);
	IsBacklightOn ibo;
	ibo.stack_id = lcd_20x4->stack_id;
	ibo.type = TYPE_IS_BACKLIGHT_ON;
	ibo.length = sizeof(IsBacklightOn);

	ipcon_device_write(lcd_20x4, (char *)&ibo, sizeof(IsBacklightOn));

	if(ipcon_answer_sem_wait_timeout(lcd_20x4) != 0) {
		ipcon_sem_post_write(lcd_20x4);
		return E_TIMEOUT;
	}

	IsBacklightOnReturn *ibor = (IsBacklightOnReturn *)lcd_20x4->answer.buffer;
	*ret_backlight = ibor->backlight;

	ipcon_sem_post_write(lcd_20x4);

	return E_OK;
}

int lcd_20x4_set_config(LCD20x4 *lcd_20x4, bool cursor, bool blinking) {
	if(lcd_20x4->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(lcd_20x4);

	SetConfig sc;
	sc.stack_id = lcd_20x4->stack_id;
	sc.type = TYPE_SET_CONFIG;
	sc.length = sizeof(SetConfig);
	sc.cursor = cursor;
	sc.blinking = blinking;

	ipcon_device_write(lcd_20x4, (char *)&sc, sizeof(SetConfig));

	ipcon_sem_post_write(lcd_20x4);

	return E_OK;
}

int lcd_20x4_get_config(LCD20x4 *lcd_20x4, bool *ret_cursor, bool *ret_blinking) {
	if(lcd_20x4->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(lcd_20x4);

	lcd_20x4->answer.type = TYPE_GET_CONFIG;
	lcd_20x4->answer.length = sizeof(GetConfigReturn);
	GetConfig gc;
	gc.stack_id = lcd_20x4->stack_id;
	gc.type = TYPE_GET_CONFIG;
	gc.length = sizeof(GetConfig);

	ipcon_device_write(lcd_20x4, (char *)&gc, sizeof(GetConfig));

	if(ipcon_answer_sem_wait_timeout(lcd_20x4) != 0) {
		ipcon_sem_post_write(lcd_20x4);
		return E_TIMEOUT;
	}

	GetConfigReturn *gcr = (GetConfigReturn *)lcd_20x4->answer.buffer;
	*ret_cursor = gcr->cursor;
	*ret_blinking = gcr->blinking;

	ipcon_sem_post_write(lcd_20x4);

	return E_OK;
}

int lcd_20x4_is_button_pressed(LCD20x4 *lcd_20x4, uint8_t button, bool *ret_pressed) {
	if(lcd_20x4->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(lcd_20x4);

	lcd_20x4->answer.type = TYPE_IS_BUTTON_PRESSED;
	lcd_20x4->answer.length = sizeof(IsButtonPressedReturn);
	IsButtonPressed ibp;
	ibp.stack_id = lcd_20x4->stack_id;
	ibp.type = TYPE_IS_BUTTON_PRESSED;
	ibp.length = sizeof(IsButtonPressed);
	ibp.button = button;

	ipcon_device_write(lcd_20x4, (char *)&ibp, sizeof(IsButtonPressed));

	if(ipcon_answer_sem_wait_timeout(lcd_20x4) != 0) {
		ipcon_sem_post_write(lcd_20x4);
		return E_TIMEOUT;
	}

	IsButtonPressedReturn *ibpr = (IsButtonPressedReturn *)lcd_20x4->answer.buffer;
	*ret_pressed = ibpr->pressed;

	ipcon_sem_post_write(lcd_20x4);

	return E_OK;
}

int lcd_20x4_callback_button_pressed(LCD20x4 *lcd_20x4, const unsigned char *buffer) {
	ButtonPressedCallback *bpc = (ButtonPressedCallback *)buffer;
	((button_pressed_func_t)lcd_20x4->callbacks[bpc->type])(bpc->button);
	return sizeof(ButtonPressedCallback);
}

int lcd_20x4_callback_button_released(LCD20x4 *lcd_20x4, const unsigned char *buffer) {
	ButtonReleasedCallback *brc = (ButtonReleasedCallback *)buffer;
	((button_released_func_t)lcd_20x4->callbacks[brc->type])(brc->button);
	return sizeof(ButtonReleasedCallback);
}

void lcd_20x4_register_callback(LCD20x4 *lcd_20x4, uint8_t cb, void *func) {
    lcd_20x4->callbacks[cb] = func;
}

void lcd_20x4_create(LCD20x4 *lcd_20x4, const char *uid) {
	ipcon_device_create(lcd_20x4, uid);

	lcd_20x4->device_callbacks[TYPE_BUTTON_PRESSED] = lcd_20x4_callback_button_pressed;
	lcd_20x4->device_callbacks[TYPE_BUTTON_RELEASED] = lcd_20x4_callback_button_released;
}
