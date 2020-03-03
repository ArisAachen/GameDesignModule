//
//  SubClass.h
//  GameDesignModule
//
//  Created by urchan on 2020/1/17.
//  Copyright © 2020 urchan. All rights reserved.
//

#ifndef SubClass_h
#define SubClass_h


//外观模式变种



enum class SoundId
{
    None,
    One,
    Two
}

//音乐引擎
class AudioEngine
{
public:
    AudioEngine();
    virtual~AudioEngine();
    
    virtual void playSound(SoundId id)
    {
        //播放音乐
    }
}

//沙盒基类
class Superpower
{
public:
    virtual~Superpower();
    
public:
    virtual void activate() = NULL:
    
protected:
    void playSound(SoundId id)
    {
        audioEngine_->playSound(id);
    }
    
    void move(int x,int y)
    {
        //处理信息
    }
    
private:
    AudioEngine* audioEngine_;
    int x_;
    int y_;
}

//继承类
class SkyLaunch:public Superpower
{
public:
    SkyLaunch(){}
    virtual~SkyLaunch(){}
    
    virtual void activate()
    {
        move(1,2);
        playSound(1,2);
    }
}


//日志类
class Log
{
public:
    Log(){}
    virtual~Log(){}
    
    void write(char* text)
    {
        //write file
    }
}

class LogBase
{
    //函数定义
public:
    LogBase(){}
    virtual~LogBase(){}
        
    void init(Log && log) {log_ = std::move(log);}
    
    Log& getLog(){return log_};
    
private:
    static Log log_;
}

class FileLog:public LogBase
{
public:
    FileLog(){}
    virtual~FileLog(){}
    
    FileLog* createFileLog(Log && log)
    {
        LogBase* logbase = new FileLog();
        logBase->init(log);
        return logbase;
    }
    
    void doSomething()
    {
        getLog().write("Log");
    }
}

#endif /* SubClass_h */
