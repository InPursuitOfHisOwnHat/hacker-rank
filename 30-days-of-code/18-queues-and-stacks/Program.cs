using System;
using System.Collections.Generic;
using System.IO;

class Solution {
    
    // A more efficient version of this is to use stack and queue pointers so that memory doesn't have to 
    // be explicitly allocated and freed each time - you could just move the pointers to the relevant indexes.
    // Maybe add a shrink() method to periodically recover memory
    // I might do that somewhere else.

    //Write your code here
        char[] queue = new char[0];
        char[] stack = new char[0];

        private void printArray(char[] arr) {

            for(int i=0; i<arr.Length; i++) {
                Console.Write("{0}", arr[i]);
            }
            Console.WriteLine();
        }

        public void pushCharacter(char c){

            int currStackLength = this.stack.Length;
            char[] newStack = new char[currStackLength+1];
            for(int i=0; i<currStackLength;i++) {
                newStack[i] = this.stack[i];
            }
            newStack[currStackLength] = c;
            this.stack = newStack;
            //printArray(this.stack);

        }

        public void enqueueCharacter(char c) {

            int currQueueLength = this.queue.Length;
            char[] newQueue = new char[currQueueLength+1];
            for(int i=0; i<currQueueLength;i++) {
                newQueue[i] = this.queue[i];
            }
            newQueue[currQueueLength] = c;
            this.queue = newQueue;
            //printArray(this.queue);
        }

        public char popCharacter() {

            int currStackLength = this.stack.Length;
            char retChar = this.stack[currStackLength-1];
            char[] newStack = new char[currStackLength-1];
            for(int i=0; i<currStackLength-1; i++) {
                newStack[i] = this.stack[i];
            }
            this.stack = newStack;
            ///printArray(this.stack);
            return retChar;
        }

        public char dequeueCharacter() {

            int currQueueLength = this.queue.Length;
            char retChar = this.queue[0];
            char[] newQueue = new char[currQueueLength-1];
            for(int i=0; i<currQueueLength-1;i++) {
                newQueue[i] = this.queue[i+1];
            }
            this.queue = newQueue;
            //printArray(this.queue);
            return retChar;
        }

    static void Main(String[] args) {
        // read the string s.
        string s = Console.ReadLine();
        
        // create the Solution class object p.
        Solution obj = new Solution();
        
        // push/enqueue all the characters of string s to stack.
        foreach (char c in s) {
            obj.pushCharacter(c);
            obj.enqueueCharacter(c);
        }
        
        bool isPalindrome = true;
        
        // pop the top character from stack.
        // dequeue the first character from queue.
        // compare both the characters.
        for (int i = 0; i < s.Length / 2; i++) {
            if (obj.popCharacter() != obj.dequeueCharacter()) {
                isPalindrome = false;
                
                break;
            }
        }
        
        // finally print whether string s is palindrome or not.
        if (isPalindrome) {
            Console.Write("The word, {0}, is a palindrome.", s);
        } else {
            Console.Write("The word, {0}, is not a palindrome.", s);
        }
    }
}