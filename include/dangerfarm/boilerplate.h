#pragma once

#include <dangerfarm/callback.h>

/**
 * \brief Write the header boilerplate for an HTML file, then call the
 * callback at the start of the content, then write the footer boilerplate.
 *
 * \param out                       The output file to which the boilerplate
 *                                  should be written.
 * \param callback                  The callback to call to generate HTML
 *                                  content between boilerplate.
 * \param context                   The context to pass the callback.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int with_html_content(FILE* out, callback_fn callback, void* context);
