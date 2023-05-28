#include <stdio.h>

#include "utils.h"
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
