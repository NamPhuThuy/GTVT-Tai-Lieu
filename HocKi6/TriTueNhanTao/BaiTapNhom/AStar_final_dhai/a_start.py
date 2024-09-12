from tabulate import tabulate

#lưu điểm đầu, điểm kết thúc và độ dài
class Edge:
    def __init__(self, start, end, weight):
        self.start = start
        self.end = end
        self.weight = weight

# lưu trạng thái
class State:
    def __init__(self, name, h, g, path=[]):
        self.name = name    # tên trạng thái
        self.h = h          # trọng số
        self.g = g          # độ dài từ start đến điểm hiện tại
        self.f = self.g + self.h
        self.path = path    # quãng đường đi từ điểm bắt đầu đến điểm hiện tại

    # sort() theo giá trị của f: nhỏ đến lớn
    def __lt__(self, other):
        return self.f < other.f

    # Định nghĩa lại cách so sanh bằng
    def __eq__(self, other):
        return (self.name == other.name and self.h == other.h
                and self.g == other.g and self.path == other.path
                and self.f == other.f)
def get_g(L, name):
    for state in L:
        if state.name == name:
            return state.g
def get_f(L, name):
    for state in L:
        if state.name == name:
            return state.f

def read_input(filename):
    # đỉnh và trọng số
    nodes = {}

    #dict: (edge_start,edge_end) - edge_weight: điểm đầu, điểm kết thúc, độ dài
    edges = {}

    #dict: tên đỉnh - danh sách đỉnh kề
    neighbors = {}

    sodinh = 0

    with open(filename, 'r') as f:

        try:
            sodinh = int(f.readline().strip())
        except ValueError:
            print("Dòng đầu tiên phải là số nguyên - đại diện cho số đỉnh")

        for _ in range(sodinh):
            node_data = f.readline().strip().split()
            node_name = node_data[0]
            try:
                node_value = int(node_data[1])
            except:
                print("Trọng số của đỉnh phải là số nguyên")

            nodes[node_name] = node_value
            neighbors[node_name] = []

        try:
            socanh = int(f.readline().strip())
        except ValueError:
            print("Số cạnh phải là một số nguyên")

        for _ in range(socanh):
            edge_data = f.readline().strip().split()
            edge_start = edge_data[0]
            edge_end = edge_data[1]

            try:
                edge_weight = int(edge_data[2])
            except ValueError:
                print("Trọng số của cạnh phải là một số nguyên")

            edges[(edge_start,edge_end)] = edge_weight
            neighbors[edge_start].append(edge_end)

        lastlst = f.readline().strip().split()
        if (len(lastlst) > 2):
            raise ValueError("Dòng cuối chỉ có 2 đỉnh: đỉnh đầu và đỉnh kết thúc")
        else:
            start, end = lastlst
            print(lastlst)

        return start, end, nodes, edges, neighbors

def astart(start, end, nodes, edges, neighbors):
    head = ["TT", "TTK", "k(u,v)", "h(v)", "g(v)", "f(v)", "Danh sách L"]
    rows = []

    #khởi tạo trạng thái ban đầu
    current_state = State(start, nodes[start], 0,[])
    L = [current_state]

    while L:
        # nếu L rỗng
        if not L:
            print('Tìm kiếm thất bại')
            return tabulate(None, headers=head, tablefmt="fancy_grid") + "Tìm kiếm thất bại"
        u = L.pop(0)

        ttmp = []

        # Nếu u là trạng thái kết thúc
        if u.name == end:
            print("Tìm kiếm thành công")
            rows.append([u.name, "TTKT-Dung"])
            u.path.append(u.name)
            return tabulate(rows, headers=head, tablefmt="fancy_grid") + "\nĐường đi là: " + " -> ".join(
                u.path[::1]) + ", đường đi có độ dài " + str(u.g)


        for v in neighbors[u.name]:

            # {(a, b): 8}
            g_v = u.g + edges[(u.name, v)]
            new_state = State(v, nodes[v], g_v, u.path + [u.name])
            if new_state not in L:
                L.append(new_state)
                ttmp.append(new_state)
                L.sort()

        rows.append(
            [u.name, "\n".join(neighbors[u.name]),
             "\n".join(f"{weight}" for (start, end), weight in edges.items() if start == u.name),
             "\n".join(str(nodes[i]) for i in neighbors[u.name]),
             "\n".join(str(get_g(ttmp, v)) for v in neighbors[u.name]),
             "\n".join(str(get_f(ttmp, v))  for v in neighbors[u.name]),
             ", ".join(L[i].name + str(L[i].f) for i in range(len(L)))])

def printfile(filename: str, content: str):
    file = open(filename, "w", encoding="utf-8")
    file.write(content)
    file.close()


if __name__ == '__main__':
    start, end, nodes, edges, neighbors = read_input("inputAStar.txt")
    printfile("outputastar.txt", astart(start, end, nodes, edges, neighbors))