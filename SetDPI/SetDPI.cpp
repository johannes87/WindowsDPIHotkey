// most code is taken from https://github.com/lihas/windows-DPI-scaling-sample

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;


static const UINT32 DpiVals[] = { 100,125,150,175,200,225,250,300,350, 400, 450, 500 };

/*Get default DPI scaling percentage.
The OS recommented value.
*/
int GetRecommendedDPIScaling()
{
    int dpi = 0;
    auto retval = SystemParametersInfo(SPI_GETLOGICALDPIOVERRIDE, 0, (LPVOID)&dpi, 1);

    if (retval != 0)
    {
        int currDPI = DpiVals[dpi * -1];
        return currDPI;
    }

    return -1;
}

void SetDpiScaling(int percentScaleToSet)
{
    int recommendedDpiScale = GetRecommendedDPIScaling();

    if (recommendedDpiScale > 0)
    {
        int index = 0, recIndex = 0, setIndex = 0;
        for (const auto& scale : DpiVals)
        {
            if (recommendedDpiScale == scale)
            {
                recIndex = index;
            }
            if (percentScaleToSet == scale)
            {
                setIndex = index;
            }
            index++;
        }

        int relativeIndex = setIndex - recIndex;
        SystemParametersInfo(SPI_SETLOGICALDPIOVERRIDE, relativeIndex, (LPVOID)0, 1);
    }
}



int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "usage: " << argv[0] << " <DPI value>" << std::endl;
        exit(1);
    }

    auto dpiValue = std::stoi(std::string(argv[1]));
    SetDpiScaling(dpiValue);

    return 0;
}

