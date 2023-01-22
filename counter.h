#ifndef SENTRY_COUNTER_H
#define SENTRY_COUNTER_H

#include "types.h"

struct counter {
	int acc;
};

struct counter_res counter_init(struct counter *c);

struct counter_res counter_inc(struct counter *c);

struct counter_res counter_amount(struct counter *c);

struct counter_res counter_count_to(struct counter *c, size_t limit);

#endif // SENTRY_COUNTER_H 
