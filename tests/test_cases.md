# Test Cases

## Entropy & Redundancy

1. `aaaaaaa` → Entropy ≈ 0.0, Redundancy ≈ 1.0
2. `abcd` → Entropy = 2.0, Redundancy ≈ 0.875
3. `aabbccdd` → Entropy = 2.0, Redundancy ≈ 0.875
4. `hello world` → Entropy ≈ 3.18, Redundancy ≈ 0.60
5. `this is a test string for entropy calculation`

## Modular Inverse

- `mod_inverse(3,7)` = **5** (vì 3*5 = 15 ≡ 1 mod 7)
- `mod_inverse(6,9)` = **Không tồn tại** (gcd(6,9)=3 ≠ 1)
- `mod_inverse(5,11)` = **9**
- `mod_inverse(7,26)` = **15**
- `mod_inverse(10,17)` = **12**
