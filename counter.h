#ifndef SENTRY_COUNTER_H
#define SENTRY_COUNTER_H

#include <stdint.h>

typedef struct {
	uint64_t acc;
} counter_t;

typedef enum {
	NO_ERROR = 0,
	UNKNOWN  = 1,
	OVERFLOW = 2,
	EMPTY    = 3
} counter_err_t;

typedef struct {
	counter_err_t errcode;
} counter_res_t;

/* Lifetime managment. */
counter_t *counter_create();

void counter_destroy(counter_t *c);

/* Modifiers. */
counter_res_t counter_init(counter_t *c);

counter_res_t counter_reset(counter_t *c);

counter_res_t counter_inc(counter_t *c);

counter_res_t counter_count_to(counter_t *c, size_t limit);

/* State. */
counter_res_t counter_amount(const counter_t *c, uint64_t *val);

/* Info. */
const char *get_error_message(counter_err_t errcode);

#endif // SENTRY_COUNTER_H 
