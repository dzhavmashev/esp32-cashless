// Function : FUN_401314d4
// Address  : 0x401314d4
// Size     : 114 bytes


int FUN_401314d4(int param_1,uint param_2,code *param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)((param_2 & 3) != 0) + (param_2 >> 2);
  iVar3 = uVar2 * 4 - param_2;
  iVar1 = -4;
  if (uVar2 <= *(uint *)(param_1 + 4)) {
    memw();
    (*(code *)&SUB_4008b530)(*(undefined4 *)(param_1 + 8),0,iVar3);
    (*(code *)&SUB_4008b530)
              (*(int *)(param_1 + 8) + uVar2 * 4,0,(*(int *)(param_1 + 4) - uVar2) * 4);
    iVar1 = (*param_3)(param_4,*(int *)(param_1 + 8) + iVar3,param_2);
    if ((iVar1 == 0) && (uVar2 != 0)) {
      FUN_401314a0(*(undefined4 *)(param_1 + 8),uVar2);
    }
  }
  return iVar1;
}

