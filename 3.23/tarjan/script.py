from cyaron import *
  
test_data = IO(file_prefix="input")

n = 20
m = 50
test_data.input_writeln(n, m)

graph = Graph.graph(n, m)
test_data.input_writeln(graph.to_str(output=Edge.unweighted_edge, shuffle = True))
test_data.output_gen("std.exe")
