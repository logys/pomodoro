#ifndef REBOUND_HPP
#define REBOUND_HPP

#include "services/button.hpp"
#include "pomodoro.hpp"

using namespace Pom;

namespace Reb
{
	enum class State {
		IDLE
	};

	class Rebound 
	{
		private:
			Pomodoro *  pomodoro_;
		public:
			Rebound(Pomodoro * pomodoro) : pomodoro_{pomodoro}
			{}
			void doIt();
			Reb::State currentState();
	};
};
#endif// REBOUND_HPP
