#include <opencv2/opencv.hpp>
#include <fstream>

using namespace cv;
using namespace std;

std::vector<std::string> split(const std::string& str, const std::string& pattern)
{
    std::vector<std::string> ret;
    if(pattern.empty()) return ret;
    size_t start=0,index=str.find_first_of(pattern,0);
    while(index!=str.npos)
    {
        if(start!=index)
            ret.push_back(str.substr(start,index-start));
        start=index+1;
        index=str.find_first_of(pattern,start);
    }
    if(!str.substr(start).empty())
        ret.push_back(str.substr(start));
    return ret;
}

int main() {
    std::string file_path = "/home/li/文档/数据/minist/train.txt";
    ifstream txt_file(file_path);
    string s;
    while(getline(txt_file,s))
    {
        std::vector<string> data = split(s," ");
        cv::Mat img = cv::imread(data[0]);
        cv::imshow("img",img);
        cv::waitKey(1);
    }
    return 0;
}
