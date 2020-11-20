# irfilter
### 20203054 김태완
​
# 도전과제: 적외선 거리 센서 잡음 필터링
​
>영상속 그래프
>>파란색 : raw_dist
빨간색 : dist_cali
초록색 : dist_ema
​
------------------------------------
​
# 코드 설명

>연속 촬영을 하듯이 여러개의 값을 뽑아 내기위해 
1번의 loop() 함수를 돌동안 반복문을 통하여 N 개의 측정값을 뽑았습니다.
​
그 뽑은 값들을 배열에 차례로 저장한후 정렬(오름차순) 한후, 앞에서 부터 값 k 개, 뒤에서 부터 k 개를 제거하고
나머지 값들의 평균을 구하여 dist_cali에 대입하였습니다.
​
이렇게 dist_cali만 해도 상당한 노이즈를 잡을 수 있었습니다. 하지만 부분 부분 살짝 튀는값들이 존재 하였기 떄문에 ema 필터까지 적용하였습니다.

----------------------------------------------

# 코드 예제
​
​''' C
void loop() {
    /*
    *
    * 
    */

    for (int i = 0; i < 반복하고 싶은 횟수(N); i++){
        list[i] = raw_dist //list에 거리값을 저장
    }

    /*
    *    정렬 
    *    저는 입력 받는 값의 개수가 그렇기 많지 않기 때문에 선택정렬로 list안의 값을 정렬해 주었습니다.
    */

    /*
    *   ema 필터 적용
    * 
    */
}
'''