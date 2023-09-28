#include <dangerfarm/news_content.h>
#include <dangerfarm/status_codes.h>

typedef struct
{
    const char* title;
    const char* description;
    const char* url;
    time_t timestamp;
    callback_fn news_page;
} news_item;

news_item entries[] = {
};

/**
 * \brief Get the count of news items.
 *
 * \returns the count of news items.
 */
size_t news_item_count()
{
    return sizeof(entries) / sizeof(news_item);
}

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
    const char** url, time_t* timestamp, callback_fn* news_page)
{
    if (index < news_item_count())
    {
        *title = entries[index].title;
        *description = entries[index].description;
        *url = entries[index].url;
        *timestamp = entries[index].timestamp;
        *news_page = entries[index].news_page;

        return STATUS_SUCCESS;
    }

    return ERROR_DANGERFARM_INDEX_OUT_OF_BOUNDS;
}
