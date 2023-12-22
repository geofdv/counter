#ifndef SENTRY_UTILS_H
#define SENTRY_UTILS_H

#include "counter.h"

int has_error(counter_res_t r);
int print_error(counter_res_t r);

#endif // SENTRY_UTILS_H
