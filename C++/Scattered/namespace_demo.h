//
// Created by Hash on 2019-08-18.
// Copyright (c) 2019 @https://github.com/HashWaney All rights reserved.
//

#ifndef DEMO_NAMESPACE_DEMO_H
#define DEMO_NAMESPACE_DEMO_H

//class
class namespace_demo {
public:
    namespace_demo();

};
//namespace
namespace NameSpaceA{
    int name =01;

}
namespace NameSpaceB{
//    int age=1;
//    namespace  NameSpaceC
//    {
//        struct Teacher{
//            char name[10];
//            int age;
//        };
//    }

    int age = 10;
    namespace NameSpaceC
    {
        struct Teacher
        {
            char name[10];
            int age;
        };
    }
}

#endif //DEMO_NAMESPACE_DEMO_H
