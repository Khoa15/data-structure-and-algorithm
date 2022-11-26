#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include "Buoi02_DSLK_BaiHat.h"
#include "Buoi02_DSLK_Int.h"
#include "Buoi02_DSLK_QuanLyDiemSV.h"
#include "Buoi02_DSLK_DaThuc.h"
using namespace std;

void menu()
{
	cout << "*********************" << endl;
	cout << "Bài tập thực hành buổi 2" << endl;
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
	cout << "a. Nhập danh sách liên kết đơn từ file text chứa các số nguyên, các số cách nhau bằng một khoảng trắng (không cho biết số lượng phần tử). VD: 2 3 4 5 12 13\n";
	cout << "b. Xóa phần tử đầu\n";
	cout << "c. Xóa phần tử sau một phần tử đã cho\n";
	cout << "d. Xóa các phần tử có giá trị bằng x\n";
	cout << "e. Xóa toàn bộ danh sách\n";
	cout << "f. Xóa các phần tử chẵn trong danh sách liên kết\n";
}
void menuBai2()
{
	cout << "*********************" << endl;
	cout << "Bài tập 2" << endl;
	cout << "*********************" << endl;
	cout << "0. Thoát" << endl;
	cout << "a. Đọc danh sách list nhạc từ file định dạng txt\n";
	cout << "b. In danh sách bài hát ra màn hình\n";
	cout << "c. Để nghe hết tất cả bài hát trong danh sách cần bao nhiêu thời gian\n";
	cout << "d. Thêm một bài nhạc mới vào đầu playlist/cuối playlist\n";
	cout << "e. Xóa một bài nhạc khỏi danh sách\n";
	cout << "f. Kiểm tra xem bài hát có tên X có trong playlist không?\n";
	cout << "g. Sắp xếp các bài hát trong playlist theo thứ tự từ điển của tên bài hát\n";
	cout << "h. Sắp xếp các bài hát theo thứ tự giảm dần của tên ca sĩ\n";
	cout << "i. Đưa một bài hát trong playlist lên đầu\n";
}
void menuBai3()
{
	cout << "*********************" << endl;
	cout << "Bài tập 3" << endl;
	cout << "*********************" << endl;
	cout << "0. Thoát" << endl;
	cout << "x. Tạo và xuất danh sách sinh viên\n";
	cout << "a. Cho biết họ tên và điểm kết quả học tập của sinh viên có mã số là x\n";
	cout << "b. Cho biết các thông tin về sinh viên có tên là x\n";
	cout << "c. Sắp xếp DSSV theo chiều tăng dần theo MaSV\n";
	cout << "d. Sắp xếp DSSV theo chiều tăng dần của tên sinh viên\n";
	cout << "e. Thêm một sinh viên sao cho vẫn giữ nguyên thứ tự tăng dần của mã số sinh viên (có kiểm tra trùng khóa)\n";
	cout << "f. Xóa sinh viên có MaSV = x\n";
	cout << "g. Xóa tất cả các sinh viên có tên là x\n";
	cout << "h. Tạo danh sách mới từ danh sách đã cho sao cho danh sách mới giảm dần theo điểm kết quả học tập\n";
	cout << "i. In danh sách các sinh viên được xếp loại khá (sinh viên xếp loại khá nếu thỏa điều kiện: 7.0 <= điểm kết quả học tập >= 8.5)\n";
	cout << "j. Cho biết sinh viên có điểm kết quả học tập cao nhất\n";
	cout << "k. Cho biết sinh viên có điểm kết quả học tập thấp nhất\n";
	cout << "l. Cho biết sinh viên có điểm kết quả học tập thấp nhất trong số các sinh viên xếp loại giỏi\n";
	cout << "m. Cho biết sinh viên có điểm kết quả học tập gần x nhất (x là số thực)\n";
}
void menuBai4()
{
	cout << "*********************" << endl;
	cout << "Bài tập 4" << endl;
	cout << "*********************" << endl;
	cout << "0. Thoát" << endl;
	cout << "a. Sắp xếp đa thức theo chiều giảm dần của bậc (số mũ)\n";
	cout << "b. Rút gọn đa thức (sau khi đã thực hiện câu a)\n";
	cout << "c. Thêm một đơn thức mới vào sao cho vẫn giữ nguyên tính thứ tự của bậc\n";
	cout << "d. Xóa một đơn thức khi biết bậc\n";
	cout << "e. Tính giá trị của đa thức khi biết giá trị của x\n";
	cout << "f. Thực hiện việc cộng/trừ/nhận 2 đa thức P và Q để tạo ra một đa thức mới\n";
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
				case 'a'://Nhập danh sách liên kết đơn từ file text chứa các số nguyên
				{
					SList sl;
					init(sl);
					inputSList(sl, ".\\input\\SoNguyen.txt");
					traverse(sl);
					cout << endl;
					break;
				}
				case 'b'://Xóa phần tử đầu
				{
					SList sl;
					init(sl);
					inputSList(sl, ".\\input\\SoNguyen.txt");
					traverse(sl);
					cout << endl;
					deleteHeadSList(sl);
					traverse(sl);
					cout << endl;
					break;
				}
				case 'c'://Xóa phần tử sau một phần tử đã cho
				{
					SList sl;
					init(sl);
					inputSList(sl, ".\\input\\SoNguyen.txt");
					traverse(sl);
					cout << endl;
					int x;
					cout << "Nhập phần tử cần tìm: ";
					cin >> x;
					Node* q = searchSList(sl, x);
					deleteMidSList(sl, q);
					traverse(sl);
					cout << endl;

					break;
				}
				case 'd'://Xóa các phần tử có giá trị bằng x
				{
					SList sl;
					init(sl);
					inputSList(sl, ".\\input\\SoNguyen.txt");
					traverse(sl);
					cout << endl;
					int x;
					cout << "Nhập phần tử cần tìm: ";
					cin >> x;
					Node* q = searchSList(sl, x);
					deleteAllXSlist(sl, x);
					traverse(sl);
					cout << endl;
					break;
				}
				case 'e'://Xóa toàn bộ danh sách
				{
					SList sl;
					init(sl);
					inputSList(sl, ".\\input\\SoNguyen.txt");
					traverse(sl);
					cout << endl;
					Node* p;
					while (p = sl.head)
						deleteHeadSList(sl);
					traverse(sl);
					cout << endl;
					break;
				}
				case 'f'://Xóa các phần tử chẵn trong danh sách liên kết
				{
					SList sl;
					init(sl);
					inputSList(sl, ".\\input\\SoNguyen.txt");
					traverse(sl);
					cout << endl;
					deleteEvenSList(sl);
					traverse(sl);
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
			SListBH playlist;
			initBH(playlist);
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
				case 'a'://Đọc danh sách list nhạc từ file định dạng txt
				{
					docListBH(playlist, "D:\\Bai Giang Chau\\CTDL-GT\\HUFI\\Chau\\Thuc Hanh\\CTDL\\input\\input.txt");
					break;
				}
				case 'b'://In danh sách bài hát ra màn hình
				{
					traverse(playlist);
					cout << endl;
					break;
				}
				case 'c'://Để nghe hết tất cả bài hát trong danh sách cần bao nhiêu thời gian
				{
					int thoigian = 0;
					for (NodeBH* p = playlist.head; p != NULL; p = p->next)
						thoigian += p->info.thoiLuong;
					cout << "Để nghe hết tất cả bài hát trong danh sách cần " << (thoigian/60) << " phút\n";
					break;
				}
				case 'd'://Thêm một bài nhạc mới vào đầu playlist/cuối playlist
				{
					NodeBH* bh = new NodeBH;
					strcpy(bh->info.tenBH, "Roi toi luon");
					strcpy(bh->info.tenCS, "Ho Phi Nal");
					strcpy(bh->info.tenTG, "Ho Phi Nal");
					bh->info.thoiLuong = 500;

					if (searchSList(playlist, bh->info) == NULL)
						addHeadSListBH(playlist, bh);
					else
						cout << "Bài hát đã có trong danh sách\n";
					traverse(playlist);
					cout << endl;
					
					break;
				}
				case 'e'://Xóa một bài nhạc khỏi danh sách
				{
					BaiHat bh;
					/*strcpy(bh.tenBH, "Rồi tới luôn");
					strcpy(bh.tenCS, "Hồ Phi Nal");
					strcpy(bh.tenTG, "Hồ Phi Nal");
					bh.thoiLuong = 500;*/
					strcpy(bh.tenBH, "TronTim");
					strcpy(bh.tenCS, "DenVauMTV");
					strcpy(bh.tenTG, "DenVau");
					bh.thoiLuong = 310;

					if (searchSList(playlist, bh))
						deleteSList(playlist, bh);
					else
						cout << "Không tìm thấy bài hát cần xóa\n";
					traverse(playlist);
					cout << endl;

					break;
				}
				case 'f'://Kiểm tra bài hát có tên X có trong danh sách hay không?
				{
					char tenBH[51];
					cout << "Nhập tên bài hát cần tìm: ";
					cin.ignore();
					cin.getline(tenBH, sizeof(tenBH));
					BaiHat bh;
					strcpy(bh.tenBH, tenBH);
					NodeBH* p;
					for (p = playlist.head; p != NULL; p = p->next)
						if (strcmp(p->info.tenBH, bh.tenBH) == 0)
						{
							cout << "Danh sách có bài hát '" << tenBH << "'\n";
							break;
						}
					if(p == NULL)
							cout << "Danh sách không có bài hát '" << tenBH << "'\n";
					break;
				}
				case 'g'://Sắp xếp các bài hát trong playlist theo thứ tự từ điển của tên bài hát
				{
					interchangeAlphabeTenBHSList(playlist);
					traverse(playlist);
					cout << endl;
					break;
				}
				case 'h'://Sắp xếp các bài hát thứ tự giảm dần của tên ca sĩ
				{
					interchangeAlphabeTenCSSList(playlist);
					traverse(playlist);
					cout << endl;
					break;
				}
				case 'i'://Đưa một bài hát trong playlist lên đầu
				{
					char tenBH[51];
					cout << "Nhập tên bài hát cần tìm: ";
					cin.ignore();
					cin.getline(tenBH, sizeof(tenBH));
					BaiHat bh;
					strcpy(bh.tenBH, tenBH);
					NodeBH* p = new NodeBH;
					for (p = playlist.head->next; p != NULL; p = p->next)
						if (strcmp(p->info.tenBH, bh.tenBH) == 0)
						{
							char tmp[51];
							strcpy(tmp, playlist.head->info.tenBH);
							strcpy(playlist.head->info.tenBH, p->info.tenBH);
							strcpy(p->info.tenBH, tmp);

							strcpy(tmp, playlist.head->info.tenCS);
							strcpy(playlist.head->info.tenCS, p->info.tenCS);
							strcpy(p->info.tenCS, tmp);

							strcpy(tmp, playlist.head->info.tenTG);
							strcpy(playlist.head->info.tenTG, p->info.tenTG);
							strcpy(p->info.tenTG, tmp);

							int n = playlist.head->info.thoiLuong;
							playlist.head->info.thoiLuong = p->info.thoiLuong;
							p->info.thoiLuong = n;
							break;
						}
					if (p == NULL)
						cout << "Danh sách không có bài hát '" << tenBH << "'\n";

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
			SListSV dssv;
			
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
				case 'x'://Tạo và xuất danh sách sinh viên
				{
					double tongDiem, soMon;

					////Sinh viên 1
					NodeSV* sv1 = new NodeSV;
					strcpy(sv1->info.maSV, "333");
					strcpy(sv1->info.hoDem, "Tran Thi");
					strcpy(sv1->info.tenSV, "Binh");
					sv1->info.namSinh = 2000;

					//Tạo danh sách các môn học cho sinh viên 1
					NodeMH* mh1 = new NodeMH;
					strcpy(mh1->info.maMH, "CSDL");
					strcpy(mh1->info.tenMH, "Cơ Sở Dữ Liệu");
					mh1->info.soTC = 3;
					mh1->info.DTL = 8;
					mh1->info.DCK = 9;
					mh1->info.diemMH = 0.3 * (mh1->info.DTL) + 0.7 * (mh1->info.DCK);
					addTailSList(sv1->info.dsmh, mh1);

					NodeMH* mh2 = new NodeMH;
					strcpy(mh2->info.maMH, "CTDL");
					strcpy(mh2->info.tenMH, "Cấu Trúc Dữ Liệu");
					mh2->info.soTC = 3;
					mh2->info.DTL = 10;
					mh2->info.DCK = 9;
					mh2->info.diemMH = 0.3 * (mh2->info.DTL) + 0.7 * (mh2->info.DCK);
					addTailSList(sv1->info.dsmh, mh2);

					//Tính điểm kết quả học tập
					tongDiem = 0, soMon = 0;
					for (NodeMH* p = sv1->info.dsmh.head; p != NULL; p = p->next)
						if (p != NULL)
						{
							tongDiem += p->info.diemMH;
							soMon = soMon + 1;
						}
					sv1->info.diemKQ = tongDiem / soMon;
					//Thêm NodeSV vào danh sách
					addTailSList(dssv, sv1);
					
					//////Sinh viên 2
					NodeSV* sv2 = new NodeSV;
					strcpy(sv2->info.maSV, "555");
					strcpy(sv2->info.hoDem, "Nguyen Van");
					strcpy(sv2->info.tenSV, "An");
					sv2->info.namSinh = 2002;

					//Tạo danh sách các môn học cho sinh viên
					NodeMH* mh3 = new NodeMH;
					strcpy(mh3->info.maMH, "CSDL");
					strcpy(mh3->info.tenMH, "Cơ Sở Dữ Liệu");
					mh3->info.soTC = 3;
					mh3->info.DTL = 5;
					mh3->info.DCK = 7;
					mh3->info.diemMH = 0.3 * (mh3->info.DTL) + 0.7 * (mh3->info.DCK);
					addTailSList(sv2->info.dsmh, mh3);


					//Tính điểm kết quả học tập
					tongDiem = 0, soMon = 0;
					for (NodeMH* p = sv2->info.dsmh.head; p != NULL; p = p->next)
						if (p != NULL)
						{
							tongDiem += p->info.diemMH;
							soMon = soMon + 1;
						}
					sv2->info.diemKQ = tongDiem / soMon;
					//Thêm NodeSV vào danh sách
					addTailSList(dssv, sv2);

					///////Sinh viên 3
					NodeSV* sv3 = new NodeSV;
					strcpy(sv3->info.maSV, "111");
					strcpy(sv3->info.hoDem, "Tran Dang");
					strcpy(sv3->info.tenSV, "Khoa");
					sv3->info.namSinh = 2004;

					//Tạo danh sách các môn học cho sinh viên
					NodeMH* mh4 = new NodeMH;
					strcpy(mh4->info.maMH, "CSDL");
					strcpy(mh4->info.tenMH, "Cơ Sở Dữ Liệu");
					mh4->info.soTC = 3;
					mh4->info.DTL = 10;
					mh4->info.DCK = 9;
					mh4->info.diemMH = 0.3 * (mh4->info.DTL) + 0.7 * (mh4->info.DCK);
					addTailSList(sv3->info.dsmh, mh4);

					NodeMH* mh5 = new NodeMH;
					strcpy(mh5->info.maMH, "CTDL");
					strcpy(mh5->info.tenMH, "Cấu Trúc Dữ Liệu");
					mh5->info.soTC = 3;
					mh5->info.DTL = 10;
					mh5->info.DCK = 9;
					mh5->info.diemMH = 0.3 * (mh5->info.DTL) + 0.7 * (mh5->info.DCK);
					addTailSList(sv3->info.dsmh, mh5);

					NodeMH* mh6 = new NodeMH;
					strcpy(mh6->info.maMH, "TRR");
					strcpy(mh6->info.tenMH, "Toán Rời Rạc");
					mh6->info.soTC = 3;
					mh6->info.DTL = 10;
					mh6->info.DCK = 10;
					mh6->info.diemMH = 0.3 * (mh6->info.DTL) + 0.7 * (mh6->info.DCK);
					addTailSList(sv3->info.dsmh, mh6);

					//Tính điểm kết quả học tập
					tongDiem = 0, soMon = 0;
					for (NodeMH* p = sv3->info.dsmh.head; p != NULL; p = p->next)
						if (p != NULL)
						{
							tongDiem += p->info.diemMH;
							soMon = soMon + 1;
						}
					sv3->info.diemKQ = tongDiem / soMon;
					//Thêm NodeSV vào danh sách
					addTailSList(dssv, sv3);

					traverse(dssv);
					cout << endl;

					break;
				}
				case 'a'://Cho biết họ tên và điểm kết quả học tập của sinh viên có mã số là x
				{	
					char maSV[11];
					cout << "Nhập mã sinh viên cần tìm: ";
					cin.ignore();//
					cin.getline(maSV, sizeof(maSV));
					for (NodeSV* p = dssv.head; p != NULL; p = p->next)
						if (strcmp(p->info.maSV, maSV) == 0)
						{
							showNodeSV(p);
							break;
						}
					break;
				}
				case 'b'://Cho biết các thông tin về sinh viên có tên là x
				{
					char hoDem [26];
					char tenSV [8];
					
					cin.ignore();
					cout << "Nhập họ đệm sinh viên cần tìm: ";
					cin.getline(hoDem, sizeof(hoDem));
					cout << "Nhập tên sinh viên cần tìm: ";
					cin.getline(tenSV, sizeof(tenSV));
					for (NodeSV* p = dssv.head; p != NULL; p = p->next)
						if ((strcmp(p->info.hoDem, hoDem) == 0) && (strcmp(p->info.tenSV, tenSV) == 0))
						{
							showNodeSV(p);
							break;
						}
					break;
					
				}
				case 'c'://Sắp xếp DSSV theo chiều tăng dần theo MaSV
				{
					interchangeAlphabeMaSVSList(dssv);
					traverse(dssv);
					cout << endl;
					break;
				}
				case 'd'://Sắp xếp DSSV theo chiều tăng dần của tên sinh viên
				{
					interchangeAlphabeTenSVSList(dssv);
					traverse(dssv);
					cout << endl;
					break;
				}
				case 'e'://Thêm một sinh viên sao cho vẫn giữ nguyên thứ tự tăng dần của mã số sinh viên (có kiểm tra trùng khóa)
				{
					NodeSV* sv4 = new NodeSV;
					strcpy(sv4->info.maSV, "444");
					strcpy(sv4->info.hoDem, "Tran Cam");
					strcpy(sv4->info.tenSV, "Hong");
					sv4->info.namSinh = 2002;

					//Tạo danh sách các môn học cho sinh viên 1
					NodeMH* mh1 = new NodeMH;
					strcpy(mh1->info.maMH, "CSDL");
					strcpy(mh1->info.tenMH, "Cơ Sở Dữ Liệu");
					mh1->info.soTC = 3;
					mh1->info.DTL = 4;
					mh1->info.DCK = 5;
					mh1->info.diemMH = 0.3 * (mh1->info.DTL) + 0.7 * (mh1->info.DCK);
					addTailSList(sv4->info.dsmh, mh1);
					//Tính điểm kết quả học tập
					int tongDiem = 0, soMon = 0;
					for (NodeMH* p = sv4->info.dsmh.head; p != NULL; p = p->next)
						if (p != NULL)
						{
							tongDiem += p->info.diemMH;
							soMon = soMon + 1;
						}
					sv4->info.diemKQ = tongDiem / soMon;
					//Thêm NodeSV vào danh sách, phải đảm bảo dssv đã tăng theo maSV, nếu chưa thì chạy câu c trước
					if (isEmpty(dssv))
						addTailSList(dssv, sv4);
					else if (dssv.head == dssv.tail)//dssv có 1 node
					{
						if (strcmp(dssv.head->info.maSV, sv4->info.maSV) < 0)
							addTailSList(dssv, sv4);
						else if (strcmp(dssv.head->info.maSV, sv4->info.maSV) > 0)
							addHeadSListSV(dssv, sv4);
						else
						{
							cout << "Đã có sinh viên trong danh sách\n";
						}
					}
					else
					{
						for (NodeSV* p = dssv.head; p->next != NULL; p = p->next)
							if (strcmp(p->info.maSV, sv4->info.maSV) == 0)
							{
								cout << "Đã có sinh viên trong danh sách\n";
								break;
							}
							else if ((strcmp(p->info.maSV, sv4->info.maSV) < 0) && (strcmp(p->next->info.maSV, sv4->info.maSV) > 0))
							{
								addAfterNodeSVSList(dssv, p, sv4);
								break;
							}
							else if (p->next == dssv.tail)//VD: dssv gồm 111 333 555, thêm sv 666 thì sẽ thêm cuối dssv
							{
								addTailSList(dssv, sv4);
								break;
							}
					}
					traverse(dssv);
					cout << endl;

					break;
				}
				case 'f'://Xóa sinh viên có MaSV = x
				{
					char maSV[11];
					cout << "Nhập mã SV cần xóa: ";
					cin.ignore();
					cin.getline(maSV, sizeof(maSV));

					deleteSList(dssv, maSV);

					traverse(dssv);
					cout << endl;

					break;
				}
				case 'g'://Xóa tất cả các sinh viên có tên là x
				{

					break;
				}
				case 'h'://Tạo danh sách mới từ danh sách đã cho sao cho danh sách mới giảm dần theo điểm kết quả học tập
				{

					break;
				}
				case 'i'://In danh sách các sinh viên được xếp loại khá (sinh viên xếp loại khá nếu thỏa điều kiện: 7.0 <= điểm kết quả học tập >= 8.5)
				{

					break;
				}
				case 'j'://Cho biết sinh viên có điểm kết quả học tập cao nhất
				{

					break;
				}
				case 'k'://Cho biết sinh viên có điểm kết quả học tập thấp nhất
				{

					break;
				}
				case 'l'://Cho biết sinh viên có điểm kết quả học tập thấp nhất trong số các sinh viên xếp loại giỏi
				{

					break;
				}
				case 'm'://Cho biết sinh viên có điểm kết quả học tập gần x nhất (x là số thực)
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
		case 4:
		{
			Polynomial poly;
			init(poly);
			//-10 -2x^2 + 3x^3 + x + 5x^2
			PNode* p1 = createPNode(-10, 0);
			PNode* p2 = createPNode(-2, 2);
			PNode* p3 = createPNode(3, 3);
			PNode* p4 = createPNode(1, 1);
			PNode* p5 = createPNode(5, 2);

			addTailPolynomial(poly, p1);
			addTailPolynomial(poly, p2);
			addTailPolynomial(poly, p3);
			addTailPolynomial(poly, p4);
			addTailPolynomial(poly, p5);
			do
			{
				system("cls");
				menuBai4();

				cout << "\nChọn câu: ";
				cin >> chonCau;

				switch (chonCau)
				{
				case 48:
				{
					cout << "Thoát" << endl;
					break;
				}
				case 'a'://Sắp xếp đa thức theo chiều giảm dần của bậc (số mũ)
				{
					traverse(poly);
					cout << endl;

					SapXepTheoBacGiamDan(poly);
					traverse(poly);
					cout << endl;

					break;
				}
				case 'b'://Rút gọn đa thức (sau khi đã thực hiện câu a, chạy câu a trước)
				{
					cout << "Đa thức ban đầu: ";
					traverse(poly);
					cout << endl;
					cout << "Đa thức sau khi rút gọn: ";
					RutGonDaThuc(poly);
					traverse(poly);
					cout << endl;
					break;
				}
				case 'c'://Thêm một đơn thức mới vào sao cho vẫn giữ nguyên tính thứ tự của bậc
				{
					cout << "Đa thức ban đầu: ";
					traverse(poly);
					cout << endl;
					PNode* p = new PNode;
					p->a = -5;
					p->n = 2;
					for(PNode* q=poly.head; q!= NULL; q = q->next)
						if (p->n >= q->n)
						{
							addAfterPNodePolynomial(poly, q, p);
							break;
						}
					RutGonDaThuc(poly);
					cout << "Đa thức sau khi thêm: ";
					traverse(poly);
					cout << endl;
					break;
				}
				case 'd'://Xóa một đơn thức khi biết bậc
				{
					traverse(poly);
					cout << endl;
					int n;
					cout << "Nhập số bậc: ";
					cin >> n;
					PNode* q = poly.head;
					while(searchPolynomial(poly, n))
					{
						deletePolynomialHasExponent(poly, n);
					}
					cout << "Đa thức sau khi xóa: ";
					traverse(poly);
					cout << endl;

					break;
				}
				case 'e'://Tính giá trị của đa thức khi biết giá trị của x
				{
					traverse(poly);
					cout << endl;
					int x;
					cout << "Nhập giá trị x: ";
					cin >> x;
					cout << "Giá trị của biểu thức: " << value(poly, x) << endl;

					break;
				}
				case 'f'://Thực hiện việc cộng/trừ/nhận 2 đa thức P và Q để tạo ra một đa thức mới
				{
					Polynomial poly1;
					init(poly1);
					//-10 -2x^2 + 3x^3 + x + 5x^2
					PNode* p1 = createPNode(-10, 0);
					PNode* p2 = createPNode(-2, 2);
					PNode* p3 = createPNode(3, 3);
					PNode* p4 = createPNode(1, 1);
					PNode* p5 = createPNode(5, 2);

					addTailPolynomial(poly1, p1);
					addTailPolynomial(poly1, p2);
					addTailPolynomial(poly1, p3);
					addTailPolynomial(poly1, p4);
					addTailPolynomial(poly1, p5);
					RutGonDaThuc(poly1);

					Polynomial poly2;
					init(poly2);
					//-1 -2x^2 - x + 5x^2
					PNode* p6 = createPNode(-1, 0);
					PNode* p7 = createPNode(-2, 2);
					PNode* p8 = createPNode(-1, 1);
					PNode* p9 = createPNode(5, 2);
					RutGonDaThuc(poly2);

					addTailPolynomial(poly2, p6);
					addTailPolynomial(poly2, p7);
					addTailPolynomial(poly2, p8);
					addTailPolynomial(poly2, p9);
					
					cout << "Đa thức 1: ";
					traverse(poly1);
					cout << endl;
					cout << "Đa thức 2: ";
					traverse(poly2);
					cout << endl;

					cout << "Cộng hai đa thức: ";
					Polynomial kq;
					init(kq);
					kq = Add(poly1, poly2);
					
					traverse(kq);
					cout << endl;
					
					cout << "Nhân hai đa thức: ";
					init(kq);

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