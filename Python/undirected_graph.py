class Graph:

    def __init__(self):
        self.dict={}

    def Add_vertex(self,vertex):
        self.dict[vertex]=[]

    def Add_edge(self,vertex,edge):
        self.dict[vertex].append(edge)

    def Delete_vertex(self,vertex):
        del self.dict[vertex]
        for i in self.dict:
            for j in self.dict[i]:
                if j==vertex:
                    self.dict[i].remove(j)
                    

    def Delete_edge(self,vertex,edge):
        self.dict[vertex].remove(edge)
        self.dict[edge].remove(vertex)


        
# Test Implementation
g=Graph()
"""
g.Add_vertex(1)
g.Add_vertex(2)
g.Add_vertex(3)
g.Add_vertex(4)
g.Add_vertex(5)
g.Add_edge(1,2)
g.Add_edge(1,3)
g.Add_edge(1,4)
g.Add_edge(2,1)
g.Add_edge(2,3)
g.Add_edge(3,1)
g.Add_edge(3,2)
g.Add_edge(3,5)
g.Add_edge(4,1)
g.Add_edge(4,5)
g.Add_edge(5,3)
g.Add_edge(5,4)
print(g.dict)
g.Delete_edge(1,3)
g.Delete_vertex(2)
print(g.dict)"""
g.Add_vertex(1)
g.Add_vertex(2)
g.Add_vertex(3)
g.Add_vertex(4)
g.Add_vertex(5)
g.Add_edge(1,2)
g.Add_edge(2,1)
g.Add_edge(2,3)
g.Add_edge(3,1)
g.Add_edge(4,1)
g.Add_edge(4,5)
g.Add_edge(3,5)
print(g.dict)
        
        
