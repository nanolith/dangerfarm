#pragma once

#include <dangerfarm/callback.h>

/**
 * \brief Write the given HTML begin tag, call the callback, then write the
 * given HTML end tag.
 *
 * \param out               The output file to which the tags should be written.
 * \param begin             The begin tag string.
 * \param end               The end tag string.
 * \param callback          The callback to call between begin and end tags.
 * \param context           The context to pass to the callback.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int with_tags(
    FILE* out, const char* begin, const char* end, callback_fn callback,
    void* context);