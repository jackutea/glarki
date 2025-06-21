#ifndef GLARKI_AKCOLOR_H
#define GLARKI_AKCOLOR_H
#include <glarki/define.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    unsigned char r; // Red component (0-255)
    unsigned char g; // Green component (0-255)
    unsigned char b; // Blue component (0-255)
    unsigned char a; // Alpha component (0-255, 0 is fully transparent, 255 is
                     // fully opaque)
} AKColorByte;

typedef struct {
    float r; // Red component (0.0-1.0)
    float g; // Green component (0.0-1.0)
    float b; // Blue component (0.0-1.0)
    float a; // Alpha component (0.0-1.0, 0 is fully transparent, 1 is fully
             // opaque)
} AKColorFloat;

struct {
    AKColorFloat (*ToFloat)(AKColorByte color);
    AKColorByte (*ToByte)(AKColorFloat color);
} AKColor_Func;

ARKI_API AKColorFloat AKColor_ToFloat(AKColorByte color);
ARKI_API AKColorByte AKColor_ToByte(AKColorFloat color);
void AKColor_BindingFunctions();

#ifdef __cplusplus
}
#endif

#endif