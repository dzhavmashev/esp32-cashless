// Function : FUN_4016e1b8
// Address  : 0x4016e1b8
// Size     : 92 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016e1b8(uint param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  code *pcVar2;
  
  uVar1 = (**(code **)(_DAT_3ffc7e64 + 0x2c))
                    ((int)((param_1 & 0xffff) * 0x18 + -0x154) / 0xe3,0xf,0);
  pcVar2 = *(code **)(_DAT_3ffc7e64 + 0x2c);
  *param_2 = uVar1;
  memw();
  uVar1 = (*pcVar2)(((param_1 & 0xffff) * 0x17 + 0x1d) / 0xcf,0xf,0);
  param_2[1] = uVar1;
  memw();
  return;
}

