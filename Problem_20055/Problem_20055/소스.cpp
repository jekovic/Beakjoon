//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#include <stack>
//#include <cstring>
//
//using namespace std;
//
//int N, K;
//int c_turn;
//
//// 인덱스
//vector<int> robot;
//int robot_index;
//
//class belt_status {
//public:
//	int durable;
//	bool isrobot;
//	belt_status(int q) {
//		this->durable = q;
//		this->isrobot = false;
//	}
//};
//
//vector<belt_status> belt;
//
//bool check_Durability() {
//	int cnt = 0;
//	for (auto& a : belt) {
//		if (a.durable == 0)
//			cnt++;
//	}
//	if (cnt >= K) {
//		return false;
//	}
//	return true;
//}
//
//void input() {
//
//	cin >> N >> K;
//
//	for (int i = 0; i < 2 * N; i++) {
//		int q;
//		cin >> q;
//		belt.push_back(belt_status(q));
//	}
//}
//
//void down_robot() {
//	if (belt[N - 1].isrobot == true) {
//		belt[N - 1].isrobot = false;
//		belt[N].durable--;
//		belt[N].isrobot = true;
//	}
//
//	for (int i = 0; i != robot.size(); i++) {
//		if (robot[i] == N - 1) {
//			robot[i] = N;
//		}
//	}
//}
//
//void move_robot() {
//	for (int i = 0; i != robot.size(); i++) {
//		int idx = robot[i];
//		if (idx == 2 * N - 1) {
//			if (belt[0].isrobot == false and belt[0].durable >= 1) {
//				robot[i] = 0;
//				belt[0].isrobot = true;
//				belt[0].durable--;
//				belt[idx].isrobot = false;
//			}
//		}
//		else {
//			if (belt[++idx].isrobot == false and belt[++idx].durable >= 1) {
//				belt[idx].isrobot = false;
//				robot[i]++;
//				belt[idx+1].isrobot = true;
//				belt[idx+1].durable--;
//				
//			}
//		}
//	}
//	down_robot();
//}
//
//void move() {
//	
//	while (1)
//	{	
//		c_turn++;
//
//		// 1. 회전
//		auto temp = belt.back();
//		belt.pop_back();
//		belt.insert(belt.begin(), temp);
//		if (belt[N - 1].isrobot == true) {
//			belt[N - 1].isrobot = false;
//			belt[N].durable--;
//			belt[N].isrobot = true;
//		}
//
//		for (int i = 0; i != robot.size(); i++) {
//			robot[i]++;
//			if (robot[i] == 2 * N - 1) {
//				robot[i] = 0;
//			}
//			else if (robot[i] == N - 1) {
//				robot[i] = N;
//			}
//		}
//		
//
//		//2. 로봇 이동
//		move_robot();
//
//		//3 올리는 칸에 로봇 올리기 
//		if (belt[0].durable > 0 and belt[0].isrobot == false) {
//			belt[0].isrobot= true;
//			belt[0].durable--;
//			robot.push_back(0);
//		}
//
//		//4	
//		if (!check_Durability())	break;
//	}
//}
//
//int main() {
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	input();
//
//	move();
//
//	cout << c_turn;
// 
//
//	return 0;
//}


#include <iostream>
#include <vector>
using namespace std;
int n, k;
int belt[202];
bool robot[202] = { 0 };
int start_pos = 0;
int end_pos;
int inital_robot_pos = -1;
int result = 1;
int cnt = 0;
bool stop = false;

void rotation_belt() {
    if (start_pos == 0) // 0이면 맨 뒤의 인덱스로 옮김
        start_pos = 2 * n - 1;
    else
        start_pos--;

    if (end_pos == 0) // 0이면 맨 뒤의 인덱스로 옮김
        end_pos = 2 * n - 1;
    else
        end_pos--;

    if (robot[end_pos])
        robot[end_pos] = false;
}

void move_robot() {
    if (inital_robot_pos != -1) {
        // 첫번째 단계에서는 로봇이 없기 때문에 패스
        int idx = end_pos;
        for (int i = 0; i < n - 1;i++) {
            int next = idx; // 로봇이 갈 다음 위치
            if (idx == 0)
                idx = 2 * n - 1; // 현재 위치      
            else
                idx--;

            if (!robot[next] && robot[idx] && belt[next] > 0) {
                // 다음 위치에 로봇이 없는지
                // 현재 위치에 로봇 존재 하는지
                // 다음 위치의 내구도가 0보다 큰지
                belt[next] -= 1; // 내구도 감소
                if (belt[next] == 0) { // 내구도가 0이면
                    cnt++; // 내구도 0 개수 추가
                    if (cnt >= k) {
                        stop = true; // 종료 flag
                        break;
                    }
                }
                robot[next] = true; // 다음 좌표 로봇 true
                robot[idx] = false; // 현재 좌표 로봇은 옮겼으니 false
            }
        }
        robot[end_pos] = false; // 내리는 위치 로봇 내려줌

    }
}

void put_robot() {
    if (belt[start_pos] > 0) {
        belt[start_pos] -= 1; // 내구도 감소
        if (belt[start_pos] == 0) { // 종료 조건
            cnt++;
            if (cnt >= k) {
                stop = true;
            }
        }
        robot[start_pos] = true; // 로봇 올림
        inital_robot_pos = 0; // 로봇 올리기 시작.
    }
}

int main() {
    cin >> n >> k;
    int temp;
    for (int i = 0; i < 2 * n;i++) {
        cin >> belt[i];
    }
    end_pos = n - 1;
    while (!stop) {
        rotation_belt();
        move_robot();
        put_robot();
        if (stop) // 종료
            break;
        result++; // 단계 완수
    }
    cout << result << endl;
    return 0;
}
