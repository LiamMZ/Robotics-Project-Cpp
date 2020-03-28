#include "colordetection.h"
#include <queue>

ColorDetector::ColorDetector(cv::Mat img){
    this->image = img;
}

bool ColorDetector::check_if_color_in_range(cv::Mat img, int row, int col){
    cv::Vec3b pixel = img.at<cv::Vec3b>(row,col);
    bool in_range = true;
    for(int i = 0; i<3; i++){
        if (pixel[i]<this->color_ranges[0][i] || pixel[i]>this->color_ranges[1][i]){
            in_range = false;
            break;
        }
    }
    return in_range;
}

std::vector<std::vector<int> > ColorDetector::do_color_filtering(){
    std::vector<std::vector<int> > mask;
    int val;
    std::vector<int> row;
    for(int y = 0; y<this->image.rows; y++){
        row.clear();
        for(int x = 0; x<this->image.cols; x++){
            val = 0;
            if( this->check_if_color_in_range(this->image, y,x)){
                val = 1;
            }
            row.push_back(val);
        }
        mask.push_back(row);
    }
    return mask;
}

std::vector<int[2] > ColorDetector::expand_nr(std::vector<std::vector<int> > img_mask, int row, int col){
    std::vector<int[2]> blob;
    std::queue<int[2]> coordinates_list;
    int cur_coordinate[2];
    coordinates_list.push({row,col});
    while (!coordinates_list.empty()){
        cur_coordinate[0] = coordinates_list.front()[0];
        cur_coordinate[1] = coordinates_list.front()[1];
        coordinates_list.pop();
        if((cur_coordinate[0]<0 || cur_coordinate[0]>img_mask.size()-1)||(cur_coordinate[1]<0 || cur_coordinate[1]>img_mask[0].size()-1)||img_mask[cur_coordinate[0]][cur_coordinate[1]]==0){
            continue;
        }
        img_mask[cur_coordinate[0]][cur_coordinate[1]] =0;
        blob.push_back(cur_coordinate);
        coordinates_list.push({cur_coordinate[0]+1, cur_coordinate[1]});
        coordinates_list.push({cur_coordinate[0]-1, cur_coordinate[1]});
        coordinates_list.push({cur_coordinate[0], cur_coordinate[1]+1});
        coordinates_list.push({cur_coordinate[0], cur_coordinate[1]-1});
    }
    return blob;
}

std::vector<std::vector<int[2] > > ColorDetector::get_blobs(std::vector<std::vector<int> > img_mask){
    int maskHeight = img_mask.size();
    int maskWidth = img_mask[0].size();
    auto local_mask = img_mask;
    std::vector<std::vector<int[2] > > blobs;
}