#include <unordered_map>
#include <iostream>
using namespace std;
//게임 캐릭터 생성
struct GameCharacter {
	int CharCd; //캐릭터 코드
	int Level;  //레벨
	int Money;  //돈
	GameCharacter() {};
	GameCharacter(int _CharCd, int _Level, int _Money)
	{
		CharCd = _CharCd;
		Level = _Level;
		Money = _Money;
	}
};
int main()
{
	unordered_map<int, GameCharacter> Characters;
	GameCharacter Characters1(12, 7, 1000);
	Characters.insert(unordered_map<int, GameCharacter>::value_type(12, Characters1));

	GameCharacter Characters2(15, 20, 111000);
	Characters.insert(unordered_map<int, GameCharacter>::value_type(15, Characters2));
	GameCharacter Characters3(200, 34, 2330103);
	Characters.insert(unordered_map<int, GameCharacter>::value_type(200, Characters3));
    
  //iterator와 begin, end 사용
  //저장한 요소를 정방향으로 순회
	unordered_map<int, GameCharacter>::iterator Iter1;
	for (Iter1 = Characters.begin(); Iter1 != Characters.end(); Iter1++) {
		cout << "캐릭터 코드 :" << Iter1->second.CharCd << " | 레벨 : " << Iter1->second.Level << " | 가진 돈 :" << Iter1->second.Money << endl;
	}
	cout << endl;
   
  //Character에 저장한 요소 수
	int Count = Characters.size();

  //검색
  //캐릭터 코드가 15인 캐릭터를 찾는다.
	unordered_map<int, GameCharacter>::iterator FindIter = Characters.find(15);
  //찾지 못했다면 FindIter은 end 위치의 반본자를 리턴된다.
	if (FindIter != Characters.end()) {
		cout << "캐릭터 코드가 15인 캐릭터를 찾았습니다." << endl;
		cout << "캐릭터 코드 :" << FindIter->second.CharCd << " | 레벨 : " << FindIter->second.Level << " | 가진 돈 :" << FindIter->second.Money << endl;
	}
	else cout << "캐릭터 코드가 15인 캐릭터가 없습니다." << endl;
	cout << endl << endl;

  //삭제
  //캐릭터 코드가 15인 캐릭터를 삭제한다
	Characters.erase(15);
	for (Iter1 = Characters.begin(); Iter1 != Characters.end(); Iter1++) {
		cout << "캐릭터 코드 :" << Iter1->second.CharCd << " | 레벨 : " << Iter1->second.Level << " | 가진 돈 :" << Iter1->second.Money << endl;
	}
	cout << endl << endl;
    
  //모든 캐릭터를 삭제한다
	Characters.erase(Characters.begin(), Characters.end());

  //Character 공백 조사
	if (Characters.empty())
		cout << "charcater는 비어 있습니다." << endl;
}