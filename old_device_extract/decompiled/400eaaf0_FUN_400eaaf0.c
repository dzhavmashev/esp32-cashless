// Function : FUN_400eaaf0
// Address  : 0x400eaaf0
// Size     : 88 bytes


int FUN_400eaaf0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  code *pcVar6;
  
  puVar5 = *(undefined4 **)(param_1 + 0x680);
  iVar3 = 0;
  if (puVar5 != (undefined4 *)0x0) {
    iVar1 = FUN_400ec1a4(puVar5 + 1,*(undefined4 *)(param_1 + 0x688));
    iVar3 = 0;
    if (iVar1 != 0) {
      piVar4 = *(int **)(param_1 + 8);
      pcVar6 = *(code **)(*piVar4 + 8);
      uVar2 = FUN_400ec1c4(puVar5 + 1,*(undefined4 *)(param_1 + 0x688));
      iVar3 = (*pcVar6)(piVar4,uVar2,iVar1);
      uVar2 = FUN_400f1a9c();
      *puVar5 = uVar2;
      uVar2 = FUN_400f1a9c();
      *(undefined4 *)(param_1 + 0x75c) = uVar2;
      *(int *)(param_1 + 0x688) = *(int *)(param_1 + 0x688) + iVar3;
    }
  }
  return iVar3;
}

