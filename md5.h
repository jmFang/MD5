
#ifndef MD5_H
#define MD5_H

/* Parameters of MD5. */
#define s11 7
#define s12 12
#define s13 17
#define s14 22
#define s21 5
#define s22 9
#define s23 14
#define s24 20
#define s31 4
#define s32 11
#define s33 16
#define s34 23
#define s41 6
#define s42 10
#define s43 15
#define s44 21

/**
 * MD5 ѹ������HMD5
 * 4��ѭ����ʹ�õ�����
 * ����(�ֺ���) g �Ķ���
 */
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

/**
 * <<<s : ��32λ����ѭ������(CLS) s λ��
 */
#define ROTATELEFT(num, n) (((num) << (n)) | ((num) >> (32-(n))))

/**
 * ÿ��ѭ���е�һ�������߼�
 * a <-b + ((a + g(b,c,d) + X[k] + T[i]) <<<s)
 * ˵����
 * a, b, c, d : MD ������(A, B, C, D) �ĵ�ǰֵ��
 * g : �ֺ���(F, G, H, I �е�һ��)��
 *  <<<s : ��32λ����ѭ������(CLS) s λ��
 * X[k] : ��ǰ������Ϣ����ĵ�k ��32λ�֣��� M [qx16+k]
 * T[i] : T ��ĵ�i ��Ԫ�أ�32λ�֡�
 * + : ģ232 �ӷ���
 */
#define FF(a, b, c, d, x, s, ac) { \
  (a) += F ((b), (c), (d)) + (x) + ac; \
  (a) = ROTATELEFT ((a), (s)); \
  (a) += (b); \
}
#define GG(a, b, c, d, x, s, ac) { \
  (a) += G ((b), (c), (d)) + (x) + ac; \
  (a) = ROTATELEFT ((a), (s)); \
  (a) += (b); \
}
#define HH(a, b, c, d, x, s, ac) { \
  (a) += H ((b), (c), (d)) + (x) + ac; \
  (a) = ROTATELEFT ((a), (s)); \
  (a) += (b); \
}
#define II(a, b, c, d, x, s, ac) { \
  (a) += I ((b), (c), (d)) + (x) + ac; \
  (a) = ROTATELEFT ((a), (s)); \
  (a) += (b); \
}

#include <string>
#include <cstring>

using std::string;

typedef unsigned char byte;
typedef unsigned int bit32;

class MD5 {
public:
	
  MD5(const string& message);

  const byte* getDigest();

  string toString();

private:

  void init(const byte* input, size_t len);
  void transform(const byte block[64]);
  void encode(const bit32* input, byte* output, size_t length);
  void decode(const byte* input, bit32* output, size_t length);

private:
 
  bool finished;  //�Ƿ���ɵı�� 
  byte buffer[64]; //����Buffer 
  byte digest[16]; // MD��� 
  bit32 state[4]; //�Ĵ��� A,B,C,D 
  bit32 count[2]; //���ȼ��� 

  static const byte PADDING[64]; //������� 
  static const char HEX_NUMBERS[16]; //ʮ�����Ʊ�ʾ 
};

#endif // MD5_H
