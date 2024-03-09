//
//  main.c
//  List
//
//  Created by 张木林 on 3/9/24.
//

#include <stdio.h>
#include "List.h"
int main()
{
    LTNode* plist = LTInit();
    LTPushBack(plist, 1);
    LTPushBack(plist, 2);
    LTPushBack(plist, 3);
    LTPushBack(plist, 5);
    LTPushBack(plist, 4);

    LTPrint(plist);


    return 0;
}
