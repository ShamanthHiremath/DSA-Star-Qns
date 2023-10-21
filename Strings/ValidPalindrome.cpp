bool isPalindrome(string str) {
    int i = 0, j = str.length() - 1;
    while (i < j) {
        if (!isalnum(str[i])) {
            i++;
        } else if (!isalnum(str[j])) {
            j--;
        } else if (tolower(str[i]) != tolower(str[j])) {
            return false;
        } else {
            i++;
            j--;
        }
    }
    return true;
}