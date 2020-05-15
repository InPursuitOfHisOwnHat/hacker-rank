using System;

namespace _24_more_linked_lists
{
using System;
using System.Collections.Generic;
class Node
{
	public int data;
	public Node next;
    public Node(int d){
        data=d;
        next=null;
    }
		
}
class Solution {


    public static Node removeDuplicates(Node head){
        
        if (head == null) {
            return null;
        }

        Node nodeToCheck;
        Node iterNode;
        Node prevIterNode;
        
        nodeToCheck = head;

        while(nodeToCheck != null) {
            //Console.WriteLine("CheckNode = {0}", nodeToCheck.data);

            iterNode = nodeToCheck.next;
            prevIterNode = nodeToCheck;

            while(iterNode != null) {
                //Console.WriteLine("Comparing {0} to {1}", iterNode.data, nodeToCheck.data);
                if (iterNode.data == nodeToCheck.data) {
                    //Console.WriteLine("Match");
                    prevIterNode.next = iterNode.next;
                    iterNode = iterNode.next;
                }
                else {
                    prevIterNode = iterNode;
                    iterNode = iterNode.next;
                }
            }
            nodeToCheck = nodeToCheck.next;
        }
        return head;
    }

        public static  Node insert(Node head,int data)
        {
            Node p=new Node(data);
            
            
            if(head==null)
                head=p;
            else if(head.next==null)
                head.next=p;
            else
            {
                Node start=head;
                while(start.next!=null)
                    start=start.next;
                start.next=p;
                
            }
            return head;
        }
        public static void display(Node head)
        {
            Node start=head;
            while(start!=null)
            {
                Console.Write(start.data+" ");
                start=start.next;
            }
        }
        static void Main(String[] args) {
        
            Node head=null;
            int T=Int32.Parse(Console.ReadLine());
            while(T-->0){
                int data=Int32.Parse(Console.ReadLine());
                head=insert(head,data);
            }
            head=removeDuplicates(head);
            display(head);
        }
    }
}
