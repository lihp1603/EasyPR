//////////////////////////////////////////////////////////////////////////
// Name:	    chars_recognise Header
// Version:		1.0
// Date:	    2014-09-28
// Author:	    liuruoze
// Copyright:   liuruoze
// Reference:	Mastering OpenCV with Practical Computer Vision Projects
// Reference:	CSDN Bloger taotao1233
// Desciption:
// Defines CCharsRecognise
//////////////////////////////////////////////////////////////////////////
#ifndef EASYPR_CORE_CHARSRECOGNISE_H_
#define EASYPR_CORE_CHARSRECOGNISE_H_

#include "easypr/core/chars_segment.h"
#include "easypr/core/chars_identify.h"

namespace easypr {

class CCharsRecognise {
 public:
  CCharsRecognise();

  ~CCharsRecognise();

  int charsRecognise(cv::Mat plate, std::string& plateLicense);

  //! 获得车牌颜色
  inline std::string getPlateColor(cv::Mat input) const {
    std::string color = "未知";
    Color result = getPlateType(input, true);
    if (BLUE == result) color = "蓝牌";
    if (YELLOW == result) color = "黄牌";
    return color;
  }

  //! 设置变量
  inline void setLiuDingSize(int param) {
    m_charsSegment->setLiuDingSize(param);
  }
  inline void setColorThreshold(int param) {
    m_charsSegment->setColorThreshold(param);
  }
  inline void setBluePercent(float param) {
    m_charsSegment->setBluePercent(param);
  }
  inline float getBluePercent() const {
    return m_charsSegment->getBluePercent();
  }
  inline void setWhitePercent(float param) {
    m_charsSegment->setWhitePercent(param);
  }
  inline float getWhitePercent() const {
    return m_charsSegment->getWhitePercent();
  }

 private:
  //！字符分割
  CCharsSegment* m_charsSegment;
};

} /* \namespace easypr  */

#endif  // EASYPR_CORE_CHARSRECOGNISE_H_