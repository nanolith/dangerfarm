#pragma once

#define TRY_OR_FAIL(operation, fail_label) \
    do \
    { \
        retval = operation; \
        if (STATUS_SUCCESS != retval) \
        { \
            goto fail_label; \
        } \
    } while (0)

#define TRY_OR_FAIL_MSG(operation, fail_label, message) \
    do \
    { \
        retval = operation; \
        if (STATUS_SUCCESS != retval) \
        { \
            fprintf(stderr, "ERROR %s.\n", message); \
            goto fail_label; \
        } \
    } while (0)
