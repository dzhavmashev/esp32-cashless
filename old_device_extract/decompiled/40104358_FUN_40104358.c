// Function : FUN_40104358
// Address  : 0x40104358
// Size     : 133 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40104358(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  puVar1 = (undefined4 *)FUN_40159fac();
  if ((param_1 != 0) && (_DAT_3ffc80e0 != 0x400)) {
    iVar2 = FUN_4015a09c();
    if (iVar2 != 0) {
      FUN_4015a08c();
      iVar2 = (*(code *)&SUB_4008c01c)();
      if (iVar2 == 0x40) {
        uVar3 = FUN_4015a08c();
        uVar4 = FUN_40159f7c();
        iVar2 = FUN_40104f84(uVar3,uVar4,0x20);
        if (iVar2 != 0) {
          return;
        }
      }
      else {
        uVar3 = FUN_4015a08c();
        uVar5 = *puVar1;
        uVar4 = FUN_40159f7c();
        FUN_4010231c(uVar3,puVar1 + 1,uVar5,0x1000,uVar4,0x20);
      }
      FUN_40159f50();
      FUN_4015a0ac(0);
    }
    if (_DAT_3ffc80e0 != 1) {
      uVar3 = FUN_40159f7c();
      (*(code *)&SUB_4008b3d0)(0x3ffc7ef0,uVar3,0x20);
      _DAT_3ffc7f30 = 0x20;
      memw();
    }
  }
  return;
}

