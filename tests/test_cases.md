# Test Cases cho Lab 01 - Entropy, Redundancy và Modular Inverse

## 1. Entropy & Redundancy Test Cases

**Test 1: Chuỗi lặp toàn bộ**  
Chuỗi: `aaaa`  
Entropy mong đợi: ≈ 0.0  
Redundancy mong đợi: ≈ 100% (hoặc rất cao)

**Test 2: Chuỗi đa dạng hoàn toàn**  
Chuỗi: `abcd`  
Entropy mong đợi: 2.0 bits  
Redundancy mong đợi: 0% (với 4 ký tự duy nhất)

**Test 3: Chuỗi có lặp và không lặp**  
Chuỗi: `aabbccdde`  
Entropy mong đợi: khoảng 2.5 - 3.0 bits  
Redundancy: trung bình

**Test 4: Chuỗi thực tế**  
Chuỗi: `hello world`  
Entropy và Redundancy: có lặp ký tự (l, o, space)

## 2. Modular Inverse Test Cases

**Test 5: Có tồn tại nghịch đảo**  
mod_inverse(3, 7) = 5  
(Kiểm tra: 3 * 5 = 15 ≡ 1 mod 7)

**Test 6: Không tồn tại nghịch đảo**  
mod_inverse(6, 9) = không tồn tại (vì gcd(6,9) = 3 ≠ 1)
