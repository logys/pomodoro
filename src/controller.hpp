#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "pomodoro.hpp"
#include "circular_buffer.hpp"
#include "signals.hpp"

class Controller {
	public:
		Controller(Pomodoro * pomodoro, CircularBuffer * buffer, Hal * bsp) :
		       	pomodoro_{pomodoro}, queue_signals_{buffer}, bsp_{bsp}{}
		void addSignal(Signals signal);
		void doIt();
	private:
		Pomodoro * pomodoro_;
		CircularBuffer * queue_signals_;
		Hal * bsp_;
		void dispatch();
		bool thereIsSignals();
};

#endif// CONTROLLER_HPP
