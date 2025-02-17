// this one  program contain all operations 
// in this program , all operations is nothing but which have already discussed in particular file

import java.util.Scanner;

 public class BinaryTreeCreationUsingRecursion{
    public Node root;
    public BinaryTreeCreationUsingRecursion(){
        this.root = null;
    }
    // class of node of binary tree
    public static class Node{
        int data;
        Node leftChild;
        Node rightChild;
        public Node(int data){
            this.data = data;
            this.leftChild = null;
            this.rightChild = null;
        }
    }

    public Node create(){
        Scanner sc = new Scanner(System.in);
        Node newNode;
        System.out.println("Enter the data otherwise enter -1 to stop inputting in the binary tree.");
        int newData = sc.nextInt();
        if(newData == -1){
            return null;
        }
        newNode = new Node(newData);
        if(this.root == null){
            this.root = newNode;
        }
        System.out.println("For leftChild child of "+newData);
        newNode.leftChild = create();
        System.out.println("For rightChild child of "+newData);
        newNode.rightChild = create();
        return newNode;
    }
    public void preOrder(Node root){
        // Root leftChild rightChild
        if(root == null){
            return;
        }
        System.out.print(root.data+"\t");
        preOrder(root.leftChild);
        preOrder(root.rightChild);
    }
     // function to inorder traversig
     public void inOrder(Node root){
        //  leftChild Root rightChild
        if(root == null){
            return;
        }
        inOrder(root.leftChild);
        System.out.print(root.data+"\t");
        inOrder(root.rightChild);
    }
    // function to postorder traversig
    public void postOrder(Node root){
        //  leftChild  rightChild Root
        if(root == null){
            return;
        }
        
        postOrder(root.leftChild);
        postOrder(root.rightChild);
        System.out.print(root.data+"\t");
    }
    
}
// Driver Code
// public class Main{
//     public static void main(String[] args) {
//         BinaryTreeCreationUsingRecursion bt = new BinaryTreeCreationUsingRecursion();
//         bt.create();
//         bt.preOrder(bt.root);
//         System.out.println();
//         bt.inOrder(bt.root);
//         System.out.println();
//         bt.postOrder(bt.root);
//     }
// }
