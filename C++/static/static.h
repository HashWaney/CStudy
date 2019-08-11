//
// Created by Hash on 2019-08-11.
// Copyright (c) 2019 @https://github.com/HashWaney All rights reserved.
//

#ifndef DEMO_STATIC_H
#define DEMO_STATIC_H

class STATIC{
public:
    static STATIC* getInstance();

private:
    static  STATIC* instance;
};

#endif //DEMO_STATIC_H
