#pragma once

#define lambda(ret, args, body) \
    ({ \
        ret lambda__anon args body \
        &lambda__anon; \
    })
