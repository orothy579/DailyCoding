import turtle
import random

def move_and_stamp():
    """
    Turtle이 지정된 영역 내에서 이동하며, 지정된 거리마다 stamp를 찍습니다.
    """
    # 설정
    colors = ['red', 'green', 'magenta', 'aquamarine', 'black', 'blue']  # 색상 목록
    turtle.speed(0)  # 최대 속도
    turtle.shape('turtle')  # 거북이 모양 설정
    turtle.penup()  # 펜을 올림 (선 없음)

    # 초기 위치 설정
    x_start, y_start = -150, 150
    turtle.goto(x_start, y_start)

    # 거북이 이동 및 스탬프 찍기
    step = 50  # 이동 거리
    for y in range(y_start, -y_start - step, -step):  # 세로 방향 이동
        for x in range(x_start, -x_start + step, step):  # 가로 방향 이동
            turtle.color(random.choice(colors))  # 색상을 랜덤으로 선택
            turtle.stamp()  # 스탬프 찍기
            turtle.forward(step)  # 오른쪽으로 이동
        # 한 행이 끝나면 아래로 이동하고 방향 전환
        y -= step
        turtle.goto(x_start, y)  # 새로운 행 시작 위치로 이동

    turtle.done()

if __name__ == "__main__":
    move_and_stamp()
