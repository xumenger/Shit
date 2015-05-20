#include <string>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

struct Tnode
{
    string word;
    int count;;
    Tnode *left;
    Tnode *right;
};
struct treenode
{
    string data;
    treenode *left;
    treenode *right;
};
typedef Tnode* PTree;

int main()
{
    
    system("pause");
    return 0;
}

Tnode* InsertLL(PTree pnr,Tnode* pn)
{//���½ڵ���뵽��ǰ�ڵ��������������ԭ�������ݷ����½ڵ����֧
       
    assert(pnr!=NULL);
    assert(pn!=NULL);
    pn->right=pnr->right;
    pnr->right=pn;
    return pnr;
       
}

Tnode* InsertLR(PTree pnr, Tnode* pn)
{//���½ڵ���뵽��ǰ�ڵ��������������ԭ�������ݷ����½ڵ����֧
    assert(pnr != NULL);
    assert(pn != NULL);
    pn->left = pnr->right;
    pnr->right = pn;
    return pnr;
}

Tnode* InsertLL_word(PTree pnr, string& word)
{//���½ڵ���뵽��ǰ�ڵ��������������ԭ�������ݷ����½ڵ����֧
    assert(pnr != NULL);
    Tnode* pn = IniTnode(word);
    return InsertLL(pnr, pn);
}

Tnode* InsertLR_word(PTree pnr, string& word)
{//���½ڵ���뵽��ǰ�ڵ��������������ԭ�������ݷ����½ڵ����֧
    assert(pnr != NULL);
    Tnode* pn = IniTnode(word);
    return InsertLR(pnr, pn);
}

void FreeTree(PTree toFree)
{//���Ļ��� 
   if(toFree == NULL)
    return ;
    //�ͷ�����
    if(toFree->left != NULL)
    FreeTree(toFree->left);
    //�ͷ�����
    if(toFree->right != NULL)
    FreeTree(toFree->right);
    //�ͷű��ڵ�
    FreeTnode(toFree);   
}

void PrintTreeLMR(const PTree proot)
{//�������������ӡ
    if(proot == NULL)
    return ;
    char buf[512];
    //��ӡ����
    if(proot->left != NULL)
    PrintTreeLMR(proot->left);
    //��ӡ���ڵ�
    cout<<ToString(buf, *proot)<<endl<<"------------------"<<endl;
    //��ӡ����
    if(proot->right != NULL)
    PrintTreeLMR(proot->right);
 
}
