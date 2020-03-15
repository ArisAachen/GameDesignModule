//
//  EventQueue.h
//  GameDesignModule
//
//  Created by urchan on 2020/1/18.
//  Copyright © 2020 urchan. All rights reserved.
//

#ifndef EventQueue_h
#define EventQueue_h

//跨线程
//队列从程序中单独封装出来

//单播队列   多播队列    工作队列
//对象生命周期：转移所有权     共享所有权      队列拥有




struct PlayMessage
{
    SoundId id;
    int volume;
}

class Audio
{
public:
    Audio(){}
    virtual~Audio(){}
    
    static void init(){head_ = 0;tail_ = 0;}
    
    void playSound(SoundId && id,int volume)
    {
        for(int i = head_;i != tail_; i = (i + 1)%MAX_PENDING)
        {
            if(pending_[i].id == id)
            {
                pending_[i].volume = max(volume,pending_[i].volume);
                return;
            }
        }
        
        //新增
        assert((tail_+1)%MAX_PENDING != head_);
        pending_[tail_],id = id;
        pending_[tail_].volume = volume;
        tail_ = (tail_ + 1) % MAX_PENDING;
    }
    
    void update()
    {
        if(head_ = tail_) return;
        
        ResourceId resource = loadSound(pending[head_].id);
        int channel = findOpenChannel();
        if(channel == -1) return;
        startSound(resource,channel,volume);
        
        head_ = (head_ + 1) % MAX_PENGDING:
    }
    
    
private:
    static int MAX_PENDING = 16;
    static int head_;
    static int tail_;
    static PlayMessage pending_[MAX_PENDING];
}


#endif /* EventQueue_h */
