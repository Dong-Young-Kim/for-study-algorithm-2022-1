#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

# define NUM 256 //ASCII code�� ��ü ũ��

//initSkip �Լ� ����
void initSkip(const string& p, int skip[NUM]) {
    int i, M = p.size();
    for (i = 0; i < NUM; i++) skip[i] = M; //(Ư������ ����)��� ���ڿ� ���� skip �迭 ����
    for (i = 0; i < M; i++) skip[(int)p[i]] = M - i - 1; //�� ���� ��ġ char�� int�� ��ȯ�Ͽ� ship �迭�� ����
}

// Boyer Moore algorithm using bad character Heuristic

int misChar(const string& t, const string& p) {
    int M = p.size(), N = t.size();

    //skip �迭�� �����ϰ� initSkip �Լ� ����
    int skip[NUM];
    initSkip(p, skip);

    int i, j; //�ؽ�Ʈ���� �̵��ϴ� ���ڸ� ��Ÿ���� i ����
    for (i = M - 1, j = M - 1; j >= 0; i--, j--) { //���� ������ ������ �̵��ϸ� Ž��
        while (t[i] != p[j]) { //����ġ �߻��� �۵�
            int k = skip[(int)t[i]];
            if (M - j > k) i += M - j; 
            //��ġ�����Ƿ� �������� �̵��� �Ÿ��� skip ��ġ ������ġ ���� ū ��� m-j ��ŭ �̵�
            //(�������� ������ ���������� ���� ����
            else i += k; //skip �迭�� ���� ��ġ�� ���߾� �̵�
            if (i >= N) return N; //text ���� ����
            j = M - 1; //j �ʱ�ȭ
        }
    }
    return i + 1;
}


int main() {
    string text;
    string pattern;

    //���� �б�
    std::ifstream txtfile("RFC2616_modified.txt");
    
    //����ũ�� ����
    txtfile.seekg(0, std::ios::end);
    int size = txtfile.tellg();
    //����ũ�⸸ŭ text ������ �Ҵ�
    text.resize(size);
    //���� ���� �о�� ����
    txtfile.seekg(0, std::ios::beg);
    txtfile.read(&text[0], size);
    
    cout << "12204284 �赿�� HW1" << endl;
    while (1) {
        cout << "\nã�� pattern �Է� : ";
        std::getline(cin, pattern);
        if (pattern == "exit") break;

        int pos, previous = 0;
        bool is_matched = 0;
        while (1) {//�ݺ� Ž��
            pos = misChar(text.substr(previous), pattern); //���� Ž����ġ ���ĺ��� Ž��
            pos += previous; //Ž�� ������ ���ڿ��� Ž���� ��ġ ����
            if (pos + pattern.size() <= text.size()) { is_matched = 1; cout << "���� �߻� : " << pos << endl; }
            else { 
                if(is_matched == 0) cout << "������ �������� ����" << endl; 
                break; 
            }
            previous = pos + 1; //���� ��ġ���� �ٽ� Ž���ϵ��� ���� ������
        }
    }

    return 0;
}