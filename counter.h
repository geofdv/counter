#ifndef SENTRY_COUNTER_H
#define SENTRY_COUNTER_H

typedef struct {
	long acc;
} counter_t;

typedef enum {
	NO_ERROR =  0,
	OVERFLOW = -1,
	EMPTY    = -2
} counter_error_t;

typedef struct {
	long value;

	struct {
		int              has;
		counter_error_t  type;
		char const*      info;
	} error;

} counter_res_t;

counter_res_t counter_init(counter_t *c);

counter_res_t counter_inc(counter_t *c);

counter_res_t counter_amount(counter_t *c);

counter_res_t counter_reset(counter_t *c);

counter_res_t counter_count_to(counter_t *c, size_t limit);

#endif // SENTRY_COUNTER_H 
