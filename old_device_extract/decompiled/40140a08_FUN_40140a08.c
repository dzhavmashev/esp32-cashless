// Function : FUN_40140a08
// Address  : 0x40140a08
// Size     : 225 bytes


undefined4 FUN_40140a08(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  if (param_2 == 0) {
    param_1[4] = 0xf3bcc908;
    param_1[5] = 0x6a09e667;
    param_1[6] = 0x84caa73b;
    param_1[7] = 0xbb67ae85;
    param_1[8] = 0xfe94f82b;
    param_1[9] = 0x3c6ef372;
    param_1[10] = 0x5f1d36f1;
    param_1[0xb] = 0xa54ff53a;
    param_1[0xc] = 0xade682d1;
    param_1[0xd] = 0x510e527f;
    param_1[0xe] = 0x2b3e6c1f;
    param_1[0xf] = 0x9b05688c;
    param_1[0x10] = 0xfb41bd6b;
    param_1[0x11] = 0x1f83d9ab;
    uVar1 = 0x137e2179;
    uVar2 = 0x5be0cd19;
  }
  else {
    param_1[4] = 0xc1059ed8;
    param_1[5] = 0xcbbb9d5d;
    param_1[6] = 0x367cd507;
    param_1[7] = 0x629a292a;
    param_1[8] = 0x3070dd17;
    param_1[9] = 0x9159015a;
    param_1[10] = 0xf70e5939;
    param_1[0xb] = 0x152fecd8;
    param_1[0xc] = 0xffc00b31;
    param_1[0xd] = 0x67332667;
    param_1[0xe] = 0x68581511;
    param_1[0xf] = 0x8eb44a87;
    param_1[0x10] = 0x64f98fa7;
    param_1[0x11] = 0xdb0c2e0d;
    uVar1 = 0xbefa4fa4;
    uVar2 = 0x47b5481d;
    memw();
  }
  param_1[0x12] = uVar1;
  param_1[0x13] = uVar2;
  param_1[0x34] = param_2;
  if (param_1[0x35] == 1) {
    uVar1 = 2;
    if (param_2 == 0) {
      uVar1 = 3;
    }
    memw();
    FUN_40143664(uVar1);
  }
  param_1[0x35] = 0;
  memw();
  return 0;
}

