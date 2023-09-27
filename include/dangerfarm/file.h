#pragma once

#include <dangerfarm/callback.h>
#include <dangerfarm/control.h>
#include <dangerfarm/lambda.h>

/**
 * \brief Attempts to open the given file for writing, passing it to the
 * provided callback function along with the provided context.
 *
 * \note The file is closed when the callback function returns.
 *
 * \param filename              The name of the file to open for writing.
 * \param callback              The callback function to call when this file is
 *                              opened for writing.
 * \param context               The context value to pass to the callback
 *                              function.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - non-zero error code on failure.
 */
int with_output_file(
    const char* filename, callback_fn callback, page_context* context);

/**
 * \brief Copy a file to the output stream.
 *
 * \param filename              The name of the file to copy.
 * \param context               The page context.
 * \param out                   The output stream.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int copy_file(
    const char* filename, page_context* context, FILE* out);

/* macro for opening output file. */
#define WRITE_FILE(fail_label, filename, body) \
    TRY_OR_FAIL(\
        with_output_file((filename), \
            lambda(int, (page_context* context, FILE* out), body), context), \
        fail_label)
