#include <stddef.h>

#include "counter.h"

static const counter_res_t error_empty_counter = {
	.value      = 0,

	.error.has  = 1,
	.error.type = EMPTY,
	.error.info = "the empty counter pointer was passed"
};

static const counter_res_t error_overflow_counter = {
	.value      = -1,

	.error.has  = 1,
	.error.type = OVERFLOW,
	.error.info = "counter overflow"
};

counter_res_t
counter_init(counter_t *c)
{
	if (c == NULL) {
		return error_empty_counter;
	}

	c->acc = 0;

	return (counter_res_t){
		.value     = 0,
		.error.has = 0
	};
}

counter_res_t
counter_inc(counter_t *c)
{
	if (c == NULL) {
		return error_empty_counter;
	}

	c->acc++;

	if (c->acc < 0) {
		return error_overflow_counter;
	}

	return (counter_res_t) {
		.value     = c->acc,
		.error.has = 0
	};
}

counter_res_t
counter_amount(counter_t *c)
{
	if (c == NULL) {
		return error_empty_counter;
	}

	return (counter_res_t) {
		.value     = c->acc,
		.error.has = 0
	};
}

counter_res_t
counter_count_to(counter_t *c, size_t limit)
{
	if (c == NULL) {
		return error_empty_counter;
	}

	for (size_t i = 0; i < limit; i++) {
		counter_res_t res;
		res = counter_inc(c);
		if (res.error.has) {
			if (res.error.type == OVERFLOW) {
				return error_overflow_counter;
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
	if (c == NULL) {
		return error_empty_counter;
	}

	c->acc = 0;

	return (counter_res_t) {
		.value     = c->acc,
		.error.has = 0
	};
}











