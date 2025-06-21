#ifndef GLARKI_DEFINE_H
#define GLARKI_DEFINE_H

#ifdef _WIN32
#define ARKI_API __declspec(dllexport)
#else
#define ARKI_API __attribute__((visibility("default")))
#endif

#endif