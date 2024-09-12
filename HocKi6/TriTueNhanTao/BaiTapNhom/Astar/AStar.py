from collections import defaultdict
from queue import PriorityQueue
from tabulate import tabulate


class Node:
    def __init__(self, val, name):
        self.val = val  # luu  gia tri cua node
        self.name = name  # luu ten cua node
        self.friends = []  # luu tru cac node con

    def connect(self, new):
        self.friends.append(new)

    def __str__(self):
        return f"{self.name} {self.val}"


class Graph:
    def __init__(self):
        self.nodes = defaultdict(Node)
        self.weight = defaultdict(list)

    def add_node(self, name, val):
        if name in self.nodes.keys():
            return
        else:
            self.nodes[name] = Node(val, name)

    def connected(self, a, b, val):
        self.nodes[a].connect(self.nodes[b])
        self.weight[(a, b)] = val

    def check(self):
        for u in self.nodes.values():
            print(u.name)
            for nd in u.friends:
                print(nd, end=" ")
            print()

        for i, v in self.weight.items():
            print(i, v)


def read_file(filename):
    file = open(filename)
    graph = Graph()
    line = file.readline().split()
    while line:
        graph.add_node(line[0], int(line[1]))
        line = file.readline().split()

    line = file.readline().split()
    while line:
        graph.connected(line[0], line[1], int(line[2]))
        line = file.readline().split()
    file.close()
    return graph


def Astar(graph, start, end):
    head = ["Phát triển TT", "TTK", "k(u,v)", "h(v)", "g(v)", "f(v)", "Danh sách L"]
    rows = []

    q = PriorityQueue()
    q.put((0, f"{start}0"))  # luu name and f(v)
    func_g = defaultdict(int)
    func_g[f"{start}0"] = 0
    visited = defaultdict(str)
    L = [f"{start}0"]
    key_func = lambda x: int(x[1:])

    while not q.empty():
        _ttk = []
        _k = []
        _h = []
        _g = []
        _f = []

        val, name = q.get()
        L.remove(name)
        if name[0] == end:

            path = [name[0]]
            rows.append([name[0], f"TTKT-DỪNG! {name}", None, None, None, None, None])

            while name[0] != start:
                name = visited[name]
                path.append(name[0])

            return tabulate(tabular_data=rows, headers=head, tablefmt="fancy_grid") + "\n" + " -> ".join(path[::-1])

        for u in graph.nodes[name[0]].friends:
            g = func_g[name] + graph.weight[(name[0], u.name)]
            f = g + u.val
            newname = f"{u.name}{f}"
            q.put((f, newname))
            func_g[newname] = g
            visited[newname] = name

            graph.weight[(name[0], u.name)]
            _ttk.append(u.name)
            _k.append(str(graph.weight[(name[0], u.name)]))
            _h.append(str(u.val))
            _g.append(str(g))
            _f.append(str(f))
            L.append(newname)

        L = sorted(L, key=key_func)

        rows.append(
            [name[0], "\n".join(_ttk), "\n".join(_k), "\n".join(_h), "\n".join(_g), "\n".join(_f), ", ".join(L)])


def printfile(filename: str, content: str):
    file = open(filename, "w", encoding="utf-8")
    file.write(content)
    file.close()


if __name__ == '__main__':
    graph = read_file("AStar_Input.txt")
    res = Astar(graph, "A", "B")
    printfile("AStar_Output.txt", res)