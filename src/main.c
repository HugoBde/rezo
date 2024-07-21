#include <stdlib.h>

#include "commons.h"
#include "layer.h"

int main(void) {
    const u32 layer_num = 3;
    const u32 sizes[] = {28 * 28, 512, 512, 10};
    u32 weights_count = 0;
    for (int i = 0; i < layer_num; i++) {
        weights_count += sizes[i] * sizes[i + 1];
    }

    f32* weights = malloc(sizeof(f32) * weights_count);
    lay_Layer* layers = malloc(sizeof(lay_Layer) * 3);

    u32 offset = 0;

    for (int i = 0; i < layer_num; i++) {
        layers[0].inputs_num = sizes[i];
        layers[0].outputs_num = sizes[i + 1];
        layers[0].weights = &weights[offset];
        offset += sizes[i] * sizes[i + 1];
    }

    return 0;
}
