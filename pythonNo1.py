import random

# 학생 리스트
studentList = [
    ['한동이', 'GLS', 75, 80, 90],
    ['김다은', '생명', 80, 45, 90],
    ['서영임', '전산', 90, 5, 70],
    ['오하늘', 'GLS', 80, 60, 77],
    ['고영명', '생명', 50, 90, 77],
    ['나현수', '전산', 88, 65, 60]
]

# 등급 계산 함수
def calculate_grade(avg):
    if avg >= 90:
        return 'A'
    elif avg >= 80:
        return 'B'
    elif avg >= 70:
        return 'C'
    elif avg >= 60:
        return 'D'
    else:
        return 'F'

# 평균 및 등급 계산
def update_student_data():
    for student in studentList:
        # 숫자(성적)만 추출하여 평균 계산
        scores = [score for score in student[2:] if isinstance(score, (int, float))]
        avg = round(sum(scores) / len(scores), 2)  # 소수점 둘째 자리까지 반올림
        grade = calculate_grade(avg)
        # 평균과 등급 데이터 유지
        if len(student) > 2 and isinstance(student[-2], float):
            student[-2:] = [avg, grade]
        else:
            student.extend([avg, grade])

# 메뉴 1: 신규 교과목 성적 입력
def add_subject_score():
    new_scores = []
    for student in studentList:
        score = int(input(f"{student[0]}의 새로운 과목 점수를 입력하세요: "))
        student.insert(-2, score)  # 평균과 등급 앞에 삽입
        new_scores.append(score)
    update_student_data()

# 메뉴 2: 전체 성적 출력
def show_all_scores():
    print("\t\t\t< 전체점수 >")
    for student in studentList:
        print("\t".join(map(str, student)))

# 메뉴 3: 행운의 성적 변경
def modify_random_score():
    # 한 명의 학생을 임의로 선택
    student = random.choice(studentList)
    # 학생의 성적 범위에서 임의의 과목 선택
    score_idx = random.randint(2, len(student) - 3)
    old_score = student[score_idx]
    new_score = random.randint(old_score, 100)  # 성적 변경
    student[score_idx] = new_score
    print(f"{student[0]}의 {score_idx - 1}번째 성적이 {old_score}에서 {new_score}로 변경되었습니다.")
    update_student_data()

# 메뉴 4: 학생 검색
def search_student():
    name = input("검색할 학생의 이름을 입력하세요: ")
    for student in studentList:
        if student[0] == name:
            print("이름\t학부\t성적\t평균\t등급")
            print("\t".join(map(str, student)))
            return
    print("자료에 없는 학생입니다.")

# 메뉴 5: 학부별 평균
def calculate_department_avg():
    departments = {}
    for student in studentList:
        dept = student[1]
        avg = student[-2]
        departments.setdefault(dept, []).append(avg)
    for dept, avgs in departments.items():
        print(f"{dept} 학부 평균: {sum(avgs) / len(avgs):.2f}")

# 메뉴 6: 내림차순 정렬
def sort_by_average_desc():
    studentList.sort(key=lambda x: x[-2], reverse=True)
    print("평균 점수를 기준으로 내림차순 정렬 완료.")
    show_all_scores()

# 메뉴 7: 새로운 학생 입력
def add_new_student():
    name = input("새로운 학생의 이름을 입력하세요: ")
    dept = input("새로운 학생의 학부를 입력하세요: ")
    scores = [int(input(f"{name}의 과목 {i+1} 점수를 입력하세요: ")) for i in range(3)]
    studentList.append([name, dept] + scores)
    update_student_data()

# 메인 프로그램
def main():
    update_student_data()
    while True:
        print("\n1. 신규 교과목 성적 입력")
        print("2. 전체 성적 보여주기")
        print("3. 행운의 성적 변경")
        print("4. 학생 검색")
        print("5. 학부별 평균")
        print("6. 내림차순 정렬")
        print("7. 새로운 학생 입력")
        print("0. 프로그램 종료")
        menu = int(input("Enter Menu : "))
        if menu == 0:
            print("프로그램을 종료합니다.")
            break
        elif menu == 1:
            add_subject_score()
        elif menu == 2:
            show_all_scores()
        elif menu == 3:
            modify_random_score()
        elif menu == 4:
            search_student()
        elif menu == 5:
            calculate_department_avg()
        elif menu == 6:
            sort_by_average_desc()
        elif menu == 7:
            add_new_student()
        else:
            print("올바른 메뉴를 선택하세요.")

if __name__ == "__main__":
    main()
