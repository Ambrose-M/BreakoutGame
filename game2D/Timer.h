#pragma once

#include <SDL.h>

class Timer
{
public:
	//Initializes variables
	Timer();

	//The various clock actions
	void start();
	void stop();
	void pause();
	void unpause();

	//Gets the timer's time
	Uint32 getTime();

	//Checks the status of the timer
	bool isStarted();
	bool isPaused();

private:
	//The clock time when the timer started
	Uint32 startTime;

	//The ticks stored when the timer was paused
	Uint32 pausedTime;

	//The timer status
	bool paused;
	bool started;
};
