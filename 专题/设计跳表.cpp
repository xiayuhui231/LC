class Skiplist {

public:
    Skiplist() : head(new Node()), maxLevels(0), length(0) {}

    bool search(int target) {
        Node* temp = head;
        while(temp) {
            // 1.在同一层级上，从左往右查找直到链表的结尾
            while (temp->right && temp->right->val < target) temp = temp->right;
            // 2.若找到符合条件的节点，即该节点的值与 target 相等,则返回true
            if(temp->right && temp->right->val == target) return true;
            // 3.若 node->right->val 大于(即不等于) target，则向下一层
            temp = temp->down;
        }
        return false;
    }

    void add(int num) {
        Node* temp = head;
        // 记录每一层可能生成索引位置的节点
        vector<Node*> nodes;
        // 1.定位插入位置;在原链表中 <=num 的最大节点前
        while (temp) {
            while (temp->right && temp->right->val < num) temp = temp->right;
            nodes.emplace_back(temp);
            temp = temp->down;
        }
        // 要不要在当前层建索引
        bool insertIndex = true;
        // 保存上一次建立的索引，本次建索引时将 down 指针连接到这里
        Node* downNode = nullptr;
        // 插入数据节点到最低层的链表（并且从下往上建立索引）
        while(insertIndex && !nodes.empty()) {
            temp = nodes.back(); nodes.pop_back();
            temp->right = new Node(num, downNode, temp->right);
            downNode = temp->right; // 保存当前节点让上一层索引的 down 指针连接
            insertIndex = ((rand() & 1) == 0); // 是否还要再往上层建索引
        }
        // 根据概率新建一层索引
        if(insertIndex) {
            temp = new Node(num, downNode, nullptr);
            head = new Node(-1, head, temp);
            ++maxLevels;
        }
        ++length; // 更新节点数量
    }

    bool erase(int num) {
        Node* temp = head;
        bool exist = false;
        while (temp) {
            while (temp->right && temp->right->val < num) temp = temp->right;
            Node* right = temp->right;
            Node* last = temp;
            // 从上往下逐个删除
            if(right && right->val == num){
                exist = true;
                last = temp;
                temp->right = right->right;
                right->right = nullptr;
                delete right;
            }
            temp = temp->down;
            // 是否需要删除这一层（最上层）索引
            if(last == head && last->right == nullptr) {
                Node* headShouldDelete = head;
                head = head->down;
                delete headShouldDelete;
                --maxLevels;
            }
        }
        if(exist) --length; // 更新节点数量
        return exist;
    }

private:
    struct Node {
        int val;
        Node* down;
        Node* right;
        Node(int _val = -1, Node* _down = nullptr, Node* _right = nullptr) : val(_val), down(_down), right(_right) {}
    };

    Node* head;
    int maxLevels; // 索引层数
    int length; // 记录节点数量

};