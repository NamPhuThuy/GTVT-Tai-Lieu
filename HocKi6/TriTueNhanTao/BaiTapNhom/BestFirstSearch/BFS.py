import queue

from tabulate import tabulate


class BFSearch:
    @staticmethod
    def readfile(filename:str):

        #luu dinh va trong so
        data_dict = {}

        #Vertices and is neighbors
        graph = {}

        # Mở tệp tin input
        with open(filename, 'r') as file:
            # Đọc số lượng dòng (n)
            n = int(file.readline().strip())

            # Vertices and it's weight
            for _ in range(n):
                line = file.readline().strip().split()
                key = line[0]
                value = int(line[1])
                data_dict[key] = value

            # Number of edges
            socanh = int(file.readline().strip())

            for _ in range(n):
                line = file.readline().strip().split()

                #the root vertex
                root_vertex = line[0]

                #list of neighbors
                adjacent_vertices = line[1:]

                #Store them into the 'graph' dictionary
                graph[root_vertex] = adjacent_vertices

            # The start point and end point
            start, end = file.readline().strip().split()

        # # In ra nội dung của từ điển
        # print('so dinh: '+str(n))
        # for key, value in data_dict.items():
        #      print(key + " " + str(value))
        # print('so canh: ' + str(socanh))
        # for vertex, neighbors in graph.items():
        #     print(f"Vertex {vertex}: Neighbors {neighbors}")
        # print(start+ " "+ end)
        return data_dict, graph, start, end

    @staticmethod
    def Search(data_dict, graph, start, end):
        heads = ["Phát triển TT", "Trạng thái kề", "Danh sách L"]
        row =[]

        # Initial the L-list only contains first state
        #

        # Khởi tạo danh sách L chỉ chứa trạng thái ban đầu
        L = [(start, [start])]  # Danh sách L gồm cặp (đỉnh, đường đi)

        # Loop
        while L:
            # Nếu L rỗng
            if not L:
                print("Tìm kiếm thất bại")
                return tabulate(None, headers=heads, tablefmt="fancy_grid") + "Tim kiem that bai"


            # Loại trạng thái u ở đầu danh sách L
            u, path = L.pop(0)

            # Nếu u là trạng thái kết thúc
            if u == end:
                print("Tìm kiếm thành công")
                row.append([u + str(data_dict[u]), "TTKT-Dung", None])
                return tabulate(row, headers=heads, tablefmt="fancy_grid") + "\nĐường đi là: " + " => ".join(path[::1])

            # Duyệt qua các trạng thái v kề u
            for v in graph.get(u, []):
                # Tạo một đường đi mới bao gồm v
                new_path = path + [v]
                # Thêm vào danh sách L sao cho L được sắp theo thứ tự tăng dần của hàm đánh giá
                L.append((v, new_path))
                L.sort(key=lambda x: data_dict.get(x[0], float('inf')))
            row.append([u+str(data_dict[u]), ", ".join([i + str(data_dict[i]) for i in graph[u]]),", ".join(i1 + str(data_dict[i1]) for i1, _ in L)])


    @staticmethod
    def printFile(s: str, content: str):
        file = open(s, "w", encoding="utf-8")
        file.write(content)
        file.close()

if __name__ == '__main__':
    data_dict, graph, start, end = BFSearch.readfile('inputbfs.txt')
    print(BFSearch.Search(data_dict, graph, start, end))

    BFSearch.printFile("output1.txt",BFSearch.Search(data_dict, graph, start, end))

