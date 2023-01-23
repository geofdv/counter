#ifndef SENTRY_COUNTER_H
#define SENTRY_COUNTER_H

typedef struct {
	int acc;
} counter_t;

typedef struct {
	int value;
	int has_err;
	char const *info;
} counter_res_t;

counter_res_t counter_init(counter_t *c);

counter_res_t counter_inc(counter_t *c);

counter_res_t counter_amount(counter_t *c);

counter_res_t counter_count_to(counter_t *c, size_t limit);

#endif // SENTRY_COUNTER_H 
