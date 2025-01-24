/*
답 : http://boj.kr/7c429b5497b149a3a42c4a2d02b9a4b5
*/

/*
 * Problem: 9996
 * URL: https://www.acmicpc.net/problem/9996
 */

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    int fileCount = 0;
    cin >> fileCount;

    smatch affix_match;

    // h*n -> ^h[a-z]*n//$로 바로 검사 가능

    // 정규 표현식에서 *는 이전 문자가 0번 이상 반복됨을 의미
    // * 자체를 문자로 인식하기 위해서는 백슬래시가 두 번 필요
    string affix_pattern_text = "[\\*]";
    regex affix_regex(affix_pattern_text);

    string fileNamePattern;
    cin >> fileNamePattern;

    // *를 기준으로 주어진 패턴 문자열을 자름
    regex_search(fileNamePattern, affix_match, affix_regex);

    // prefix*suffix 형태, ssub_match를 문자열로 변환
    string filename_prefix = affix_match.prefix().str();
    string filename_suffix = affix_match.suffix().str();

    // prefix[a-z]*suffix로 패턴 교체, 중간에는 하나 이상의 소문자만 들어감
    // [a-z]+ 하나 이상의 소문자
    // [a-z]* 0개 이상의 소문자
    string filename_pattern_text = filename_prefix + "[a-z]*" + filename_suffix;
    regex filename_regex(filename_pattern_text);

    // 입력값에 따라 자료의 크기가 결정되므로, vector 구조 사용
    vector<string> fileNames(fileCount);

    for (string fileName : fileNames)
    {
        cin >> fileName;

        // true : prefix[a-z]suffix
        bool isMatched = regex_match(fileName, filename_regex);

        string answer = isMatched ? "DA" : "NE";
        cout << answer << '\n';
    }

    return 0;
}