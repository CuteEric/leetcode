#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int slow = 0, fast = 0;

    // �ҵ���һ��0Ԫ��
    while (nums[fast] != 0)
        ++fast;
    slow = fast; // slowָ���һ��0��λ��
    ++fast;      // fastָ��0֮���λ��
    
    // ����ʣ������Ԫ��
    while (fast < numsSize) {
        if (nums[fast] == 0) { // ����0������
            ++fast;
	    continue;
        } else { // �������0Ԫ�أ�����ǰ����
            nums[slow++] = nums[fast++];
        }
    }

    // ��slow֮�������λ�ö���ֵΪ0
    while (slow < numsSize)
        nums[slow++] = 0;
}

void print(int nums[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {0, 1, 0, 3, 12};
    print(nums, 5);
    moveZeroes(nums, 5);
    print(nums, 5);
}
