#pragma once
#include <opencv2/opencv.hpp>
#include <vector>

class ColorDetector{
    public:
    ColorDetector(cv::Mat img);
    std::vector<std::vector<int> > getCorners();
    private:
    bool check_if_color_in_range(cv::Mat img, int row, int col);
    std::vector<std::vector<int> > do_color_filtering();
    std::vector<int[2]> expand_nr(std::vector<std::vector<int> > img_mask, int row, int col);
    std::vector<std::vector<int[2] > > get_blobs(std::vector<std::vector<int> > img_mask);
    std::vector<int[2]> get_blob_centroids(std::vector<std::vector<int*> > blobs_list);
    cv::Mat image;
    int color_ranges[2][3]  {{170,39,39}, {255,140,120}};
};