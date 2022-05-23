#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "pomodoro.hpp"
#include "circular_buffer.hpp"
#include "signals.hpp"

class Controller {
	public:
		Controller(Pomodoro * pomodoro, CircularBuffer * buffer) :
		       	pomodoro_{pomodoro}, signals_{buffer}{}
		void addSignal(Signals signal);
		void doIt();
	private:
		void dispatch(Signals signal);
		Pomodoro * pomodoro_;
		CircularBuffer * signals_;
};

#endif// CONTROLLER_HPP
