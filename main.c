#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "counter.h"


int
has_error(struct counter_res r)
{
	return r.has_err != 0;
}

void
print_error(struct counter_res r)
{
	if (r.info == NULL) {
		printf("no errors\n");
		return;
	}
		
	printf("error: %s\n", r.info);
}

int
main(int argc, char *argv[])
{
	enum { count_limit = 3 };
	struct counter c1;

	struct counter_res result;

	result = counter_init(&c1);
	if (has_error(result)) {
		print_error(result);
		return -1;
	}

	/**/
	result = counter_count_to(&c1, count_limit);
	if (has_error(result)) {
		print_error(result);
		return -2;
	}


	result = counter_amount(&c1);
	if (has_error(result)) {
		print_error(result);
		return -3;
	}

	printf("count: %d\n", result.value);
	/**/

	return 0;
}
