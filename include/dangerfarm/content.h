#pragma once

#include <dangerfarm/callback.h>

/**
 * \brief Create the main index page.
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
int main_index(page_context* context, FILE* out);

/**
 * \brief Create the project index page.
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
int project_index(page_context* context, FILE* out);

/**
 * \brief Create the CSS file.
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
int css_file(page_context* context, FILE* out);
