// Function : FUN_400e6f20
// Address  : 0x400e6f20
// Size     : 178 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e6f20(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar1 = FUN_400e6a84(param_1);
  if (iVar1 != 0) goto LAB_400e6f61;
  FUN_400f0780(0x3ffc5490,"ificate");
  while( true ) {
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    func_0x40082ecc();
    param_1 = iVar1;
LAB_400e6f61:
    FUN_400f0be8(auStack_34,"uration");
    iVar3 = param_1 + 0x28;
    iVar2 = FUN_400f143c(iVar3,auStack_34);
    FUN_400f0a50(auStack_34);
    if (iVar2 != -1) {
      FUN_400f0780(0x3ffc5490,"TE-----");
    }
    if ((*(byte *)(param_1 + 0x37) & 0x80) == 0) {
      iVar3 = *(int *)(param_1 + 0x28);
    }
    (*(code *)&LAB_40184403_1)(param_2,iVar3);
    iVar2 = param_1 + 8;
    if ((*(byte *)(param_1 + 0x17) & 0x80) == 0) {
      iVar2 = *(int *)(param_1 + 8);
    }
    FUN_40184414(param_2,iVar2);
    iVar2 = param_1 + 0x18;
    if ((*(byte *)(param_1 + 0x27) & 0x80) == 0) {
      iVar2 = *(int *)(param_1 + 0x18);
    }
    FUN_4018441c(param_2,iVar2);
  }
  return;
}

