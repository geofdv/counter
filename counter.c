#include <stddef.h>
#include <stdlib.h>

#include "counter.h"

static const counter_res_t counter_error_empty = {
	.value      = 0,

	.error.has  = 1,
	.error.type = EMPTY,
	.error.info = "the empty counter pointer was passed"
};

static const counter_res_t counter_error_overflow = {
	.value      = -1,

	.error.has  = 1,
	.error.type = OVERFLOW,
	.error.info = "counter overflow"
};

/*
  we don't use counter_res_t as the return type here,
  because we assume that bad result of malloc call it's not a "counter" type error,
  it's error of runtime (OS).
*/
counter_t *
create_counter()
{
	counter_t *c = malloc(sizeof(*c));

	return c;
}

void
destroy_counter(counter_t *c)
{
	free(c);
}

counter_res_t
counter_init(counter_t *c)
{
	if (NULL == c) {
		return counter_error_empty;
	}

	c->acc = 0;

	return (counter_res_t) {
		.value     = 0,
		.error.has = 0
	};
}

counter_res_t
counter_inc(counter_t *c)
{
	if (NULL == c) {
		return counter_error_empty;
	}

	c->acc++;

	if (c->acc == 0) {
		return counter_error_overflow;
	}

	return (counter_res_t) {
		.value     = c->acc,
		.error.has = 0
	};
}

counter_res_t
counter_amount(counter_t *c)
{
	if (NULL == c) {
		return counter_error_empty;
	}

	return (counter_res_t) {
		.value     = c->acc,
		.error.has = 0
	};
}

counter_res_t
counter_count_to(counter_t *c, size_t limit)
{
	if (NULL == c) {
		return counter_error_empty;
	}

	for (size_t i = 0; i < limit; i++) {
		counter_res_t res;
		res = counter_inc(c);
		if (res.error.has) {
			if (res.error.type == OVERFLOW) {
				return counter_error_overflow;
			}
		}
	}

	return (counter_res_t) {
		.value     = c->acc,
		.error.has = 0
	};
}


counter_res_t
counter_reset(counter_t *c)
{
	if (NULL == c) {
		return counter_error_empty;
	}

	c->acc = 0;

	return (counter_res_t) {
		.value     = c->acc,
		.error.has = 0
	};
}

