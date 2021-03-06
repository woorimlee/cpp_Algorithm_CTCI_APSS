//전문가를 위한 C++(개정4판) 
//87쪽 시작

#include <iostream>
#include <string>
#include <array>
#include <cstdio>
#include <initializer_list>

using namespace std;

/*
용어
1. Referential transparency : 참조적 투명성. 함수의 반환 값이 그 입력 값만으로 결정. 
	메모이제이션 기법을 사용하려면 참조적 투명함수로 구현되어야 함.
	ex) int cnt = 0;
		int count() {
			return cnt++;
		}
	이런 것은 참조적 투명함수가 아님. 실행할 때마다 cnt 값이 달라짐.

2. Structured binding : 구조적 바인딩. part1 이름 공간에서 자세히 설명
*/

namespace part1 {
	//기본 int형, 값을 따로 지정해주지 않으면 0부터 채워짐
	enum Cafe { SB, CB, E, TS, CafeCount}; //열거형 개수를 세기 위해 

	void enum_Test() {
		Cafe c1;
		c1 = SB;
		int i = SB;
		if (c1 == SB)
			cout << c1 << " " << i << endl;
		c1 = (Cafe)3;
		if (c1 == TS)
			cout << c1 << endl;
		c1 = (Cafe)5;
		if (c1 == SB)
			cout << c1 << endl;
	}

	//스위치도 자주 쓰인다고 하네요?
	void switch_default_Test(Cafe cafe) {
		switch (cafe) { //수식에 대한
			case Cafe::SB: //연산 결과
				cout << "스타벅스\n";
				break;
			//fallthrough 폴스루, 흘려보내기 방식
			case CB:
			case TS:
				cout << "중고가\n";
				break;
			default :
				//일치하는게 하나도 없으면 default 실행.
				//보통 에러 잡기위해 씀
				cout << "중저가\n";
				break;
			}
	}

	//함수마다 내부적으로 __func__라는 로컬 변수가 있고, 함수 이름을 갖고 있음
	void now_func_name() {
		cout << "현재 함수 이름 : " << __func__ << "\n";
		return;
	}

	//c++17부터 <array> 헤더의 std 공간에서 제공하는 size함수 사용 가능
	void check_arr_size() {
		int arr[3];
		cout << "size를 이용한 배열 크기 확인 : " << size(arr) << "\n";
	}
	//array를 c스타일 배열 보다 추천함
	//1. 내장 함수
	//2. 포인터 관련된 인덱스 실수
	void use_array() {
		array<int, 5> arr = { 5, 2, 1 };
		cout << "arr size : " << arr.size();
		cout << "\nfront : " << arr.front() << " back : " << arr.back() << "\n";
		array<int, 5> arr2 = { 0 };
		arr2.fill(-1);
		cout << "arr2 : ";
		for (auto it : arr2) {
			cout << it << " ";
		}
		cout << "\nswaped arr & arr2 : ";
		arr.swap(arr2);
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << " " << arr2[i] << " ";
		}
		cout << "\n";
		return;
	}

	//structured binding : 구조적 바인딩
	void use_sb() {
		//여러 개의 변수를 선언할 때 배열, 구조체, 페어 등으로 초기화 가능.
		array<int, 3> arr = { 11, 22, 33 };
		auto [x, y, z] = arr;
		cout << x << " " << y << " " << z << "\n";
		struct Point { double mx, my, mz; };
		Point point;
		point.mx = 1.0; point.my = 2.0; point.mz = 3.0;
		auto [x2, y2, z2] = point;
		printf("%.1lf %.1lf %.1lf\n", x2, y2, z2);
		return;
	}
	
	//반복자를 리턴하는(begin()과 end()가 존재하는) 모든 컨테이너에 적용 가능한
	//범위 기반 for문
	void use_range_based_for_loop() {
		array<int, 4> arr = { 1, 2, 3, 4 };
		for (int i : arr) {
			cout << i << " ";
		}
		cout << "\n";
		return;
	}

	//initializer_list를 이용하면 여러 인수를 받는 함수를 쉽게 작성할 수 있다.
	//<initializer_list> 헤더를 포함한다.
	void use_ini_list(initializer_list<int> lst) {
		int total = 0;
		for (int i : lst) {
			total += i;
		}
		cout << total << "\n";
		return;
	}
}

int main() {
	part1::enum_Test();
	//열거형 for구문 돌리는 방법
	/*
	for (part1::Cafe i = part1::Cafe::SB; i < part1::Cafe::CafeCount; i = (part1::Cafe)(i+1)) {
		part1::switch_default_Test(i);
	}
	*/
	//part1::now_func_name();
	//part1::check_arr_size();
	//part1::use_array();
	//part1::use_sb();
	//part1::use_range_based_for_loop();
	//part1::use_ini_list({1, 2, 3, 4, 5});

	return 0;
}