#ifndef JK_STATE_H
#define JK_STATE_H

namespace cub{

struct JK_state
{
    float x;
    float y;
    float z;
    float r;
    float u;
    float v;
    int16_t px;
    int16_t py;
    std::bitset<12> buttons;
};
}

#endif // JK_STATE_H
