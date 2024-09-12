from queue import Queue
isEndGame = False

def read_file_to_list_of_lists(filename):
    data = []
    with open(filename, 'r') as f:
        lines = f.readlines()
        for line in lines:
            # Remove trailing whitespace and split based on spaces
            content = line.strip().split(' v ')
            # Skip empty lines
            if content:
                data.append(content)
    return data


def check(arr1, arr2):
    isDuplicate = False
    ans = []

    Arr1 = []
    Arr2 = []
    for i in range(len(arr1)):
        Arr1.append(arr1[i])

    for i in range(len(arr2)):
        Arr2.append(arr2[i])


    # Check for the end-game
    if (len(arr1) == 1 and len(arr2) == 1):
        if (len(arr1[0]) * len(arr2[0]) == 2):
            if (arr1[0][len(arr1[0]) - 1] == arr2[0][len(arr2[0]) - 1]):
                #End game
                ans = "IsEndGame"
                return ans

    for i in range(len(arr1)):
        for j in range(len(arr2)):
            # print(i, j)
            # print(arr1[i], arr2[j])
            # print()

            # If there are only one negative and one positive
            if (len(arr1[i]) * len(arr2[j]) == 2):

                # print(arr1[i][len(arr1[i]) - 1], arr2[j][len(arr2[j]) - 1])
                if (arr1[i][len(arr1[i]) - 1] == arr2[j][len(arr2[j]) - 1]):
                    print("Check Dup")
                    Arr1.pop(i)
                    Arr2.pop(j)
                    isDuplicate = True

    if (isDuplicate):
        for i in range(len(Arr1)):
            ans.append(Arr1[i])

        for j in range(len(Arr2)):
            ans.append(Arr2[j])
    print(ans)
    return ans

def printQueue(q):
    temp_list = []

    # Loop through the queue, append elements to the list, and enqueue them back
    while not q.empty():
        element = q.get()
        temp_list.append(element)
        q.put(element)  # Re-enqueue the element to preserve the queue

    # Print the elements from the temporary list
    print(*temp_list)  # Unpack the list for printing
    print("checkout")

filename = "Input.txt"  # Replace with your actual file name
list_of_lists = read_file_to_list_of_lists(filename)

if __name__ == '__main__':
    with open("Output.txt", "w") as file:

        tempString = [str(f"-{list_of_lists[len(list_of_lists) - 1][0]}")]

        list_of_lists.append(tempString)
        list_of_lists.remove(['P'])
        # list_of_lists.append(['-P'])

        for i in list_of_lists:
            file.write(str(i))
            file.write("\n")
        print(list_of_lists)

        maxLength = len(list_of_lists)
        L_ID = 0
        R_ID = maxLength - 1

        while R_ID < len(list_of_lists):
            print("R_ID = " + str(R_ID) + str(list_of_lists[R_ID]))
            print("len: " + str(len(list_of_lists)))
            for i in range(L_ID, maxLength):
                temp = check(list_of_lists[i], list_of_lists[R_ID])
                print("lists: " + str(list_of_lists[i]) + str(list_of_lists[R_ID]))
                if (temp != []):
                    temp.sort()

                    print(temp)
                    if temp not in list_of_lists:
                        list_of_lists.append(temp)
                        print(list_of_lists)
                        file.write(f"Tu ({i}) {str(list_of_lists[i])} va ({R_ID}) {str(list_of_lists[R_ID])} => {str(temp)} (Ap dung luat phan giai)")
                        file.write("\n")

            R_ID = R_ID + 1
            print("check")
        engGameText = "Ta thay: hai menh de " + str(list_of_lists[i-3]) + " va " + str(
                list_of_lists[R_ID - 1]) + " mau thuan voi nhau, ma menh de " + str(
                list_of_lists[i]) + " duoc suy ra tu menh de '-P' -> menh de '-P' la sai -> menh de 'P' la dung "

        print("checkread")
        print(engGameText)
        file.write(str(engGameText))
        file.write("hihi")











