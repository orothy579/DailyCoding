import turtle
import random

def read_Path():
    try:
        with open("turtlePath.txt", "r") as file:
            path = [tuple(map(int, line.strip().split(','))) for line in file.readlines()]
        print("Read the path file")
        return path
    except IOError as e: 
        print(f"I/OError: {e}")
        return []

def create_Path():
    path = [(random.randint(-150, 150), random.randint(-150, 150)) for _ in range(100)]
    for point in path:
        print(point)
    print("Created new path")
    return path

def draw_Path(pathList):
    if not pathList:
        print("No path available to draw")
        return

    turtle.penup()
    turtle.goto(pathList[0]) 
    turtle.pendown()

    for x, y in pathList[1:]:
        turtle.goto(x, y)  
def draw_PathbyForward(pathList):
    print("완료 하지 못했습니다.")

def write_Path(pathList):
    """
    현재 경로를 파일(turtlePath.txt)로 저장
    """
    try:
        with open("turtlePath.txt", "w") as file:
            for x, y in pathList:
                file.write(f"{x},{y}\n")
        print("Saved the path file")
    except IOError as e :
        print(f"I/OError: {e}")

pathList = []

def main():

    while True:
        menu = input("Enter Menu(1-read path, 2-create Path, 3-draw path, 4-draw path by forward, 5-write path, 0-end): ")

        match menu:
            case '1':
                pathList = read_Path()
            case '2':
                pathList = create_Path()
            case '3':
                draw_Path(pathList)
            case '4':
                draw_PathbyForward(pathList)
            case '5':
                write_Path(pathList)
            case '0':
                print("Good bye")
                break
            
    turtle.done()

if __name__ == "__main__":
    main()
