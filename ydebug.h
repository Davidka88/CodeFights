#define DB(A) std::cout << #A "=" << (A) << std::endl
#define DB1(A) DB(A)
#define DB2(A,B) std::cout << #A "=" << (A) << " " #B "=" << (B) << std::endl
#define DB3(A,B,C) std::cout << #A "=" << (A) \
                         << " " #B "=" << (B) \
						 << " " #C "=" << (C) << std::endl
