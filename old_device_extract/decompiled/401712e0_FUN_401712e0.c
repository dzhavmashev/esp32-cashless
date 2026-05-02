// Function : FUN_401712e0
// Address  : 0x401712e0
// Size     : 90 bytes


void FUN_401712e0(undefined4 param_1,code *param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  while( true ) {
    iVar4 = param_4 * 2 + 1;
    if (param_5 <= iVar4) {
      return;
    }
    iVar5 = param_4 * 2 + 2;
    if ((iVar5 < param_5) &&
       (puVar2 = (undefined4 *)(param_3 + iVar4 * 4), iVar1 = (*param_2)(param_1,*puVar2,puVar2[1]),
       iVar1 < 0)) {
      iVar4 = iVar5;
    }
    puVar2 = (undefined4 *)(param_3 + param_4 * 4);
    puVar3 = (undefined4 *)(param_3 + iVar4 * 4);
    iVar5 = (*param_2)(param_1,*puVar2,*puVar3);
    if (-1 < iVar5) break;
    uVar6 = *puVar2;
    *puVar2 = *puVar3;
    *puVar3 = uVar6;
    param_4 = iVar4;
  }
  return;
}

