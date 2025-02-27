#include <Remote_Control.h>
static int Command;
State currentstate =Idle;
int Jump_OK=1;
int Jump_Start = 1;
void CTRL(void)
{
	Command = wb_keyboard_get_key();
	
	if (Command == WB_KEYBOARD_LEFT)
	{
		currentstate = Turn_Left;

	}
	else if (Command == WB_KEYBOARD_RIGHT)
	{
		currentstate = Turn_Right;

	}

	else if (Command == WB_KEYBOARD_UP)
	{

		currentstate = Forward;

	}
	else if (Command == WB_KEYBOARD_DOWN)
	{
		currentstate = Back;

	}
	else if (Command == WB_KEYBOARD_END)
	{
		int change = wb_keyboard_get_key();
		if (change == WB_KEYBOARD_HOME)
		{
			currentstate = Jump;
			if (Jump_Start == 1)
			{
				Start_Jump();
				Jump_Start = 0;
			}
		}
		else
		{
			currentstate = Stop;
			Jump_Start = 1;
		}
	}
	
	if (Command == WB_KEYBOARD_HOME)
	{
		currentstate = Jump;
		if (Jump_Start == 1)
		{
			Start_Jump();
			Jump_Start = 0;
		}
	}
	if (Command == -1)
	{
		currentstate = Idle;
	}
}
void CTRL_Enable(int sampling_period)
{
	 wb_keyboard_enable(sampling_period);
}
void CTRL_Disable(void)
{
	 wb_keyboard_disable();
}
