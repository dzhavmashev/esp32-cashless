// Function : FUN_400e6c2c
// Address  : 0x400e6c2c
// Size     : 308 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e6c2c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar5 = param_1 + 0x10;
  FUN_400f0be8(param_1,&DAT_3f42161d);
  FUN_400f0be8(iVar5,&DAT_3f42161d);
  do {
    *(undefined1 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0x16d;
    iVar1 = FUN_400e6a84(param_2);
    if (iVar1 != 0) {
      iVar1 = param_2 + 8;
      FUN_400f0be8(auStack_34,"invalid");
      iVar2 = FUN_400f143c(iVar1,auStack_34);
      FUN_400f0a50(auStack_34);
      if (iVar2 == -1) {
        pcVar6 = "-Device";
LAB_400e6d10:
        FUN_400f0d70(param_1,pcVar6);
      }
      else {
        uVar3 = (*(code *)&LAB_40183a7b_1)(iVar1);
        if (uVar3 < iVar2 + 0x12U) {
          pcVar6 = "32-";
          goto LAB_400e6d10;
        }
        FUN_400f1520(auStack_44,iVar1,iVar2);
        FUN_400f0be8(auStack_34,"");
        uVar4 = FUN_400f10c0(auStack_34,auStack_44);
        FUN_400f0d18(param_1,uVar4);
        FUN_400f0a50(auStack_34);
        FUN_400f0a50(auStack_44);
      }
      FUN_400f0d70(iVar5," Device");
      iVar1 = FUN_400e6ab4(param_2);
      *(bool *)(param_1 + 0x20) = iVar1 == 0;
      *(undefined4 *)(param_1 + 0x24) = 0xe42;
    }
    iVar1 = iStack_24;
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) {
      return;
    }
    func_0x40082ecc();
    FUN_400f0a50(auStack_34);
    FUN_400f0a50(iVar5);
    FUN_400f0a50(iVar1);
    thunk_FUN_401710d8(param_1);
    param_1 = iVar1;
  } while( true );
}

