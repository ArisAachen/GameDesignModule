//
//  ServiceLocator.h
//  GameDesignModule
//
//  Created by urchan on 2020/1/18.
//  Copyright © 2020 urchan. All rights reserved.
//

#ifndef ServiceLocator_h
#define ServiceLocator_h

//装饰模式

using interface = struct;

//基类
interface Audio
{
    virtual void playSound(int soundID) = NULL;
    virtual void stopSound(int soundID) = NULL;
    virtual void stopAllSounds() = NULL;
}

//播放类
class ConsoleAudio:public Audio
{
public:
    ConsoleAudio(){}
    virtual~ConsoleAudio(){}
    
    virtual void playSound(int soundID)
    {
        //playSound
    }
    
    virtual void stopSound(int soundID)
    {
        //stopSound
    }
    
    virtual void stopAllSounds()
    {
        //stopAllSound
    }
}

class NullAudio:public Audio
{
public:
    NullAudio(){}
    virtual~NullAudio(){}
    
    virtual void playSound(int soundID)
    {
        //logError
    }
    
    virtual void stopSound(int soundID)
    {
        //logError
    }
    
    virtual void stopAllSounds()
    {
        //logerror
    }
    
}

//定位器
class Locator
{
public:
    Locator(){}
    virtual~Locator(){}
    
    static void initialize()
    {
        service_ = &nullService_;
    }
    
    static Audio* getAudio() {return service_;}
    
    static void provide(Audio* service)
    {
        if(service == nullptr) service = &nullService_;
        service_ = service;
    }
    
private:
    static NullAudio nullService_;
    static Audio* service_;
}

//装饰日志
class LoggedAudio:public Audio
{
public:
    LoggedAudio() = delete;
    
    LoggedAudio(Audio& wrapped):wrapped_(wrapped){}
    
    virtual void playSound(int soundID)
    {
        log(...);
        wrapped_->playSound(soundID);
    }
    
    virtual void stopSound(int soundID)
    {
        log(...);
        wrapped_->stopSound(soundID);
    }
    
    virtual void stopAllSound()
    {
        log(...);
        wrapped_->stopAllSound();
    }
    
    virtual~LoggedAudio(){}
    
    
private:
    Audio& wrapped_;
}


#endif /* ServiceLocator_h */
