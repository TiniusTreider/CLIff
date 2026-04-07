#include "cliff.h"
#include "control.h"

volatile sig_atomic_t should_stop = 0;

int main(void)
{
	setup();

	while(!should_stop)
	{
		tick();
	}

	clean();

	return 0;
}

