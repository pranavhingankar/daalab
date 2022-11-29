class BSTNode
{
public:
    int data;
    BSTNode *left, *right;
    int leftSize;
    BSTNode(){
        this->data = 0;
        left = right = nullptr;
        leftSize = 0;
    }
    BSTNode(int data)
    {
        this->data = data;
        left = right = nullptr;
        leftSize = 0;
    }
    BSTNode *insert(BSTNode *root, int data)
    {
        if (!root)
            return new BSTNode(data);

        // Updating size of left subtree.
        if (data <= root->data)
        {
            root->left = insert(root->left, data);
            root->leftSize++;
        }
        else
            root->right = insert(root->right, data);

        return root;
    }
    int getRank(BSTNode *root, int x)
    {
        // data found
        if (root->data == x)
            return root->leftSize;

        if (x < root->data)
        {
            // not found
            if (!root->left)
                return -1;
            else
                return getRank(root->left, x);
        }
        else
        {
            // not found
            if (!root->right)
                return -1;
            else
            {
                int rightSize = getRank(root->right, x);
                if (rightSize == -1)
                    return -1;
                return root->leftSize + 1 + rightSize;
            }
        }
        return -1;
    }
};
