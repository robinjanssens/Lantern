#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include <neopixel.h>

class Background
{
  public:
    Background(Adafruit_NeoPixel* strip, uint8_t* x_offset, uint8_t* y_offset);
    // ------------------------------
    // Backgrounds
    // ------------------------------
    void rainbow();
    void plasma();
    void police();
    void fire();
    void solid(uint8_t red, uint8_t green, uint8_t blue);
    // ------------------------------
    // Overlays
    // ------------------------------
    void flashes();
  private:
    Adafruit_NeoPixel* strip;
    // define positions of pixels in reference to first led.
    const uint8_t positions[300][2] = { {0,0}, {1,21}, {2,42}, {3,63}, {3,84}, {4,105}, {5,126}, {6,147}, {7,168}, {8,189}, {9,210}, {9,231}, {10,252}, {11,19}, {12,40}, {13,61}, {14,82}, {14,103}, {15,124}, {16,145}, {17,166}, {18,187}, {19,208}, {20,229}, {20,250}, {21,16}, {22,37}, {23,58}, {24,79}, {25,100}, {26,121}, {26,142}, {27,163}, {28,184}, {29,205}, {30,226}, {31,247}, {31,13}, {32,35}, {33,56}, {34,77}, {35,98}, {36,119}, {37,140}, {37,161}, {38,182}, {39,203}, {40,224}, {41,245}, {42,11}, {43,32}, {43,53}, {44,74}, {45,95}, {46,116}, {47,137}, {48,158}, {48,179}, {49,200}, {50,221}, {51,242}, {52,8}, {53,29}, {54,50}, {54,72}, {55,93}, {56,114}, {57,135}, {58,156}, {59,177}, {60,198}, {60,219}, {61,240}, {62,6}, {63,27}, {64,48}, {65,69}, {65,90}, {66,111}, {67,132}, {68,153}, {69,174}, {70,195}, {71,216}, {71,237}, {72,3}, {73,24}, {74,45}, {75,66}, {76,88}, {77,109}, {77,130}, {78,151}, {79,172}, {80,193}, {81,214}, {82,235}, {82,1}, {83,22}, {84,43}, {85,64}, {86,85}, {87,106}, {88,127}, {88,148}, {89,169}, {90,190}, {91,211}, {92,232}, {93,253}, {94,19}, {94,40}, {95,61}, {96,82}, {97,104}, {98,125}, {99,146}, {99,167}, {100,188}, {101,209}, {102,230}, {103,251}, {104,17}, {105,38}, {105,59}, {106,80}, {107,101}, {108,122}, {109,143}, {110,164}, {111,185}, {111,206}, {112,227}, {113,248}, {114,14}, {115,35}, {116,56}, {116,77}, {117,98}, {118,120}, {119,141}, {120,162}, {121,183}, {122,204}, {122,225}, {123,246}, {124,12}, {125,33}, {126,54}, {127,75}, {128,117}, {129,138}, {130,159}, {131,180}, {132,201}, {133,222}, {133,243}, {134,9}, {135,30}, {136,51}, {137,72}, {138,93}, {139,114}, {139,135}, {140,157}, {141,178}, {142,199}, {143,220}, {144,241}, {145,7}, {145,28}, {146,49}, {147,70}, {148,91}, {149,112}, {150,133}, {150,154}, {151,175}, {152,196}, {153,217}, {154,238}, {155,4}, {156,25}, {156,46}, {157,67}, {158,88}, {159,109}, {160,130}, {161,151}, {162,173}, {162,194}, {163,215}, {164,236}, {165,2}, {166,23}, {167,44}, {167,65}, {168,86}, {169,107}, {170,128}, {171,149}, {172,170}, {173,191}, {173,212}, {174,233}, {175,254}, {176,20}, {177,41}, {178,62}, {179,83}, {179,104}, {180,125}, {181,146}, {182,167}, {183,189}, {184,210}, {184,231}, {185,252}, {186,18}, {187,39}, {188,60}, {189,81}, {190,102}, {190,123}, {191,144}, {192,165}, {193,186}, {194,207}, {195,228}, {196,249}, {196,15}, {197,36}, {198,57}, {199,78}, {200,99}, {201,120}, {201,141}, {202,162}, {203,183}, {204,205}, {205,226}, {206,247}, {207,13}, {207,34}, {208,55}, {209,76}, {210,97}, {211,118}, {212,139}, {212,160}, {213,181}, {214,202}, {215,223}, {216,244}, {217,10}, {218,31}, {218,52}, {219,73}, {220,94}, {221,115}, {222,136}, {223,157}, {224,178}, {224,199}, {225,220}, {226,242}, {227,8}, {228,29}, {229,50}, {230,71}, {230,92}, {231,113}, {232,134}, {233,155}, {234,176}, {235,197}, {235,218}, {236,239}, {237,5}, {238,26}, {239,47}, {240,68}, {241,89}, {241,110}, {242,131}, {243,152}, {244,173}, {245,194}, {246,215}, {247,236}, {247,3}, {248,24}, {249,45}, {250,66}, {251,87}, {252,108}, {252,129}, {253,150}, {254,171}, {255,192} };
    // cosine table
    const uint8_t cosine_table[256] = { 255, 255, 255, 255, 254, 254, 254, 253, 253, 252, 251, 250, 250, 249, 248, 246, 245, 244, 243, 241, 240, 238, 237, 235, 234, 232, 230, 228, 226, 224, 222, 220, 218, 215, 213, 211, 208, 206, 203, 201, 198, 196, 193, 190, 188, 185, 182, 179, 176, 173, 170, 167, 165, 162, 158, 155, 152, 149, 146, 143, 140, 137, 134, 131, 128, 124, 121, 118, 115, 112, 109, 106, 103, 100, 97, 93, 90, 88, 85, 82, 79, 76, 73, 70, 67, 65, 62, 59, 57, 54, 52, 49, 47, 44, 42, 40, 37, 35, 33, 31, 29, 27, 25, 23, 21, 20, 18, 17, 15, 14, 12, 11, 10, 9, 7, 6, 5, 5, 4, 3, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 4, 5, 5, 6, 7, 9, 10, 11, 12, 14, 15, 17, 18, 20, 21, 23, 25, 27, 29, 31, 33, 35, 37, 40, 42, 44, 47, 49, 52, 54, 57, 59, 62, 65, 67, 70, 73, 76, 79, 82, 85, 88, 90, 93, 97, 100, 103, 106, 109, 112, 115, 118, 121, 124, 127, 131, 134, 137, 140, 143, 146, 149, 152, 155, 158, 162, 165, 167, 170, 173, 176, 179, 182, 185, 188, 190, 193, 196, 198, 201, 203, 206, 208, 211, 213, 215, 218, 220, 222, 224, 226, 228, 230, 232, 234, 235, 237, 238, 240, 241, 243, 244, 245, 246, 248, 249, 250, 250, 251, 252, 253, 253, 254, 254, 254, 255, 255, 255 };
    const uint8_t rainbow_wave_table[256] = { 0, 0, 0, 1, 1, 2, 3, 4, 5, 7, 9, 10, 12, 14, 17, 19, 21, 24, 27, 30, 33, 36, 39, 43, 46, 50, 54, 58, 62, 66, 70, 74, 78, 83, 87, 92, 96, 101, 105, 110, 115, 119, 124, 129, 133, 138, 143, 147, 152, 157, 161, 166, 170, 174, 179, 183, 187, 191, 195, 199, 203, 207, 210, 214, 217, 221, 224, 227, 230, 232, 235, 237, 240, 242, 244, 246, 247, 249, 250, 251, 252, 253, 254, 254, 255, 255, 255, 255, 254, 254, 253, 252, 251, 250, 249, 247, 246, 244, 242, 240, 237, 235, 232, 230, 227, 224, 221, 217, 214, 210, 207, 203, 199, 195, 191, 187, 183, 179, 174, 170, 166, 161, 157, 152, 147, 143, 138, 133, 129, 124, 119, 115, 110, 105, 101, 96, 92, 87, 83, 78, 74, 70, 66, 62, 58, 54, 50, 46, 43, 39, 36, 33, 30, 27, 24, 21, 19, 17, 14, 12, 10, 9, 7, 5, 4, 3, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    uint8_t* x_offset; // automatically rolls over at 256
    uint8_t* y_offset; // automatically rolls over at 256
    // flashes
    uint8_t counter = 0;
    uint8_t flashes_overlay[300];
    // ------------------------------
    // Support Functions
    // ------------------------------
    uint8_t getRed(uint32_t color);
    uint8_t getGreen(uint32_t color);
    uint8_t getBlue(uint32_t color);
};

#endif // BACKGROUND_H_
