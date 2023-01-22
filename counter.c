#include <stddef.h>

#include "counter.h"

static const struct counter_res error_empty_counter = {
	.has_err = 1,
	.info = "the empty counter pointer was passed"
};

struct counter_res
counter_init(struct counter *c)
{
	if (c == NULL) {
		return error_empty_counter;
	}

	c->acc = 0;

	return (struct counter_res){
		.value   = 0,
		.has_err = 0
	};
}

struct counter_res
counter_inc(struct counter *c)
{
	if (c == NULL) {
		return error_empty_counter;
	}

	c->acc++;

	return (struct counter_res) {
		.value   = c->acc,
		.has_err = 0
	};
}

struct counter_res
counter_amount(struct counter *c)
{
	if (c == NULL) {
		return error_empty_counter;
	}

	return (struct counter_res) {
		.value   = c->acc,
		.has_err = 0
	};
}

struct counter_res
counter_count_to(struct counter *c, size_t limit)
{
	if (c == NULL) {
		return error_empty_counter;
	}

	for (size_t i = 0; i < limit; i++) {
		counter_inc(c);
	}

	return (struct counter_res) {
		.value   = c->acc,
		.has_err = 0
	};
}
