#include "AKColor.h"

AKColorFloat ToFloat(AKColorByte color) {
    AKColorFloat result;
    result.r = color.r / 255.0f;
    result.g = color.g / 255.0f;
    result.b = color.b / 255.0f;
    result.a = color.a / 255.0f;
    return result;
}

AKColorByte ToByte(AKColorFloat color) {
    AKColorByte result;
    result.r = (unsigned char)(color.r * 255.0f);
    result.g = (unsigned char)(color.g * 255.0f);
    result.b = (unsigned char)(color.b * 255.0f);
    result.a = (unsigned char)(color.a * 255.0f);
    return result;
}

void AKColor_BindingFunctions() {
    AKColor_Func.ToByte = ToByte;
    AKColor_Func.ToFloat = ToFloat;
}