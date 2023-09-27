#pragma once

#include <dangerfarm/callback.h>
#include <stdio.h>

typedef struct page_context page_context;

struct page_context
{
    const char* title;
    const char* url;
    const char* site_name;
    const char* description;
};

/**
 * \brief Create a default page context and pass it to the given callback.
 *
 * \param callback              The callback to call with the context.
 * \param out                   The output file for this callback operation.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int with_default_page_context(callback_fn callback, FILE* out);

/**
 * \brief Override the title in a page context, and call the callback with the
 * updated page context.
 *
 * \param title                 The title to override.
 * \param context               The context to override.
 * \param callback              The callback to call with the context.
 * \param out                   The output file for this callback operation.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int with_page_title(
    const char* title, page_context* context, callback_fn callback, FILE* out);

/**
 * \brief Override the url in a page context, and call the callback with the
 * updated page context.
 *
 * \param url                   The url to override.
 * \param context               The context to override.
 * \param callback              The callback to call with the context.
 * \param out                   The output file for this callback operation.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int with_page_url(
    const char* url, page_context* context, callback_fn callback, FILE* out);

/**
 * \brief Override the site name in a page context, and call the callback with
 * the updated page context.
 *
 * \param site_name             The site name to override.
 * \param context               The context to override.
 * \param callback              The callback to call with the context.
 * \param out                   The output file for this callback operation.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int with_page_site_name(
    const char* site_name, page_context* context, callback_fn callback,
    FILE* out);

/**
 * \brief Override the description in a page context, and call the callback with
 * the updated page context.
 *
 * \param description           The description to override.
 * \param context               The context to override.
 * \param callback              The callback to call with the context.
 * \param out                   The output file for this callback operation.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int with_page_description(
    const char* description, page_context* context, callback_fn callback,
    FILE* out);

/* macro for setting the page title. */
#define PAGE_TITLE(fail_label, title, body) \
    TRY_OR_FAIL(\
        with_page_title((title), context, \
            lambda(int, (page_context* context, FILE* out), body), out), \
        fail_label)
