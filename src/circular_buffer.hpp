#ifndef CIRCULAR_BUFFER_HPP
#define CIRCULAR_BUFFER_HPP

#include "signals.hpp"
#include <cstdint>

class CircularBuffer{
	public:
		std::uint16_t Count = 0;
		Signals get();
		void add(Signals signal);
	private:
		short head_index = 0;
		short tail_index = 0;
		Signals data[10];
};
#endif// CIRCULAR_BUFFER_HPP
