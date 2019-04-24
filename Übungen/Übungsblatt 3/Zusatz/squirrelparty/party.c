#include <stdio.h>

int squirrel_party(short stueck, char tag) {

	short fun = 0;

	switch(tag) {
		case 'm':
		case 'd':
		case 'M':
		case 'D':
		case 'f':
			if (stueck <= 40 || stueck >= 60 ) {
				fun = 0;
			} else {
				fun = 1;
			}
			break;
		case 's':
		case 'S':
			if ( stueck >= 40 ) {
				fun = 1;
			} else {
				fun = 0;
			}
			break;
		default : 
			break;
	}

	return fun;
}
