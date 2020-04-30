#ifndef PUSH_DRIVER_H
#define PUSH_DRIVER_H
typedef enum{PUSH_OFF, PUSH_ON}PUSH_STATE;

void push_init(void);
void push_close(void);
PUSH_STATE push_read(void);


#endif // PUSH_DRIVER_H
