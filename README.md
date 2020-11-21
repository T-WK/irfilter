# 도전과제: 적외선 거리 센서 잡음 필터링


---------------------------

### irfilter
### 20203054 김태완

---------------------------
​
## 영상속 그래프
- 파란색 : raw_dist
- 빨간색 : dist_cali
- 초록색 : dist_ema
​
​
## 코드 설명

>연속 촬영을 하듯이 여러개의 값을 뽑아 내기위해 
>1번의 loop() 함수를 돌동안 반복문을 통하여 N 개의 측정값을 뽑았습니다.
>
>그 뽑은 값들을 배열에 차례로 저장한후 정렬(오름차순) 한후, 앞에서 부터 값 k 개, 뒤에서 부터 k 개를 제거하고
>나머지 값들의 평균을 구하여 dist_cali에 대입하였습니다.
>
>이렇게 dist_cali만 해도 상당한 노이즈를 잡을 수 있었습니다. 하지만 부분 부분 살짝 튀는값들이 존재 하였기 떄문에 ema 필터까지 적용하였습니다.



## ir_distance_filter 예제
- ir_distance_filter함수 gist
	- https://gist.github.com/T-WK/715fde5441b68110a239bc1e0eda1db4

- 실행파일
	- https://github.com/T-WK/irfilter/blob/main/irfilter.ino
