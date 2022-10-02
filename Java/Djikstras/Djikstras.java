package Graphs.Djikstras;

import java.util.*;

class Graph {
    class Edge{
        int src, dst, weight;
        Edge(int s, int d, int w)
        {
            this.src = s;
            this.dst = d;
            this.weight = w;
        }
    }

    class Pair implements Comparable<Pair>{
        int v, weight;
        String path;

        Pair(int v, int weight, String path)
        {
            this.v = v;
            this.weight = weight;
            this.path = path;
        }

        public int compareTo(Pair e) {
            return this.weight - e.weight;
        }
    }

    ArrayList<Edge>[] edge;

    Graph(int v) {
        edge = new ArrayList[v];
        for(int i=0; i<v; i++)
        {
            edge[i] = new ArrayList<>();
        }
    }

    public void addEdge(int source, int dest, int weight) {
        edge[source].add(new Edge(source,dest,weight));
        edge[dest].add(new Edge(dest,source,weight));
    }

    public void djisktra(int source, int dest, int v)
    {
        PriorityQueue<Pair> pr = new PriorityQueue<>();

        boolean visit[] = new boolean[v];

        pr.add(new Pair(source,0, source+""));
        int weight = 0;
        String path = "";

        while(!pr.isEmpty())
        {
            Pair p = pr.remove();

            if(visit[p.v] == true) continue;

            if(p.v == dest){ weight = p.weight;
            path = p.path;
            }

            visit[p.v] = true;

            for(Edge e : edge[p.v])
            {
                if(visit[e.dst] == false)
                {
                    pr.add(new Pair(e.dst,p.weight + e.weight, p.path + " " + e.dst));
                }
            }

        }

        System.out.print("Weight : " + weight);
        System.out.println(" Path : " + path);

    }

}

public class Djikstras {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print(" Enter the number of vertices : ");
        int v = sc.nextInt();
        System.out.print(" Enter the number of edges : ");
        int e = sc.nextInt();

        Graph graph = new Graph(e);

        System.out.print("\n Enter the source, destination & weight for " + e + " edges : \n");
        for(int i=0; i<e; i++)
        {
            int source = sc.nextInt();
            int dest = sc.nextInt();
            int weight = sc.nextInt();
            graph.addEdge(source,dest,weight);
        }

        System.out.println(" Enter the source and destination to find path : ");
        int source = sc.nextInt();
        int dest = sc.nextInt();

        graph.djisktra(source,dest,v);

        sc.close();
    }
}
