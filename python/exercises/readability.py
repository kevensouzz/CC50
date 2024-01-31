def coleman_liau(text):
    letters = 0
    sentences = 0
    words = 1
    for char in text:
        if char.isalpha():
            letters += 1
        elif char.isspace():
            words += 1
        elif char in "!?.":
            sentences += 1

    grade = int(
        round(0.0588 * letters / words * 100 - 0.296 * sentences / words * 100 - 15.8)
    )

    if grade > 16:
        print("After Grade 16")
    elif grade < 1:
        print("Before Grade 1")
    else:
        print(f"Grade: {grade}")


text = input("Text: ")
coleman_liau(text)
