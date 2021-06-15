#ifndef ACTION_H
#define ACTION_H

enum ActionType{
	POWEROFF,
	TOGGLE,
	PLAY
};

void action_set_play(void);
void action_set_pause(void);
void action_set_poweroff(void);

#endif // ACTION_H
