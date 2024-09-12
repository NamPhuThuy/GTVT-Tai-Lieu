from queue import Queue
def read_file(filename):
   with open(filename, "r") as f:


    while True:
        line = f.readline()
        if not line:
            break

        # Tách chuỗi thành các phần tử
        elements = line.split()

        # Mảng để lưu các phần tử đã chỉnh sửa trong từng dòng
        modified_line_elements = []

        # Lặp qua từng phần tử trong dòng
        for element in elements:
            # Loại bỏ các dấu cách và chữ "v"
            modified_element = element.replace(" ", "").replace("v", "")
            # Thêm vào mảng đã chỉnh sửa trong từng dòng
            modified_line_elements.append(modified_element)

        # Thêm mảng các phần tử đã chỉnh sửa từ dòng hiện tại vào mảng hai chiều
        modified_elements.append(" ".join(modified_line_elements))

        # In dòng đã chỉnh sửa (không bao gồm dấu xuống dòng)
        # print(" ".join(modified_line_elements))

        # In mảng hai chiều


def resolve(modified_elements):
    while True:
        new_check = 0  # Biến để kiểm tra xem đã tìm được câu mới chưa

        # Lặp qua tất cả các cặp phần tử trong modified_elements
        for i in range(len(modified_elements)):
            for j in range(i + 1, len(modified_elements)):
                a = modified_elements[i]
                b = modified_elements[j]

                # Kiểm tra xem a và b có tạo ra câu mới không
                if check(a, b):
                    modified_elements.append(check(a, b))  # Thêm câu mới vào modified_elements
                if check(a, b)== None:
                    return 1;
        return 0;
def check(arr1, arr2):
    ans = []

    for i in range(len(arr1)):
        for j in range(len(arr2)):
            # If there are only one negative and one positive
            if len(arr1[i]) == 2 and len(arr2[j]) == 2:
                if arr1[i][1] == arr2[j][1]:
                    # Remove the conflicting elements
                    arr1.pop(i)
                    arr2.pop(j)
                    ans.extend(arr1)
                    ans.extend(arr2)
                    print(i,j,ans)
                    if not ans:  # Nếu ans rỗng
                        return 0  # Trả về 0 để thông báo rằng không có câu mới

    return ans
if __name__ == '__main__':
    modified_elements = []  # Mảng hai chiều để lưu các phần tử đã chỉnh sửa từ từng dòng
    read_file("Input.txt")  # Đọc từ tệp và cập nhật modified_elements

    # Phân giải tập modified_elements
    result = resolve(modified_elements)
    if result == 1:
        print("Không còn câu mới.")
    else:
        print("Tìm thấy câu mới.")

    print(modified_elements)  # In ra modified_elements sau khi đã phân giải
