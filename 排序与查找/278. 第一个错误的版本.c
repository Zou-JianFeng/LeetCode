// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    long head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (isBadVersion(mid)) {
            tail = mid;
        } else {
            head = mid + 1;
        }
    }
    return head;
}