// Function : FUN_4015f5c0
// Address  : 0x4015f5c0
// Size     : 63 bytes


int FUN_4015f5c0(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = (*(code *)&SUB_4000ab7c)(param_2 + param_3,4);
  uVar3 = 4;
  if ((uVar1 < 0x101) && (uVar3 = 2, uVar1 < 0x41)) {
    uVar3 = 3;
  }
  iVar2 = FUN_4015fb34(0,uVar3,uVar1);
  if (iVar2 != 0) {
    *param_1 = *(int *)(*(int *)(iVar2 + 4) + 4) + param_2;
    *(short *)(iVar2 + 0x16) = (short)param_3;
    memw();
  }
  memw();
  return iVar2;
}

