#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class SegmentTree{
    inline static int n;
    vector<int> segmentTree;
    void buildTree(vector<int>& nums, int currNode, int left, int right){
        if(left == right) segmentTree[currNode] = nums[left];
        else{
            int leftChild = currNode*2 + 1;
            int rightChild = currNode*2 + 2;
            buildTree(nums, leftChild, left, (left+right)/2);
            buildTree(nums, rightChild, (left+right)/2 + 1, right);
            segmentTree[currNode] = segmentTree[leftChild] + segmentTree[rightChild];
        }
    }
public:
    SegmentTree(vector<int>& nums){
        this->n = size(nums);
        int treeHeight = ceil(log2(n)) + 1;
        int nodes = pow(2, treeHeight) - 1;
        segmentTree.resize(nodes);
        int currNode = 0, left = 0, right = n-1;
        buildTree(nums, currNode, left, right);
    }
    int sumRange(int left, int right, int currNode = 0, int currLeft = 0, int currRight = n-1){
        // cout << "CurrNode->" << currNode << endl;
        if(currLeft > right or currRight < left) return 0;
        if(left <= currLeft and currRight <= right) return segmentTree[currNode];
        int mid = currLeft + (currRight-currLeft) / 2;
        // cout << "mid->" << mid << endl;
        if(left > mid)
            return sumRange(left, right, currNode*2 + 2, mid+1, currRight);
        else if(right <= mid)
            return sumRange(left, right, currNode*2 + 1, currLeft, mid);
        else{
            int sumFromLeft = sumRange(left, right, currNode*2 + 1, currLeft, mid);
            int sumFromRight = sumRange(left, right, currNode*2 + 2, mid+1, currRight);
            return sumFromLeft + sumFromRight;
        }
    }
    void update(int index, int val, int currNode = 0, int currLeft = 0, int currRight = n-1){
        if(currLeft == currRight) {segmentTree[currNode] = val; return;}
        int mid = currLeft + (currRight-currLeft)/2;
        if(index <= mid) update(index, val, currNode*2 + 1, currLeft, mid);
        else update(index, val, currNode*2 + 2, mid+1, currRight);
        segmentTree[currNode] = segmentTree[currNode*2+1] + segmentTree[currNode*2+2];
    }
};

int main(int argc, char const *argv[]){
    vector<int> nums = {18, 17, 13, 19, 15, 11, 20, 12, 33, 25};
    SegmentTree segmentTree(nums);
    // for(int num: segmentTree.segmentTree) cout << num << ' '; cout << endl;
    segmentTree.update(0,45);
    // for(int num: segmentTree.segmentTree) cout << num << ' '; cout << endl;
    cout << segmentTree.sumRange(0,9) << endl;
    segmentTree.update(1,53);
    // for(int num: segmentTree.segmentTree) cout << num << ' '; cout << endl;
    cout << segmentTree.sumRange(0,9) << endl;
    segmentTree.update(2,84);
    // for(int num: segmentTree.segmentTree) cout << num << ' '; cout << endl;
    cout << segmentTree.sumRange(0,9) << endl;
    segmentTree.update(3,37);
    // for(int num: segmentTree.segmentTree) cout << num << ' '; cout << endl;
    cout << segmentTree.sumRange(0,9) << endl;
    segmentTree.update(4,16);
    // for(int num: segmentTree.segmentTree) cout << num << ' '; cout << endl;
    cout << segmentTree.sumRange(0,9) << endl;
    segmentTree.update(5,85);
    // for(int num: segmentTree.segmentTree) cout << num << ' '; cout << endl;
    cout << segmentTree.sumRange(0,9) << endl;
    segmentTree.update(6,97);
    // for(int num: segmentTree.segmentTree) cout << num << ' '; cout << endl;
    cout << segmentTree.sumRange(0,9) << endl;
    segmentTree.update(7,31);
    // for(int num: segmentTree.segmentTree) cout << num << ' '; cout << endl;
    cout << segmentTree.sumRange(0,9) << endl;
    segmentTree.update(8,34);
    // for(int num: segmentTree.segmentTree) cout << num << ' '; cout << endl;
    cout << segmentTree.sumRange(0,9) << endl;
    segmentTree.update(9,64);
    // for(int num: segmentTree.segmentTree) cout << num << ' '; cout << endl;
    cout << segmentTree.sumRange(0,9) << endl;
    return 0;
}
