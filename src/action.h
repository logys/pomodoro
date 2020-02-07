#ifndef ACTION_H
#define ACTION_H

typedef enum run_state{ACTION_RUNNING, ACTION_REACHED, ACTION_POWEROFF, 
	ACTION_PAUSE, ACTION_DISABLED}RUN_STATE;
void initAction(void);
void (*action)(void);
void setActionPowerOff(void);
void setActionTogglePlayPause(void);


#endif // ACTION_H
