//
//  Recurrence.h
//  GameDesignModule
//
//  Created by urchan on 2020/1/17.
//  Copyright © 2020 urchan. All rights reserved.
//

#ifndef Recurrence_h
#define Recurrence_h

//等时长循环
while(true)
{
    double start = getCurrentTime();
    processInput();
    update();
    render();
    sleep(start + MS_PER_FRAME - getCurrentTime());
}

//变长循环
double lastTime = getCurrentTime();
while(true)
{
    double current = getCurrentTIme();
    double elapsed = lastTime - current;
    processInput();
    update(elapsed);
    render();
    lastTime = current;
}

//调整
double previous = getCurrentTime();
double lag = 0.0;
while(true)
{
    double current = getCurrentTime();
    double elapsed = current - previous;
    previous = current;
    lag += elapsed;
    while(lag >= MS_PER_UPDATE)
    {
        update();
        lag -= MS_PER_UPDATE;
    }
    
    render();
}


#endif /* Recurrence_h */
