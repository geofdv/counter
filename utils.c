#include <stdio.h>

#include "utils.h"
#include "counter.h"

int
has_error(counter_res_t r)
{
	return r.errcode != NO_ERROR;
}

int
print_error(counter_res_t r)
{
	const char *msg = get_error_message(r.errcode);

	return fprintf(stderr, "error: %s\n", msg);
}
