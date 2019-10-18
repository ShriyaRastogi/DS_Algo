Node* newnode(int data)
{
    Node* nnode = new Node();
    nnode->data = data;
    nnode->left = NULL;
    nnode->right = NULL;
    nnode->height = 1;
    return nnode;
}
int height(Node* node)
{
    if(node == NULL) return 0;
    return node->height;
}
int bf(Node* node)
{
    if(node==NULL) return 0;
    return height(node->left) - height(node->right);
}
Node* rightRotate(Node* node)
{
    if(node == NULL) return NULL;
    Node *p = node;
    Node *q = node->left;
    Node* hold = q->right;
    q->right = p;
    p->left = hold;
    p->height = max(height(p->left),height(p->right))+1;
    q->height = max(height(q->left),height(q->right))+1;
    return q;
}
Node* leftRotate(Node* node)
{
    if(node == NULL) return NULL;
    Node *p = node;
    Node *q = node->right;
    Node* hold = q->left;
    q->left = p;
    p->right = hold;
    p->height = max(height(p->left),height(p->right))+1;
    q->height = max(height(q->left),height(q->right))+1;
    return q;
}
Node* insertToAVL( Node* node, int data)
{
    if(node == NULL) return newnode(data);
    if(data < node->data) node->left = insertToAVL(node->left,data);
    else if(data > node->data) node->right = insertToAVL(node->right,data);
    else return node; // no duplicates
    node->height = max(height(node->left), height(node->right)) + 1;
    int b = bf(node);
    if(b>1) // left heavy
    {
        int lb = bf(node->left);
        if(lb == 1) node = rightRotate(node);
        else if(lb==-1)
        {
            node->left = leftRotate(node->left);
            node = rightRotate(node);
        }
    }
    else if(b<-1)
    {
        int lb = bf(node->right);
        if(lb == -1) node = leftRotate(node);
        else if(lb==1)
        {
            node->right = rightRotate(node->right);
            node = leftRotate(node);
        }
    }
    return node;
    
    
}