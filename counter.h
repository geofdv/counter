#ifndef SENTRY_COUNTER_H
#define SENTRY_COUNTER_H

struct counter {
	int acc;
};

struct counter_res {
	int value;
	int has_err;
	char const *info;
};

struct counter_res counter_init(struct counter *c);

struct counter_res counter_inc(struct counter *c);

struct counter_res counter_amount(struct counter *c);

struct counter_res counter_count_to(struct counter *c, size_t limit);

#endif // SENTRY_COUNTER_H 
