
#include"List.h"


void Test1()
{
    ListNode *plist = ListCreate();
    ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 5);
	ListPushBack(plist, 4);

	ListPrint(plist);

	ListPushFront(plist, 10);
	ListPrint(plist);
}
int main()
{
    Test1();
    return 0;
}