/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			bst.cpp
 * Author(s):		Peter Bauer
 * Due Date:		May 31, 2017
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "bst.h"



struct Node
{
  int value;
  struct Node* left;
  struct Node* right;
};

/**
*** Initializes the binary search tree. Deletes all existing nodes in the tree
*** @return The number of deleted nodes
*/
Bst new_bst() {
  Bst newBst=(Bst)malloc(sizeof(struct Node));
  newBst->left=0;
  newBst->right=0;
  newBst->value=0;
  newBst=0;
return newBst;
}

void delete_bst(Bst bst){
  if(bst!=0)
  {
    delete_bst(bst->left);
    delete_bst(bst->right);
    sfree(bst);
}
}

/**
*** @return The depth of the BST
*/
int get_depth(Bst bst){
  if(bst==0)
  {
    return 0;
  }
  else
  {
    int ldepth=get_depth(bst->left);
    int rdepth=get_depth(bst->right);

    if(ldepth>rdepth)
    {
      return ldepth+1;
    }
    else
    {
      return rdepth+1;
    }
}
}

/**
*** Adds a value to the BST
*/
void add(Bst* bst, int value){
  if((*bst)==0)
  {
    Bst newBst=(Bst)malloc(sizeof(struct Node));
    newBst->left=0;
    newBst->right=0;
    newBst->value=value;
    *bst=newBst;
  }
  else if(value<=(*bst)->value)
  {
    add(&(*bst)->left,value);
  }
  else
  {
    add(&(*bst)->right,value);
}

}

/**
*** @return The value of the root element of the BST
*/
int root_value(Bst bst){
  return bst->value;
}

Bst left_subtree(Bst root){
  return root->left;
}

Bst right_subtree(Bst root){
  return root->right;
}

int traverse_pre_order(Bst bst, int *elements, int start){
  if(bst != 0)
  {
    elements[start] = bst->value;
    if(get_depth(bst) > 0)
    {
       start+=1;
       start = traverse_pre_order(bst->left, elements, start);
       start = traverse_pre_order(bst->right, elements, start);
    }
  }
  return start;
}

int traverse_in_order(Bst bst, int *elements, int start){
  if(bst != 0)
  {
    if(bst->left != 0)
    {
      start = traverse_in_order(bst->left, elements, start);
    }
    elements[start] = bst->value;
    start+=1;
    if(bst->right != 0)
    {
      start = traverse_in_order(bst->right, elements, start);
    }
  }
   return start;
}

int traverse_post_order(Bst bst, int *elements, int start){
  if(bst != 0)
  {
      if(bst->left != 0)
      {
        start = traverse_post_order(bst->left, elements, start);
      }
      if(bst->right != 0)
      {
        start = traverse_post_order(bst->right, elements, start);
      }
      elements[start] = bst->value;
      start+=1;
  }
   return start;
}

bool are_equal(Bst bst1, Bst bst2){
  if(bst1 == 0)
  {
    return bst2 == 0;
  }
  else if(get_depth(bst1) == get_depth(bst2))
  {
      if(bst1->value == bst2->value)
      {
        return (are_equal(bst1->left, bst2->left)) && (are_equal(bst1->right, bst2->right));
      }
  }
    return false;
}

void most_left_longest_branch(Bst bst, Bst* branch){

}

int get_number_of_subtrees(Bst bst){
    
}
