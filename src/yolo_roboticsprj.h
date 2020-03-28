#pragma once
#include <opencv2/opencv.hpp>
#include <opencv4/opencv2/dnn/dnn.hpp>
#include <vector>
#include <string>

class ComputerVision{
    public:
    ComputerVision(std::string classesFile, std::string configFile,std::string weightsFile);
    std::vector<int> findTarget(cv::Mat image, std::string target);
    private:
    std::vector<int> get_output_layers();
    std::vector<std::string> classes;
    cv::dnn::Net net;
};