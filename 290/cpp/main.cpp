#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        string lastWord[26]; // �ַ������ʵ�ӳ��
	unordered_map<string, char> map; // ���ʵ��ַ���ӳ��

        // ��ʼ���ַ����ַ�����ӳ��
        for (int i = 0; i < 26; ++i)
            lastWord[i] = "";
            
        int len = str.size(), patternLen = pattern.size();
        int start = 0, end = 0, patternIndex = 0;
        string sub;
        
	// ���λ�ȡ��һ������
        while (patternIndex < patternLen && end < len) {
            while (end < len && str[end] != ' ') // �ҵ����ʽ�β
                ++end;
            // ��ȡ����
            sub = str.substr(start, end - start);
            
	    // �ж��ַ������ʵ�ӳ���Ƿ���֮ǰ��ӳ���ͻ
            if (lastWord[pattern[patternIndex] - 'a'] == "") // ֮ǰû�б�������ַ���ӳ��
                lastWord[pattern[patternIndex] - 'a'] = sub; // �洢�µ�ӳ��
            else if (lastWord[pattern[patternIndex] - 'a'] != sub) // // ��֮ǰ��ӳ�䲻����
	        return false;
                
	    // �жϵ��ʵ��ַ���ӳ���Ƿ���֮ǰ��ӳ���ͻ
            if (map.find(sub) == map.end()) // ֮ǰû�б�����õ��ʵ�ӳ��
                map[sub] = pattern[patternIndex]; // �洢�µ�ӳ��
            else if (map[sub] != pattern[patternIndex]) // ��֮ǰ��ӳ�䲻��
                return false;
                
            ++patternIndex;  // ָ����һ���ַ�
            start = end + 1; // ��һ�����ʿ�ʼλ��
	    end = start;     // ��һ�����ʳ�ʼ����λ��
        }

        // ���pattern��str�����ߵ���β�ˣ���ƥ��ɹ�
        return end >= len && patternIndex >= patternLen;
    }
};

int main() {
    Solution s;
    cout << s.wordPattern("abba", "dog cat cat dog") << endl;
    cout << s.wordPattern("abba", "dog cat cat fish") << endl;
    cout << s.wordPattern("aaaa", "dog cat cat dog") << endl;
    cout << s.wordPattern("aaaa", "dog dog dog dog") << endl;
    cout << s.wordPattern("aaa", "dog dog dog dog") << endl;
    cout << s.wordPattern("abba", "dog dog dog dog") << endl;
}
