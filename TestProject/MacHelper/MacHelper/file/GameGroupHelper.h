//
//  GameGroupHelper.hpp
//  MacHelper
//
//  Created by gongxun on 16/11/1.
//  Copyright © 2016年 gongxun. All rights reserved.
//

#ifndef GameGroupHelper_hpp
#define GameGroupHelper_hpp

#include <string>
#include <vector>

using namespace std;

class GameGroupHelper
{
public:
    static GameGroupHelper *singleton();
    
    //生成项目配置文件
    void buildConfigFile();
    
    //生成网页测试项目
    void buildHtmlTest();
private:
    //项目根目录
    string mProjectPath;
    //项目版本号
    string mProjectVersion;
    
    void buildConfig(const string &srcPath, const string &recPath, const string &rootPath);
    
    string getCurDateTime();
    
    string getRenameJsFile(const string &jsFile);
    
    static GameGroupHelper *mGameGroupHelper;
    GameGroupHelper();
    ~GameGroupHelper();
};

#endif /* GameGroupHelper_hpp */