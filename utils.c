#include <stdio.h>

#include "utils.h"
#include "counter.h"

int
has_error(counter_res_t r)
{
	return r.error.has != 0;
}

int
print_error(counter_res_t r)
{
	if (r.error.info == NULL) {
		return 0;
	}

	return fprintf(stderr, "error: %s\n", r.error.info);
}
