#pragma once

#define INTERNAL_CAT(a, b) INTERNAL_CAT_I(a, b)
#define INTERNAL_CAT_I(a, b) a##b

#define VAR_DEFINE(name, id) INTERNAL_CAT(name, id)