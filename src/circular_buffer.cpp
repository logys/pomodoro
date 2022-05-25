#include "circular_buffer.hpp"

Signals CircularBuffer::get()
{
	Signals signal = data[head_index];
	Count -= 1;
	if(head_index < 9)
		head_index += 1;
	else
		head_index = 0;
	return signal;
}

void CircularBuffer::add(Signals signal)
{
	data[tail_index] = signal;
	Count += 1;
	if(tail_index < 9){
		tail_index += 1;
	}else
		tail_index = 0;

}
