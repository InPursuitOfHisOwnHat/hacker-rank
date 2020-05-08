

//Complete the following function.

int marks_summation(int* marks, int number_of_students, char gender) {

    int* final_address = marks + number_of_students;

    if (gender == 'g') {
        marks++;
    }

    int sum = 0;

    while(marks <= final_address) {
        sum += *marks;
        marks+=2;
    }

    return sum;
}

