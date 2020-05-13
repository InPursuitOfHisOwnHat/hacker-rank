using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace _23_bst_level_order_traversal
{

    class Node{
        public Node left,right;
        public int data;
        public Node(int data){
            this.data=data;
            left=right=null;
        }
    }
    class Solution{
    static System.Collections.Queue q = new System.Collections.Queue();

    static int getHeight(Node root){
      
        int left_height = 0;
        int right_height = 0;

        if (root.left != null) {
            left_height = 1 + getHeight(root.left);
        }

        if (root.right != null) {
            right_height = 1 + getHeight(root.right);
        }
        
        if (left_height > right_height) {
            return left_height;
        }
        else  {
            return right_height;
        }
    }


    static void add_level_data_to_queue(Node root, int level) {

        if (root != null) {
            if (level == 1) {
                q.Enqueue(root.data);
            }
            else {
                add_level_data_to_queue(root.left, level-1);
                add_level_data_to_queue(root.right, level-1);
            }
        }
    }

    static void levelOrder(Node root){

        // Get height of the tree
        int treeHeight = getHeight(root);
        //Console.WriteLine("Tree Height {0}", treeHeight);
        //Adding 1 because the getHeight() function is more of a longest path function - doesn't include top node - Might change this later.
        for(int i=1; i<=treeHeight+1; i++) {
            add_level_data_to_queue(root, i);
        }

        foreach (int j in q) {
            Console.Write("{0} ", j);
        }

    }


        static Node insert(Node root, int data){
            if(root==null){
                return new Node(data);
            }
            else{
                Node cur;
                if(data<=root.data){
                    cur=insert(root.left,data);
                    root.left=cur;
                }
                else{
                    cur=insert(root.right,data);
                    root.right=cur;
                }
                return root;
            }
        }
        static void Main(String[] args){
            Node root=null;
            int T=Int32.Parse(Console.ReadLine());
            while(T-->0){
                int data=Int32.Parse(Console.ReadLine());
                root=insert(root,data);            
            }
            levelOrder(root);
            
        }
    }
}
