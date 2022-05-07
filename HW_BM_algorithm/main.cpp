#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

# define NUM 256 //ASCII code의 전체 크기

//initSkip 함수 구현
void initSkip(const string& p, int skip[NUM]) {
    int i, M = p.size();
    for (i = 0; i < NUM; i++) skip[i] = M; //(특수문자 포함)모든 문자에 대해 skip 배열 생성
    for (i = 0; i < M; i++) skip[(int)p[i]] = M - i - 1; //각 문자 위치 char을 int로 변환하여 ship 배열에 저장
}

// Boyer Moore algorithm using bad character Heuristic

int misChar(const string& t, const string& p) {
    int M = p.size(), N = t.size();

    //skip 배열을 생성하고 initSkip 함수 실행
    int skip[NUM];
    initSkip(p, skip);

    int i, j; //텍스트에서 이동하는 문자를 나타내는 i 변수
    for (i = M - 1, j = M - 1; j >= 0; i--, j--) { //패턴 끝에서 앞으로 이동하며 탐색
        while (t[i] != p[j]) { //불일치 발생시 작동
            int k = skip[(int)t[i]];
            if (M - j > k) i += M - j; 
            //일치했으므로 왼쪽으로 이동한 거리가 skip 위치 문자위치 보다 큰 경우 m-j 만큼 이동
            //(왼쪽으로 패턴이 삐져나오는 것을 방지
            else i += k; //skip 배열이 패턴 위치에 맞추어 이동
            if (i >= N) return N; //text 끝에 도달
            j = M - 1; //j 초기화
        }
    }
    return i + 1;
}


int main() {
    string text;
    string pattern;

    //파일 읽기
    std::ifstream txtfile("RFC2616_modified.txt");
    
    //파일크기 읽음
    txtfile.seekg(0, std::ios::end);
    int size = txtfile.tellg();
    //파일크기만큼 text 사이즈 할당
    text.resize(size);
    //파일 내용 읽어와 저장
    txtfile.seekg(0, std::ios::beg);
    txtfile.read(&text[0], size);
    
    cout << "12204284 김동영 HW1" << endl;
    while (1) {
        cout << "\n찾을 pattern 입력 : ";
        std::getline(cin, pattern);
        if (pattern == "exit") break;

        int pos, previous = 0;
        bool is_matched = 0;
        while (1) {//반복 탐색
            pos = misChar(text.substr(previous), pattern); //이전 탐색위치 이후부터 탐색
            pos += previous; //탐색 성공시 문자열이 탐색된 위치 저장
            if (pos + pattern.size() <= text.size()) { is_matched = 1; cout << "패턴 발생 : " << pos << endl; }
            else { 
                if(is_matched == 0) cout << "패턴이 존재하지 않음" << endl; 
                break; 
            }
            previous = pos + 1; //다음 위치부터 다시 탐색하도록 변수 설설정
        }
    }

    return 0;
}