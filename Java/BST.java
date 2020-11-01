public class BST {
		private Node root;
		
		private Node getNode(Node node, int value){ 
			
			if(value == node.value){ 
				return node;
			}else{
				if(value < node.value){ 	
						if(node.hasLeft()){
							return getNode(node.left, value);
						}else{
							return node;
						}		
					}else{ 
						if(node.hasRight()){
							return getNode(node.right, value); 
						}else{
							return node;
						}		
					}
			}
		}
			
		public boolean add(int value){
			
			if(root == null){ 
				
				root = new Node(value);
				System.out.print("\n"+value+"Rt ");
				return true;
				
			}else{
				
				Node node = getNode(root, value); 
				
				if(value != node.value){ 
					Node newNode = new Node(value);
						if(value < node.value){
							node.left = newNode;
							System.out.print(value+"L ");
						}else{ 
							node.right = newNode;
							System.out.print(value+"R ");
						}
					return true;
				}
				
			}
			return false;
		}
		
	
	
	class Node{
		public int value;
		public Node left; 
		public Node right;
		
		public Node(int value){
			this.value = value;
		}
		
		public boolean hasLeft(){ 
			if(left != null) {
				return true;
			}
				return false;
		}
		
		public boolean hasRight(){
			if(right != null) {
				return true;
			}
				return false;
		}
	}
	
	public static void main(String[] args) {
		BST A = new BST();
		
		//Creating a Binary Search Tree
		A.add(8); //Root
		A.add(2); //Goes to the left of the root.
		A.add(10); //Goes to the right of the root.
		A.add(3); //Goes to the left of the root, and to the right of 2.
		A.add(1); //Goes to the left of the root, and to the left of 2.
		A.add(9); //Goes to the right of the root, and to the left of 10.
		A.add(11); //Goes to the right of the root, and to the right of 11.



		/*
		 		8
		 	/		\
		  2           10
		 / \         / \
		1   3		9	11
		 				
		 					*/	
	}

}
