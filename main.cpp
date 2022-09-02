#include "utils/args/arguments.h"
#include "utils/log.h"
#include "utils/img/formatter.h"

#include <vector>

int main(int argc, char** argv)
{
    Log::Init();

    Arguments args = Arguments(argc, argv);

    std::vector<uint8_t> img;

    static constexpr size_t channelCount = 4;    // Working with RGBA.
    auto                    width        = args.Get<uint64_t>("width");
    auto                    height       = args.Get<uint64_t>("height");
    img.reserve(width * height * 4);

    // Fill the img with blue pixels.
    for (size_t i = 0; i < width * height; i++)
    {
        img.push_back(0);       // R.
        img.push_back(0);       // G.
        img.push_back(0xFF);    // B.
        img.push_back(0xFF);    // A.
    }

    ImgSaver saver = ImgSaver(img, args);
    saver.Save("out/img.png");

    return 0;
}
