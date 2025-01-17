# Метод шифрования RSA

Большие числа хранятся в std::deque работа с ними происходит за счет перегрузки операторов +, -, *, /, % и т.п.

## Алгоритм создания открытого и секретного ключей

RSA-ключи генерируются следующим образом:

1) Выбираются два различных случайных простых числа p и q;
2) Вычисляется их произведение n = p⋅q;
3) Вычисляется значение функции Эйлера от числа n: φ(n)=(p−1)⋅(q−1);
4) Выбирается целое число e ( 1 < e < φ (n) ) , взаимно простое со значением функции φ(n), число e называется открытой экспонентой обычно в качестве е берут простые числа Ферма, т.к. в их двоичной записи мало единиц с ними быстрей производить различные вычисления, первая тройка чисел Ферма: 17, 257 или 6553;
5) Вычисляется число d , мультипликативно обратное к числу e по модулю φ (n):
                   d⋅e ≡ 1 (mod φ(n))
6) пара (e, n) публикуется в качестве открытого ключа RSA;
7) пара (d, n) играет роль закрытого ключа RSA.

## Шифрование и расшифрование
![Public_key_encryption,_transmission_and_decryption_light-ru-rendered svg](https://github.com/user-attachments/assets/067c209d-4ebd-4a34-ae41-9218f1b2df64)
Предположим, Боб хочет послать Алисе сообщение m. Сообщениями являются целые числа в интервале от 0 до n−1.
### Алгоритм шифрования:
Взять открытый ключ (e, n) Алисы. Взять открытый текст m. Зашифровать сообщение с использованием открытого ключа Алисы:
    
    c = m^e (mod n)      
### Алгоритм расшифрования:
Принять зашифрованное сообщение c. Взять свой закрытый ключ (d, n). Применить закрытый ключ для расшифрования сообщения:
    
    m = c^d (mod n)
