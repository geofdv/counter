#include <stddef.h>
#include <stdlib.h>

#include "counter.h"

/* Errors processing. */
const char *err_messages[] = {
	"no errors",
	"impossible sitation",
	"counter overflow",
	"the empty counter pointer was passed"
};

/* TODO: out of bound check */
const char *
get_error_message(counter_err_t errcode)
{
	return err_messages[errcode];
}

static const counter_res_t counter_empty = {
	.errcode = EMPTY
};

static const counter_res_t counter_overflow = {
	.errcode = OVERFLOW
};

static const counter_res_t counter_unknown = {
	.errcode = EMPTY
};

static const counter_res_t counter_success = {
	.errcode = NO_ERROR
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

	if (c->acc == UINT64_MAX) {
		return counter_overflow;
	}

	c->acc++;

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
counter_count_to(counter_t *c, uint64_t limit)
{
	if (!c) {
		return counter_empty;
	}

	for (uint64_t i = 0; i < limit; ++i) {
		counter_res_t res;
		res = counter_inc(c);
		if (res.errcode != NO_ERROR) {
			if (res.errcode == OVERFLOW) {
				return counter_overflow;
			} else {
				return counter_unknown;
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

