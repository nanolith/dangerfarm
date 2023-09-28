#pragma once

#include <dangerfarm/callback.h>

/**
 * \brief Create the jemu65c02 page.
 *
 * \note This function assumes that a default page context is passed to it,
 * along with a NULL output file.
 *
 * \param context           The default page context.
 * \param out               NULL and ignored.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int project_jemu65c02_index(page_context* context, FILE* output);
