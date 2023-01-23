#include <stddef.h>

#include "counter.h"

static const counter_res_t error_empty_counter = {
	.has_err = 1,
	.info = "the empty counter pointer was passed"
};

counter_res_t
counter_init(counter_t *c)
{
	if (c == NULL) {
		return error_empty_counter;
	}

	c->acc = 0;

	return (counter_res_t){
		.value   = 0,
		.has_err = 0
	};
}

counter_res_t
counter_inc(counter_t *c)
{
	if (c == NULL) {
		return error_empty_counter;
	}

	c->acc++;

	return (counter_res_t) {
		.value   = c->acc,
		.has_err = 0
	};
}

counter_res_t
counter_amount(counter_t *c)
{
	if (c == NULL) {
		return error_empty_counter;
	}

	return (counter_res_t) {
		.value   = c->acc,
		.has_err = 0
	};
}

counter_res_t
counter_count_to(counter_t *c, size_t limit)
{
	if (c == NULL) {
		return error_empty_counter;
	}

	for (size_t i = 0; i < limit; i++) {
		counter_inc(c);
	}

	return (counter_res_t) {
		.value   = c->acc,
		.has_err = 0
	};
}
