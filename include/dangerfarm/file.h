#pragma once

#include <dangerfarm/callback.h>

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
int with_output_file(const char* filename, callback_fn callback, void* context);
