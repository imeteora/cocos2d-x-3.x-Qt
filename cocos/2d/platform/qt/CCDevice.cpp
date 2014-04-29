
#include "CCPlatformConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_QT5

#include "CCDevice.h"
#include "ccTypes.h"
#include "CCImage.h"
#include <QImage>
#include <QFontDatabase>
#include <QPainter>

NS_CC_BEGIN

class BitmapDC
{
public:
    BitmapDC() : m_pPainter(NULL)
      , m_pImage(NULL)
    {
    }

    ~BitmapDC()
    {
        CC_SAFE_DELETE(m_pPainter);
        CC_SAFE_DELETE(m_pImage);
    }

    bool drawText(const char * pszText, QSize& size, const FontDefinition &textDefinition, const char * pFontName = NULL, int fontSize = 0)
    {
        bool nRet = false;
        do
        {
            CC_BREAK_IF(pszText == NULL || strlen(pszText) <= 0);

            // Set font
            std::string fontName = pFontName;

            if (fontName.c_str())
            {
                int nFindttf = fontName.find(".ttf");
                int nFindTTF = fontName.find(".TTF");
                if (nFindttf >= 0 || nFindTTF >= 0)
                {
                    QFontDatabase::addApplicationFont(fontName.c_str());

                    // delete .ttf suffix from fontName
                    int nFindPos = fontName.rfind("/");
                    fontName = &fontName[nFindPos+1];
                    nFindPos = fontName.rfind(".");
                    fontName = fontName.substr(0, nFindPos);
                }
            }

            int flags = 0;
            if (textDefinition._alignment == TextHAlignment::CENTER) {
                flags |= Qt::AlignHCenter;
            }
            else if (textDefinition._alignment == TextHAlignment::LEFT) {
                flags |= Qt::AlignLeft;
            }
            else if (textDefinition._alignment == TextHAlignment::RIGHT) {
                flags |= Qt::AlignRight;
            }

            if (textDefinition._vertAlignment == TextVAlignment::TOP) {
                flags |= Qt::AlignTop;
            }
            else if (textDefinition._vertAlignment == TextVAlignment::BOTTOM) {
                flags |= Qt::AlignBottom;
            }
            else if (textDefinition._vertAlignment == TextVAlignment::CENTER) {
                flags |= Qt::AlignVCenter;
            }

            QRect rect;
            QFont font(fontName.c_str(), fontSize);
            QImage* image = new QImage(100, 100, QImage::Format_ARGB32);
            QPainter painter(image);
            painter.setFont(font);
            rect = painter.boundingRect(rect, flags, pszText);

            // if content width is 0, use text size as content size
            if (size.width() <= 0)
            {
                size.setWidth(rect.width());
                size.setHeight(rect.height());
            }

            QRect drawRect(0, 0, 0, 0);
            drawRect.setRight(rect.width());
            drawRect.setBottom(rect.height());

            m_pImage = new QImage(size, QImage::Format_ARGB32);
            m_pPainter = new QPainter(m_pImage);

            m_pPainter->setCompositionMode(QPainter::CompositionMode_Source);
            m_pPainter->fillRect(drawRect, Qt::transparent);
            m_pPainter->setCompositionMode(QPainter::CompositionMode_SourceOver);

            m_pPainter->setPen(Qt::white);
            m_pPainter->setFont(font);
            m_pPainter->drawText(drawRect, flags, pszText);
            m_pPainter->end();

//            CC_SAFE_DELETE(m_pPainter);

            nRet = true;
        } while (0);
        return nRet;
    }
private:
    friend class Device;

    QPainter* m_pPainter;
    QImage* m_pImage;
};

static BitmapDC& sharedBitmapDC(void)
{
    static BitmapDC s_bmpDC;
    return s_bmpDC;
}

int
Device::getDPI()
{
    return 160;
}

void
Device::setAccelerometerInterval(float interval)
{
    CC_UNUSED_PARAM(interval);
    return;
}

void
Device::setAccelerometerEnabled(bool isEnabled)
{
    CC_UNUSED_PARAM(isEnabled);
    return;
}

Data
Device::getTextureDataForText(const char *text, const FontDefinition &textDefinition, TextAlign align, int &width, int &height)
{
    Data _retData = Data::Null;
    do {
        CC_BREAK_IF(text == NULL);
        BitmapDC& _dc = sharedBitmapDC();

        bool bRet = false;
        QSize size;
        size.setWidth(width);
        size.setHeight(height);
        /// draw the text on the bitmap DC.
        bRet = _dc.drawText(text, size,
                            textDefinition,
                            textDefinition._fontName.c_str(),
                            textDefinition._fontSize);
        CC_BREAK_IF(bRet == false);

        unsigned long nLen = 0l;
#if (QT_VERSION < QT_VERSION_CHECK(5, 0,0))
            nLen = _dc.m_pImage->numBytes();
#else
            nLen = _dc.m_pImage->byteCount();
#endif  //
        _retData.copy(_dc.m_pImage->bits(), nLen);

    } while (false);
    return _retData;
}

NS_CC_END
#endif  /// CC_TARGET_PLATFORM == CC_PLATFORM_QT5

