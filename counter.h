#ifndef SENTRY_COUNTER_H
#define SENTRY_COUNTER_H

#include <stdint.h>

typedef struct {
	uint64_t acc;
} counter_t;

typedef enum {
	NO_ERROR =  0,
	UNKNOWN  = -1,
	OVERFLOW = -2,
	EMPTY    = -3
} counter_err_t;

typedef struct {

	struct {
		int             has;
		counter_err_t   type;
		const char*     info;
	} error;

} counter_res_t;

counter_t *counter_create();

void counter_destroy(counter_t *c);

counter_res_t counter_init(counter_t *c);

counter_res_t counter_reset(counter_t *c);

counter_res_t counter_inc(counter_t *c);

counter_res_t counter_amount(const counter_t *c, uint64_t *val);

counter_res_t counter_count_to(counter_t *c, size_t limit);

#endif // SENTRY_COUNTER_H 
