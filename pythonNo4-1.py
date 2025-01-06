import turtle

def draw_circles_in_order():

    positions = [(0, 100), (0, -100), (-100, 0), (100, 0)]  # 상, 하, 좌, 우 위치
    turtle.speed(3)  # 속도 설정

    for pos in positions:
        turtle.penup()
        turtle.goto(pos)
        turtle.pendown()
        turtle.circle(50)

    turtle.done()

if __name__ == "__main__":
    draw_circles_in_order()
