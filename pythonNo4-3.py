import turtle

def draw_polygon(sides, length):

    angle = 360 / sides  # 각 변의 외각 계산
    turtle.setheading(angle/2)  # 시작 각도를 설정
    for _ in range(sides):
        turtle.forward(length)
        turtle.left(angle)

def main():
    turtle.speed(3)  # 속도 설정
    length = int(input("Enter length of a side: "))  # 한 변의 길이 입력

    while True:
        sides = int(input("Enter figure (3-triangle, 4-square, 5-pentagon, 6-hexagon, 0-end): "))
        if sides == 0:
            print("End of program")
            break
        elif sides < 3:
            print("Please input more than 3")
            continue

        # 도형 그리기
        draw_polygon(sides, length)
        turtle.penup()
        turtle.home()  # 초기 위치로 돌아감
        turtle.pendown()

    turtle.done()

if __name__ == "__main__":
    main()
