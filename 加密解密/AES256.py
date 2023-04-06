from Crypto.Cipher import AES
from binascii import b2a_hex, a2b_hex
import base64


# 如果text不足16位的倍数就用空格补足为16位
def add_to_16(text):
    if len(text.encode('utf-8')) % 16:
        add = 16 - (len(text.encode('utf-8')) % 16)
    else:
        add = 0
    text = text + ('\0' * add)
    return text.encode('utf-8')


# 加密函数
def encrypt(text):
    key = '\x39\x39\x39\x39\x39\x39\x39\x39\x39\x39\x39\x39\x39\x39\x39\x39'.encode('utf-8')
    mode = AES.MODE_CBC
    iv = b'\x31\x31\x31\x31\x31\x31\x31\x31\x31\x31\x31\x31\x31\x31\x31\x31'
    text = add_to_16(text)
    cryptos = AES.new(key, mode, iv)
    cipher_text = cryptos.encrypt(text)
    # 因为AES加密后的字符串不一定是ascii字符集的，输出保存可能存在问题，所以这里转为16进制字符串
    return b2a_hex(cipher_text)


# 解密后，去掉补足的空格用 strip () 去掉
def decrypt(text):
    key = '\x39\x39\x39\x39\x39\x39\x39\x39\x39\x39\x39\x39\x39\x39\x39\x39'.encode('utf-8')
    iv = b'\x31\x31\x31\x31\x31\x31\x31\x31\x31\x31\x31\x31\x31\x31\x31\x31'
    mode = AES.MODE_CBC
    cryptos = AES.new(key, mode, iv)
    plain_text = cryptos.decrypt(a2b_hex(text))
    return bytes.decode(plain_text).rstrip('\0')
def testAESGCM() :
    key = bytes.fromhex('3132333435363132333435363132333435363132333435363132333435363132')
    print(key)
    iv = bytes.fromhex('313233343132333431323334')
    text = bytes.fromhex('313233')
    cipher = AES.new(key, AES.MODE_GCM, iv)
    cipher_text, tag = cipher.encrypt_and_digest(text)
    print("testAESGCMcipher_text hex=",b2a_hex(cipher_text))
    print("testAESGCM        tag hex=",b2a_hex(tag))
    # enc_result = base64.b64encode(cipher_text + tag)
    enc_result = base64.b64encode(cipher_text)
    print("testAESGCM     base64 hex=",enc_result.decode())

# 加密函数
def encryptCTR():
    text = "hello world"
    key = '\x39\x39\x39\x39\x39\x39\x39\x39\x39\x39\x39\x39\x39\x39\x39\x39'.encode('utf-8')
    iv = b'\x31\x31\x31\x31\x31\x31\x31\x31\x31\x31\x31\x31\x31\x31\x31\x31'

    text = add_to_16(text)

    counter = Counter.new(128, initial_value=iv)
    cryptos = AES.new(key, AES.MODE_CTR, counter=counter)
   
    cryptos = AES.new(key, AES.MODE_CTR)
    cipher_text = cryptos.encrypt(text)
    print("encryptCTRcipher_text hex=",b2a_hex(cipher_text))
    # 因为AES加密后的字符串不一定是ascii字符集的，输出保存可能存在问题，所以这里转为16进制字符串
    return b2a_hex(cipher_text)


if __name__ == '__main__':
    e = encrypt("hello world")  # 加密
    d = decrypt(e)  # 解密
    print("加密:", e)
    print("解密:", d)
    testAESGCM()
    encryptCTR()


'''
123456123456123456123456123456123456
'''
