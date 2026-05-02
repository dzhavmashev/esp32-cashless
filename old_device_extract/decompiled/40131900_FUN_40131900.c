// Function : FUN_40131900
// Address  : 0x40131900
// Size     : 123 bytes


undefined4 FUN_40131900(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined1 *puVar3;
  int iVar4;
  
  uVar1 = *(int *)(param_1 + 4) * 4;
  uVar2 = param_3;
  if (uVar1 < param_3) {
    iVar4 = param_3 + *(int *)(param_1 + 4) * -4;
    (*(code *)&SUB_4008b530)(param_2,0);
    param_3 = uVar1;
    param_2 = param_2 + iVar4;
  }
  else {
    for (; uVar2 != uVar1; uVar2 = uVar2 + 1) {
      if ((*(uint *)(*(int *)(param_1 + 8) + (uVar2 & 0xfffffffc)) >> ((uVar2 & 3) << 3) & 0xff) !=
          0) {
        return 0xfffffff8;
      }
    }
  }
  puVar3 = (undefined1 *)(param_2 + param_3);
  uVar2 = 0;
  while (puVar3 = puVar3 + -1, param_3 != uVar2) {
    *puVar3 = (char)(*(uint *)(*(int *)(param_1 + 8) + (uVar2 & 0xfffffffc)) >> ((uVar2 & 3) << 3));
    memw();
    memw();
    uVar2 = uVar2 + 1;
  }
  return 0;
}

