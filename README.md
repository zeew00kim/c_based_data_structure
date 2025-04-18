**25년 1학기 자료구조 수업에 대한<br>
코드 로직을 이곳에 정리할 예정입니다.**
<br>
<strong><a href="https://velog.io/@zeew00/series/C%EC%96%B8%EC%96%B4">코드 정리 내용 참고 블로그</a></strong>

---
## sorttingLogic.c

**각종 정렬 방식에 대해 선택하고 원하는 만큼 반복하는 로직**
- 각 정렬 방식은 별도의 함수로 구현
- 배열 정렬 결과 출력 함수 별도 구현
---
## 3dArray.c

**3차원 배열, 문자열을 사용해 학생의 이름과 점수를 입력 및 평균을 구하는 로직**
- 반복문을 통해 각 반 별 학생의 이름과 해당 학생의 과목 점수 4개 기입
- 각 점수를 출력하는 함수와 평균을 구하는 함수를 별도 구현
---
## strcmp.c
- `strcpy`를 통해 `name`의 문자열 내용을 `imitation` 문자열에 복사
- `conpareString()` 함수의 `strcmp` 기능을 사용해 문자열을 사전적 우선순위로 정렬
- `printString()` 정렬된 2d 문자열의 내용을 출력하는 함수
---
## funcPointer.c
- `func(int (*fp)(int, int))` 함수 포인터로 원하는 함수를 호출
- `do ~ while`문을 사용하여 사용자가 원하는 만큼 반복
---
## getPrimeNumber.c (2주차 월요일)
- `prime number(소수)` = 1과 자기 자신으로만 나누어 떨어지는 숫자
- `clock_t = start, end` 값을 사용해 프로세스를 실행하는 데에 소요된 시간을 계산
- `getPrimeNumber()` 2 ~ 10000 사이의 소수 값들을 구하는 함수
- 소수의 개수와 최종 소요 시간을 출력
---
## findMax.c (2주차 월요일)
- `rand()` 난수로 채워진 배열 중 `max` 값을 찾아 출력
---
## useStruct.c 
- 하나의 구조체에 다른 구조체를 선언하는 코드 로직
- `int main()`함수에서 구조체에 접근하고 값을 입력
- `printStructValues()`함수를 통해 구조체의 메모리 내부 값에 접근 및 출력<br>
`공부하면서 대충 만들어서 스파게티 코드가 되었습니다... (추후 수정 예정)`
---
## multipleLogic.c (2주차 수요일)
2차원 배열 `arr1[2][3]`의 행과 `arr[3][2]`의 열<br>
인덱스 번호의 값을 곱하고 cycle 한 번에 곱했던 값 3개를<br>
모두 더하여 각각 더해진 4개의 값을 새로운 2차원 배열인<br>
`tempArr[2][2]`에 삽입하는 코드 로직입니다.

---
## mulAndSumArr.c (2주차 수요일)
위의 `multipleLogic.c` 코드에 `arr1`, `arr3` 배열의<br>
동일한 인덱스 위치의 값을 더하여 `mulArr` 베열에 삽입하는<br>
기능의 로직이 추가된 코드입니다.

---
## sparseMatrix.c (3주차 월요일)
- 행/열과 하나의 행렬 요소 값을 가진 `struct Element` 구조체 선언
- `main()` 함수에서 구조체 배열 `Element structArr[5]` 선언
- `srand(time(NULL))` 함수를 통해 행/열/요소 값을 랜덤으로 생성
- `printArr()` 함수를 통해 희소행렬 및 전치행렬 결과 값을 출력
- `transportARR()` 구조체 배열을 순회하며 행과 열 값을 교환
---
 