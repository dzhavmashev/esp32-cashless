// Function : FUN_400eab98
// Address  : 0x400eab98
// Size     : 302 bytes


void FUN_400eab98(undefined4 *param_1,undefined4 param_2,undefined1 param_3,uint param_4)

{
  undefined4 uVar1;
  
  *param_1 = &DAT_3f409930;
  param_1[1] = param_2;
  param_1[2] = 0;
  param_1[5] = 0;
  param_1[9] = 0;
  param_1[0xd] = 0;
  param_1[0x11] = 0;
  param_1[0x15] = 0;
  param_1[0x19] = 0;
  param_1[0x1d] = 0;
  param_1[0x1f] = 0;
  param_4 = param_4 & 0xff;
  FUN_400f057c(param_1 + 0x20);
  *(undefined2 *)(param_1 + 0x23) = 0x75b;
  param_1[0x24] = 15000;
  *(undefined1 *)(param_1 + 0x25) = 1;
  param_1[0x2b] = 10000;
  param_1[0x22] = 0;
  *(undefined1 *)((int)param_1 + 0x8e) = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2c] = 0;
  func_0x4008b538(param_1 + 0x2d,0,0x18);
  *(undefined2 *)(param_1 + 0x33) = 0;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  func_0x4008b538(param_1 + 0x36,0,0x5a0);
  param_1[0x19e] = 0;
  param_1[0x19f] = 0;
  param_1[0x1a0] = 0;
  param_1[0x1a1] = 0;
  param_1[0x1a2] = 0;
  FUN_400ec5b0(param_1 + 0x1a3);
  param_1[0x1d7] = 0;
  param_1[0x1d8] = 0;
  *(undefined2 *)(param_1 + 0x1d9) = 0x700;
  FUN_400efef4(0x3ffc53f4);
  FUN_401742a0(param_1 + 0x2d,0x18,"p32-tls");
  uVar1 = func_0x4008fcd0(1);
  param_1[0x34] = uVar1;
  func_0x4008fac0(uVar1,0,0);
  if (param_1[1] == 1) {
    if (1 < param_4) {
      param_4 = 0x7fffffff;
    }
    func_0x40090934(0x400ebbac,"2%06llx",0x1400,param_1,param_3,param_1 + 0x35,param_4);
  }
  param_1[0x1f] = param_1 + 0x2d;
  return;
}

