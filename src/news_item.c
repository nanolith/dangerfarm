#include <dangerfarm/news_content.h>

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
