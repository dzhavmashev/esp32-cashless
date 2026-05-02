// Function : FUN_4013f7ec
// Address  : 0x4013f7ec
// Size     : 126 bytes


undefined4 FUN_4013f7ec(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  if (param_2 == 0) {
    param_1[2] = 0x6a09e667;
    param_1[3] = 0xbb67ae85;
    param_1[4] = 0x3c6ef372;
    param_1[5] = 0xa54ff53a;
    param_1[6] = 0x510e527f;
    param_1[7] = 0x9b05688c;
    param_1[8] = 0x1f83d9ab;
    uVar1 = 0x5be0cd19;
  }
  else {
    param_1[2] = 0xc1059ed8;
    param_1[3] = 0x367cd507;
    param_1[4] = 0x3070dd17;
    param_1[5] = 0xf70e5939;
    param_1[6] = 0xffc00b31;
    param_1[7] = 0x68581511;
    param_1[8] = 0x64f98fa7;
    uVar1 = 0xbefa4fa4;
    memw();
  }
  param_1[9] = uVar1;
  param_1[0x1a] = param_2;
  if (param_1[0x1b] == 1) {
    memw();
    FUN_40143664();
  }
  param_1[0x1b] = 0;
  memw();
  return 0;
}

