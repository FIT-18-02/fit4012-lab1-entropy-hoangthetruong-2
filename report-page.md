# Report 1 Page – FIT4012 Lab 1

## 1. Mục tiêu
Hiểu cách tính entropy, redundancy và áp dụng thuật toán tìm nghịch đảo modulo trong lập trình.

## 2. Cách làm
- Đọc hiểu chương trình entropy mẫu.
- Bổ sung hàm tính redundancy.
- Hoàn thiện hàm mod_inverse().
- Chạy thử trên nhiều test case.

## 3. Kết quả chính

### 3.1 Entropy và redundancy
| Input | Entropy | Redundancy | Nhận xét |
|---|---:|---:|---|
| aaaa | 0.00 | 2.00 | Dữ liệu lặp lại hoàn toàn nên entropy thấp |
| abcd | 2.00 | 0.00 | Phân phối đều nên entropy cao |
| hello world | 2.85 | 0.61 | Dữ liệu thực tế, entropy trung bình |

### 3.2 Modulo inverse
| a | m | Kết quả mong đợi | Kết quả chương trình |
|---:|---:|---|---|
| 3 | 7 | 5 | 5 |
| 10 | 17 | 12 | 12 |
| 6 | 9 | Không tồn tại | Không tồn tại |

## 4. Kết luận
Qua bài lab, em hiểu rõ hơn về entropy là thước đo mức độ ngẫu nhiên của dữ liệu, còn redundancy thể hiện phần dư thừa có thể tối ưu. Ngoài ra, em đã biết cách sử dụng thuật toán Euclid mở rộng để tìm nghịch đảo modulo.

Khó khăn lớn nhất là hiểu cách hoạt động của công thức entropy và triển khai mod_inverse đúng. Sau khi làm bài, em hiểu rõ hơn về cách dữ liệu được biểu diễn và xử lý trong bảo mật và mã hóa.

