#include "utils/args/arguments.h"
#include "utils/log.h"
#include "utils/img/formatter.h"
#include "renderer/render.h"
#include "renderer/objects/sphere.h"

#include <vector>

int main(int argc, char** argv)
{
    Log::Init();

    Arguments args = Arguments(argc, argv);

    Render render = Render(args);

    render.AddObject<Sphere>(Point3 {0.0, 0.0, -1.0}, 0.5);
    render.AddObject<Sphere>(Point3 {0.0, -100.5, -1.0}, 100.0);

    const auto& img = render.Finalize();

    ImgSaver saver = ImgSaver(img, args);
    saver.Save(ImgType::Png, "out/img.png");
    saver.Save(ImgType::Jpeg, "out/img.jpg");

    return 0;
}
