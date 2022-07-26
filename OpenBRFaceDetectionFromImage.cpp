/*
* use appropriate image having face
*/

#include <openbr/openbr_plugin.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//class query;
using namespace cv;
int main(int argc, char *argv[])
{

   cv::Mat cvin = cv::imread("/home/openBRex/imgs/rohit.jpg", CV_LOAD_IMAGE_COLOR);

  br::Context::initialize(argc, argv);
 
  QSharedPointer<br::Transform> transform =
 // br::Transform::fromAlgorithm("Open+Cascade(FrontalFace)+ASEFEyes"); //uncomment this line and loop.. both works
  br::Transform::fromAlgorithm("Open+Cascade(FrontalFace)++ASEFEyes+Draw(inPlace=true)");

  br::Globals->enrollAll = true;
  br::Template q0(cvin);
  br::TemplateList querylist;
  querylist.push_back(q0);
  querylist >> *transform;

  cv::imshow("Detector", querylist.front().m());

 // cv::Mat vis = querylist.front().m();
 /* for ( auto query : querylist) {
    const QPoint firstEye = query.file.get<QPoint>("First_Eye");
    const QPoint secondEye = query.file.get<QPoint>("Second_Eye");
    const QRect faceroi = query.file.get<QRect>("FrontalFace");


    printf("%s face: (%d, %d, %d, %d)\teyes: (%d, %d) (%d, %d)\n",
          qPrintable(query.file.fileName()),
          faceroi.x(), faceroi.y(), faceroi.width(), faceroi.height(),
          firstEye.x(), firstEye.y(), secondEye.x(), secondEye.y());

    cv::Point fe(firstEye.x(), firstEye.y());
    cv::Point se(secondEye.x(), secondEye.y());
    cv::Point te(firstEye.x() + 30, firstEye.y());

    cv::circle(vis, fe, 5.0, cv::Scalar(255, 0, 0));
    cv::circle(vis, se, 5.0, cv::Scalar(0, 0, 255));
    cv::rectangle(vis, Point (faceroi.x(),faceroi.y()), Point (faceroi.x()+faceroi.width(),faceroi.y()+faceroi.height()), Scalar(255,0,255),2,8,0);

  }*/
 // cv::namedWindow( "Detector", WINDOW_NORMAL/*WINDOW_AUTOSIZE */);
 // cv::imshow("Detector", vis);
  cv::waitKey();

  br::Context::finalize();

  return 0;
}
