#include <stddef.h>
#include <stdlib.h>

#include "counter.h"

static const counter_res_t counter_empty = {
	.error.has  = 1,
	.error.type = EMPTY,
	.error.info = "the empty counter pointer was passed"
};

static const counter_res_t counter_overflow = {
	.error.has  = 1,
	.error.type = OVERFLOW,
	.error.info = "counter overflow"
};

static const counter_res_t counter_success = {
	.error.has = 0
};

counter_t *
counter_create()
{
	counter_t *c = malloc(sizeof(*c));

	return c;
}

void
counter_destroy(counter_t *c)
{
	free(c);
}

counter_res_t
counter_init(counter_t *c)
{
	if (!c) {
		return counter_empty;
	}

	c->acc = 0;

	return counter_success;
}

counter_res_t
counter_inc(counter_t *c)
{
	if (!c) {
		return counter_empty;
	}

	c->acc++;
	if (c->acc == 0) {
		return counter_overflow;
	}

	return counter_success;
}

counter_res_t
counter_amount(const counter_t *c, uint64_t *val)
{
	if (!c) {
		return counter_empty;
	}

	*val = c->acc;

	return counter_success;
}

counter_res_t
counter_count_to(counter_t *c, size_t limit)
{
	if (!c) {
		return counter_empty;
	}

	for (size_t i = 0; i < limit; i++) {
		counter_res_t res;
		res = counter_inc(c);
		if (res.error.has) {
			if (res.error.type == OVERFLOW) {
				return counter_overflow;
			}
		}
	}

	return counter_success;
}


counter_res_t
counter_reset(counter_t *c)
{
	if (!c) {
		return counter_empty;
	}

	c->acc = 0;

	return counter_success;
}

