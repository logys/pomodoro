#ifndef BUTTON_H
#define BUTTON_H
typedef struct Button{
	short pin;
}Button;

void button_create(Button *, short pin);
short button_read(void);

#endif// BUTTON_H
