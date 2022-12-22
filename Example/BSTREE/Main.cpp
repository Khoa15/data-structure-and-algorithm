#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include "BSTree.h"
using namespace std;

void menu()
{
	cout << "*********************" << endl;
	cout << "Bài tập thực hành buổi 6" << endl;
	cout << "*********************" << endl;
	cout << "0. Thoát" << endl;
	cout << "1. Bài 1\n";
	cout << "2. Bài 2\n";
	cout << "3. Bài 3\n";
	cout << "4. Bài 4\n";
	cout << "5. Bài 5\n";
}
void menuBai1()
{
	cout << "*********************" << endl;
	cout << "Bài tập 1" << endl;
	cout << "*********************" << endl;
	cout << "0. Thoát" << endl;
	cout << "a. Tạo cây NPTK bằng 3 cách" << endl;
	cout << "b. Duyệt cây NPTK bằng 6 cách" << endl;
	cout << "c. Duyệt cây NPTK theo chiều rộng tương ứng với 2 phép duyệt cây NLR, NRL" << endl;
	cout << "d. Duyệt cây NPTK theo chiều sâu tương ứng với 6 phép duyệt cây" << endl;
	cout << "e. Thêm 1 nút có giá trị x vào cây" << endl;
	cout << "f. Tìm kiếm 1 nút có giá trị x có tồn tại trên cây hay không?" << endl;
	cout << "g. Xóa nút có giá trị x trên cây" << endl;
	cout << "h. Xuất các phần tử theo chiều giảm dần" << endl;
	cout << "i. Đếm số giá trị lớn hơn x, nhỏ hơn x, có giá trị trong doạn [x, y]" << endl;
	cout << "j. Tìm nút có giá trị lớn nhất/nhỏ nhất của cây" << endl;
	cout << "k. Xuất ra nội dung các nút ở mức k/nội dung các nút lá ở mức k/nội dung các nút chỉ có 1 con ở mức k" << endl;
	cout << "l. Đếm số nút ở mức k/số nút lá ở mức k/số nút chỉ có 1 con ở mức k" << endl;
	cout << "m. Tính tổng giá trị các nút dương/giá trị các nút âm trên cây" << endl;
	cout << "n. Tìm phần tử có khoảng cách về giá trị gần nhất với phần tử x trong cây (nếu cây rỗng trả về -1)" << endl;
	cout << "o. Tìm phần tử có khoảng cách về giá trị xa nhất với phần tử x trong cây (nếu cây rỗng trả về -1)" << endl;
	cout << "p. Đếm số nút của cây (dùng đệ quy, không dùng đệ quy)" << endl;
	cout << "q. Đếm số nút là số nguyên tố, là số chính phương, là số hoàn thiện, là số thịnh vượng, là số yếu của cây" << endl;
	cout << "r.	Tính tổng giá trị các nút của cây (dùng đệ quy, không dùng đệ quy)" << endl;
	cout << "s.	Tính tổng giá trị các nút là số nguyên tố, là số chính phương, là số hoàn thiện, là số thịnh vượng, là số yếu của cây" << endl;
	cout << "t.	Xóa toàn bộ cây" << endl;
}
void menuBai2()
{
	cout << "*********************" << endl;
	cout << "Bài tập 2" << endl;
	cout << "*********************" << endl;
	cout << "0. Thoát" << endl;
	cout << "a. Tạo cây NPTK bằng 2 cách (nhập liệu từ bàn phím, tạo ngẫu nhiên tự động).\n";
	cout << "b. Duyệt cây NPTK bằng 6 cách: traverseNLR, traverseLNR, traverseLRN, traverseNRL, traverseRNL, traverseRLN\n";
	cout << "c. Thêm 1 nút là phân số p vào cây\n";
	cout << "d. Tìm kiếm 1 phân số x có trên cây hay không?\n";
	cout << "e. Xóa một phân số x trên cây\n";
	cout << "f. Xóa những phân số > 2 (xét theo giá trị)\n";
	cout << "g. Xóa những phân số có mẫu số là số nguyên tố\n";
	cout << "h. Tính tổng các phân số.\n";
	cout << "i. Tìm phân số nhỏ nhất\n";
	cout << "j. Tìm phân số lớn nhất\n";
	cout << "k. Liệt kê các phân số có tử số lớn hơn mẫu số\n";
	cout << "l. Liệt kê các phân số có tử số nhỏ hơn mẫu số.\n";
	cout << "m. Liệt kê các phân số có tử số và mẫu số đồng thời là các số nguyên tố.\n";
	cout << "n. Liệt kê các phân số ở mức k (k được nhập từ bàn phím)\n";
	cout << "o. Đếm số lượng phân số ở mức k (k được nhập từ bàn phím).\n";
	cout << "p. Tính tổng các phân số ở mức k (k được nhập từ bàn phím)\n";
	cout << "q. Đếm có bao nhiêu phân số có cả tử số và mẫu số đều là các số nguyên tố.\n";
	cout << "r. Xóa toàn bộ danh sách.\n";
}
void menuBai3()
{
	cout << "*********************" << endl;
	cout << "Bài tập 3 (tiếp theo bài 1)" << endl;
	cout << "*********************" << endl;
	cout << "0. Thoát" << endl;
	cout << "a. Viết hàm xuất các số hoàn thiện trong cây\n";
	cout << "b. Viết hàm xuất tất cả các nút trên tầng thứ k của cây. (*)\n";
	cout << "c. Viết hàm xuất tất cả các nút trên cây theo thứ tự từ tầng 0 đến tầng h - 1 của cây(với h là chiều cao của cây). (*)\n";
	cout << "d. Đếm số lượng nút lá mà thông tin tại nút đó là giá trị chẵn\n";
	cout << "e. Đếm số lượng nút có đúng 1 con mà thông tin tại nút đó là số nguyên tố\n";
	cout << "f. Đếm số lượng nút có đúng 2 con mà thông tin tại nút đó là số chính phương\n";
	cout << "g. Đếm số lượng nút nằm ở tầng thấp hơn tầng thứ k của cây\n";
	cout << "h. Đếm số lượng nút nằm ở tầng cao hơn tầng thứ k của cây\n";
	cout << "i. Tính tổng các nút lẻ\n";
	cout << "j. Tính tổng các nút lá mà thông tin tại nút đó là giá trị chẵn\n";
	cout << "k. Tính tổng các nút có đúng 1 con mà thông tin tại nút đó là số nguyên tố\n";
	cout << "l. Tính tổng các nút có đúng 2 con mà thông tin tại nút đó là số chính phương\n";
	cout << "m. Kiểm tra cây nhị phân T có phải là cây nhị phân tìm kiếm hay không?\n";
	cout << "n. Kiểm tra cây nhị phân T có phải là cây nhị phân cân bằng hay không?\n";
	cout << "o. Kiểm tra cây nhị phân T có phải là cây nhị phân cân bằng hoàn toàn hay không?\n";
}

void main()
{
	SetConsoleOutputCP(CP_UTF8);
	int chonBai = 0;
	char chonCau = 0;
	do
	{
		system("cls");
		menu();
		cout << "\nChọn bài tập: ";
		cin >> chonBai;

		switch (chonBai)
		{
		case 0:
		{
			cout << "Thoát" << endl;
			break;
		}
		case 1:
		{
			do
			{
				system("cls");
				menuBai1();

				cout << "\nChọn câu: ";
				cin >> chonCau;

				switch (chonCau)
				{
				case 48:
				{
					cout << "Thoát" << endl;
					break;
				}
				case 'a'://Tạo cây NPTK bằng 3 cách
				{
					BSTree bt;
					initBSTree(bt);
					////Cách 1: Tạo cây NP từ mảng các phần tử cho trước
					/*int a[] = { 10, 5, 30, 2, 8, 25, 45, 3, 6, 9, 14, 33, 66 };
					int n = 13;
					createBSTree_FromArray(bt, a, n);
					traverseLNR(bt.Root);
					cout << endl;*/

					////Cách 2: Tạo cây NPTK từ mảng được nhập từ bàn phím
					/*int* a, n;
					cout << "Nhập số phần tử của mảng: ";
					cin >> n;
					a = new int[n];
					for (int i = 0; i < n; i++)
					{
						cout << "Nhập phần tử thứ " << i << ": ";
						cin >> a[i];
					}

					for (int i = 0; i < n; i++)
						cout << a[i] << '\t';
					cout << endl;
					createBSTree_FromArray(bt, a, n);
					traverseLNR(bt.Root);
					cout << endl;*/

					///Cách 3: Tạo cây NPTK ngẫu nhiên
					/*int n = 0;
					cout << "Nhập số phần tử của mảng: ";
					cin >> n;
					srand(time(NULL));
					for (int i = 0; i < n; i++)
					{
						int x = (rand() % 199) - 99;
						insertTNode(bt.Root, createTNode(x));
					}
					traverseLNR(bt.Root);
					cout << endl;*/

					///Cách 4: Tạo cây NPTK từ file
					createBSTree_FromFile(bt, ".\\data\\BSTree.txt");
					traverseLNR(bt.Root);
					cout << endl;
					break;
				}
				case 'b'://Duyệt cây NLR, LNR, LRN
				{
					BSTree bt;
					initBSTree(bt);
					createBSTree_FromFile(bt, ".\\data\\BSTree.txt");

					cout << "Duyệt cây theo LNR:\n";
					traverseLNR(bt.Root);
					cout << endl;

					cout << "Duyệt cây theo NLR:\n";
					traverseNLR(bt.Root);
					cout << endl;

					cout << "Duyệt cây theo LRN:\n";
					traverseLRN(bt.Root);
					cout << endl;
					break;
				}
				case 'c'://Duyệt cây NPTK theo chiều rộng tương ứng với 2 phép duyệt cây NLR, NRL
				{
					BSTree bt;
					initBSTree(bt);
					createBSTree_FromFile(bt, ".\\data\\BSTree.txt");
					
					cout << "Duyệt cây NPTK theo chiều rộng tương ứng NLR:\n";
					traverseBreadthNLR(bt.Root);
					cout << endl;
					break;
				}
				case 'd'://Duyệt cây NPTK theo chiều sâu tương ứng với 6 phép duyệt cây NLR, LNR, LRN, NRL, RNL, RLN
				{
					BSTree bt;
					initBSTree(bt);
					createBSTree_FromFile(bt, ".\\data\\BSTree.txt");
					
					cout << "Duyệt cây NPTK theo chiều sâu tương ứng NLR:\n";
					traverseDepthNLR(bt.Root);
					cout << endl;
					break;
				}
				case 'e'://Thêm 1 nút có giá trị x vào cây
				{
					BSTree bt;
					initBSTree(bt);
					createBSTree_FromFile(bt, ".\\data\\BSTree.txt");
					
					int x;
					cout << "Nhập giá trị của nút cần thêm vào cây: ";
					cin >> x;
					insertTNode(bt.Root, createTNode(x));
					cout << "Cây sau khi thêm nút x:\n";
					traverseLNR(bt.Root);
					cout << endl;
					break;
				}
				case 'f'://Tìm kiếm một nút có giá trị x trên cây hay không?
				{
					BSTree bt;
					initBSTree(bt);
					createBSTree_FromFile(bt, ".\\data\\BSTree.txt");
					traverseLNR(bt.Root);
					cout << endl;

					int x;
					cout << "Nhập giá trị của nút cần tìm: ";
					cin >> x;
					if (findTNode(bt.Root, x) != NULL)
						cout << "Tìm thấy nút x trên cây";
					else
						cout << "Không tìm thấy nút x trên cây";
					cout << endl;
					break;
				}
				case 'g'://Xóa nút có giá trị x trên cây
				{
					BSTree bt;
					initBSTree(bt);
					createBSTree_FromFile(bt, ".\\data\\BSTree.txt");
					traverseLNR(bt.Root);
					cout << endl;

					int x;
					cout << "Nhập giá trị của nút cần xóa: ";
					cin >> x;
					deleteTNodeX(bt.Root, x);
					cout << "Cây sau khi xóa nút x:\n";
					traverseLNR(bt.Root);
					cout << endl;
					break;
				}
				case 'h'://Xuất các phần tử theo chiều giảm dần
				{
					BSTree bt;
					initBSTree(bt);
					createBSTree_FromFile(bt, ".\\data\\BSTree.txt");

					traverseRNL(bt.Root);
					cout << endl;
					break;
				}
				case 'i'://Đếm số giá trị lớn hơn x, nhỏ hơn x, có giá trị trong đoạn [x, y].
				{
					BSTree bt;
					initBSTree(bt);
					createBSTree_FromFile(bt, ".\\data\\BSTree.txt");
					traverseLNR(bt.Root);
					cout << endl;
					
					int x, y;
					cout << "Nhập giá trị x: ";
					cin >> x;
					cout << endl;
					cout << "Nhập giá trị y: ";
					cin >> y;
					cout << endl;

					cout << "Số nút có giá trị lớn hơn x: " << countTNodeGreaterthanX(bt.Root, x) << endl;
					cout << "Số nút có giá trị nhỏ hơn x: " << countTNodeLessthanX(bt.Root, x) << endl;
					cout << "Số nút có giá trị trong đoạn [x, y]: " << countTNodeInSegment(bt.Root, x, y) << endl;

					break;
				}
				case 'j'://Tìm nút có giá trị lớn nhất, nhỏ nhất của cây.
				{
					BSTree bt;
					initBSTree(bt);
					createBSTree_FromFile(bt, ".\\data\\BSTree.txt");
					traverseLNR(bt.Root);
					cout << endl;

					TNode* p = findMaxTNode(bt.Root);
					cout << "Nút có giá trị lớn nhất trong cây: " << p->Info << endl;
					p = findMinTNode(bt.Root);
					cout << "Nút có giá trị nhỏ nhất trong cây: " << p->Info << endl;
					break;
				}
				case 'k'://Xuất ra nội dung các nút ở mức k/nội dung các nút lá ở mức k/ nội dung các nút chỉ có 1 con ở mức k / .....
				{
					BSTree bt;
					initBSTree(bt);
					createBSTree_FromFile(bt, ".\\data\\BSTree.txt");
					
					int k = 0;
					cout << "Nhập mức k: ";
					cin >> k;
					cout << "Các nút ở mức k: ";
					showTNodeOfLevelK(bt.Root, k);
					cout << endl;
					cout << "Các nút lá ở mức k: ";
					showTNodeIsLeafOfLevelK(bt.Root, k);
					cout << endl;
					cout << "Các nút chỉ có 1 con: ";
					showTNodeHasOneChild(bt.Root);
					cout << endl;
					break;
				}
				case 'l'://Đếm số nút ở mức k/số nút lá ở mức k/ số nút chỉ có 1 con ở mức k / .....
				{
					BSTree bt;
					initBSTree(bt);
					createBSTree_FromFile(bt, ".\\data\\BSTree.txt");

					int k = 0;
					cout << "Nhập mức k: ";
					cin >> k;
					cout << "Số nút ở mức k: " << countTNodeOfLevelK(bt.Root, k) << endl;
					cout << "Số nút lá ở mức k: " << countTNodeIsLeafOfLevelK(bt.Root, k) << endl;
					cout << "Số nút chỉ có 1 con ở mức k: " << countTNodeHasOneChildOfLevelK(bt.Root, k) << endl;
					break;
				}
				case 'm'://Tính tổng giá trị các nút dương/ giá trị các nút âm trên cây
				{
					BSTree bt;
					initBSTree(bt);
					createBSTree_FromFile(bt, ".\\data\\BSTree.txt");
					traverseLNR(bt.Root);
					cout << endl;

					cout << "Tổng giá trị các nút dương: " << sumTNodePositive(bt.Root) << endl;
					break;
				}
				case 'n'://Tìm phần tử có khoảng cách về giá trị gần nhất với phần tử x	trong cây(nếu cây rỗng trả về - 1).
				{
					BSTree bt;
					initBSTree(bt);
					createBSTree_FromFile(bt, ".\\data\\BSTree.txt");
					traverseLNR(bt.Root);
					cout << endl;

					int x;
					cout << "Nhập phần tử x cần tìm: ";
					cin >> x;
					cout << "Khoảng cách về giá trị gần nhất với phần tử x: " << minDistance(bt.Root, x) << endl;

					break;
				}
				case 'o'://Tìm phần tử có khoảng cách về giá trị xa nhất với phần tử x trong cây(nếu cây rỗng trả về - 1).
				{
					BSTree bt;
					initBSTree(bt);
					createBSTree_FromFile(bt, ".\\data\\BSTree.txt");
					traverseLNR(bt.Root);
					cout << endl;

					int x;
					cout << "Nhập phần tử x cần tìm: ";
					cin >> x;
					cout << "Khoảng cách về giá trị xa nhất với phần tử x: " << maxDistance(bt.Root, x) << endl;

					break;
				}
				case 'p'://Đếm số nút của cây (dùng đệ quy / không dùng đệ quy)
				{
					BSTree bt;
					initBSTree(bt);
					createBSTree_FromFile(bt, ".\\data\\BSTree.txt");
					traverseLNR(bt.Root);
					cout << endl;

					cout << "Số nút của cây dùng đệ quy: " << countTNode(bt.Root) << endl;
					cout << "Số nút của cây không dùng đệ quy: " << countTNodeNoRecursive(bt.Root) << endl;
					break;
				}
				case 'q'://Đếm số nút là số nguyên tố, là số chính phương, là số hoàn thiện, là số thịnh vượng, là số yếu của cây.
				{
					BSTree bt;
					initBSTree(bt);
					createBSTree_FromFile(bt, ".\\data\\BSTree.txt");
					traverseLNR(bt.Root);
					cout << endl;

					cout << "Số các nút là số nguyên tố: " << countTNodeNguyenTo(bt.Root) << endl;
					cout << "Số các nút là số chính phương: " << countTNodeChinhPhuong(bt.Root) << endl;
					cout << "Số các nút là số hoàn hảo: " << countTNodeHoanHao(bt.Root) << endl;
					cout << "Số các nút là số thịnh vượng: " << countTNodeThinhVuong(bt.Root) << endl;
					break;
				}
				case 'r'://Tính tổng giá trị các nút của cây (dùng đệ quy / không dùng đệ quy).
				{
					BSTree bt;
					initBSTree(bt);
					createBSTree_FromFile(bt, ".\\data\\BSTree.txt");
					traverseLNR(bt.Root);
					cout << endl;

					cout << "Tổng các nút trong cây dùng đệ quy: " << sumTNode(bt.Root) << endl;
					cout << "Tổng các nút trong cây không dùng đệ quy: " << sumTNodeNoRecursive(bt.Root) << endl;
					break;
				}
				case 's'://Tính tổng giá trị các nút là số nguyên tố, là số chính phương, là số hoàn thiện, là số thịnh vượng, là số yếu của cây
				{
					BSTree bt;
					initBSTree(bt);
					createBSTree_FromFile(bt, ".\\data\\BSTree.txt");
					traverseLNR(bt.Root);
					cout << endl;

					cout << "Tổng giá trị các nút là số nguyên tố: " << sumTNodeNguyenTo(bt.Root) << endl;
					cout << "Tổng giá trị các nút là số chính phương: " << sumTNodeChinhPhuong(bt.Root) << endl;
					cout << "Tổng giá trị các nút là số hoàn hảo: " << sumTNodeHoanHao(bt.Root) << endl;
					cout << "Tổng giá trị các nút là số thịnh vượng: " << sumTNodeThinhVuong(bt.Root) << endl;
					break;
				}
				case 't'://Xóa toàn bộ cây.
				{
					BSTree bt;
					initBSTree(bt);
					createBSTree_FromFile(bt, ".\\data\\BSTree.txt");
					traverseLNR(bt.Root);
					cout << endl;

					deleteTree(bt.Root);
					traverseLNR(bt.Root);
					cout << endl;
					break;
				}
				default:
					break;
				}
				if (chonCau != 48)
					system("pause");
			} while (chonCau != 48);
			break;
		}
		case 2:
		{
			do
			{
				system("cls");
				menuBai2();
				cout << "\nChọn câu: ";
				cin >> chonCau;

				switch (chonCau)
				{
				case 48:
				{
					cout << "Thoát" << endl;
					break;
				}
				case 'a'://Tạo cây nhị phân bằng 3 cách (từ một mảng, nhập liệu từ bàn phím, tạo ngẫu nhiên tự động)
				{
					
					break;
				}
				case 'b'://Duyệt cây NP bằng 6 cách: NLR, LNR, LRN, NRL, RNL, RLN
				{
					
					break;
				}
				case 'c'://Thêm 1 nút là phân số p làm con trái/phải của nút T
				{
					break;
				}
				case 'd'://Đếm số lượng những phân số lớn hơn 1
				{
					
					break;
				}
				case 'e'://Tối giản tất cả các nút (phân số) của cây
				{
					
					break;
				}
				case 'f'://Tìm kiếm trên cây có nút nào có giá trị bằng với phân số x hay không?
				{
					
					break;
				}
				default:
					break;
				}
				if (chonCau != 48)
					system("pause");
			} while (chonCau != 48);
			break;
		}
		case 3:
		{
			do
			{
				system("cls");
				menuBai3();
				cout << "\nChọn câu: ";
				cin >> chonCau;

				switch (chonCau)
				{
				case 48:
				{
					cout << "Thoát" << endl;
					break;
				}
				case 'a'://Tính tổng các phân số
				{
					
					break;
				}
				case 'b'://Tìm phân số nhỏ nhất / lớn nhất
				{
					

					break;
				}
				case 'c'://Liệt kê các phân số có tử số lớn hơn mẫu số / nhỏ hơn mẫu số
				{
					

					break;
				}
				case 'd'://Liệt kê các phân số có tử số và mẫu số đồng thời là số nguyên tố
				{
					
					break;
				}
				case 'e'://Liệt kê các phân số ở mức k (k được nhập từ bàn phím)
				{
					

					break;
				}
				case 'f'://Đếm số lượng phân số mức k (k được nhập từ bàn phím)
				{
					
					break;
				}
				case 'g'://Tính tổng các phân số ở mức k (k được nhập từ bàn phím)
				{
					
					break;
				}
				default:
					break;
				}
				if (chonCau != 48)
					system("pause");
			} while (chonCau != 48);
			break;
		}
		default:
			break;
		}
		system("pause");
	} while (chonBai != 0);
}