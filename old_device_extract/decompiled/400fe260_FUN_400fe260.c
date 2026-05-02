// Function : FUN_400fe260
// Address  : 0x400fe260
// Size     : 101 bytes


void FUN_400fe260(int *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = (*(code *)&LAB_40184d8e_2)(param_1);
  iVar3 = *param_1;
  uVar4 = iVar1 * (param_2 & 0xff);
  memw();
  uVar2 = (uVar4 & 0xffff) + 7 >> 3;
  if ((*(uint *)(iVar3 + 0x20) & 0x8000000) == 0) {
    uVar2 = (uVar4 & 0x1fff) << 3;
  }
  memw();
  if (uVar2 == 0) {
    uVar2 = *(uint *)(iVar3 + 0x24) & 0x7fffffff;
  }
  else {
    memw();
    *(uint *)(iVar3 + 0x24) = *(uint *)(iVar3 + 0x24) & 0x80ffffff | (uVar2 & 0x7f) << 0x18;
    memw();
    uVar2 = *(uint *)(iVar3 + 0x24) | 0x80000000;
  }
  memw();
  *(uint *)(iVar3 + 0x24) = uVar2;
  memw();
  return;
}

