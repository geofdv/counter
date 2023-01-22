#ifndef SENTRY_TYPES_H
#define SENTRY_TYPES_H

struct counter_res {
	int value;
	int has_err;
	char const *info;
};

#endif // SENTRY_TYPES_H
