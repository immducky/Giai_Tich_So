#!/usr/bin/python3
# -*- coding: utf-8 -*-

# -----------------------------------------------
# Author: Thanh HoangVan
# Email: thanh.hoangvan051199@gmail.com
# School of Applied Mathematics and Informatics
# -----------------------------------------------

# import các thư viện cần thiết
import numpy as np
import numpy.linalg as LA
import pandas as pd
import matplotlib.pyplot as plt


# -----------------------------------------------

# Hàm vẽ đồ thị sai số  sau mỗi vòng lặp
def Graph(x, y):
    """
    Hàm vẽ đồ thị sai số sau mỗi vòng lặp
    ---
    Parameters:
    ---
        x: số vòng lặp
        y: sai số của từng vòng lặp
    Return
    ---
        Đồ thị biểu diễn sai số sau mỗi vòng lặp
    """

    x = np.arange(1, x + 1)
    plt.plot(x, y, 'r')
    plt.grid()
    plt.title("Sai số sau từng vòng lặp")
    plt.xlabel("Lần lặp")
    plt.ylabel("Sai số")
    plt.show()


# Hàm áp dụng pp lặp Newton tìm gần đúng ma trận nghịch đảos
def Newton(A, X0, eps):
    """
    Hàm tính gần đúng ma trận nghịch đảo
        bằng pp Newton
    ======================================================
    ---
    Parameters
    ---
        A: ma trận A cần tìm nghịch đảo gần đúng
        X0: Ma trận xuât phát
        eps: sai số
    Returns
    ---
        X: Ma trận nghịch đảo gần đúng của A
    """

    err_hist = []  # List chứa giá trị sai số sau từng vòng lặp
    iter_num = 0  # Biến lưu số lần lặp của thuật toán
    n = A.shape[0]
    X = X0.copy()
    # X0 = X = LA.inv(A)
    E = np.eye(n, n)
    G0 = E - A.dot(X)
    if LA.norm(G0) < 1:
        print("||G0|| = %s" % LA.norm(G0))
        print("Thuật toán có thể hội tụ")
        print("*" * 40)
        error = 1
        k = 1
        q = np.random.uniform(LA.norm(G0))  # Chọn q ngẫu nhiên trong khoảng ||G0|| < q < 1
        print("q = %s" % q)
        print("*" * 40)
        while error >= eps:
            T = 2 * E - A.dot(X)
            X = X.dot(T)
            error = LA.norm(X0) / (1 - q) * q ** (2 ** k)

            print("X_{0} =".format(k), '\n', X)
            print("Error:", error, '\n')

            iter_num += 1
            err_hist.append(error)

            k += 1

        print("*" * 40, '\n')
        print("Kiểm chứng kết quả")
        print("A1 = ", '\n', X, '\n')

        print("*" * 40, '\n')
        print("Kiểm chứng kết quả")
        print("A.A1 = ", '\n', A.dot(X), '\n')
        print("Numpy A1 =", '\n', LA.inv(A))
        Graph(iter_num, err_hist)  # Vẽ đồ thị sai số sau mỗi vòng lặp
        return X
    else:
        print("||G0|| = %s" % LA.norm(G0))
        print("Phương pháp Newton không thể hội tụ do ||G0|| > 1")


# -----------------------------------------------
if __name__ == '__main__':
    # # Đọc ma trận A từ file
    path = "./A.csv"
    A = pd.read_csv(path).values

    # print(LA.inv(A))

    # Đọc ma trận X0 từ file
    path2 = "./X0.csv"
    X0 = pd.read_csv(path2).values

    print("det(A) = ", LA.det(A))  # Tính định thức
    print("*" * 40)

    # Kiểm tra det(A)
    if LA.det(A) != 0:
        # eps = float(input("Nhập vào sai số: "))
        eps = 1e-10
        A1 = Newton(A, X0, eps)
    else:
        print("Không thể tìm ma trận nghịch đảo gần đúng vì det(A) = 0")