/****************************************************************************
Copyright (c) 2010 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#include "CCFileUtilsQt.h"
#include "platform/CCCommon.h"

// Qt
#include <QApplication>
#include <QFileInfo>

using namespace std;

NS_CC_BEGIN

FileUtils* FileUtils::getInstance()
{
    if (s_sharedFileUtils == NULL)
    {
        s_sharedFileUtils = new CCFileUtilsQt();
        s_sharedFileUtils->init();
    }
    return s_sharedFileUtils;
}

CCFileUtilsQt::CCFileUtilsQt()
{
}

bool CCFileUtilsQt::init()
{
    _defaultResRootPath = qApp->applicationDirPath().toLocal8Bit().constData();
    return FileUtils::init();
}

bool CCFileUtilsQt::isFileExistInternal(const std::string& strFilePath) const
{
    std::string strPath = strFilePath;
    if (!isAbsolutePath(strPath))
    { // Not absolute path, add the default root path at the beginning.
        strPath.insert(0, _defaultResRootPath);
    }
    QFileInfo fileInfo(strPath.c_str());
    return fileInfo.exists();
}

bool CCFileUtilsQt::isAbsolutePath(const std::string& strPath) const
{
    QFileInfo fileInfo(strPath.c_str());
    return fileInfo.isAbsolute();
}

std::string
CCFileUtilsQt::getWritablePath() const
{
    std::string ret(qApp->applicationDirPath().toLocal8Bit().constData());
    return ret;
}

//bool
//CCFileUtilsQt::isFileExistInternal(const string &filename) const
//{
//    return true;
//}

NS_CC_END
