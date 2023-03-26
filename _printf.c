#include "main.h"
/**
* _printf - is a function that selects the correct function to print.
* @format: identifier to look for.
* Return: the length of the string.
*/
int _printf(const char * const format, ...)
{
	convert_match m[] = {
		{ "%s", printf_string}, {"%c", printf_char},
		{"%%", printf_37},
		{"%i", printf_int}, {"%d", printf_dec}, {"%r", printf_srev},
		{"%R", printf_rot13}, {"%b", printf_bin}, {"%u", printf_unsigned},
		{"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
		{"%S", printfexclusive_string}, {"%p", printf_pointer}
	};
	val_list args;
	int i = 0, j, len = 0;

	val_start(args, format);
	if(format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:

	while(format != '\0')
	{
		j = 13;
		while(j >= 0)
		{
			if(m[j].id[0] == format[i] && m[j].id[1] == format[i+1])
			{
				len += m[j].f(args);
				i = i + 2;
				goto Here;
			}
			j--;
		}
	}
	var_end(args);
	return (len);
}
