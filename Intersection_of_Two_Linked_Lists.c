#include <stdio.h>

/*
 * 解题思路：双指针法，pa指向链表a的初始节点，pb指向链表b的初始节点,lengthA lengthB
 * case1：lengthA = lengthB,pa和pb扫描各自链表,当pa=pb时，此节点就是交点
 * case2：lengthA != lengthB,假设lengthA大，那么pa节点先向前移动lengthA-lengthB，然后再开始逐步扫描给链表，
 *        当pa=pb时，pa为交点
 * */
struct ListNode{
    int val;
    struct ListNode * next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
       struct ListNode * pa = headA;
       struct ListNode * pb = headB;
        int lengthA = 0;
        int lengthB = 0;
        while(pa) {pa = pa->next;lengthA++;}
        while(pb) {pb = pb->next;lengthB++;}
        if(lengthA<=lengthB){
            int n = lengthB - lengthA;
            pa = headA;
            pb = headB;
            while(n){
                pb = pb->next;
                n--;
            }
        }else{
            int n = lengthA - lengthB;
            pa = headA;
            pb = headB;
            while(n){
                pa = pa->next;
                n--;
            }
        }
        while(pa!=pb){
            pa = pa->next;
            pb = pb->next;
        }
        return pa;


}
