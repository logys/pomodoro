#ifndef IPOMODORO_HPP
#define IPOMODORO_HPP
class IPomodoro {
	public:
		virtual void add1Second() = 0;
		virtual void enable() = 0;
};
#endif// IPOMODORO_HPP
