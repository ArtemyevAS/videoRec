/*# Copyright (c) 2021 toolsAI.me
#
# No aplicable license
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*/
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int num_args, char** args)
{

int videoDevNo=0;
int fps_req =0;
string s, file_path;

  Mat frame;

  int frame_width = 720;
  int frame_height = 576;

  printf("\nRequired! - NO OpenGL, OpenCV vers> 4.5\n", frame_width, frame_height);

// parsing program args
    if (num_args != 6)
    {
        printf("\nIncorrect arguments\nUsage: prog DEVNO FPS WIDTH HEIGHT PATH_OUTPUT_FILE\n");
        return 0;
    }

        s = args[1];
        videoDevNo = std::stoi(s);
        printf("\nUsing videoDev %d", videoDevNo);

        s = args[2];
        fps_req = std::stoi(s);
        printf("\nUsing FPS %d", fps_req);

        s = args[3];
        frame_width = std::stoi(s);

        s = args[4];
        frame_height = std::stoi(s);

        file_path = args[5];

        printf ("\nWriting to: %s", file_path.c_str());

        printf("\nResolution: %dx%d", frame_width, frame_height);
        printf("\nCodec: H.264\n");


  // Create a VideoCapture object and use camera to capture the video
  VideoCapture cap(videoDevNo);


    cap.set(3,frame_width);
    cap.set(4,frame_height);

  // Check if camera opened successfully
  if(!cap.isOpened()){
   	cout << "Error opening video stream" << endl;
        return -1;
  }
    // Capture frame-by-frame
    cap >> frame;
    if (frame.empty())
      return 0;

  // define the codec and create VideoWriter object.The output is stored in file_path file.

  VideoWriter video(file_path.c_str(), cv::VideoWriter::fourcc('H','2','6','4') , fps_req, Size(frame_width,frame_height),false);

    if (!video.isOpened())
    {
        printf("\nError opening file");
        return 0;
    }


  while(1){

    // Capture frame-by-frame
    cap >> frame;

    // If the frame is empty, break immediately
    if (frame.empty())
      break;

    // frames captured in grayscale, comment if colors required
    cv::cvtColor(frame,frame, COLOR_RGB2GRAY);
    video.write(frame);

    // Display the resulting frame
    imshow( "Frame", frame );

    // Press  ESC on keyboard to  exit
    char c = (char)waitKey(1);
    if( c == 27 )
      break;
  }

  // When everything done, release the video capture and write object
  cap.release();
  video.release();

  // Closes all the frames
  destroyAllWindows();
  return 0;
}
