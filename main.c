#include <stdio.h>

#include "counter.h"
#include "utils.h"

int
main()
{
	enum { count_limit = 3 };

	counter_t           *c1;
	counter_res_t		res;
	uint64_t			value;

	c1 = counter_create();
	if (!c1) {
		fprintf(stderr, "malloc error\n");
		return 1;
	}

	res = counter_init(c1);
	if (has_error(res)) {
		print_error(res);
		return 2;
	}

	res = counter_count_to(c1, count_limit);
	if (has_error(res)) {
		print_error(res);
		return 3;
	}

	res = counter_amount(c1, &value);
	if (has_error(res)) {
		print_error(res);
		return 4;
	}
	printf("counter containts %ld\n", value);

	res = counter_reset(c1);
	if (has_error(res)) {
		print_error(res);
		return 5;
	}

	res = counter_amount(c1, &value);
	if (has_error(res)) {
		print_error(res);
		return 4;
	}
	printf("counter containts %ld after reset\n", value);

	counter_destroy(c1);

	return 0;
}
