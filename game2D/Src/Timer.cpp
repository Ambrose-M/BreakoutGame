#include "Timer.h"

Timer::Timer()
{
	startTime = 0;
	pausedTime = 0;

	started = false;
	paused = false;
}

void Timer::start()
{
	//Start timer
	started = true;

	//Unpause timer
	paused = false;

	//Get clock time
	startTime = SDL_GetTicks();
	pausedTime = 0;
}

void Timer::pause()
{
	//If timer hasn't started and isn't paused
	if (started && !paused)
	{
		//Pause timer
		paused = true;

		//Get time paused
		pausedTime = SDL_GetTicks() - startTime;
		startTime = 0;
	}
}

void Timer::unpause()
{
	//If timer has started and is paused
	if (started && paused)
	{
		//Unpause timer
		paused = false;

		//Reset start time
		startTime = SDL_GetTicks() - pausedTime;

		//Reset paused time
		pausedTime = 0;
	}
}

void Timer::stop()
{
	//Stop timer
	started = false;

	//Unpause timer
	paused = false;

	//Clear variables
	startTime = 0;
	pausedTime = 0;
}

Uint32 Timer::getTime()
{
	//The actual timer time
	Uint32 time = 0;

	//If timer has started
	if (started)
	{
		//If timer is paused
		if (paused)
		{
			//Return the time that the timer was paused
			time = pausedTime;
		}
		else
		{
			//Return the current time minus the start time
			time = SDL_GetTicks() - startTime;
		}
	}

	return time;
}

bool Timer::isStarted()
{
	//Timer has started
	return started;
}

bool Timer::isPaused()
{
	//Timer has started and is paused
	return started && paused;
}


