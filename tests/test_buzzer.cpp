#include <gtest/gtest.h>
#include "buzzer.hpp"
#include "pin.hpp"
#include "powerdown.hpp"

class PowerDownStub : public PowerDown {
	public:
		void standBy(){stand_by_ = true;}
		bool standbyCalled(){return stand_by_;}
	private:
		bool stand_by_ = false;
};

class BuzzerTest : public ::testing::Test {
	protected:
		PowerDownStub * power_down;
		Buzzer * buzzer;
		virtual void SetUp() override
		{
			power_down = new PowerDownStub();
			buzzer = new Buzzer(power_down);
		}
		virtual void TearDown() override
		{
			delete buzzer;
			delete power_down;
		}
};

TEST_F(BuzzerTest, should_call_sdtandby)
{
	buzzer->doit();

	ASSERT_TRUE(power_down->standbyCalled());
}
