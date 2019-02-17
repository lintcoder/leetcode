#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

inline double bilinear_filter(double x)
{
    if (x < 0.0)
        x = -x;
    if (x < 1.0)
        return 1.0 - x;
    return 0.0;
}

int precompute_coeffs(int inSize, int outSize, int** boundsp, double** kkp)
{
    double filterscale = (double)inSize / outSize;
    double scale = filterscale;
    if (filterscale < 1.0)
        filterscale = 1.0;
    double support = 1.0 * filterscale;
    int ksize = (int)ceil(support) * 2 + 1;
    
    double* kk = (double*)malloc(outSize * ksize * sizeof(double));
    int* bounds = (int*)malloc(outSize * 2* sizeof(int));
    double center = 0, ww = 0, ss = 0;
    int xmin = 0, xmax = 0;
    
    for (int i = 0; i < outSize; ++i)
    {
        center = (i + 0.5) * scale;
        ww = 0.0;
        ss = 1.0 / filterscale;
        
        xmin = (int) (center - support + 0.5);
        if (xmin < 0)
            xmin = 0;
        xmax = (int) (center + support + 0.5);
        if (xmax > inSize)
            xmax = inSize;
        xmax -= xmin;
        double* k = &kk[i * ksize];
        for (int j = 0; j < xmax; ++j)
        {
            double w = bilinear_filter((j + xmin - center + 0.5) * ss);
            k[j] = w;
            ww += w;
        }
        for (int j = 0; j < xmax; ++j)
        {
            if (ww != 0.0)
                k[j] /= ww;
        }
        for (int j = xmax; j < ksize; ++j)
            k[j] = 0;
        bounds[i*2] = xmin;
        bounds[i*2 + 1] = xmax;
    }
    *boundsp = bounds;
    *kkp = kk;
    
    return ksize;
}

void resize(const unsigned char* srcImg, unsigned char* dstImg, int srcSize, int dstSize)
{
    int srcWidth = srcSize;
    int srcHeight = srcSize;
    int dstWidth = dstSize;
    int dstHeight = dstSize;

    int* bounds_horiz = nullptr, *bounds_vert = nullptr;
    double* kk_horiz = nullptr, *kk_vert = nullptr;

    int ksize_horiz = precompute_coeffs(srcWidth, dstWidth, &bounds_horiz, &kk_horiz);
    int ksize_vert = precompute_coeffs(srcHeight, dstHeight, &bounds_vert, &kk_vert);

    cout << ksize_horiz << " " << ksize_vert << endl;
    int ybox_first = bounds_vert[0];
    int ybox_last = bounds_vert[dstHeight*2 - 2] + bounds_vert[dstHeight*2 - 1];

    cout << ybox_first << " " << ybox_last << endl;

    for (int i = 0; i < dstHeight; ++i)
    {
        bounds_vert[i*2] -= ybox_first;
    }
    
    free(bounds_horiz);
    free(bounds_vert);
    free(kk_horiz);
    free(kk_vert);
}

int main()
{
    unsigned char* imgData = new unsigned char[200*200];
    unsigned char* resizeImg = new unsigned char[64];
    resize(imgData, resizeImg, 200, 64);

    delete[] imgData;
    delete[] resizeImg;

    int k = (64*3+3) & -4;
    cout << k << endl;
    return 0;
}
