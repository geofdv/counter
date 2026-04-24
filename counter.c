#include <stddef.h>
#include <stdlib.h>

#include "counter.h"

/* Errors processing. */
const char *err_messages[] = {
	[NO_ERROR] = "no errors",
	[NULL_PTR] = "null pointer was passed",
	[OVERFLOW] = "counter overflow"
};

/* TODO: out of bound check */
const char *
get_error_message(counter_err_t errcode)
{
	return err_messages[errcode];
}

static const counter_res_t counter_success = {
	.errcode = NO_ERROR
};

static const counter_res_t counter_null_ptr = {
	.errcode = NULL_PTR
};

static const counter_res_t counter_overflow = {
	.errcode = OVERFLOW
};

/* Public api. */

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
		return counter_null_ptr;
	}

	c->acc = 0;

	return counter_success;
}


counter_res_t
counter_set(counter_t *c, uint64_t limit)
{
	if (!c) {
		return counter_null_ptr;
	}

	c->acc = limit;

	return counter_success;
}

counter_res_t
counter_reset(counter_t *c)
{
	if (!c) {
		return counter_null_ptr;
	}

	c->acc = 0;

	return counter_success;
}

counter_res_t
counter_inc(counter_t *c)
{
	return counter_add(c, 1);
}

counter_res_t
counter_add(counter_t *c, uint64_t limit)
{
	if (!c) {
		return counter_null_ptr;
	}

	if (c->acc > UINT64_MAX - limit)
	{
		return counter_overflow;
	}

	c->acc += limit;

	return counter_success;
}

counter_res_t
counter_amount(const counter_t *c, uint64_t *val)
{
	if (!c) {
		return counter_null_ptr;
	}

	*val = c->acc;

	return counter_success;
}

