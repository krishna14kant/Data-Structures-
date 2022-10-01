import java.io.*;

public class LinkedList {
	static class Node {
		int data;
		Node next;
		Node(int data) {
			this.data = data;
			next = null;
		}
	}

	static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static int N = 0;

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		Node head = null;
		int key = 0;
		do {
			out.write("Enter a value: "); out.flush();
			int data = Integer.parseInt(in.readLine());
			// head = addNodeAtBeginning(head, data);
			head = addNodeAtEnding(head, data);

			out.write("Want to continue insertion ? (0/1): "); out.flush();
			key = Integer.parseInt(in.readLine()) == 1 ? 1 : 0;
		} while (key != 0);

		N = getNodesCount(head);

		out.write("\n"); out.flush();
		displayList(head);

		out.write("\nWant to add node at middle? (1/0): "); out.flush();
		key = Integer.parseInt(in.readLine());

		if (key == 1) {
			// out.write("Enter the position for the new node: "); out.flush();
			// int pos = Integer.parseInt(in.readLine());
			// out.write("Enter a value: "); out.flush();
			// head = addNodeAtMiddle(head, Integer.parseInt(in.readLine()), pos);

			out.write("\nEnter the node before which you want the insertion: "); out.flush();
			int data = Integer.parseInt(in.readLine());
			out.write("Enter the value: "); out.flush();
			int val = Integer.parseInt(in.readLine());
			Node temp = head;
			while (temp.data != data) temp = temp.next;
			out.write("\nSelected Node value: " + temp.data + "\n"); out.flush();
			addNodeAtCurrNodePos(temp, val);
			N = getNodesCount(head);
			displayList(head);
		}

		out.write("\nWant to delete a node? (1/0): "); out.flush();
		key = Integer.parseInt(in.readLine());

		if (key == 1) {
			// out.write("Enter the position for the new node: "); out.flush();
			// int pos = Integer.parseInt(in.readLine());
			// out.write("Enter a value: "); out.flush();
			// head = addNodeAtMiddle(head, Integer.parseInt(in.readLine()), pos);

			out.write("\nEnter the node you want to delete: "); out.flush();
			int data = Integer.parseInt(in.readLine());
			Node temp = head;
			while (temp.data != data) temp = temp.next;
			out.write("\nSelected Node value: " + temp.data + "\n"); out.flush();
			deleteCurrNode(temp);
		}
		
		out.write("\nTotal " + N + " nodes found.\n"); out.flush();
		displayList(head);
		displayListReversely(head, N);
	}
// ---------------------- Counting nodes in the list ---------------------------------------------------
	static int getNodesCount(Node head) {
		if (head == null) {
			return 0;
		}
		int count = 0;
		while (head != null) {
			count++;
			head = head.next;
		}
		return count;
	}
// ---------------------- Displaying nodes in the list ---------------------------------------------------
	static void displayList(Node head) throws IOException {
		if (head == null || N == 0) {
			out.write("The list is empty.\n"); out.flush();
			return;
		}
		out.write("The list is:\n"); out.flush();
		Node temp = head;
		int i = N;
		while (temp != null && i-- > 0) {
			out.write((temp.data) + " ");
			out.flush();
			temp = temp.next;
		}
		out.write("\n"); out.flush();
	}
	static void displayListReversely(Node head, int N) throws IOException {
		if (head == null || N == 0) {
			out.write("The list is empty.\n"); out.flush();
			return;
		}
		int[] list = new int[N];
		int i = 0;
		for (i = 0; head != null && i < N; head = head.next)
			list[i++] = head.data;
		i--;
		out.write("Displaying list reversely:\n"); out.flush();
		for (; i >= 0; i--) {
			out.write(list[i] + " ");
			out.flush();
		}
		out.write("\n"); out.flush();
	}
// ---------------------- Adding a node in the list ---------------------------------------------------
	static void addNodeAtCurrNodePos(Node posNode, int val) {
		Node temp = new Node(posNode.data);
		temp.next = posNode.next;
		posNode.data = val;
		posNode.next = temp;
	}
	static Node addNodeAtMiddle(Node head, int val, int pos) throws IOException {
		Node node = new Node(val);
		if (pos == 0) {
			node.next = head;
			head = node;
			return head;
		}
		Node temp = head;
		while(--pos > 0){
			if (temp == null) {
				out.write("\nYou entered position greater than total nodes!!!\n"); out.flush();
				return head;
			}
			temp = temp.next;
		}
		node.next = temp.next;
		temp.next = node;
		return head;
	}
	static Node addNodeAtEnding(Node head, int val) {
		Node node = new Node(val);
		if (head == null) {
			head = node;
		} else {
			Node temp = head;
			while (temp.next != null) temp = temp.next;
			temp.next = node;
		}
		return head;
	}
	static Node addNodeAtBeginning(Node head, int val) {
		Node node = new Node(val);
		if (head == null) {
			head = node;
		} else {
			node.next = head;
			head = node;
		}
		return head;
	}
// ---------------------- Deleting a node in the list ---------------------------------------------------
	// Not developed these yet
	static void deleteCurrNode(Node posNode) {
		N--;
		if (posNode.next == null) {
			posNode = null;
			return;
		}
		Node temp = new Node(posNode.next.data);
		temp.next = posNode.next.next;
		posNode.data = temp.data;
		posNode.next = temp.next;
	}
	static Node deleteNodeAtMiddle(Node head, int val, int pos) throws IOException {
		Node node = new Node(val);
		if (pos == 0) {
			node.next = head;
			head = node;
			return head;
		}
		Node temp = head;
		while(--pos > 0){
			if (temp == null) {
				out.write("\nYou entered position greater than total nodes!!!\n"); out.flush();
				return head;
			}
			temp = temp.next;
		}
		node.next = temp.next;
		temp.next = node;
		return head;
	}
	static Node deleteNodeAtEnding(Node head, int val) {
		Node node = new Node(val);
		if (head == null) {
			head = node;
		} else {
			Node temp = head;
			while (temp.next != null) temp = temp.next;
			temp.next = node;
		}
		return head;
	}
	static Node deleteNodeAtBeginning(Node head, int val) {
		Node node = new Node(val);
		if (head == null) {
			head = node;
		} else {
			node.next = head;
			head = node;
		}
		return head;
	}
}
