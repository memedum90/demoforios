//
//  KobilAstContextHolder.cpp
//  Smartface
//
//  Created by Ugur Kilic on 01.07.2014.
//  Copyright (c) 2014 Smartface. All rights reserved.
//

#include "KobilAstContextHolder.h"

static KobilAstContextHolder *kobilContextHolder = NULL;

KobilAstContextHolder::KobilAstContextHolder() {
    ctx = NULL;
}

KobilAstContextHolder* KobilAstContextHolder::getInstance() {
    if (!kobilContextHolder)
    {
        kobilContextHolder = new KobilAstContextHolder();
    }
    return kobilContextHolder;
}
