auto divCeil = []<class T>(T a, T b) -> T {
    return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
};
