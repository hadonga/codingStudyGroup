std::mutex mtx1, mtx2;
void safe_dual_lock() {
    std::lock(mtx1, mtx2); // 同时锁定，避免死锁
    std::lock_guard<std::mutex> lock1(mtx1, std::adopt_lock); // 接管已锁定的mtx1
    std::lock_guard<std::mutex> lock2(mtx2, std::adopt_lock); // 接管mtx2
    // 操作共享资源
}