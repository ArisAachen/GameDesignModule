//
//  DoubleBuffing.h
//  GameDesignModule
//
//  Created by urchan on 2020/1/16.
//  Copyright © 2020 urchan. All rights reserved.
//

#ifndef DoubleBuffing_h
#define DoubleBuffing_h

//两个字节，一个像素
//帧缓存区 RAM的一块
//缓存区类。维护两个缓存，进行切换

 class Framebuffer
{
public:
    Framebuffer();
    virtual~Framebuffer();
    
    virtual void clear()
    {
        for(int i = 0;i<WIDTH*HEIGHT;i++)
        {
            pixels_[i] = WHITE;
        }
    }
    
    virtual void draw(int x,int y)
    {
        pixels_[WIDTH*y + x] = BLACK;
    }
    
    const char* getPixels()
    {
        return pixels_;
    }
    
private:
    static const int WIDTH = 160;
    static const int HEIGHTt = 120;
    char pixels_[WIDTH*HEIGHt];
}


class Scene
{
public:
    Scene():current_(buffer[0]),next_(buffer[1]){}
    virtual~Scene(){}
    
    virtual void draw()
    {
        next_->clear();
        current_->draw(1,1);
        swap();
    }
    
    virtual void swap()
    {
        Framebuffer* temp = current_;
        current_ = next_;
        next_ = temp;
    }
    
    Framebuffer& getBuffer() {return *current_;}
    
private:
    Framebuffer buffer_[2];
    Framebuffer* current_;
    Framebuffer* next_;
}




#endif /* DoubleBuffing_h */
