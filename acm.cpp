#include <iostream>
#include <stdexcept>
//数据结构3.25
using namespace std;
class MinStack {
private:
    struct Node
    {
        int value;
        int minSoFar;  // 最小值，截止到当前节点
        Node* next;
    };
    Node* topNode;  // 栈顶节点，用于push和pop操作
public:
    MinStack() : topNode(nullptr) {}

    // 压入元素
    void push(int value) {
        if (topNode == nullptr) {
            // 如果栈为空，直接将元素入栈
            topNode = new Node{value, value, nullptr};
        } else {
            // 如果栈不为空，计算新的最小值并入栈
            int newMin = (value < topNode->minSoFar) ? value : topNode->minSoFar;
            topNode = new Node{value, newMin, topNode};
        }
    }
    // 弹出元素
    void pop() {
        if (topNode == nullptr)
        {
            cout<<"Error!The Stack is Empty!";
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
    // 查找最小值
    int findMin() {
        if (topNode == nullptr)
        {
            cout<<"Error!The Stack is Empty!";
        }
        return topNode->minSoFar;
    }
    // 析构函数，释放内存
    ~MinStack() {
        while (topNode != nullptr) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }
};

int main() {
    MinStack stack;

    stack.push(3);
    stack.push(6);
    stack.push(4);
    stack.push(2);

    cout << "Min Value: " << stack.findMin() << endl;

    stack.pop();

    cout << "Min Value after pop: " << stack.findMin() <<endl;

    system("pause");
    return 0;
}
