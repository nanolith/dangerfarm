#pragma once

#include <dangerfarm/callback.h>
#include <dangerfarm/control.h>
#include <dangerfarm/lambda.h>

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
int with_html_content(FILE* out, callback_fn callback, page_context* context);

/* helper macro for writing the above template wrapper. */
#define WRAP_TEMPLATE(fail_label, body) \
    TRY_OR_FAIL(\
        with_html_content(out, \
            lambda(int, (page_context* context, FILE* out), body), context), \
        fail_label)
