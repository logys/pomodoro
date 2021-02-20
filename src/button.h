#ifndef BUTTON_H
#define BUTTON_H

typedef enum {OFF, ON}BUTTON_STATE;

typedef struct Button{
	short pin;
}Button;

Button button_create(short pin);
BUTTON_STATE button_read(Button *);

#endif// BUTTON_H
