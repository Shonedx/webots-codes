#pragma once
#ifndef REMOTE_CONTROL_H
#define REMOTE_CONTROL_H
#include <Allheads.h>
typedef enum 
{
	Idle=0,
	Forward, 
	Back,
	Turn_Left,
	Turn_Right,
	Translate_Left,
	Translate_Right,
	Jump,
	Stop,
}State; //״̬

void CTRL_Enable(int sampling_period);
void CTRL_Disable(void);
void CTRL(void);

extern int Command;
extern State currentstate;
#endif // !1
