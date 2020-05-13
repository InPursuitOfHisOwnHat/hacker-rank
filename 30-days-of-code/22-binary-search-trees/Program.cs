using System;

namespace _22_binary_search_trees
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
            int height=getHeight(root);
            Console.WriteLine(height);
            
        }
    }
}
