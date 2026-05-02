// Function : FUN_400fe2c8
// Address  : 0x400fe2c8
// Size     : 38 bytes


uint FUN_400fe2c8(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)&LAB_40184d8e_2)(param_1);
  iVar2 = 0x3f8;
  memw();
  if ((*(uint *)(*param_1 + 0x20) >> 0x1b & 1) == 0) {
    iVar2 = 0xf;
  }
  return iVar2 / iVar1 & 0xffff;
}

