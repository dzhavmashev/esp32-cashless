// Function : FUN_400ee6c4
// Address  : 0x400ee6c4
// Size     : 257 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400ee6c4(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  undefined1 auStack_34 [16];
  int *piStack_24;
  
  memw();
  memw();
  piStack_24 = _DAT_3ffc5708;
  if (((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) && (*param_2 == 0)) goto LAB_400ee71c;
  iVar1 = FUN_400f1380(param_2,0);
  if (iVar1 != 0x2f) goto LAB_400ee71c;
  FUN_400f0d18(param_1 + 0x2c,param_2);
  FUN_400ed9f0(param_1);
  iVar1 = 1;
  while( true ) {
    param_1 = iVar1;
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (piStack_24 == _DAT_3ffc5708) break;
    func_0x40082ecc();
LAB_400ee71c:
    iVar4 = param_1 + 0x3c;
    FUN_400f0d4c(auStack_34,iVar4);
    uVar2 = FUN_400f1114(auStack_34,0x3a);
    iVar3 = FUN_400f12d8(param_2,uVar2);
    FUN_400f0a50(auStack_34);
    iVar1 = 0;
    if (iVar3 != 0) {
      iVar1 = FUN_400f13c0(param_2,0x3a,6);
      iVar3 = FUN_400f13c0(param_2,0x2f,7);
      if ((iVar1 == -1) || (iVar3 < iVar1)) {
        iVar1 = FUN_400f11c0(iVar4,"r");
        uVar5 = 0x50;
        if (iVar1 != 0) {
          uVar5 = 0x1bb;
        }
        *(undefined2 *)(param_1 + 0x1c) = uVar5;
      }
      *(undefined1 *)(param_1 + 0x9c) = 1;
      FUN_400eda0c(param_1,1);
      FUN_400f0d4c(auStack_34,param_2);
      if ((*(byte *)(param_1 + 0x4b) & 0x80) == 0) {
        iVar4 = *(int *)(param_1 + 0x3c);
      }
      iVar1 = FUN_400eda84(param_1,auStack_34,iVar4);
      FUN_400f0a50(auStack_34);
    }
  }
  return;
}

