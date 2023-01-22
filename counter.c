#include <stddef.h>

#include "counter.h"

static const struct counter_res error_empty_counter = {
	.has_err = 1,
	.info = "the empty counter pointer was passed"
};

struct counter_res
counter_init(struct counter *c)
{
	struct counter_res result;

	if (c == NULL) {
		return error_empty_counter;
	}

	c->acc = 0;

	result.has_err = 0;

	return result;
}

struct counter_res
counter_inc(struct counter *c)
{
	struct counter_res result;

	if (c == NULL) {
		return error_empty_counter;
	}

	c->acc++;

	result.has_err = 0;

	return result;
}

struct counter_res
counter_amount(struct counter *c)
{
	struct counter_res result;

	if (c == NULL) {
		return error_empty_counter;
	}

	result.value = c->acc;
	result.has_err = 0;

	return result;
}

struct counter_res
counter_count_to(struct counter *c, size_t limit)
{
	struct counter_res result;

	if (c == NULL) {
		return error_empty_counter;
	}

	for (size_t i = 0; i < limit; i++) {
		counter_inc(c);
	}

	result.has_err = 0;

	return result;
}
