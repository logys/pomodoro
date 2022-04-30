#ifndef HAL_HPP
#define HAL_HPP
class Hal {
	public:
		virtual void standBy() = 0;
		virtual void buzzing() = 0;
};
#endif// HAL_HPP
