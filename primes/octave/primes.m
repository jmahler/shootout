#!/usr/bin/octave --silent

max = 200;
num = 2;
count = 0;

while count < max
	found = 1;
	for i = 2:(num - 1)
		if (0 == mod(num, i))
			found = 0;
			break;
		endif
	endfor

	if found
		printf('%i\n', num)
		count = count + 1;
	endif

	num = num + 1;
endwhile
