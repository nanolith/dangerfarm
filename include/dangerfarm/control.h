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
