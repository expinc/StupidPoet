#pragma once


const char* g_locale = "zh_CN.UTF-8";


#if defined(WIN32) || defined(_WIN32)
#define PATH_SEPARATOR "\\"
#define PATH_SEPARATOR_U16 u"\\"
#else
#define PATH_SEPARATOR "/"
#define PATH_SEPARATOR_U16 u"/"
#endif
