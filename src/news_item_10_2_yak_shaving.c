#include <dangerfarm/boilerplate.h>
#include <dangerfarm/control.h>
#include <dangerfarm/file.h>
#include <dangerfarm/html.h>
#include <dangerfarm/news_content.h>
#include <dangerfarm/page_context.h>
#include <dangerfarm/status_codes.h>
#include <stdio.h>

static int main_content(page_context* context, FILE* out);

/**
 * 10/2 update: yak shaving.
 */
int news_item_10_2_yak_shaving(page_context* context, FILE* out)
{
    int retval;

    WRITE_FILE(done, "static-site/news/2023/10/02/yak_shaving.html", {
        PAGE_TITLE(done, "danger.farm Yak Shaving", {
            PAGE_URL(done,
                "https://danger.farm/news/2023/10/02/yak_shaving.html", {
                PAGE_SITE_NAME(done, "danger.farm", {
                    PAGE_SITE_DESCRIPTION(done,
                        "[ 2023-10-02 ] - "
                        "In which I shave some yaks.", {
                        WRAP_TEMPLATE(done, {
                            TRY_OR_FAIL(main_content(context, out), done);
                            XSUCCESS();
                        });
                        XSUCCESS();
                    });
                    XSUCCESS();
                });
                XSUCCESS();
            });
            XSUCCESS();
        });
        XSUCCESS();
    });

    XSUCCESS();
}

/**
 * \brief The main page content.
 *
 * \param context           The default page context.
 * \param out               NULL and ignored.
 *
 * \returns a status code indicating success or failure.
 *      - STATUS_SUCCESS on success.
 *      - a non-zero error code on failure.
 */
int main_content(page_context* context, FILE* out)
{
    int retval;

    XH1(done, {
        XTEXT(done, "[ 2023-10-02 ] Yak Shaving");
        XSUCCESS();
    });

    XP(done, {
        XTEXT(done,
            "I'm engaged in some yak shaving at the moment. The problem with "
            "projects in general is that they lead down interesting rabbit "
            "holes. Unfortunately, it's often the case that these rabbit holes "
            "are important to kick things along. I'm in ");
        XA_HREF(done, "https://yakshav.es/the-patron-saint-of-yakshaves/", {
            XTEXT(done, "good company");
            XSUCCESS();
        });
        XTEXT(done,
            " when it comes to yak shaving; sometimes I just have to embrace "
            "it.");
        XSUCCESS();
    });

    XP(done, {
        XTEXT(done,
            "This particular yak shaving adventure involves a particular "
            "philosophical question: if I statically generate the content for "
            "this website using a content generator written in C, then "
            "shouldn't I also consider building content libraries in C? I "
            "decided to sort of run with this insane idea. Because, statically "
            "generating web content in C is insane, and I admit that. The "
            "particular feature I wanted was syntax highlighting for my "
            "documents. This led me down the path of considering lexical "
            "analysis for source files, which led me down the path of "
            "being somewhat curmudgeonly about existing C parser libraries. "
            "Fine... I'll write one \"real quick\"...");
        XSUCCESS();
    });

    XP(done, {
        XTEXT(done,
            "Well, that's sort of where I am. For years, I've wanted to build "
            "an extensible C lexer and parser library that I could use to "
            "enable some ideas I have regarding source level reflection, "
            "simple language extensions, importing C source files into a proof "
            "assistant, source code data mining, and of course, syntax "
            "highlighting. Each of these use cases represents a small snow "
            "flake of \"it would be so nice if...\", but when combined, these "
            "form an avalanche of development itch. So, I've been pouring over "
            "ISO/IEC9899:2017, and refining an API that properly captures "
            "these use cases. There are certainly some interesting problems to "
            "be found in a C parser, especially when different use cases care "
            "about different levels of abstraction. More on this later, but "
            "the important thing is that I am being productive, even if that "
            "productivity involves taking a pair of clippers to a yak. There "
            "is a method to my madness.");
        XSUCCESS();
    });

    XSUCCESS();
}
