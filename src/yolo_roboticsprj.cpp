#include "yolo_roboticsprj.h"
#include <fstream>
#include <iostream>

ComputerVision::ComputerVision(std::string classesFile, std::string configFile,std::string weightsFile){
    try{
        std::ifstream cfile;
        cfile.open(classesFile, std::ios::in);
        if(!cfile.is_open())throw -1;
        std::string cls;
        while(cfile>>cls){
            this->classes.push_back(cls);
        }
        this->net = cv:dnn::readnet(&weightsFile, &configFile);
    }
    catch(...){
        std::cout<<"An error occured!"<<std::endl;
    }
}

std::vector<int> ComputerVision::get_output_layers(){
    vector<std::string> layer_names = this->net.getLayerNames();
    vector<int> output_layers;
    for(auto i : this->net.getUnconnectedOutLayers()){
        output_layers.push_back(layernames[i[0]-1]);
    }
    return output_layers;
}

std::vector<int> ComputerVision::findTarget(cv::Mat image, std::string target){
    int Width = image.shape[1];
    int Height = image.shape[0];
    float scale = 0.00392;
    //convert image to 4 dimensional blob, scale by factor
    cv::Mat blob = cv::dnn::blobFromImage(image, scale, cv::Size(416,416), cv::Scalar(0,0,0), true, crop=false);
    this->net.setInput(blob);
    auto outs = this->net.forward(this->get_output_layers());
    return std::vector<int>;

}