#pragma once

#include <dangerfarm/callback.h>
#include <time.h>

/**
 * \brief Get the count of news items.
 *
 * \returns the count of news items.
 */
size_t news_item_count();

/**
 * \brief Get a news item by index.
 *
 * \param index                 The index for the news item.
 * \param title                 Pointer to the title pointer to populate on
 *                              success.
 * \param description           Pointer to the description pointer to populate
 *                              on success.
 * \param url                   Pointer to the url pointer to populate on
 *                              success.
 * \param timestamp             Pointer to the time_t variable to receive the
 *                              timestamp for this item.
 * \param news_page             Pointer to the news page callback to populate on
 *                              success.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
size_t news_item_get(
    size_t index, const char** title, const char** description,
    const char** url, time_t* timestamp, callback_fn* news_page);

/******************************************************************************/
/* News Items                                                                 */
/******************************************************************************/

/**
 * Website launch.
 */
int news_item_website_launch(page_context* context, FILE* out);

/**
 * 10/2 update: yak shaving.
 */
int news_item_10_2_yak_shaving(page_context* context, FILE* out);
