#include "shell.h"
/**
 * handler - handles the ctrl-c signal
 * @han: signal received
 * Return: Nothing.
 */
void handler(int han)
{
	(void)han;
	write(1, "\n#cisfun$ ", 10);
}
