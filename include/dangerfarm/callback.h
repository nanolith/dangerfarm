#pragma once

#include <dangerfarm/page_context_fwd.h>
#include <stdio.h>

/**
 * \brief The callback function is called with a page context and an output
 * file.
 *
 * \param context           Pointer to the page context for this callback.
 * \param out               The output file for this callback operation.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - non-zero error code on failure.
 */
typedef int (*callback_fn)(page_context* context, FILE* out);
