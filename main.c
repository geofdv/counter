#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "counter.h"


int
has_error(counter_res_t r)
{
	return r.error.has != 0;
}

void
print_error(counter_res_t r)
{
	if (r.error.info == NULL) {
		printf("no errors\n");
		return;
	}
		
	printf("error: %s\n", r.error.info);
}

int
main(int argc, char *argv[])
{
	enum { count_limit = 3 };
	counter_t c1;

	counter_res_t result;

	result = counter_init(&c1);
	if (has_error(result)) {
		print_error(result);
		return -1;
	}

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

	printf("count: %ld\n", result.value);


	result = counter_reset(&c1);
	if (has_error(result)) {
		print_error(result);
		return -4;
	}

	printf("value after reset: %ld\n", result.value);

	return 0;
}
