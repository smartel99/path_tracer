#include "utils/args/arguments.h"
#include "utils/log.h"
#include "utils/img/formatter.h"
#include "renderer/render.h"

#include <vector>

int main(int argc, char** argv)
{
    Log::Init();

    Arguments args = Arguments(argc, argv);

    Render render = Render(args);
    const auto& img = render.Finalize();

    ImgSaver saver = ImgSaver(img, args);
    saver.Save("out/img.png");

    return 0;
}
