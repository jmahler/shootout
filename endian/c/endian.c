
/*
 * NAME
 *
 * endian - detect endianess of current system
 *
 * DESCRIPTION
 *
 * This program determines the endianess of the current system and
 * displays the result.
 *
 *   $ endian
 *   Little Endian
 *
 * AUTHOR
 *
 * Jeremiah Mahler <jmmahler@gmail.com>
 * http://github.com/jmahler
 *
 * COPYRIGHT
 *
 * Copyright (c) 2014, Jeremiah Mahler. All Rights Reserved.
 * This project is free software and released under the
 * GNU General Public License.
 */

#include <stdio.h>
#include <inttypes.h>

int main()
{
	uint16_t x = 0x00AB;
	uint8_t *p = (uint8_t*) &x;

	if (0xAB == *p)
		printf("Little Endian\n");
	else
		printf("Big Endian\n");
	
	return 0;
}
