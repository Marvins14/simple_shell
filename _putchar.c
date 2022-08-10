#include <unistd.h>
/**
 * _putchar - just like function putchar
 *
 * @c: char to take
 * Return: 1 on success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
