#!/usr/bin/octave -qf

if (2 != length(argv()))
	printf('usage: %s <start> <n>', program_name());
	exit(1);
endif

num = str2num(argv(){1});
max = str2num(argv(){2});

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
