// Function : FUN_400fb50c
// Address  : 0x400fb50c
// Size     : 70 bytes


int FUN_400fb50c(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int aiStack_24 [9];
  
  iVar3 = *(int *)(param_1 + 0x3c);
  iVar4 = -1;
  if (iVar3 == param_2) {
    uVar1 = *(uint *)(param_1 + 0x38);
    *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;
    for (uVar2 = iVar3 + param_3; uVar2 < (uVar1 < 0x7e) * uVar1 + (uint)(uVar1 >= 0x7e) * 0x7e;
        uVar2 = uVar2 + 1) {
      memw();
      iVar4 = (*(code *)&LAB_40184b76_2)(param_1 + 0x18,uVar2,aiStack_24);
      if (iVar4 != 0) goto LAB_400fb541;
      if (aiStack_24[0] == 2) {
        *(uint *)(param_1 + 0x3c) = uVar2;
        goto LAB_400fb541;
      }
    }
    iVar4 = 0;
  }
LAB_400fb541:
  memw();
  return iVar4;
}

