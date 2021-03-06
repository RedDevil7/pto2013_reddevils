INCLUDEPATH += $$PWD

SOURCES +=  $$PWD/histogram.cpp \
            $$PWD/pnm.cpp \
            $$PWD/tools.cpp \
            $$PWD/transformations/transformation.cpp \
            $$PWD/transformations/bin_gradient.cpp \
            $$PWD/transformations/bin_iterbimodal.cpp \
            $$PWD/transformations/bin_manual.cpp \
            $$PWD/transformations/bin_niblack.cpp \
            $$PWD/transformations/bin_otsu.cpp \
            $$PWD/transformations/blur_gaussian.cpp \
            $$PWD/transformations/blur_linear.cpp \
            $$PWD/transformations/blur_uniform.cpp \
            $$PWD/transformations/conversion_grayscale.cpp \
            $$PWD/transformations/convolution.cpp \
            $$PWD/transformations/corner_harris.cpp \
            $$PWD/transformations/correction.cpp \
            $$PWD/transformations/edge_canny.cpp \
            $$PWD/transformations/edge_gradient.cpp \
            $$PWD/transformations/edge_laplacian.cpp \
            $$PWD/transformations/edge_laplacian_of_gauss.cpp \
            $$PWD/transformations/edge_prewitt.cpp \
            $$PWD/transformations/edge_roberts.cpp \
            $$PWD/transformations/edge_sobel.cpp \
            $$PWD/transformations/edge_zero.cpp \
            $$PWD/transformations/histogram_equalization.cpp \
            $$PWD/transformations/histogram_stretching.cpp \
            $$PWD/transformations/hough.cpp \
            $$PWD/transformations/hough_lines.cpp \
            $$PWD/transformations/hough_rectangles.cpp \
            $$PWD/transformations/map_height.cpp \
            $$PWD/transformations/map_horizon.cpp \
            $$PWD/transformations/map_normal.cpp \
            $$PWD/transformations/morph_dilate.cpp \
            $$PWD/transformations/morph_erode.cpp \
            $$PWD/transformations/morph_openclose.cpp \
            $$PWD/transformations/morphological_operator.cpp \
            $$PWD/transformations/negative_image.cpp \
            $$PWD/transformations/noise_bilateral.cpp \
            $$PWD/transformations/noise_median.cpp \
            $$PWD/transformations/segmentation.cpp

HEADERS +=  $$PWD/histogram.h \
            $$PWD/matrix.h \
            $$PWD/pnm.h \
            $$PWD/tools.h \
            $$PWD/transformations.h \
            $$PWD/transformations/transformation.h \
            $$PWD/transformations/bin_gradient.h \
            $$PWD/transformations/bin_iterbimodal.h \
            $$PWD/transformations/bin_manual.h \
            $$PWD/transformations/bin_niblack.h \
            $$PWD/transformations/bin_otsu.h \
            $$PWD/transformations/blur_gaussian.h \
            $$PWD/transformations/blur_linear.h \
            $$PWD/transformations/blur_uniform.h \
            $$PWD/transformations/conversion_grayscale.h \
            $$PWD/transformations/convolution.h \
            $$PWD/transformations/corner_harris.h \
            $$PWD/transformations/correction.h \
            $$PWD/transformations/edge_canny.h \
            $$PWD/transformations/edge_gradient.h \
            $$PWD/transformations/edge_laplacian.h \
            $$PWD/transformations/edge_laplacian_of_gauss.h \
            $$PWD/transformations/edge_prewitt.h \
            $$PWD/transformations/edge_roberts.h \
            $$PWD/transformations/edge_sobel.h \
            $$PWD/transformations/edge_zero.h \
            $$PWD/transformations/histogram_equalization.h \
            $$PWD/transformations/histogram_stretching.h \
            $$PWD/transformations/hough.h \
            $$PWD/transformations/hough_lines.h \
            $$PWD/transformations/hough_rectangles.h \
            $$PWD/transformations/map_height.h \
            $$PWD/transformations/map_horizon.h \
            $$PWD/transformations/map_normal.h \
            $$PWD/transformations/morph_dilate.h \
            $$PWD/transformations/morph_erode.h \
            $$PWD/transformations/morph_openclose.h \
            $$PWD/transformations/morphological_operator.h \
            $$PWD/transformations/negative_image.h \
            $$PWD/transformations/noise_bilateral.h \
            $$PWD/transformations/noise_median.h \
            $$PWD/transformations/segmentation.h
